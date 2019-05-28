//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Scene.h-----------------------------------------------------------//
//---Cette classe permet de répertorier une scène qui possède plusieurs séquences---//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "./Scene/Scene.h"
#include <Windows.h>
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur
	scene::scene(int id, std::string name, int tpsPause)
	{
		this->id=id;
		this->name=name;
		this->tpsPause=tpsPause;
	}

	scene::scene()
	{
	this->id=0;
	this->name="\0";
	this->tpsPause=0;
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
//initialisation du nombre de séquences d'une scène
	void scene::setNbSeq(int NbSeq)
	{
		this->NbSeq=NbSeq;
	}
//récupération de l'id scene
	int scene::getId()
	{
		return id;
	}
//récupération du Nom de la scène
	std::string scene::getName()
	{
		return name;
	}
//récupération du temps entre chaque scène
	int scene::getTime()
	{
		return tpsPause;
	}
//récupération du nombre de séquences
	int scene::getNbSeq()
	{
		return seq.size();
	}
//initialisation des sequences des scènes
	void scene::setSequences(sequence*sequ)
	{
		this->seq.push_back(sequ);
	}
//récupération des sequences des scènes
	std::vector<sequence*> scene::getSequences()
	{
		return this->seq;
	}
//permet la planification des séquences avec leur durée
	void scene::planifyScene()
	{   int i;
		unsigned long lastProcessedTime = GetTickCount();
        times.clear();

		for (i = 0; i < seq.size(); i++)
		{
			lastProcessedTime+=seq[i]->getDuree();
			times.push_back(lastProcessedTime);
		}

		sequenceIndex = 0;
	}
//permet de lancer une scène en fonction du temps de chaque séquences
	bool scene::updateScene()
	{
		unsigned long currentTime= GetTickCount();
		if (currentTime> times[sequenceIndex])
		{
			sequenceIndex++;
		}

		if(sequenceIndex < seq.size())
		{
            // Mise à jour du trameManager avec les sequenceUsedEquipment
			sequence * s = seq[sequenceIndex];
			std::vector<usedEquipement*> usedEquips = s->getTrame()->getUsedEquipement();
			std::vector<sequenceUsedEquipement*> seqUsedEquips = s->getSequenceUsedEquipments();
			//insertion des valeurs transmises dans les sequenceUsedEquipement
			for(int i = 0; i < seqUsedEquips.size(); i++)
			{
				//on recherche les valeurs des usedEquipement parmis les sequencesUsedEquipement
				std::vector<usedEquipement*>::iterator it = std::find(usedEquips.begin(), usedEquips.end(), seqUsedEquips[i]->getUsedEquipment());
				if(it != usedEquips.end())
				{
					//valeurs des propriétés
					usedEquipement * usedEquip = (*it);
					usedEquip->getValues()[seqUsedEquips[i]->getProperty()] = seqUsedEquips[i]->getValue();
				}
            }
		}
		//retourne un boléen
		return sequenceIndex>=seq.size();
	}
//retourne le nombre de séquences
	int scene::getSeqIndex()
	{
		//retourne
		return sequenceIndex >= seq.size() ? seq.size() - 1 : sequenceIndex;
	}
