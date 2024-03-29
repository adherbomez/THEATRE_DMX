//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Programme.h-------------------------------------------------------//
//---Cette classe permet d'initialiser un programme avec les sc�nes affect�es-//
//---------------------------------------------------------------------------//

#ifndef ProgrammeH
#define ProgrammeH
#include <map>
#include "./Scene/Scene.h"
#include "String.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
//---------------------------------------------------------------------------

class programme
{
	private:
		int id;
		std::string name;
		int nbScene;
		std::vector<scene*>scn; //scenes avec leurs s�quences (encapsulation)

	public:
		programme(int id, std::string name,std::vector<scene*>scene);
		programme();

		void setId(int id);
		void setName(std::string name);
		void setNbScene(int nbScene);

		//r�cup�ration des attributs
		int getId();
		std::string getName();
		int getNbScene();
		std::vector<scene*>getScenes();
		void AjouterUneSceneAuProgramme(scene * s1);




};

#endif

