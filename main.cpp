#include<iostream>
#include"pokemon.h"
#include"bestiaire.h"
#include"Pokedex.h"
#include"utils.h"
#include"ressource.h"
#include"historique.h"
using namespace std;



void afficheMenu()
{
	cout << "    PokeMonGo    " << endl;
	cout << endl;
	cout << "1.Index des pokemons  " << endl;
	cout << "2.Mon Pokedex  " << endl;
	cout << "3.Attraper un pokemon  " << endl;
	cout << "4.Power-up et ¨¦volution  " << endl;
	cout << "5.Affiche l'historique des evolutions" << endl;
	cout << "6.Combat  " << endl;
	cout << "7.Quitter  " << endl;
	cout << " Entrez votre chiox  :" << endl;
}


void powerupAndEvolution(Pokedex* pokedex , EspecePokemon bestiaire[150],Ressources &ressources, Historique* historique) {
	int newchoice = 0;
	int idPokemon = -1;
	do
	{
		cout << "Choisir l'identifiant du pokemon ¨¤ faire ¨¦voluer ou progresser." << endl;
		cin >> idPokemon;
	} while (idPokemon<0);
	Pokemon* p = &(pokedex->mesPokemons[idPokemon]);

	cout << "Choisir l'action ¨¤ r¨¦aliser : " << endl;
	cout << " 1 - Powerup" << endl;
	cout << " 2 - Evolution" << endl;
	cout << " 3 - Retour au menu principal" << endl;

	do {
		cin >> newchoice;
		if (newchoice != 1 && newchoice != 2 && newchoice != 3) {
			cout << "mauvais choix, saisir 1, 2 ou 3";
		}
	} while (newchoice != 1 && newchoice != 2 && newchoice != 3);


	if (newchoice == 1) {
		cout << endl;
		cout << "Let's power up!!";
		cout << endl;
		if (ressources.candies >= 10 && ressources.stardust >= 500)
		{
			ressources.candies -= 10;
			ressources.stardust -= 500;
			powerup(p);
		}
		else cout << "Power - up impossible : 10 bonbons et 500 poussi¨¨res sont n¨¦cessaires.Peut ¨ºtre devriez - vous attraper plus de pokemons !" << endl;

	}
	else if (newchoice == 2) {
		int i = 0;
		while (i < 150 && strcmp(p->nom, bestiaire[i].nom) != 0)
		{
			i++;
		}
		const char* nextEvolution = bestiaire[i].evolvesTo;

		int nbBonbonsNecessaires = bestiaire[i].nbBonbonsPourEvoluer;

		if (nextEvolution == nullptr)
		{
			cout << "Evolution impossible: le pokemon est d¨¦j¨¤ dans sa derni¨¨re ¨¦volution !" << endl;
		}
		else
		{
			if (nbBonbonsNecessaires > ressources.candies)
			{
				cout << "Evolution impossible : " << nbBonbonsNecessaires << " bonbons sont n¨¦cessaires. Peut ¨ºtre devriez-vous attraper plus de pokemons !";
			}
			else {
				ressources.candies = ressources.candies - nbBonbonsNecessaires;
				/*Evolution *evolution = new Evolution;
				evolution->from = p->nom;
				evolution->to = nextEvolution;
				evolution->nextEvol = nullptr;
				if (his.debut == nullptr) {
					his.debut = evolution;
					his.nombre += 1;
				}
				else {
					evolution->nextEvol = his.debut->nextEvol;
					his.debut = evolution;
					his.nombre += 1;
				}
*/
				evolve(p,nextEvolution,historique);
				
			}
		}
	}
}


int main(int argc, const char* argv[]) {

	EspecePokemon monBestiaire[150];
	initBestiaire(monBestiaire); 
	const char* typesLabel[] = {
	"Normal", "Flying", "Poison", "Ground",
	"Rock", "Bug", "Ghost", "Steel", "Fire", "Grass", "Water",
	"Electric", "Psychic", "Ice", "Dragon", "Dark", "Fairy"
	};
	
	Ressources ressources;
	ressources.candies = 100;
	ressources.stardust = 1000;

	Pokedex* pokedex = initPokedex(3);
	Historique* historique = new Historique;
	


	Pokemon a;
	a.nom = "Seadra";
	a.XP = 1;
	a.CP = 4;
	a.evolution = 1;
	a.PV = 23;

	Pokemon b;
	b.nom = "Arbok";
	b.XP = 0;
	b.CP = 123;
	b.evolution = 2;
	b.PV = 134;

	Pokemon d;
	d.nom = "Paras";
	d.XP = 0;
	d.CP = 23;
	d.evolution = 1;
	d.PV = 90;

	Pokemon c;
	c.nom = "Bulbasaur";
	c.XP = 40;
	c.CP = 300;
	c.evolution = 1;
	c.PV = 223;

	/*Pokemon e;
	e.nom = "Arkanine";
	e.XP = 0;
	e.CP = 23;
	e.evolution = 2;
	e.PV = 290;*/
	

	insertPokemon(&pokedex, a);
	cout << "******* Pokedex after inserting pokemon a *********" << endl;
	displayPokedex(pokedex, monBestiaire, typesLabel);
	cout << "***************************************************" << endl;
	cout << endl << endl;
	insertPokemon(&pokedex, b);
	cout << "******* Pokedex after inserting pokemon b *********" << endl;
	displayPokedex(pokedex, monBestiaire, typesLabel);
	cout << "***************************************************" << endl;
	cout << endl << endl;
	insertPokemon(&pokedex, c);
	cout << "******* Pokedex after inserting pokemon c *********" << endl;
	displayPokedex(pokedex, monBestiaire, typesLabel);
	cout << "***************************************************" << endl << endl << endl;
	insertPokemon(&pokedex, d);
	cout << "******* Pokedex after inserting pokemon d *********" << endl;
	displayPokedex(pokedex, monBestiaire, typesLabel);
	cout << "***************************************************" << endl;
	cout << endl << endl;
	/*insertPokemon(&pokedex, e);
	cout << "******* Pokedex after inserting pokemon e *********" << endl;
	displayPokedex(pokedex, monBestiaire, typesLabel);
	cout << "***************************************************" << endl << endl << endl;*/



	afficheMenu();
	int n = 7;



	do
	{
		
		cin >> n;
		switch (n)
		{
		case 1:
		{	


			//triBestiaires(monBestiaire);
			displayBestiaires(monBestiaire);
			cout << " Comment voulez-vous afficher votre table?" << endl;
			int chx = 0;
			do {
				cout << " 1 - Tri naturel " << endl << " 2 - Tri par nom " << endl;
				cin >> chx;
			} while (chx != 1 && chx != 2);
			
			switch (chx)
			{
			case 2:
				triBestiaires(monBestiaire);
				break;
			case 1:
				displayBestiaires(monBestiaire);
				break;
			default:
				cout << " Entrer '1'et '2' SVP" << endl;
				break;
			}

			break;
		}
		case 2:
		{
			displayPokedex(pokedex,monBestiaire,typesLabel);

			cout << (*pokedex).capacity << endl;
			cout << (*pokedex).nbPokemons << endl;
			cout << "=================================================="<<endl;
			break;
		}
		case 3:
		{
			int choiceCap = 0;
			
			do {
				Pokemon* pokemonS;
				pokemonS = genererPokemon(monBestiaire/*, typesLabel*/);
				display(*pokemonS, typesLabel, monBestiaire);

				
				cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
				cout << endl << "\tQue souhaitez-vous faire ? " << endl;
				cout << "\t 1- Tenter de le capturer" << endl;

				cout << "\t 2- Laisser ce pokemon vivre sa vie en plein air.";
				cout << "Regardons s'il n'y en aurait pas d'autres aux alentours ..." << endl;
				cout << "\t 3- Ne plus attraper de pokemon." << endl;
				cin >> choiceCap;

				
				if (choiceCap == 1)
				{
					int probability = 0;
					probability = random_at_most(100);
					if ((int)(probability >=70)) {
						insertPokemon(&pokedex, *pokemonS);

						//mise ¨¤ jour des ressources
						ressources.stardust = ressources.stardust + 100;
						ressources.candies = ressources.candies + 3;
						cout << "***************************************************" << endl;
						
						displayPokedex(pokedex, monBestiaire, typesLabel);
						cout << endl;
						cout << "******* Bravo! Vous l'avez captur¨¦! *********" << endl;
						cout << endl << endl;
					}
					else cout << "\t Le pokemon s'est ¨¦chapp¨¦ ! " << endl << endl;
					
					choiceCap = 3;
					cout << "\tVoulez-vous continuer ¨¤ attraper des pokemons ?" << endl;
					cout << "\t 1 - Oui" << endl;
					cout << "\t 2 - Non" << endl;
					cin >> choiceCap;
					if (choiceCap == 2) {
						choiceCap = 3; // forcer le fait de sortir du menu apr¨¨s une capture
					}
					

				}
			} while (choiceCap != 3);

			
			break;
		}
		case 4:
		{
			powerupAndEvolution(pokedex,monBestiaire,ressources,historique);
			break;
		}
		

		case 5:
		{
			afficherHistorique(historique);
			/*if (historique.debut == nullptr)
			{
				cout << "la liste est vide....." << endl;
			}
			cout << "Historique des evolutions:"<<"( "<<historique.nombre <<" )"<< endl;
			Historique tmp = historique;
			while (tmp.debut != nullptr) {
				
				cout << tmp.debut->from <<"  ->  "<<tmp.debut->to<< endl;
				tmp.debut = tmp.debut->nextEvol;
			}
*/
			break;
		}

		case 6:
		{
			cout << "5.Combat  " << endl;
			break;
		}

		case 7:
		
			char chioxQ;
			do {
				cout << "voulez-vous quitter  ? " << endl;
				cout << "  saisir votre choix ('o'ou 'n'):  ";

				cin >> chioxQ;
			} while ( chioxQ!= 'o');
			
			cout << "Goodbye!" << endl;
			break;

		
		default:
			cout << "Choisir un nombre entre 1-6 : " << endl;

			break;

		}
		cout << endl << endl;
		afficheMenu();
	} while (n != 7);

	cout << "Good bye, we will catch 'em all later!\n";


	/*Pokemon  pTest;
	pTest.nom = "Pikachu";
	pTest.CP = 10;
	pTest.evolution = 1;
	pTest.PV = 20;
	pTest.XP = 30;
	display(pTest, typesLabel,monBestiaire);*/


	return 0;
}
