//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:UsedEquipement.h--------------------------------------------------//
//---Cette classe permet de recuperer les informations de la classe equipement
//et d'initialiser le canal et les valeurs des propriétés---//
//---------------------------------------------------------------------------//
#ifndef UsedEquipementH
#define UsedEquipementH
#include <iostream>
#include <vector>
#include "Equipement.h"
#include "Property.h"
#include <map>
//---------------------------------------------------------------------------

class usedEquipement
{
	private:
		int canal;
		equipement*equip;
		std::map<property*,int>values;


	public:
		usedEquipement();

		void setCanal(int canal);
		std::map<property*,int> setValues(std::map<property*,int>values);

		int getCanal();
		std::map<property*,int> getValues();
};

#endif

