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
#include "Scene.h"
#include "String.h"
//---------------------------------------------------------------------------

class programme
{
	private:
		int id;
		char*name;
		int nbScene;
		std::map<std::string,scene*>scenes; //scenes avec leurs s�quences (encapsulation)

	public:
		programme(int id, char*name,std::map<std::string,scene*>scn);

		void setId(int id);
		void setName(char*name);
// (� voir)		void setOrder(int Order);
		void setNbScene(std::map<std::string,scene*>scn); //r�cup�re la size du vecteur scene

		//r�cup�ration des attributs
		int getId();
		char* getName();
		int getNbScene();
//(� voir)	int getOrder();
		std::map<std::string,scene*> getScenes();
};

#endif

