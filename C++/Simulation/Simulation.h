//---------------------------------------------------------------------------

#ifndef SimulationH
#define SimulationH

#include <vector>
#include"./BDD/BDD.h"
#include"./MySQL/MySQL.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>
//---------------------------------------------------------------------------

class programme;
class scene;
class sequence;
class manager;

class simulation
{
	private:
		programme * prog;
		scene * scn1;
		scene * scn2;
		sequence * seq1;
		sequence * seq2;
		sequence * seq3;
		std::vector<scene*> scn;
		manager * manage;
	public:

		programme* getProgramme(int id);



};
#endif
