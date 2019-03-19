<?php
require('class_bdd_php.php');
require('class_scene.php');
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
	$scene = new Scene();

// fonction qui permet d'ajouter une scene sur l'ihm
	public function AjouterScene()
	{
		if(1)
		{
			connexion();
			envoyer();
			deconnexion();	
			return true;
		}
			
		else
		{
			return false;
		}
				
		
	}
// fonction qui permet de modifier une scene sur l'ihm
	public function ModifierScene()
	{
		if(1)
		{
			connexion();
			envoyer();
			deconnexion();	
			return true;
		}
			
		else
		{
			return false;
		}
		
				
	}
// fonction qui permet de supprimer une scene sur l'ihm
	public function SupprimerScene()
	{
		if(1)
		{
			connexion();
			envoyer();
			deconnexion();	
			return true;
		}
			
		else
		{
			return false;
		}
	}		
	
// fonction qui permet de lancer une scene a partir de l'ihm		
	public function RunScene()
	{
		if(1)
		{
				connexion();
				envoyer();
				deconnexion();	
				return true;
		}
			
		else
		{
			return false;
		}
				 	
	}
	
}

?>