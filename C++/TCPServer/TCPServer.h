//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:TCPServer.h-------------------------------------------------------//
//---Cette classe permet de gerer la réception des données envoyé par le-----//
//---TCPclient et de découpé la trame pour identifier si c'est un programme--//
//-----ou une scene----------------------------------------------------------//
//---------------------------------------------------------------------------//


#ifndef TCPServerH
#define TCPServerH
#include "Programme.h"
#include "SharedData.h"
#include <iostream>
#include <WS2tcpip.h>
#include<String.h>
#include <string>
#include "ServerStructs.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;
//---------------------------------------------------------------------------
class TCPServer
{
	private:

		WSADATA wsData;
		SOCKET listening;
		SOCKET clientSocket;
		sockaddr_in client;


	public:

		TCPServer();
	//variable pour le partage de la structure clientMessage
		SharedData<clientMessage> * shData;
		void bindSocket(unsigned short port);
	//methodes static pour la réutilisation
		static DWORD WINAPI connexion(LPVOID params);
		static DWORD WINAPI received(LPVOID params);

};
//---------------------------------------------------------------------------
#endif
