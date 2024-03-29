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
#include"./Programme/Programme.h"
#include"./Scene/Scene.h"
#include"./BDD/BDD.h"
#include"./MySQL/MySQL.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "String.h"
#include "./property/property.h"
#include "./Equipement/Equipement.h"
#include <sstream>
#include <map>
//---------------------------------------------------------------------------
using namespace std;

class manager
{
	private:
		equipement*equip;
		programme*prog;
		scene*scn;
		MySQL* mysql;
		bool EtatConnect;

        void afficheDoubleVector(std::vector<std::vector<std::string> > vector);

	public:
		manager();
		~manager();
		programme*getProg(idProg); //compare avec l'id de la bdd
		scene*getScn(idScn);      		//compare avec l'id de la bdd

		scene*updateScene(scene*scn);      	//instancie un nouvel objet scene
		programme*updateProg(programme*prog); 	//instancie un nouvel objet programme
		char*sendOk();
		char*sendError();
		void CloseConnection();
		bool CheckEtat();
		bool Connect();


		equipement*InsertEquipment(std::string Name);
		void InsertProperties(std::string Description, std::string Order, std::string IdEquipement);
};

#endif

