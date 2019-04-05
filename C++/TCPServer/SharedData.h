//---------------------------------------------------------------------------//
//---PROJET_THEATRE_DMX------------------------------------------------------//
//---Développé par Arthur Dherbomez------------------------------------------//
//---BTSSN2------------------------------------------------------------------//
//---Class:SharedData.h------------------------------------------------------//
//---Cette classe permet de partager une donnée dans plusieurs thread à l'aide//
//---du mutex. Elle est réutilisable grâce au template-----------------------//
//---------------------------------------------------------------------------//
#ifndef SharedDataH
#define SharedDataH

#include <windows.h>
#include <vector>
//---------------------------------------------------------------------------//

//cette classe gère les exceptions et elle est utilisé pour le mutex
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

//cette classe permet de partager une donnée entre plusieurs execution du système
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

//methode qui permet d'ajouter une donnée à partager
template <typename T>
	void SharedData<T>::Add(T data)
	{
	//??????
		DWORD dwWaitResult = WaitForSingleObject(
								mutex,
								INFINITE);
	//on stock la data dans le vector shared
		shared.push_back(data);

	//on libère le mutex
		ReleaseMutex(mutex);
	}

//cette methode permet de retourner le message partagé
template <typename T>
	T SharedData<T>::Get()
	{
	//??????????
		DWORD dwWaitResult;
		dwWaitResult = WaitForSingleObject(
								mutex,
								INFINITE);
	//on vérifie si shared possède une valeur est on affiche le
	//message d'erreur grâce à la classe TCPServerException
		if(shared.size() == 0)
		{
			ReleaseMutex(mutex);
			throw TCPServerException("Empty collection");
		}
	//on récupère le message partagé
		T data = shared.front();
	//on le libère du vector
		shared.erase(shared.begin());
	//on libère le mutex
		ReleaseMutex(mutex);

		return data;
	}


//---------------------------------------------------------------------------
#endif
