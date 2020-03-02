#include "Pokedex.h"
#include <iostream>
#include"utils.h"
using namespace std;

Pokedex* initPokedex(const int size)
{
	Pokedex* pokedex= new Pokedex;
	pokedex->capacity = size;
	pokedex->nbPokemons = 0;
	pokedex->mesPokemons = new Pokemon[size];
	return pokedex;
}

void insertPokemon(Pokedex **monPokedex, Pokemon p)
{
		
	// on r¨¦alise un d¨¦r¨¦fencement une fois pour toutes, le reste
	// du code de cette fonction devient plus lisible.
	Pokedex* pokedex = *monPokedex;

	// 1- A-t-on assez de place dans la tabeau dynamique ?
	if (pokedex->capacity == pokedex->nbPokemons) {

		// le tableau dynamique est plein,
		// on va commencer par l'aggrandir de 50% de sa capacit¨¦
		Pokedex* newpokedex = initPokedex((int)(pokedex->capacity * 1.5));
		for (int i = 0; i < pokedex->nbPokemons; i++) {
			newpokedex->mesPokemons[i] = pokedex->mesPokemons[i];
		}
		newpokedex->nbPokemons = pokedex->nbPokemons;


		// le pokedex devient celui nouvellement construit contenant les anciens pokemons.
		*monPokedex = newpokedex;
		pokedex = newpokedex;

	}

	// 2- on cherche l'index auquel nous allons ins¨¦rer ce
	// nouveau pokemon, au regard de son nom (tri par ordre
	// croissant des noms de pokemon).
	if (pokedex->nbPokemons == 0) {
		pokedex->mesPokemons[0] = p;
	}
	else {
		// au moins un pokemon, cherchons la position du
		// nouveau pokemon.
		int i = 0;
		while (i < pokedex->nbPokemons && strcmp(pokedex->mesPokemons[i].nom, p.nom) < 0) {
			i++;
		}

		// on quitte la boucle car il faut l'ins¨¦rer ¨¤ la fin, ou en cours de tableau
		// suivant si on a quitt¨¦ car i == pokedex->nbPokemons ou si on a trouv¨¦ un pokemon
		// apr¨¨s le pokemon $p$ dnas l'ordre alphab¨¦tique.
		if (i == pokedex->nbPokemons) {
			pokedex->mesPokemons[i] = p;
		}
		else {
			// il faut d¨¦caler les pokemons du sous tableau partant de la droite du
			// tbaleau afin d'y faire un trou dans le tableau et y placr notre pokemon.
			// Voir principe du tri par insertion vu en module BCD algorithmie.
			for (int k = pokedex->nbPokemons - 1; k >= i; k--) {
				pokedex->mesPokemons[k + 1] = pokedex->mesPokemons[k];
			}
			pokedex->mesPokemons[i] = p;
		}
	}

	pokedex->nbPokemons = pokedex->nbPokemons + 1;
	/*if ((*monPokedex)->nbPokemons+1 >= (*monPokedex)->capcity){
		
		Pokedex* new_p = initPokedex((int)((*monPokedex)->capcity * 1.5));
		
		for (int i = 0; i < (*monPokedex)->nbPokemons; i++) {
			new_p->mesPokemons[i] = (*monPokedex)->mesPokemons[i];
		}
		
		new_p->mesPokemons[(*monPokedex)->nbPokemons] = p;
		delete (*monPokedex)->mesPokemons;
		(*monPokedex)->capcity = (int)((*monPokedex)->capcity * 1.5);
		(*monPokedex)->mesPokemons = new_p->mesPokemons;
		(*monPokedex)->nbPokemons++;
	}
	else {
		(*monPokedex)->mesPokemons[(*monPokedex)->nbPokemons] = p;
		(*monPokedex)->nbPokemons++;
	}*/
}

void displayPokedex(Pokedex* pokedex, EspecePokemon bestiaire[150], const char* typesLabel[18])
{
	cout << endl << "Contenu du pokedex (Actuellement";
	cout << pokedex->nbPokemons << "pokemons captur¨¦s)" << endl;
	for (int i = 0; i < pokedex->nbPokemons; i++)
	{
		display(pokedex->mesPokemons[i], typesLabel, bestiaire);
	}

}

Pokemon* genererPokemon(EspecePokemon bestiaire[150]/*,const char* typesLabel[18]*/)
{
	Pokemon* PokeX = new Pokemon;
	EspecePokemon bestiaireSauvage = bestiaire[random_at_most(149)];
	while(bestiaireSauvage.estEvolue != 0)
	{
			bestiaireSauvage= bestiaire[random_at_most(149)];
	}
	PokeX->nom = bestiaireSauvage.nom;
	PokeX->evolution = 0;
	PokeX->XP = 0;
	PokeX->CP = (int)rand_interval(200,1000);
	PokeX->PV = (int)rand_interval(30,500);

	return PokeX;
}
