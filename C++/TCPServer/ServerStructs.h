//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:ServerStructs.h---------------------------------------------------//
//---Ici, on définit les structures qui permettent de stocker les informations//
//---d'un client à savoir son objet TCPServer, son socket et son client.-----//
//---On stock aussi le message du client et ses informations dans ClientMessage//
//---------------------------------------------------------------------------//

#ifndef SERVERSTRUCTS_H
#define SERVERSTRUCTS_H

class TCPServer;

#include <windows.h>
#include <string>

//structure sur l'information de l'etat d'un client
typedef struct etatClient
{
	bool connect;

}etatClient;
//structure sur un client et ses informations
 typedef struct clientInfo
	{
		TCPServer*server;
		SOCKET sock;
		etatClient clEtat;

	}clientInfo;
//structure sur les informations d'un client et le message qu'il envoie
 typedef struct clientMessage
 {
	clientInfo clInfo;
	std::string message;

 } clientMessage;

 #endif