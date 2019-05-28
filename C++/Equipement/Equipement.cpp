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
		return properties.size();
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
//	//ajoute une propriété à un équipement
//	void equipement::addProperty(std::string name, property * prop)
//	{
//		properties[name] = prop;
//	}
//	//retourne les propriétés ordonnées
//	std::vector<property*> equipement::getOrderedProperties()
//	{
//		std::vector<property*> nonOrderedProperties;
//
//		for(std::map<std::string,property*>::iterator it = properties.begin(); it != properties.end(); it++)
//		{
//			nonOrderedProperties.push_back((*it).second);
//		}
//
//		std::vector<property*> orderedProperties;
//
//		while(nonOrderedProperties.size() > 0)
//		{
//			int minIdx = 0;
//			for(int i = 1; i < nonOrderedProperties.size(); i++)
//			{
//				if(nonOrderedProperties[i]->getOrder() < nonOrderedProperties[minIdx]->getOrder())
//				{
//					minIdx = i;
//				}
//			}
//
//			orderedProperties.push_back(nonOrderedProperties[minIdx]);
//			nonOrderedProperties.erase(nonOrderedProperties.begin() + minIdx);
//		}
//
//		return orderedProperties;
//	}
