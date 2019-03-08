//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:TrameManager.h--------------------------------------------------------//
//---Cette classe permet la construction de la trame DMX en r�cup�rant le canal,
//les �quipements et leurs propri�t�s---//
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

