//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Equipement.h------------------------------------------------------//
//---Cette classe permet d'instancier des equipements comme des lumières-----//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "Equipement.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	//constructeur
	equipement::equipement()
	{

	}
	//setId
	void equipement::setId(int id)
	{

	}
	//retourne l'id
	int equipement::getId()
	{

	}
	//vérifie l'ordre des propriétés grâce à l'attribut order de Property
	bool equipement::verifOrder(property*prop)
	{

	}
	//recupère le nombre de voies d'un équipement (ses propriétés)
	int equipement::getNbVoies()
	{


	}
	//permet de récuperer les propriétés
	std::map<string,property*> getProperties()
	{

	}
	//initialise le nom de l'equipement
	void equipement::setName(char*name)
	{

	}
	//retourne le nom de l'equipement
	char* equipement::getName()
	{

	}
