//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Sequence.h--------------------------------------------------------//
//---Cette classe permet de définir une séquence avec une durée et la trame--//
//qui lui sera affectée------------------------------------------------------//
//---------------------------------------------------------------------------//


#pragma hdrstop

#include "Sequence.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//récupére la trame
	sequence::sequence(int id, int duree, trameManager*trame)
	{
		this->id=id;
		this->duree=duree;
		this->trame=trame;
	}
//initialise la durée de la séquence
	void sequence::setDuree(int duree)
	{
		this->duree=duree;
	}
//setId
	void sequence::setId(int id)
	{
		this->id=id;
	}
//recupère la durée de la sequence
	int sequence::getDuree()
	{
		return duree;
	}
//récupère l'id de séquence
	int sequence::getId()
	{
		return id;
	}



