//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:Manager.h---------------------------------------------------------//
//---Cette classe permet de generer un objet de type scene ou programme en lien
//--------------avec la BDD--------------------------------------------------//
//---------------------------------------------------------------------------//

#pragma hdrstop

#include "./Manager/Manager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//constructeur
	manager::manager()
	{
		this->mysql = new MySQL();
	}


	void manager::afficheDoubleVector(std::vector<std::vector<std::string> > vector)
	{
		std::string str;

		char * conv = new char[10];
		itoa(vector.size(), conv, 10);

		str += conv;
        str += " lignes\n";

		for (int i = 0; i < vector.size(); i++) {
			for (int j = 0; j < vector[i].size(); j++) {
				str += " " + vector[i][j];
			}

			str += "\n";
		}

		MessageBox(NULL, str.c_str(), "test", MB_OK | MB_ICONQUESTION);
    }

//permet de r�cup�rer un programme dans la bdd grace � son id
	programme*manager::getProg(idProg)
	{
		char *buffer;
		buffer = new char[100];
		this->prog = new programme();
		//Construction de la requ�te :
		std::string request = "SELECT * FROM `program` WHERE `idProgram`='";
		itoa(idProg,buffer,10);
		request +=buffer;
		request += "';";


		//Envoie de la requ�te :
		vector < vector < string > > results = this->mysql->Select(request);
			afficheDoubleVector(results);

		//stockage des donn�es r�c�ptionn�e
		this->prog->setId(idProg);
		this->prog->setName(results[0][1]);

		//Construction de la seconde requ�te visant � r�cup�rer le nombre de scenes :
		request.clear();
		request = "SELECT * FROM `scene`,`compoprogram`,`program` WHERE  `scene`.`IdScene`=`compoprogram`.`IdScenecompo` AND `compoprogram`.`IdProgram` = `program`.`IdProgram` AND `compoprogram`.`IdProgram`='";
		request +=buffer;
		request += "';";

		//Utilisation de la nouvelle requ�te :
		vector < vector < string > > results2 = this->mysql->Select(request);
			afficheDoubleVector(results2);


		int NbRow = results2.size();
		this->prog->setNbScene(NbRow);
		//je simule les valeurs de la base
//			for (int i = 0; i < results2.size(); i++) {
//
//			for (int j = 0; j < results2[i].size(); j++) {
//				MessageBox(NULL, results2[i][j].c_str(),"test", MB_OK | MB_ICONQUESTION);
//			}
//		}


		for (int i = 0; i < NbRow; i++)
		{
				scene *s = new scene();
				int StockId=atoi(results2[i][0].c_str());

				s->setId(StockId);
				s->setName(results2[i][1]);
				s->setTime(atoi(results2[i][5].c_str()));

				request.clear();
				request =  "SELECT * FROM `scene`,`sequence` WHERE `sequence`.`IdScene`=`scene`.`IdScene` AND `scene`.`IdScene` = '";
				request += results2[i][0];
				request += "';";
				vector < vector < string > > results3 = this->mysql->Select(request);
				s->setNbSeq(results3.size());

				this->prog->AjouterUneSceneAuProgramme(s);
				delete s;
		}
		return this->prog;
	}
//permet de r�cup�rer une sc�ne dans la bdd grace � son id
	scene*manager::getScn(idScn)
	{
		char *buffer;
		buffer = new char[100];
		this->scn = new scene();
		std::string request = "SELECT * FROM `scene` WHERE `IdScene`='";
		itoa(idScn,buffer,10);
		request +=buffer;
		request += "';";

		vector < vector < string > > results = this->mysql->Select(request);

		afficheDoubleVector(results);
		this->scn->setId(idScn);
		this->scn->setName(results[0][1]);
		request.clear();


	}
	equipement*manager::InsertEquipment(std::string Name)
	{
		vector< vector<string> > test;
		char *buffer;
		buffer = new char[100];
		std::string result;
		int idEquipement=0;
		std::string request = "INSERT INTO `equipment`(`Nom`) VALUES ('";
		request += Name;
		request += "');";
		this->mysql->Insert(request);
		request.clear();

		request = "SELECT `IdEquipment` FROM `equipment` WHERE `equipment`.`Nom`='";
		request += Name;
		request += "';";

		test = this->mysql->Select(request);

		idEquipement = atoi(test[0][0].c_str());
		 const char *temp = Name.c_str();
		 char * Nom =(char*)temp;
		this->equip = new equipement(idEquipement,Nom);

		afficheDoubleVector(test);

		return this->equip;
	}

	void manager::InsertProperties(std::string Description, std::string Order, std::string IdEquipement)
	{
		std::string request = "INSERT INTO `properties`(`Description`, `Order`, `IdEquipment`) VALUES ('";
		request += Description;
		request += "','";
		request += Order;
		request += "','";
		request += IdEquipement;
		request += "');";
		this->mysql->Insert(request);
		request.clear();


	}

//permet de v�rifier et de remplacer les bons �l�ments d'une scene dans la bdd
	scene*manager::updateScene(scene*scn)
	{

	}
//permet de v�rifier et de remplacer les bons �l�ments d'un programme dans la bdd
	programme*manager::updateProg(programme*prog)
	{

	}
//permet de renvoyer un message d'envoi r�ussi
	char*manager::sendOk()
	{

	}
//permet de renvoyer un message d'erreur
	char*manager::sendError()
	{

	}

	bool manager::CheckEtat()
	{
		return this->EtatConnect;
	}

	bool manager::Connect()
	{
		std::string Adresse="192.168.65.97";
		std::string ID="root";
		std::string MDP="root";
		std::string NomDeBase="theater";
		this->EtatConnect=this->mysql->Connect(Adresse,ID,MDP,NomDeBase);
	}

	manager::~manager()
	{
		this->mysql->Disconnect();
	}
