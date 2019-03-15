<?php

/*----------------------------------------------------------------/
PROJET THEATRE DMX512
DEVELOPPÉ PAR : MAXIME LEPELLETIER 
BTS SN2

		- classe programme de l'ihm php - 

cette classe permet de parametrer les programmes de lumiere.
ces derniers contiennent des scenes (objet du fichier class_scene.php)
/----------------------------------------------------------------*/


Class Programme 
{
	protected $_Scene;					//réccupere une scene existante
	private $_Id;						//n°ID du programme
	private $_Nom;						//nom du programme
	private $_NbScene;					//nombre de scenes présentes dans le programme
	private $_TailleMax;				//taille maximum du programme
	private $_Order;					//ordre des scenes dans le programme

//Constructeur avec parametres
	public function __construct($_Id,$_Nom,$_NbScene,$_TailleMax,$_Order,)
 		{
    		$this->_id=$_Id;
    		$this->_Nom=$_Nom;
    		$this->_NbScene=$_NbScene;
    		$this->_TailleMax=$_TailleMax;
    		$this->_Order=$_Order;
  	 	}

//Fonction qui vas retrouner l'id du programme'
	public function GetId()
		{
			return $_Id;	
		}

//Fonction qui permet de parametrer l'id du programme
	public function SetId($_Id)
		{
			$this->$_Id=$_Id;
		}

//Fonction qui vas retrouner le nom du programme
	public function GetNom()
		{
			return $_Nom;			
		}

//Fonction qui permet de parametrer le nom du programme
	public function SetNom($_Nom)
		{
			$this->$_Nom=$_Nom;	
		}

//Fonction qui vas retrouner le nombre de scene
	public function GetNbscene()
		{
			return $_NbScene;			
		}

//Fonction qui permet de parametrer le nombre de scene
	public function SetNbscene($_NbScene)
		{
			$this->$_NbScene=$_NbScene;
		}

//Fonction qui vas retrouner le nombre maximal de scene d'un programme
	public function GetTaillemax()
		{
			return $_TailleMax;			
		}

//Fonction qui permet de parametrer le nombre maximal de scene d'un programme
	public function SetTaillemax($_TailleMax)
		{
			$this->$_TailleMax=$_TailleMax;	
		}

//Fonction qui vas retrouner l'ordre des scenes
		public function GetOrder()
		{
			return $_Order;
		}

//Fonction qui permet de parametrer l'ordre
		public function SetOrder($_Order)
		{
			$this->$_Order=$_Order;
		}


}

?>