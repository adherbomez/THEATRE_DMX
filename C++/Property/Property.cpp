//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Property.h--------------------------------------------------------//
//---Cette classe permet d'identifier les propri�t�s d'un �quipement comme une lumi�re---//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "Property.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur
	property::property(int id ,int order, char*description)
	{
		this->id=id;
		this->order=order;
		this->description=description;
	}
//d�finie l'ordre de la propri�t�
	int property::setOrder(int order)
	{
		this->order=order;
	}
//id de la propri�t�
	int property::setId(int id)
	{
		this->id=id;
	}
//affectation d'une description renseignant la fonction de la propri�t�
	char* property::setDescription(char*description)
	{
		this->description=description;
	}
//retourne l'ordre de la propri�t�
	int property::getOrder()
	{
		return order;
	}
//retourne l'id de la propri�t�
	int property::getId()
	{
		return id;
	}
//retourne la description de la propri�t�
	char* property::getDescription()
	{
		return description;
	}
