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

class sequenceUsedEquipement
{
	private:
		int id;
		int value;

	public:
		sequenceUsedEquipement();

		void setSequenceValue(int value);
		void setId(int id);
		int getSequenceValue();
		int getId();
};

#endif

