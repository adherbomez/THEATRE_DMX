//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Scene.h-----------------------------------------------------------//
//---Cette classe permet de r�pertorier une sc�ne qui poss�de plusieurs s�quences---//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "Scene.h"
#include <Windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur
	scene::scene(int id, std::string name, int tpsPause)
	{
		this->id=id;
		this->name=name;
		this->tpsPause=tpsPause;
	}
//setID
	void scene::setId(int id)
	{
		this->id=id;
	}
//initialisation du nom
	void scene::setName(std::string name)
	{
		this->name=name;
	}
//initialisation du temps de pause
	void scene::setTime(int tpsPause)
	{
		this->tpsPause=tpsPause;
	}
//initialisation du nombre de s�quences d'une sc�ne
	void scene::setNbSeq(std::vector<sequence*>seq)
	{
		this->seq=seq;
	}
//r�cup�ration de l'id scene
	int scene::getId()
	{
		return id;
	}
//r�cup�ration du Nom de la sc�ne
	std::string scene::getName()
	{
		return name;
	}
//r�cup�ration du temps entre chaque sc�ne
	int scene::getTime()
	{
		return tpsPause;
	}
//r�cup�ration du nombre de s�quences
	int scene::getNbSeq()
	{
		return seq.size();
	}
//initialisation des sequences des sc�nes
	void scene::setSequences(sequence*sequ)
	{
		this->seq.push_back(sequ);
	}
//r�cup�ration des sequences des sc�nes
	std::vector<sequence*> scene::getSequences()
	{
		return this->seq;
	}

	void scene::planifyScene()
	{   int i;
		unsigned long lastProcessedTime = GetTickCount();
		for (i = 0; i < seq.size(); i++)
		{
			lastProcessedTime+=seq[i]->getDuree();
			times.push_back(lastProcessedTime);
		}

		sequenceIndex = 0;
	}
	bool scene::updateScene()
	{
		unsigned long currentTime= GetTickCount();
		if (currentTime> times[sequenceIndex])
		{
			sequenceIndex++;
		}
		return sequenceIndex==seq.size();
	}

	int scene::getSeqIndex()
	{
		return sequenceIndex;
	}
