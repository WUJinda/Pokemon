#include "historique.h"
#include<iostream>
using namespace std;

void insererTete(Historique* historique, const char* from, const char* to)
{
	Evolution* e = new Evolution;
	e->from = from;
	e->to = to;
	e->nextEvol = nullptr;

	if (historique->debut == nullptr)
	{
		historique->nombre = 1;
		historique->debut = e;

	}
	else {

		e->nextEvol = historique->debut;
		historique->debut = e;
		historique->nombre += 1;

	}
}

void afficherHistorique(Historique* historique)
{
	if (historique->debut == nullptr) {
		cout << " Vous n'avez encore r¨¦alis¨¦ aucune ¨¦volution ! " << endl;
	}else
	{ 
		cout << "            " << endl;
		Evolution* current = historique->debut;
		while (current != nullptr)
		{
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			
			cout << current->from << " -> " << current->to << endl;
			
			current = current->nextEvol;
		}
	}
	
}
