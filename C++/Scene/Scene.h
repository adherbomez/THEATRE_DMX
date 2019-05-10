//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Scene.h-----------------------------------------------------------//
//---Cette classe permet de r�pertorier une sc�ne qui poss�de plusieurs s�quences---//
//---------------------------------------------------------------------------//

#ifndef SceneH
#define SceneH
#include <vector>
#include "./Sequence/Sequence.h"
#include "String.h"
//---------------------------------------------------------------------------

class scene
{
	private:
		int id;
		std::string name;
		int tpsPause;
		int NbSeq;
		std::vector<sequence*> seq;
		std::vector<unsigned long> times;
		int sequenceIndex;


	public:
		scene(int id, std::string name, int tpsPause);
		scene();

		void setId(int id);
		void setName(std::string name);
		void setTime(int tpsPause);  //temps entre chaque scenes
		void setNbSeq(int NbSeq); //r�cup�re la size du vecteur
		void setSequences(sequence*sequ); //r�cup�re les s�quences de la sc�ne
		void planifyScene(); //calcul les temps de changement de sequences
		bool updateScene(); //renvoi true la scene est termin�e
		int getSeqIndex();

		//r�cup�ration des attributs
		int getId();
		std::string getName();
		int getTime();
		int getNbSeq();
		std::vector<sequence*> getSequences();

};

#endif

