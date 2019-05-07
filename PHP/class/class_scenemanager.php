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
	public function AjouterScene($bdd,$_Scene)
	{
		$this->_Scene=$_Scene;
		$bdd = new BDD('maxime','mdp','192.168.65.97','theater','root','root');
		$req='INSERT INTO scene (Nomscene) VALUES (:Nomscene)';
		$valeurs = ['Nomscene'=>$_Scene];
		$pdo = $bdd->GetBDD();
		$prepareinsert=$pdo->prepare($req);
		if($prepareinsert->execute($valeurs))
		{
				echo "scene ajoutée (fct)";
		}
		
		$bdd = NULL;
	}
	
		
	
// fonction qui permet de modifier une scene sur l'ihm
		public function ModifierScene()
		{
		
		
		}
// fonction qui permet de supprimer une scene sur l'ihm
		public function SupprimerScene($bdd,$_idscene)
		{
		$this->_idscene=$_idscene;
		$bdd = new BDD('maxime','mdp','192.168.65.97','theater','root','root');
		$req='DELETE FROM `scene` WHERE `IdScene`= :ids ';
		$valeurs = ['idp'=>$this->_idscene];
		$pdo = $bdd->GetBDD();
		$preparedelete=$pdo->prepare($req);
		$preparedelete->bindParam('idp',$this->_idscene);
		if($preparedelete->execute($valeurs))
		{
			echo "scene supprimée (fct)";
		}			
		$bdd = NULL;	
		}
// fonction qui permet de lancer une scene a partir de l'ihm		
		public function RunScene()
		{
			
			
		}
	
}

?>