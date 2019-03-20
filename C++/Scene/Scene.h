//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Scene.h-----------------------------------------------------------//
//---Cette classe permet de répertorier une scène qui possède plusieurs séquences---//
//---------------------------------------------------------------------------//

#ifndef SceneH
#define SceneH
#include <vector>
#include "Sequence.h"
#include "String.h"
//---------------------------------------------------------------------------

class scene
{
	private:
		int id;
		std::string name;
		int tpsPause;
		std::vector<sequence*> seq;


	public:
		scene(int id, std::string name, int tpsPause, std::vector<sequence*>seq);

		void setId(int id);
		void setName(std::string name);
		void setTime(int tpsPause);  //temps entre chaque scenes
		void setNbSeq(std::vector<sequence*>); //récupère la size du vecteur
		void setSequences(std::vector<sequence*>); //récupère les séquences de la scène

		//récupération des attributs
		int getId();
		std::string getName();
		int getTime();
		int getNbSeq();
		std::vector<sequence*> getSequences();

};

#endif

