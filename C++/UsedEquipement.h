//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:UsedEquipement.h--------------------------------------------------//
//---Cette classe permet de recuperer les informations de la classe equipement
//et d'initialiser le canal et les valeurs des propriétés---//
//---------------------------------------------------------------------------//
#ifndef PropertyH
#define PropertyH
#include <iostream>
#include <vector>
#include "Equipement.h"
//---------------------------------------------------------------------------

class usedEquipement
{
	public:
		int canal;
		Equipement equip;
		typedef std::map<Property*,int>values;


	private:
		usedEquipement();

		int setCanal(int canal);
		std::map<Property*,int> setValues(std::map<Property*,int>values);

		int getCanal();
		std::map<Property*,int> getValues();
};

#endif

