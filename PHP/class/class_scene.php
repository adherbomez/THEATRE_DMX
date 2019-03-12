<?php

/*----------------------------------------------------------------/
PROJET THEATRE DMX512
DEVELOPPÉ PAR : MAXIME LEPELLETIER 
BTS SN2

		- classe scene de l'ihm php - 

cette classe permet de parametrer les scene de lumiere.
ces derniers composent les programmes (objet du fichier class_programme.php)
/----------------------------------------------------------------*/

Class Scene 
{
	private $_Duree;			//durée de l'inter scene
	private $_Id;				//n° ID de la scene
	private $_Nom;				//nom de la scene ex:"scene bleue"
	private $_Attribute;		//attribut de la scene
	
	//Constructeur avec parametres
	public function __construct($_Id,$_Nom,$_Attribute,$_Duree,)
	{
		$this->_id=$_Id;
		$this->_Nom=$_Nom;
		$this->_Attribute=$_Attribute;
		$this->_Duree=$_Duree;
	}

	//Fonction qui vas retrouner la durée
	public function GetDuree()
	{
		return  $_Duree;	
	}
	//Fonction qui permet de parametrer la durée
	public function SetDuree($_Duree)
	{
		$this->_Duree=$_Duree;	
	}

	//Fonction qui vas retourner l'id de la scene
	public function GetId()
	{
		return $_Id;		
	}

	//Fonction qui vas retourner l'id de la scene
	public function SetId($_Id)
	{
		$this->_Id=$_Id;
	}

	//Fonction qui vas retourner le nom de la scene
	public function GetNom()
	{
		return $_Nom;
	}

	//Fonction qui vas permettre de parametrer le nom de la scene
	public function SetNom($_Nom)
	{
		$this->_Nom=$_Nom;
	}
	//Fonction qui vas retourner l'id de la scene
	public function GetAttribute()
	{
		return $_Attribute;
	}

	//Fonction qui vas retourner l'id de la scene
	public function SetAttribute($_Attribute)
	{
		$this->_Attribute=$_Attribute;
	}

?>