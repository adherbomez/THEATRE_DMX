<?php

/*----------------------------------------------------------------/
PROJET THEATRE DMX512
DEVELOPPÉ PAR : MAXIME LEPELLETIER 
BTS SN2

		- classe de gestion de l'ihm php - 

cette classe permet de se connecter / interagir / se deconnecter de la base de donnée de l'application
pour pouvoir ajouter et supprimer des scenes ou des programmes , sans avoir a passer par le c++ et le protocole tcp-ip

/----------------------------------------------------------------*/

Class BDD{
		
		private $_Bdd ;										// variable qui contiendra la connexion a la bdd
		private $_Req;										//fonction qui permet de se connecter a la base de donnée de l'application.

//permet d'établir un deconnexion entre l'ihm et la base de donnée
public function connexion()
{
	try 
	{
		$_Bdd = new PDO('mysql:host=localhost;dbname=test', 'root', 'root');
	} 
	catch (PDOException $e) 								//gestion de l'erreur de connexion a la base de donnée
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

// permet l'envoi d'une requete a la base de donnée 
public function envoyer($_Req)
{
	return true;
}
