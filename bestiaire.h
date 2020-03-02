#ifndef bestiaire_h
#define bestiaire_h
#include"pokemonTypes.h"
#include"pokemon.h"

void initBestiaire(EspecePokemon bestiaire[]);
void displayBestiaires(EspecePokemon bestiaire[]);
void triBestiaires(EspecePokemon bestiaire[]);
const char* typePokemon(Pokemon p, const char * type[],EspecePokemon bestiaire[]);

//EspecePokemon lookupPokemon(EspecePokemon bestiaire[],const char* nom);
#endif
