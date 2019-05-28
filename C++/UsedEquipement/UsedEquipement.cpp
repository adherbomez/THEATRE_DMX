//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:UsedEquipement.h--------------------------------------------------//
//---Cette classe permet de recuperer les informations de la classe equipement
//et d'initialiser le canal.---//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "UsedEquipement.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur
	usedEquipement::usedEquipement(int canal, equipement * equip)
	{
		this->adresse=canal;

        std::vector<property*> properties = equip->getOrderedProperties();

		for(int i = 0; i < properties.size(); i++)
			this->values[properties[i]] = 0;

		this->equip = equip;
	}
//initialisation du canal qui est la première adresse de la trame
	void usedEquipement::setAdresse(int adresse)
	{
		this->adresse=adresse;
	}
//valeur de chaque propriétés
	std::map<property*,int> usedEquipement::setValues(std::map<property*,int>values)
	{
		this->values=values;
	}
//retourne le canal
	int usedEquipement::getAdresse()
	{
		return adresse;
	}
//retourne les valeurs
	std::map<property*,int> &
	usedEquipement::getValues()
	{
		return values;
	}
//retourne le nombre de voies
	int usedEquipement::getNbVoies()
	{
        return equip->getNbVoies();
	}
//retourne les propriétés dans l'ordre
	std::vector<property*> usedEquipement::getOrderedProperties()
	{
		return equip->getOrderedProperties();
	}

