//---------------------------------------------------------------------------

#ifndef BDDH
#define BDDH
//---------------------------------------------------------------------------

#include <vcl.h>
#define __WIN__
#include "include/mysql.h"
#include <vector>
#include <string>


using namespace std;

class BDD
{
	public :

		virtual Connect(char*Addr,char*Id,char*Mdp,char*Table)=0;
		virtual Disconnect()=0;

		virtual bool Insert(string request)=0;
		virtual bool Update(string request)=0;
		virtual bool Delete(string request)=0;
		virtual bool Select(string request)=0;
};

#endif
