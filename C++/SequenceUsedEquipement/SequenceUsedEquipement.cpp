//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:SequenceUsedEquipement.h------------------------------------------//
//---Cette classe permet de donnée une valeur à une séquence prédéfinie par un
//---équipement et un usedEquipement-----------------------------------------//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "SequenceUsedEquipement.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur de la classe, récupère les valeurs
	sequenceUsedEquipement::sequenceUsedEquipement(usedEquipement * usedEquip, property * prop, int value)
	{
		this->usedEquip = usedEquip;
		this->prop = prop;
		this->value = value;
	}
//paramètre l'instance d'un usedEquipement
	void sequenceUsedEquipement::setUsedEquipment(usedEquipement * usedEquip)
	{
		this->usedEquip = usedEquip;
	}
//paramètre l'instance d'un Property
	void sequenceUsedEquipement::setProperty(property * prop)
	{
		this->prop = prop;
	}
//paramètre la value d'une propriété
	void sequenceUsedEquipement::setValue(int value)
	{
		this->value = value;
	}
//récupère la value
	int sequenceUsedEquipement::getValue()
	{
		return value;
	}
//récupère l'instance d'un UsedEquipement
	usedEquipement * sequenceUsedEquipement::getUsedEquipment()
	{
		return usedEquip;
	}
//récupère l'instance d'une Propriété
	property * sequenceUsedEquipement::getProperty()
	{
		return prop;
	}
