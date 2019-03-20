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
		void setNbSeq(std::vector<sequence*>); //r�cup�re la size du vecteur
		void setSequences(std::vector<sequence*>); //r�cup�re les s�quences de la sc�ne

		//r�cup�ration des attributs
		int getId();
		std::string getName();
		int getTime();
		int getNbSeq();
		std::vector<sequence*> getSequences();

};

#endif

