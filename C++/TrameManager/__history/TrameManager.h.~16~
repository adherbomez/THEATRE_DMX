//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:TrameManager.h--------------------------------------------------------//
//---Cette classe permet la construction de la trame DMX en récupérant le canal,
//les équipements et leurs propriétés---//
//---------------------------------------------------------------------------//

#ifndef TrameManagerH
#define TrameManagerH
#include <stdlib.h>
#include <map>
#include <vector>
#include "UsedEquipement.h"
#include "Equipement.h"
#include "string.h"
#include "Graph.h"
//---------------------------------------------------------------------------

class trameManager
{
	private:
		std::vector<usedEquipement*> trame;
		char * dmx;
	public:
		Graph*graph;


		trameManager();

		bool insertEquipement(usedEquipement*usedEquip);
		void removeEquipement(usedEquipement*usedEquip);
		bool checkConflict();

		char*getTrame();
		std::vector<usedEquipement*> getUsedEquipement();

};

#endif

