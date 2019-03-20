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
#include "UsedEquipement.h"
#include "Equipement.h"
#include "string.h"
//---------------------------------------------------------------------------

class trameManager
{
	private:
		std::map<std::string,usedEquipement*> trame;
		char* dmx[512];

	public:
		trameManager();

		bool insertEquipement(equipement*,int canal);
		void removeEquipement(int canal);
		bool checkConflict();

		char*getTrame();
		std::vector<usedEquipement*> getUsedEquipement();

};

#endif

