//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:SequenceUsedEquipement.h------------------------------------------//
//---Cette classe permet de donn�e une valeur � une s�quence pr�d�finie par un
//---�quipement et un usedEquipement-----------------------------------------//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "SequenceUsedEquipement.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur de la classe, r�cup�re les valeurs
	sequenceUsedEquipement::sequenceUsedEquipement(usedEquipement * usedEquip, property * prop, int value)
	{
		this->usedEquip = usedEquip;
		this->prop = prop;
		this->value = value;
	}
//param�tre l'instance d'un usedEquipement
	void sequenceUsedEquipement::setUsedEquipment(usedEquipement * usedEquip)
	{
		this->usedEquip = usedEquip;
	}
//param�tre l'instance d'un Property
	void sequenceUsedEquipement::setProperty(property * prop)
	{
		this->prop = prop;
	}
//param�tre la value d'une propri�t�
	void sequenceUsedEquipement::setValue(int value)
	{
		this->value = value;
	}
//r�cup�re la value
	int sequenceUsedEquipement::getValue()
	{
		return value;
	}
//r�cup�re l'instance d'un UsedEquipement
	usedEquipement * sequenceUsedEquipement::getUsedEquipment()
	{
		return usedEquip;
	}
//r�cup�re l'instance d'une Propri�t�
	property * sequenceUsedEquipement::getProperty()
	{
		return prop;
	}
