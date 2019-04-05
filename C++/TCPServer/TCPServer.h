//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:TCPServer.h-------------------------------------------------------//
//---Cette classe permet de gerer la r�ception des donn�es envoy� par le-----//
//---TCPclient et de d�coup� la trame pour identifier si c'est un programme--//
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
	//methodes static pour la r�utilisation
		static DWORD WINAPI connexion(LPVOID params);
		static DWORD WINAPI received(LPVOID params);

};
//---------------------------------------------------------------------------
#endif
