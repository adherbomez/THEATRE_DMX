//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Sequence.h--------------------------------------------------------//
//---Cette classe permet de d�finir une s�quence avec une dur�e et la trame--//
//qui lui sera affect�e------------------------------------------------------//
//---------------------------------------------------------------------------//


#pragma hdrstop

#include "Sequence.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//r�cup�re la trame
	sequence::sequence(int id, int duree, trameManager*trame)
	{
		this->id=id;
		this->duree=duree;
		this->trame=trame;
	}
//initialise la dur�e de la s�quence
	void sequence::setDuree(int duree)
	{
		this->duree=duree;
	}
//setId
	void sequence::setId(int id)
	{
		this->id=id;
	}
//recup�re la dur�e de la sequence
	int sequence::getDuree()
	{
		return duree;
	}
//r�cup�re l'id de s�quence
	int sequence::getId()
	{
		return id;
	}



