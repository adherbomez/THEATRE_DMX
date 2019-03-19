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
//---------------------------------------------------------------------------

class scene
{
	private:
		int id;
		char*nom;
		int tpsPause;
		std::map<int,sequence*> seq;


	public:
		scene();

		void setId(int id);
		void setName(int name);
		void setTime(int tpsPause);  //temps entre chaque scenes
		void setNbSeq(std::map<int,sequence*>); //récupère la size du vecteur
		void setSequences(std::map<string,sequence*>); //récupère les séquences de la scène

		//récupération des attributs
		int getId();
		int getName();
		int getTime();
		int getNbSeq();
		std::map<string,sequence*> getSequences();

};

#endif

