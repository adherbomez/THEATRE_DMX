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
					echo 'connexion etablie';
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
	private function connexionBdd($host,$dbname,$username,$mdp){
			try
			{
				$this->_Bdd= new PDO('mysql:host='.$host.';dbname='.$dbname.'',$username,$mdp);
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

	public function Modelaccueil($_Bdd)
	{
		foreach($this->_Bdd->query('SELECT * FROM `program` ORDER BY`IdProgram`') as $row) 
		    {
		        echo "<li class='btnprog'><a href=''>".$row['Nom']."</a></li><br>";
		    }
	    foreach($this->_Bdd->query('SELECT * FROM `program` ORDER BY`IdProgram`') as $row) 
	    {
	        echo "<li class='btnprog'><a href=''>".$row['Nom']."</a></li><br>";
	    }
	}

}
		
?>
	