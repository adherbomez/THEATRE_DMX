//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:UsedEquipement.h--------------------------------------------------//
//---Cette classe permet de recuperer les informations de la classe equipement
//et d'initialiser le canal et les valeurs des propri�t�s---//
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
		int adresse;
		std::map<property*,int> values;
		equipement*equip;

	public:
		usedEquipement(int canal, equipement * equip);

		void setAdresse(int adresse);
		std::map<property*,int> setValues(std::map<property*,int>values); //valeurs des propri�t�s d'un equipement
		int getAdresse();     //1ere position dans la trame d'une s�quence
		int getNbVoies();
		std::map<property*,int> & getValues();

		std::vector<property*> getOrderedProperties();
};

#endif

