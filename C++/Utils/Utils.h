//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Utils.h-----------------------------------------------------------//
//---Cette classe permet de mettre à disposition via des methodes static-----//
//---des outils qui simplifient l'utilisation et la réutilisation du code----//

#ifndef UtilsH
#define UtilsH

#include <string>
#include <vector>
#include <vcl.h>

	class Utils
	{
		public:
			static bool startsWith(std::string mainStr, std::string toMatch);
			static const std::vector<std::string> explode(const std::string& s, const char& c);

	};

//---------------------------------------------------------------------------
#endif
