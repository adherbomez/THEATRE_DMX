//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Equipement.h------------------------------------------------------//
//---Cette classe permet d'instancier des equipements comme des lumi�res-----//
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
	//Id de l'�quipement
	void equipement::setId(int id)
	{
		this->id=id;
	}
	//retourne l'id
	int equipement::getId()
	{
		return id;
	}
	//v�rifie l'ordre des propri�t�s gr�ce � l'attribut order de Property
	bool equipement::verifOrder(property*prop)
	{
		return true;
	}
	//recup�re le nombre de voies d'un �quipement (ses propri�t�s)
	int equipement::getNbVoies()
	{
		return properties.size();
	}
	//permet de r�cuperer les propri�t�s
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
//	//ajoute une propri�t� � un �quipement
//	void equipement::addProperty(std::string name, property * prop)
//	{
//		properties[name] = prop;
//	}
//	//retourne les propri�t�s ordonn�es
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
