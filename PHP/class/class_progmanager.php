<?php
require('class_bdd_php.php');
require('class_programme.php');
require('class_socket.php');

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
	
	$programme = new Programme();

// fonction qui permet d'ajouter un Programme sur l'ihm
		public function AjouterProg()
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

// fonction qui permet de modifier un Programme
		public function ModifierProg()
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
// fonction qui permet de supprimer un Programme sur l'ihm
		public function SupprimerProg()
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

// fonction qui permet de lancer un Programme a partir de l'ihm		
		public function RunProg()
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