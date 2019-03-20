//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Property.h--------------------------------------------------------//
//---Cette classe permet d'identifier les propriétés d'un équipement comme une lumière---//
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
//définie l'ordre de la propriété
	int property::setOrder(int order)
	{
		this->order=order;
	}
//id de la propriété
	int property::setId(int id)
	{
		this->id=id;
	}
//affectation d'une description renseignant la fonction de la propriété
	char* property::setDescription(char*description)
	{
		this->description=description;
	}
//retourne l'ordre de la propriété
	int property::getOrder()
	{
		return order;
	}
//retourne l'id de la propriété
	int property::getId()
	{
		return id;
	}
//retourne la description de la propriété
	char* property::getDescription()
	{
		return description;
	}
