#pragma once
#ifndef pokemonTypes_h
#define pokemonTypes_h

#include <string>
using namespace std;

typedef enum {
	Normal, Fighting, Flying, Poison, Ground,
	Rock, Bug, Ghost, Steel, Fire, Grass, Water, 
	Electric, Psychic, Ice, Dragon, Dark, Fairy
}PokemonType;


typedef struct {

	const char* nom;
	PokemonType type;
	int nbBonbonsPourEvoluer;
	bool estEvolue;
	const char* evolvesTo;


}EspecePokemon;


#endif