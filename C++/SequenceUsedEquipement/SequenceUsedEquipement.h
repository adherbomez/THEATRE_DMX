//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:SequenceUsedEquipement.h------------------------------------------//
//---Cette classe permet de donn�e une valeur � une s�quence pr�d�finie par un
//---�quipement et un usedEquipement-----------------------------------------//
//---------------------------------------------------------------------------//

#ifndef SequenceUsedEquipementH
#define SequenceUsedEquipementH
//---------------------------------------------------------------------------

class usedEquipement;
class property;

class sequenceUsedEquipement
{
	private:
		usedEquipement * usedEquip;
		property * prop;
		int value;

	public:
		sequenceUsedEquipement(usedEquipement * usedEquip, property * prop, int value);
		void setUsedEquipment(usedEquipement * usedEquip);
		void setProperty(property * prop);
		void setValue(int value);
		int getValue();
		usedEquipement * getUsedEquipment();
		property * getProperty();

};

#endif

