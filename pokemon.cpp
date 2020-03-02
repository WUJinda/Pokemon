#include"pokemon.h"
#include"pokemonTypes.h"
#include"bestiaire.h"
#include"historique.h"
#include<iostream>
using namespace std;

void evolve(Pokemon* p,const char* nextEvolution, Historique* historique)
{
	const char* oldName = p->nom;
	p->nom = nextEvolution;
	insererTete(historique, oldName, nextEvolution);
	p->evolution += 1;

	cout << endl << "F¨¦licitations, votre " << oldName << " est devenu un " << nextEvolution << " ! " << endl << endl;
}

void powerup(Pokemon* p)
{

	p->CP = (int)(p->CP * 1.25);
	cout << "F¨¦licitations, votre " << p->nom << " a progress¨¦ et gagn¨¦ 25% de ses points de combats, une v¨¦ritable armoire ¨¤ glace ! ";
}

void display(const Pokemon p, const char* type[], EspecePokemon bestiaire[])
{
	//EspecePokemon esp = lookupPokemon(bestiaire, p.nom);
	const char* type0 = typePokemon(p, type, bestiaire);
	//type0 = type[esp.type];
	cout <<"++++++++++++++++++++++++++++++++++++++"<< endl;
	cout << p.nom << " (Evolution : " << p.evolution << " ) " << endl;
	cout << "------------------------------------" << endl;
	cout << " Type : " << type0 << endl;
	cout << " PV : " << p.PV << "  |  CP : " << p.CP << " |  XP : " << p.XP << endl;

}
