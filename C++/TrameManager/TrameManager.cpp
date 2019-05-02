//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:TrameManager.h--------------------------------------------------------//
//---Cette classe permet la construction de la trame DMX en r�cup�rant le canal,
//les �quipements et leurs propri�t�s---//
//---------------------------------------------------------------------------//
#pragma hdrstop

#include "TrameManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur
	trameManager::trameManager()
	{

	}
//insere dans dmx[512] l'equipement �  l'adresse choisi
	bool trameManager::insertEquipement(equipement*equip,int adresse)
	{
//		int i,j;
//
//		adresse-=1;
//
//		for (i = 0; i < 512; i++)
//		{
//			while(dmx[i]==dmx[adresse])
//			{
//				for (j = adresse; j < adresse+equip->getNbVoies(); j++)
//				{
//					for (std::map<>,allocator<pair<>)
//					{
//						dmx[j]=trame->getValues[j];
//					}
//
//				}
//
//			}
//
//		}
	}
//suppression d'un �quipement au canal choisis
	void trameManager::removeEquipement(int adresse)
	{

	}
//verifie si des trames ne se superposes pas et si il n'y a pas d'erreurs
	bool trameManager::checkConflict()
	{
	   return true;
	}
//r�cup�re la trame
	char* trameManager::getTrame()
	{
		return dmx;
	}
//renvoi un vecteur avec toutes les informations utilent � la trame
	std::vector<usedEquipement*> trameManager::getUsedEquipement()
	{
		return trame;
	}
