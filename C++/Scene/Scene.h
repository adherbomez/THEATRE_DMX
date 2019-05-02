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
		std::vector<unsigned long> times;
		int sequenceIndex;


	public:
		scene(int id, std::string name, int tpsPause);

		void setId(int id);
		void setName(std::string name);
		void setTime(int tpsPause);  //temps entre chaque scenes
		void setNbSeq(std::vector<sequence*>); //récupère la size du vecteur
		void setSequences(sequence*sequ); //récupère les séquences de la scène
		void planifyScene(); //calcul les temps de changement de sequences
		bool updateScene(); //renvoi true la scene est terminée
		int getSeqIndex();

		//récupération des attributs
		int getId();
		std::string getName();
		int getTime();
		int getNbSeq();
		std::vector<sequence*> getSequences();

};

#endif

