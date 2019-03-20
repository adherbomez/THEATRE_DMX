//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Scene.h-----------------------------------------------------------//
//---Cette classe permet de répertorier une scène qui possède plusieurs séquences---//
//---------------------------------------------------------------------------//

#ifndef SceneH
#define SceneH
#include <map>
#include "Sequence.h"
#include "String.h"
//---------------------------------------------------------------------------

class scene
{
	private:
		int id;
		char*name;
		int tpsPause;
		std::map<std::string,sequence*> seq;


	public:
		scene(int id, char*name, int tpsPause, std::map<std::string,sequence*>seq);

		void setId(int id);
		void setName(char*name);
		void setTime(int tpsPause);  //temps entre chaque scenes
		void setNbSeq(std::map<int,sequence*>); //récupère la size du vecteur
		void setSequences(std::map<std::string,sequence*>seq); //récupère les séquences de la scène

		//récupération des attributs
		int getId();
		char* getName();
		int getTime();
		int getNbSeq();
		std::map<std::string,sequence*> getSequences();

};

#endif

