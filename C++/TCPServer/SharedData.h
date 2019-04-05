//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---D�velopp� par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:SharedData.h------------------------------------------------------//
//---Cette classe permet de partager une donn�e dans plusieurs thread � l'aide//
//---du mutex. Elle est r�utilisable gr�ce au template-----------------------//
//---------------------------------------------------------------------------//
#ifndef SharedDataH
#define SharedDataH

#include <windows.h>
#include <vector>
//---------------------------------------------------------------------------//

//cette classe g�re les exceptions et elle est utilis� pour le mutex
	class TCPServerException : public std::exception
	{
		private:
			std::string message;

		public:
		//constructeur
			TCPServerException(std::string msg)
			{
				message = msg;
			}
		//cette methode retourne le message d'erreur
			virtual const char * what() const throw()
			{
				return message.c_str();
			}
	};
//---------------------------------------------------------------------------//

//cette classe permet de partager une donn�e entre plusieurs execution du syst�me
template <typename T>
	class SharedData
	{
		private:
			HANDLE mutex;
			std::vector<T> shared;

		public:
			SharedData();
			~SharedData();
			void Add(T data);
			T Get();
	};
//---------------------------------------------------------------------------//

//constructeur qui initialise le mutex
template <typename T>
	SharedData<T>::SharedData()
	{
		mutex = CreateMutex(
					NULL,
					FALSE,
					NULL);
	}

//destructeur qui ferme le mutex
template <typename T>
	SharedData<T>::~SharedData()
	{
		CloseHandle(mutex);
	}

//methode qui permet d'ajouter une donn�e � partager
template <typename T>
	void SharedData<T>::Add(T data)
	{
	//??????
		DWORD dwWaitResult = WaitForSingleObject(
								mutex,
								INFINITE);
	//on stock la data dans le vector shared
		shared.push_back(data);

	//on lib�re le mutex
		ReleaseMutex(mutex);
	}

//cette methode permet de retourner le message partag�
template <typename T>
	T SharedData<T>::Get()
	{
	//??????????
		DWORD dwWaitResult;
		dwWaitResult = WaitForSingleObject(
								mutex,
								INFINITE);
	//on v�rifie si shared poss�de une valeur est on affiche le
	//message d'erreur gr�ce � la classe TCPServerException
		if(shared.size() == 0)
		{
			ReleaseMutex(mutex);
			throw TCPServerException("Empty collection");
		}
	//on r�cup�re le message partag�
		T data = shared.front();
	//on le lib�re du vector
		shared.erase(shared.begin());
	//on lib�re le mutex
		ReleaseMutex(mutex);

		return data;
	}


//---------------------------------------------------------------------------
#endif
