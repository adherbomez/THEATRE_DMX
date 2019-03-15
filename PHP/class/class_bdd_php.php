<?php

/*----------------------------------------------------------------/
PROJET THEATRE DMX512
DEVELOPPÉ PAR : MAXIME LEPELLETIER 
BTS SN2

		- classe BDD de l'ihm php - 

cette classe permet de se connecter / interagir / se deconnecter de la base de donnée de l'application
pour pouvoir ajouter et supprimer des scenes ou des programmes , sans avoir a passer par le c++ et le protocole tcp-ip

/----------------------------------------------------------------*/

Class BDD{

		private $bdd ;						// variable qui contiendra la connexion a la bdd
		private $req;						//fonction qui permet de se connecter a la base de donnée de l'application.

//permet d'établir un deconnexion entre l'ihm et la base de donnée
public function connexion()
{
	try 
	{
		$bdd = new PDO('mysql:host=localhost;dbname=test', $user, $pass);
	} 
	catch (PDOException $e) 
	{
   		print "Erreur !: " . $e->getMessage() . "<br/>";
  		die();
	}
}

//permet la deconnexion de la base de donnee
public function deconnexion()
{
	$bdd = NULL;
}



		
}