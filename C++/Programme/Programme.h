//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Programme.h-------------------------------------------------------//
//---Cette classe permet d'initialiser un programme avec les scènes affectées-//
//---------------------------------------------------------------------------//

#ifndef ProgrammeH
#define ProgrammeH
#include <map>
#include "Scene.h"
#include "String.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
//---------------------------------------------------------------------------

class programme
{
	private:
		int id;
		char*name;

		std::vector<scene*>scn; //scenes avec leurs séquences (encapsulation)

	public:
		programme(int id, char*name,std::vector<scene*>scene);

		void setId(int id);
		void setName(char*name);
// (à voir)		void setOrder(int Order);
		void setNbScene(); //récupère la size du vecteur scene

		//récupération des attributs
		int getId();
		char* getName();
		int getNbScene();
//(à voir)	int getOrder();
		std::vector<scene*>getScenes();
};

#endif

