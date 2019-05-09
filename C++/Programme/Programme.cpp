//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Programme.h-------------------------------------------------------//
//---Cette classe permet d'initialiser un programme avec les sc�nes affect�es-//
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
// (� voir)		void setOrder(int Order);


//r�up�ration de l'ID du programme
	int programme::getId()
	{
		return id;
	}
//r�cup�ration du nom du programme
	std::string programme::getName()
	{
		return name;
	}
//r�cup�ration du nombre de scenes
	int programme::getNbScene()
	{
		return nbScene;
	}
//(� voir)	int getOrder();
//r�cup�ration des sc�nes d'un programme et leurs s�quences
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

