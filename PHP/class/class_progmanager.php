<?php
require_once  ('../class/class_bdd_php.php');
require_once  ('../class/class_scenemanager.php');

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
		private $scene;
		private $bdd;
		function __construct()
		{
			
		}

		// fonction qui permet d'ajouter un Programme sur l'ihm
		public function AjouterProgramme($bdd,$_nomprog)
		{
			$this->_nomprog=$_nomprog;
			$bdd = new BDD('maxime','mdp',ipadress,'theater','maxime','mdp');
			$req='INSERT INTO program (Nom) VALUES (:Nom)';
			$valeurs = ['Nom'=>$_nomprog];
			$pdo = $bdd->GetBDD();
			$prepareinsert=$pdo->prepare($req);
			if($prepareinsert->execute($valeurs))
			{
					echo "programme ajouté a la base de données";
			}
			
			$bdd = NULL;
			
		}
		

// fonction qui permet de modifier un Programme
		public function ModifierProgramme($bdd,$_idprog)
		{
			$this->_idprog=$_idprog;
		
			// modifier le nom

		}

// fonction qui permet de supprimer un Programme sur l'ihm
		public function SupprimerProgramme($bdd,$_idprog)
		{

			$this->_idprog=$_idprog;
			$bdd = new BDD('maxime','mdp',ipadress,'theater','maxime','mdp');
			$req='DELETE FROM `program` WHERE `IdProgram`= :idp ';
			$pdo = $bdd->GetBDD();
			$preparedelete=$pdo->prepare($req);
			$preparedelete->bindParam('idp',$this->_idprog);
			if($preparedelete->execute($valeurs))
			{
					$scene->SuppimerScene($bdd,$_idprog,'');				
					echo "programme et contenu supprimé ";
			}	
			else 
			{
					echo "probleme suppression du programme";
			}

			$bdd = NULL;
		}

		public function	compoexist($_idprog,$place)
		{	
			$this->_idprog=$_idprog;
			$this->place=$place;
			$bdd = new BDD('maxime','mdp',ipadress,'theater','maxime','mdp');
			$varexist='SELECT * FROM `compoprogram` WHERE idProgramcompo = :idp and place = :place';
			$pdo = $bdd->GetBDD();
			$preparereq=$pdo->prepare($varexist);
			$preparereq->bindParam('idp',$_idprog);
			$preparereq->bindParam('place',$place);
			if($preparereq->execute())
			{
				if($preparereq->rowCount() > 0)
				{
	 				return true;
				}
				else
				{
					return false;
				}	

					echo "deja existant";
			}	
			else 
			{
					echo "probleme suppression prog (fct)";
			}
			
		}



	}

?>