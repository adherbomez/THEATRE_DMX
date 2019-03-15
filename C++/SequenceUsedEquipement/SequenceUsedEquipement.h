//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:SequenceUsedEquipement.h------------------------------------------//
//---Cette classe permet de donnée une valeur à une séquence prédéfinie par un
//---équipement et un usedEquipement-----------------------------------------//
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

