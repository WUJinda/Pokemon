#ifndef pokemon_h
#define pokemon_h
#include"pokemonTypes.h"
#include"historique.h"

typedef struct{

	const char* nom;
	int XP;
	int evolution;
	int PV;
	int CP;


}Pokemon;


void evolve(Pokemon* p, const char* nextEvolution, Historique* historique);
void powerup(Pokemon* p);
void display(const Pokemon p,const char* type[],EspecePokemon bestiaire[]);

#endif