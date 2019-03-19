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
	equipement::equipement(int id, char* name)
	{
		this->id=id;
		this->name=name;
	}
	//Id de l'équipement
	void equipement::setId(int id)
	{
		this->id=id;
	}
	//retourne l'id
	int equipement::getId()
	{
		return id;
	}
	//vérifie l'ordre des propriétés grâce à l'attribut order de Property
	bool equipement::verifOrder(property*prop)
	{
		return true;
	}
	//recupère le nombre de voies d'un équipement (ses propriétés)
	int equipement::getNbVoies()
	{
		return 5;
	}
	//permet de récuperer les propriétés
	std::map<std::string,property*> equipement::getProperties()
	{
		return properties;
	}
	//initialise le nom de l'equipement
	void equipement::setName(char*name)
	{
		this->name=name;
	}
	//retourne le nom de l'equipement
	char* equipement::getName()
	{
		return name;
	}
