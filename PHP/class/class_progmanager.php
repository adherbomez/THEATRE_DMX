<?php
require_once  ('../class/class_bdd_php.php');

/*----------------------------------------------------------------/
PROJET THEATRE DMX512
DEVELOPPÉ PAR : MAXIME LEPELLETIER 
BTS SN2

		- classe manager de programme de l'ihm php - 

cette classe permet de parametrer les scene de lumiere.
ces derniers composent les programmes (objet du fichier class_programme.php)
/----------------------------------------------------------------*/



	Class progmanager 
	{ 
		private $bdd;
		function __construct()
		{
			echo "lien prog ok <br>";
		}

		// fonction qui permet d'ajouter un Programme sur l'ihm
		public function AjouterProgramme($bdd,$_nomprog)
		{
			$this->_nomprog=$_nomprog;
			$bdd = new BDD('maxime','mdp','192.168.65.97','theater','root','root');
			$req='INSERT INTO program (Nom) VALUES (:Nom)';
			$valeurs = ['Nom'=>$this->_nomprog];
			$pdo = $bdd->GetBDD();
			$prepareinsert=$pdo->prepare($req);
			if($prepareinsert->execute($valeurs))
			{
					echo "programme ajouté (fct)";
			}
			
			$bdd = NULL;
		}
		

// fonction qui permet de modifier un Programme
		public function ModifierProgramme()
		{
			
		}

// fonction qui permet de supprimer un Programme sur l'ihm
		public function SupprimerProgramme($bdd,$id)
		{
			$this->_nomprog=$_nomprog;
			$bdd = new BDD('maxime','mdp','192.168.65.97','theater','root','root');
			$req='INSERT INTO program (Nom) VALUES (:Nom)';
			$valeurs = ['Nom'=>$this->_nomprog];
			$pdo = $bdd->GetBDD();
			$prepareinsert=$pdo->prepare($req);
			if($prepareinsert->execute($valeurs))
			{
					echo "programme ajouté (fct)";
			}
			
			$bdd = NULL;
		}

// fonction qui permet de lancer un Programme a partir de l'ihm		
		public function RunProgramme()
		{
		
		}

		


	}

?>