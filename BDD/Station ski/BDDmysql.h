/***************************************************************************************/
/*Développé par Dherbomez Arthur, Hugo Louvel et Adrien Mercier en classe de BTSSN1 ***/
/*le 18/05/2018																	  ****/
/*																				 ****/
/*Langage C++ : Projet Station de Ski  								   			****/
/* 																			   ****/
/*********************************************************************************/

#ifndef SQLH
#define SQLH
#include <vcl.h>
#define __WIN__
#include "include/mysql.h"

class MySQL
{
  private :
		bool Etat;
		MYSQL*SQL;   //objet de la classe

  public :
		MySQL();
		//~MySQL();
		bool connexion(char*adre,char*id,char*mdp,char*table);  //etabli la connexion à la BDD
		bool deconnexion();   //se deconnecte de la BDD
		bool getEtat();       //retourne l'etat de la BDD
		//TStringList Lecture(String req);
		bool Enregistrer(float temp);   //enregistre les température dans la BDD



};


//---------------------------------------------------------------------------
#endif

