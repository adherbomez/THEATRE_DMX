<?php
require('class_bdd_php.php');/*----------------------------------------------------------------/
PROJET THEATRE DMX512
DEVELOPPÉ PAR : MAXIME LEPELLETIER 
BTS SN2

		- classe manager de programme de l'ihm php - 

cette classe permet de parametrer les scene de lumiere.
ces derniers composent les programmes (objet du fichier class_programme.php)
/----------------------------------------------------------------*/

	Class progmanager extends Programme

	{ 
				protected $_Programme;

// fonction qui permet d'ajouter un Programme sur l'ihm
		public function AjouterProgramme()
		{
			throw new Exception("erreur lors de lajout du programme", 5);
			
			try
			{
				
			}
			catch (Exception $e)
			{
			
			}

		}
// fonction qui permet de modifier un Programme
		public function ModifierProgramme()
		{
			throw new Exception("erreur lors de la modification du programme", 6);
			
			try
			{
				
			}
			catch (Exception $e)
			{
			
			}	
		}
// fonction qui permet de supprimer un Programme sur l'ihm
		public function SupprimerProgramme()
		{
			throw new Exception("erreur lors de la suppression du programme", 7);
			
			try
			{
				
			}
			catch (Exception $e)
			{
			
			}
		}
// fonction qui permet de lancer un Programme a partir de l'ihm		
		public function RunProgramme()
		{
			throw new Exception("erreur lors du lancement du programme", 2);
			
			try
			{
				
			}
			catch (Exception $e)
			{
			
			}
			
		}


	}

?>