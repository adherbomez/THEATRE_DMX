/***************************************************************************************/
/*Développé par Dherbomez Arthur, Hugo Louvel et Adrien Mercier en classe de BTSSN1 ***/
/*le 18/05/2018																	  ****/
/*																				 ****/
/*Langage C++ : Projet Station de Ski  								   			****/
/* 																			   ****/
/*********************************************************************************/

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------

#include <vcl.h>

class Carte
{
	public:
	   Carte(int adresse);    //initialise l'adresse
	  ~Carte();                //ferme la connexion
	  bool getEtat();               //retourne l'etat de la carte
	  int lecture_analog(int channel);       //retourne la température
	  bool connexion();                 //ouvre la connexion avec la carte


	private:

	 int adr;
	 bool etat;
       int res;

};

 #endif
