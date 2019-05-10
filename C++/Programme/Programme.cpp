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
	programme::programme(int id, std::string name,std::vector<scene*>scene)
	{
	   this->id=id;
	   this->name=name;
	   this->scn=scene;
	}
		programme::programme()
	{
	   this->id=0;
	   this->name="";

	}
//setId
	void programme::setId(int id)
	{
		this->id=id;
	}
//initialisation du nom d'un progamme
	void programme::setName(std::string name)
	{
		this->name=name;
	}
// (à voir)		void setOrder(int Order);


//réupération de l'ID du programme
	int programme::getId()
	{
		return id;
	}
//récupération du nom du programme
	std::string programme::getName()
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
	std::vector<scene*> programme::getScenes()
	{
		return scn;
	}

	void programme::AjouterUneSceneAuProgramme(scene * s1)
	{
		scn.push_back(s1)  ;
	}

	void programme::setNbScene(int nbScene)
	{
        this->nbScene=nbScene;
	}

