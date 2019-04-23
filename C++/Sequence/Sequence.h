//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Sequence.h--------------------------------------------------------//
//---Cette classe permet de définir une séquence avec une durée et la trame--//
//qui lui sera affectée------------------------------------------------------//
//---------------------------------------------------------------------------//

#ifndef SequenceH
#define SequenceH
#include "TrameManager.h"
//---------------------------------------------------------------------------

class sequence
{
	private:
		int id;
		int duree;
		trameManager* trame;
		int nbSeqUsedEq;

	public:
		sequence(int id, int duree, trameManager*);

		void setDuree(int value);
		void setId(int id);
		trameManager*setTrame();

		int getDuree();
		int getId();
		trameManager*getTrame();
};

#endif

