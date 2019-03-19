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
		std::map<property*,int> setValues(std::map<property*,int>values); //valeurs des propriétés d'un equipement
		int getCanal();     //1ere position dans la trame d'une séquence
		std::map<property*,int> getValues();
};

#endif

