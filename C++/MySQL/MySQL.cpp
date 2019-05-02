//---------------------------------------------------------------------------

#pragma hdrstop

#include "MySQL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MySQL::MySQL()
{
//	  mysql_init(SQL);       //initialise la connexion
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

void MySQL::Disconnect()
{
	mysql_close(SQL);
}




bool MySQL::Insert(string request)
{
	if(mysql_query(SQL,request.c_str())==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MySQL::Delete(string request)
{
	if(mysql_query(SQL,request.c_str())==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
