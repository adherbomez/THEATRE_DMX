<?php
require_once  ('../class/class_bdd_php.php');

/*----------------------------------------------------------------/
PROJET THEATRE DMX512
DEVELOPPÉ PAR : MAXIME LEPELLETIER 
BTS SN2

		- classe manager de scene de l'ihm php - 

cette classe permet d'utiliser des fonctions d'interraction avec les scenes
il s'agit la de pouvoir ajouter des 
/----------------------------------------------------------------*/


	Class Scenemanager
{
		protected $_Scene;


// fonction qui permet d'ajouter une scene sur l'ihm
	public function AjouterScene($bdd,$IdProg,$_idscene,$nb)
	{
		$this->_idscene=$_idscene;
		$this->IdProg=$IdProg;
		$this->nb=$nb;

		$bdd = new BDD('maxime','mdp',ipadress,'theater','maxime','mdp');
		$req='INSERT INTO `compoprogram`(`IdProgramCompo`,`IdSceneCompo`, `Place`,`TempsPause`) VALUES (:id_prog , :id_scene , :place , 0)';
		$valeurs = ['id_scene'=>$_idscene ,'id_prog'=>$IdProg ,'place'=>$nb ];
		$pdo = $bdd->GetBDD();
		$prepareinsert=$pdo->prepare($req);
		if($prepareinsert->execute($valeurs))
		{
				echo "scenes ajoutées au programme";
		}
		
		$bdd = NULL;
	}
	
		
	
// fonction qui permet de modifier une scene sur l'ihm
		public function ModifierScene($bdd,$_IdProg,$_idscene,$nb)
		{
			$this->_idscene=$_idscene;
			$this->_IdProg=$_IdProg;
			$this->nb=$nb;
//
			$bdd = new BDD('maxime','mdp',ipadress,'theater','maxime','mdp');
			$req='UPDATE `compoprogram` SET `IdProgramCompo`= :id_prog ,`IdSceneCompo`= :id_scene,`Place`= :place  WHERE IdProgramCompo = :id_prog and place = :place';
			$valeurs = ['id_scene'=>$_idscene ,'id_prog'=>$_IdProg ,'place'=>$nb ];
			$pdo = $bdd->GetBDD();
			$prepareinsert=$pdo->prepare($req);
			if($prepareinsert->execute($valeurs))
			{
					echo "scènes du programme modifiée";
			}
			
			$bdd = NULL;
			
		}

// fonction qui permet de supprimer une scene sur l'ihm
		public function SupprimerScene($bdd,$_IdProg,$nb)
		{

			$this->_IdProg=$_IdProg;
			$this->nb = $nb;

			if ($nb == '' ) 
			{
				
				$bdd = new BDD('maxime','mdp',ipadress,'theater','maxime','mdp');
				$req='DELETE FROM `compoprogram` WHERE `IdProgramCompo`= :id_prog ';
				$valeurs = ['id_prog' => $_IdProg];
				$pdo = $bdd->GetBDD();
				$preparedelete=$pdo->prepare($req);
				if($preparedelete->execute($valeurs))
				{
					echo "contenu du progamme effacé";
				}
			}
			else
			{
				$bdd = new BDD('maxime','mdp',ipadress,'theater','maxime','mdp');
				$req='DELETE FROM `compoprogram` WHERE `place`= :place and `IdProgramCompo`= :id_prog ';
				$valeurs = ['id_prog' => $_IdProg ,'place' => $nb ];
				$pdo = $bdd->GetBDD();
				$preparedelete=$pdo->prepare($req);
				if($preparedelete->execute($valeurs))
				{	

					$nb = $bdd->Nbplace('',$_IdProg);

					for ( $i = 1 ; $i <= $nb; $i++)
					{
						$req='UPDATE `compoprogram` SET `Place`= :place  WHERE IdProgramCompo = :id_prog and place = :place  where place = :indice';
						$valeurs = ['place' => $nb , 'id_prog' => $_IdProg, 'indice'=> $nb+1];
						$pdo = $bdd->GetBDD();
						$preparedelete=$pdo->prepare($req);
						if($preparedelete->execute($valeurs))
						{
							echo "bla";
						}
					}
					echo "scene supprimée du programme";
				}			

			}
			
			$bdd = NULL;	
		}

}

?>