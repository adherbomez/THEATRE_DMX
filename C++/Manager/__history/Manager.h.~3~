//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Manager.h---------------------------------------------------------//
//---Cette classe permet de generer un objet de type scene ou programme en lien
//--------------avec la BDD--------------------------------------------------//
//---------------------------------------------------------------------------//


#ifndef ManagerH
#define ManagerH
#include"Programme.h"
#include"Scene.h"
//---------------------------------------------------------------------------

class Manager
{
	private:
		programme*prog;
		scene*scn;

	public:
		manager();
		Programme*getProg(idProg);
		Scene*getScn(idScn);
		scn*UpdateScene(scene*scn);
		prog*UpdateProg(programme*prog);
		char*sendOk();
		char*sendError();


};

#endif

