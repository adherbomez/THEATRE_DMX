//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:TrameManager.h--------------------------------------------------------//
//---Cette classe permet la construction de la trame DMX en récupérant le canal,
//les équipements et leurs propriétés---//
//---------------------------------------------------------------------------//

#ifndef PropertyH
#define PropertyH
//---------------------------------------------------------------------------

class trameManager
{
	public:
		typedef std::vector<UsedEquipement*> trame;
		char* dmx[512];

	private:
		trameManager();

		bool insertEquipement(Equipement*,int canal);
		void removeEquipement(int canal);
		bool checkConflict();

		char*getTrame();
		std::vector<UsedEquipement*> getUsedEquipement();

};

#endif

