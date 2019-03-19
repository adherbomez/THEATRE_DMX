//---------------------------------------------------------------------------

#pragma hdrstop

#include "BDD.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MySQL::MySQL()
 {
	 SQL = mysql_init(NULL);
 }

 bool MySQL::Connect(char*Addr,char*Id,char*Mdp,char*Table)
 {

	 if (!mysql_real_connect(SQL,Addr,Id,Mdp,Table, 0, NULL, 0))
	 {
	   Etat=false;
	 }
	 else
	 {
	   Etat=true;
	 }

	 return Etat;
 }

 bool MySQL::Disconnect()
 {

	mysql_close(SQL);
 }


