//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Manager.h---------------------------------------------------------//
//---Cette classe permet de generer un objet de type scene ou programme en lien
//--------------avec la BDD--------------------------------------------------//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "Manager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur
	manager::manager()
	{

	}
//permet de récupérer un programme dans la bdd grace à son id
	programme*manager::getProg(idProg)
	{
		programme *P1 ;

		// On va rechercher en base les informations du programme
		// select Nom from Programme
		char* Nom = "lacDesSignes";

		P1->setId(idProg);
		P1->setName()

		return P1;
	}
//permet de récupérer une scène dans la bdd grace à son id
	scene*manager::getScn(idScn)
	{

	}
//permet de vérifier et de remplacer les bons éléments d'une scene dans la bdd
	scene*manager::updateScene(scene*scn)
	{

	}
//permet de vérifier et de remplacer les bons éléments d'un programme dans la bdd
	programme*manager::updateProg(programme*prog)
	{

	}
//permet de renvoyer un message d'envoi réussi
	char*manager::sendOk()
	{

	}
//permet de renvoyer un message d'erreur
	char*manager::sendError()
	{

	}

