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

			//On définie les variables
	function __construct($name,$pswrd,$host,$dbname,$username,$mdp){

		if($this->isConnect()==false)
		{
			$this->_Name=$name;
			$this->_Pwrd=$pswrd;
			$this->connexionBdd($host,$dbname,$username,$mdp);
			echo 'connexion etablie <br>';
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
	public function compare($table)
	{	
		$connect=$this->_Bdd->query("SELECT * FROM ".$table." WHERE `username` = '".$this->_Name."' AND `password` = '".$this->_Pwrd."'");
		//on vérifie si au moins 1 ligne à était éxécuté avec rowcount();
		if($connect->rowCount() > 0)
		{
			echo"Connexion reussie";
			$this->_connect = true;
			header('location: accueil.php');
			exit();
		}
		else
		{
			echo "erreur dans l'iddentifiant ou le mot de passe";
			$this->_connect = false;
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
	        echo '<li class="btnprog"><a href="accueil.php?item=PRG;'.$row['IdProgram'].'"><h2>'.$row['Nom'].'<br></h2></a></li><br>';
	        echo '<ul Id="scene">';
	        // puis on recherche les scenes en les ordonnant selon leur place dans leur programmess
        foreach($this->_Bdd->query("SELECT * FROM `scene` INNER JOIN `program` INNER join `compoprogram` ON program.IdProgram =compoprogram.IdProgram and scene.IdScene = compoprogram.IdScenecompo and compoprogram.IdProgram = ".$row['IdProgram']." ORDER by compoprogram.Place") as $row) 
		    {
		   		echo '<li class="btnscen"><a href="accueil.php?item=SCN;'.$row['IdScenecompo'].' name=".$row["IdScenecompo"].">".$row["Nomscene"]."</a></li><br>';
		    }
		    
		   	echo "</ul>";
	    }
	    echo'</ul>'; 
	   
	}
//cree un formulaire select avec les programmes de la base de données
    public function listprog($_Bdd,$name)
	{
		echo'<SELECT name='.$name.' size="1">';
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
		echo'<SELECT name='.$name.' size="1">';
		echo '<option class="scenelist" value=""></option>';
		foreach($this->_Bdd->query('SELECT * FROM `scene` ORDER BY`IdScene`') as $row) 
	    {
	   		echo "<option class='scenelist' value=".$row['IdScene'].">" .$row['Nomscene']."</option>";
	    }
	    echo '</SELECT>';
	}
			
//permet de reccuperer le dernier ID
    public function Lastid($_champ,$_table)
	{	
		$maxid=0;
		$reponse = $this->_Bdd->query('SELECT '.$_champ.' FROM '.$_table.'');
		while ($donnees = $reponse->fetch())
		{
			$maxid++;
		}
		return $maxid;
	}
//retourne la bdd utilisée
	public function GetBDD()
	{
		return $this->_Bdd;
	}

}
		
?>
	