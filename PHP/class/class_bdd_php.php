<?php

/*----------------------------------------------------------------/
PROJET THEATRE DMX512
DEVELOPPÉ PAR : MAXIME LEPELLETIER 
BTS SN2

		- classe de gestion de l'ihm php - 

cette classe permet de se connecter / interagir / se deconnecter de la base de donnée de l'application
pour pouvoir ajouter et supprimer des scenes ou des programmes , sans avoir a passer par le c++ et le protocole tcp-ip

/----------------------------------------------------------------*/
class BDD{

			private $_Name;
			private $_Pwrd;
			private $_Bdd;
			private $_connect = false;
			private $req;

			//On définie les variables
	function __construct($name,$pswrd,$host,$dbname,$username,$mdp){

		if($this->isConnect()==false)
		{
			$this->_Name=$name;
			$this->_Pwrd=$pswrd;
			$this->connexionBdd($host,$dbname,$username,$mdp);
			
		}
		else
		{
			echo 'deja connécté';
		}	
	}

//vérifie la connection	
	public function  isConnect()
	{
			return $this->_connect;
	}

//Permet de se connecter à la bdd
	private function connexionBdd($host,$dbname,$username,$mdp)
	{
		try
		{
			$this->_Bdd= new PDO('mysql:host='.$host.';dbname='.$dbname.'',$username,$mdp,array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));
		}
		catch(Exception $e)
		{
			echo $e->getMessage();
		}
	}

//Compare la BDD avec les informations rentrées dans le formulaire
	public function compare($user,$pass)
	{	
			$this->user=$user;
			$this->pass=$pass;
			$bdd = new BDD('maxime','mdp',ipadress,'theater','maxime','mdp');
			$varexist='SELECT * FROM login WHERE `username` = :username AND `password` = :password';
			$pdo = $bdd->GetBDD();
			$preparereq=$pdo->prepare($varexist);
			$preparereq->bindParam('idp',$_idprog);
			$preparereq->bindParam('place',$_idprog);
			if($preparereq->execute())
			{
		$this->_Bdd->query("SELECT * FROM ".$table." WHERE `username` = '".$this->_Name."' AND `password` = '".$this->_Pwrd."'");
		//on vérifie si au moins 1 ligne à était éxécuté avec rowcount();
		if($req->rowCount() > 0)
		{
			echo"Connexion reussie";
			$this->_connect = true;
			// header('Location: accueilboot.php'); 
			// exit();		

		}
		else
		{
			echo "erreur dans l'iddentifiant ou le mot de passe";
			$this->_connect = false;
		}
	}
	}

//cette fonction permet de s'inscrire à la bdd
	public function inscription($table)
	{
		if($this->_Bdd->query("INSERT INTO ".$table."(`username`, `password`) VALUES ('".$this->_Name."','".$this->_Pwrd."')"))
		{
			echo "Inscription réussie";
		}
		else
		{
			echo"Echec de l'inscription";
		}
	}
//fonction de modelisation de l'ihm , permet l'affichage des programmes et des scenes dynamiquement
	public function Modelaccueil($_Bdd)
	{
		//on cherche en base de données les programmes
		echo'<ul id="prog" type="circle">';
		foreach($this->_Bdd->query('SELECT * FROM `program` ORDER BY`IdProgram`') as $row) 
	    {
	    	//on les affiche dans des div draggables , en les classant par id
	        echo '<li class="btn btn-dark"><a class="fontprog" href="accueilboot.php?item=PRG;'.$row['IdProgram'].'"><h2>'.$row['Nom'].'<br></h2></a></li><br>';

	        echo '<ul Id="sceneprog">';
	        echo "<div>";
	        // puis on recherche les scenes en les ordonnant selon leur place dans leur programmess
        	foreach($this->_Bdd->query("SELECT * FROM `scene` INNER JOIN `program` INNER join `compoprogram` ON program.IdProgram =compoprogram.IdProgramCompo and scene.IdScene = compoprogram.IdSceneCompo and compoprogram.IdProgramCompo = ".$row['IdProgram']." ORDER by compoprogram.Place") as $row) 
		    {
		    	
		    	echo '<div class="d-inline-block bg-info"><a href="accueilboot.php?item=SCN;'.$row['IdSceneCompo'].'" id="listprog"><li class="list-group-item" draggable="true" >'.$row['Place']. " : " .$row["Nomscene"].'</li></a></div>';
		    	
		   		
		    }
		    echo "</div>";
		   	echo "</ul>";
	    }
	    echo'</ul>'; 
	   
	}
//cree un formulaire select avec les programmes de la base de données
   public function listprog($_Bdd,$name)
	{
		echo'<SELECT  style="max-width: 40%;" class="form-control"  name='.$name.' size="1">';
		echo '<option class="proglist" value=""></option>';
		foreach($this->_Bdd->query('SELECT * FROM `program` ORDER BY`IdProgram`') as $row) 
	    {
	   		echo "<option class='proglist' value=".$row['IdProgram'].">" .$row['Nom']."</option>";
	    }
	    echo '</SELECT>';
	}
//cree un formulaire select avec les scenes de la base de données
	 public function listscene($_Bdd,$name)
	{
		echo '<SELECT  style="max-width: 40%;" class="form-control" name='.$name.' size="1">';
		echo '<option  value=""></option>';
		foreach($this->_Bdd->query('SELECT * FROM `scene` ORDER BY `Idscene`') as $row) 
	    {
	   		echo "<option class='proglist' value=".$row['IdScene'].">" .$row['Nomscene']."</option>";
	    }
	    echo '</SELECT>';
	}
	

//cree un formulaire select avec les scenes de la base de données (spécifique a un programme)
	//  public function listsceneofprog($_Bdd,$name,$IdProgram)
	// {
	// 	echo '<SELECT  onchange="visible()" style="max-width: 40%;" class="form-control" name='.$name.' size="1">';
	// 	echo '<option  value=""></option>';
	// 	foreach($this->_Bdd->query('SELECT * FROM `compoprogram` , `scene` WHERE scene.IdScene = compoprogram.IdSceneCompo and IdProgramCompo = '.$IdProgram.'') as $row) 
	//     {
	//    		echo "<option class='proglist' value=".$row['IdScene'].">" .$row['Nomscene']."</option>";
	//     }
	//     echo '</SELECT>';
	// }
	
			
//permet de reccuperer le dernier ID
    public function Nbplace($_Bdd,$_IdProg)
	{	
		$nbscene=0;
		foreach ( $this->_Bdd->query('SELECT * FROM `compoprogram` where IdProgramCompo = '.$_IdProg.'') as $row ) 
		{
		 	$nbscene++;
		} 
		return $nbscene;
	}
//retourne la bdd utilisée
	public function GetBDD()
	{
		return $this->_Bdd;
	}

}
	

?>
	