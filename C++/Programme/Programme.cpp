//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Programme.h-------------------------------------------------------//
//---Cette classe permet d'initialiser un programme avec les scènes affectées-//
//---------------------------------------------------------------------------//
#pragma hdrstop

#include "Programme.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur du programme
	programme::programme(int id, char*name,std::map<std::string,scene*>scn)
	{
	   this->id=id;
	   this->name=name;
	   this->scenes=scn;
	}
//setId
	void programme::setId(int id)
	{
		this->id=id;
	}
//initialisation du nom d'un progamme
	void programme::setName(char* name)
	{
		this->name=name;
	}
// (à voir)		void setOrder(int Order);
//initialisation du nombre de scenes d'un programme
	void programme::setNbScene(std::map<std::string,scene*>scn)
	{
		this->nbScene=scn.size();
	}
//réupération de l'ID du programme
	int programme::getId()
	{
		return id;
	}
//récupération du nom du programme
	char* programme::getName()
	{
		return name;
	}
//récupération du nombre de scenes
	int programme::getNbScene()
	{
		return nbScene;
	}
//(à voir)	int getOrder();
//récupération des scènes d'un programme et leurs séquences
	std::map<std::string,scene*> programme::getScenes()
	{
		return scenes;
    }

