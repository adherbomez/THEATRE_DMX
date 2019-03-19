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
//---------------------------------------------------------------------------

class programme
{
	private:
		int id;
		char*name;
		int nbScene;
		std::map<std::string,scene*>scenes; //scenes avec leurs séquences (encapsulation)

	public:
		programme(int id, char*name,std::map<std::string,scene*>scn);

		void setId(int id);
		void setName(char*name);
// (à voir)		void setOrder(int Order);
		void setNbScene(std::map<std::string,scene*>scn); //récupère la size du vecteur scene

		//récupération des attributs
		int getId();
		char* getName();
		int getNbScene();
//(à voir)	int getOrder();
		std::map<std::string,scene*> getScenes();
};

#endif

