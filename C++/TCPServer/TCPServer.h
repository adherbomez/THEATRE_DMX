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
//---------------------------------------------------------------------------

class TCPServer
{
	private:

		std::unique_ptr<ServerImpl> mImpl;

	public:

	//constructeurs du serveur
		TCPServer();
		TCPServer(const Server&) = delete;
		TCPServer& operator=(const Server&) = delete;
		TCPServer(Server&&);
		TCPServer& operator=(Server&&);
		~TCPServer();

		bool start(unsigned short _port);
		void stop();
		void update();
		std::unique_ptr<Messages::Base> poll();

		bool onConnect();
		bool onReceived();
		programme*parseProgramme(data);
		scene*parseScene(data);
		scene*updateScene(scn);
};


#endif
