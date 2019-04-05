<?php
require('class_scene.php');
include('class_bdd_php.php');

/*----------------------------------------------------------------/
PROJET THEATRE DMX512
DEVELOPPÉ PAR : MAXIME LEPELLETIER 
BTS SN2

		- classe manager de scene de l'ihm php - 

cette classe permet d'utiliser des fonctions d'interraction avec les scenes
il s'agit la de pouvoir ajouter des 
/----------------------------------------------------------------*/


	Class Scenemanager extends Scene
{
	protected $_Scene;
	private $_Erreur;

// fonction qui permet d'ajouter une scene sur l'ihm
	public function AjouterScene($_Scene)
	{
		
	
		
	}
// fonction qui permet de modifier une scene sur l'ihm
	public function ModifierScene()
	{
		throw new Exception("erreur lors de la modification de scene", 2);
		
		try
		{
			
		}
		catch (Exception $e)
		{
		
		}
		
	}
// fonction qui permet de supprimer une scene sur l'ihm
	public function SupprimerScene()
	{
		throw new Exception("erreur suppression de scene", 3);
		
		try
		{

		}
		catch (Exception $e)
		{
		
		}
		
	}
// fonction qui permet de lancer une scene a partir de l'ihm		
	public function RunScene()
	{
		throw new Exception("erreur lors du lancement de la scene", 4);
		
		try
		{
			
		}
		catch (Exception $e)
		{
		
		}
		
	}
	
}

?>