#ifndef pokedex_h
#define pokedex_h
#include"pokemon.h"  



typedef struct
{
	Pokemon* mesPokemons;
	int nbPokemons;
	int capacity;
	
}Pokedex;


Pokedex* initPokedex(const int size);
void insertPokemon(Pokedex **monPokedex, Pokemon p);
void displayPokedex(Pokedex* pokedex, EspecePokemon bestiaire[150],
	const char* typesLabel[18]);

Pokemon* genererPokemon(EspecePokemon bestiaire[150]/*, char* typesLabel[18]*/);
#endif
