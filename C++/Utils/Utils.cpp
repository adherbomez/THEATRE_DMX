//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Utils.h-----------------------------------------------------------//
//---Cette classe permet de mettre à disposition via des methodes static-----//
//---des outils qui simplifient l'utilisation et la réutilisation du code----//

#pragma hdrstop

#include "Utils.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//cette methode permet de comparer si le mainStr contient toMatch et retourne en conséquence
	bool Utils::startsWith(std::string mainStr, std::string toMatch)
	{
		// std::string::find retourne 0 si toMatch est trouvé au début du message
		if(mainStr.find(toMatch) == 0)
			return true;
		else
			return false;
	}
//cette methode permet de découper une trame
	const std::vector<std::string> Utils::explode(const std::string& msg, const char& c)
	{
	std::string buff = "";
	std::vector<std::string> v;
		for(int i = 0; i < msg.length(); i++)
		{
		char compare = msg[i];
			if(compare != c) buff+=compare;
			else if(compare == c && buff != "")
			{
				v.push_back(buff);
				buff = "";
			}
		}
			if(buff != "")
			v.push_back(buff);

			return v;
	}

