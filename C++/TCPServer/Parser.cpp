//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Parser.h----------------------------------------------------------//
//---La classe Parser va permettre de récuperer et fragmenter la donnée------//
//---du TCP client pour la traiter et définir si c'est un programme ou une---//
//---scène qui est reçu et quel est l'ip de celui-ci pour ensuite l'envoyer--//
//---au manager--------------------------------------------------------------//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "Parser.h"
#include "Utils.h"
#include <sstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//methode qui découpe la donnée reçue du TCPClient
	std::string Parser::Parse(clientMessage message)
	{   int i;
		Parser parseObj;
		Send(message.clInfo, message.message);
		std::string resultat;

		if(Utils::startsWith(message.message, "PRG"))
		{
			parseObj.parse=Utils::explode(message.message,';');
					resultat+=parseObj.parse[1];
				  return resultat;


//			 std::istringstream iss(message.message);
//			 std::string sousChaine;
//			 while (getline(iss, sousChaine))
//			 {
//				parseObj.parse.push_back(sousChaine);
//			 }
//				for (i = 0; i < parseObj.parse.size(); i++)
//				{
//
//						return parseObj.id=parseObj.parse[i+1];
//
//				}
		}

		else if(Utils::startsWith(message.message, "SCN"))
		{
//           parseObj.parse=Utils::explode(message.message,';');
//
//				  return parseObj.parse;
		}
	}
//methode qui renvoi un message de reception au client
	void Parser::Send(clientInfo cl, std::string sentence)
	{
		send(cl.sock, sentence.c_str(), sentence.length() + 1, 0);
	}
