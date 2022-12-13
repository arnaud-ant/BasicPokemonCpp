#include "pokemon.h"
#include "pokemonTypes.h"
#include "Pokedex.h"
#include "bestiaire.h"
#include <iostream>
using namespace std;

void AfficheMenu(void)
{
	cout << endl;
	cout << "---------MENU----------" << endl;
	cout << "1 : Index de Pokemons" << endl;
	cout << "2 : Mon Pokedex" << endl;
	cout << "3 : Attraper un Pokemon" << endl;
	cout << "4 : Power-up" << endl;
	cout << "5 : Evoluer" << endl;
	cout << "6 : Combat" << endl;
	cout << "7 : Historique" << endl;
	cout << "8 : Quitter" << endl;
}

void evolve(Pokemon* Poke,Ressource* rss,EspecePokemon bestiaire[]) 
{
	int i = PokeToBestiaire(Poke, bestiaire);
	if (bestiaire[i].evolvesTo != nullptr)
	{
		if (rss->BonBon >= bestiaire[i].nbBonbonsPourEvoluer)
		{
			Poke->nom = bestiaire[i + 1].nom;
			Poke->evo += 1;
			rss->BonBon -= bestiaire[i].nbBonbonsPourEvoluer;
			cout << "Evolution reussi en " << Poke->nom << " !" << endl;
		}
		else
		{
			cout << "Pas assez de ressources pour evoluer : " << rss->BonBon << "/" << bestiaire[i].nbBonbonsPourEvoluer << " bonbons"<< endl;
		}
	}
	else
	{
		cout << "Le pokemon ne peut pas evoluer" << endl;
	}
}

void powerup(Pokemon* Poke,Ressource* rss)
{
	if (rss->BonBon>=10 && rss->poussieres>=500)
	{
		rss->BonBon -= 10;
		rss->poussieres -= 500;
		Poke->CP += 0.25 * Poke->CP;
		cout << "Power-up reussi, les CP de  sont desormais de : " << Poke->CP << endl;
	}
	else
	{
		cout << "Pas assez de ressources pour power-up : " << rss->BonBon << "/10 bonbons et " << rss->poussieres << "/500 poussieres" << endl;
	}
}

void display(Pokemon p,EspecePokemon bestiaire[], const char* swap[])
{
	int i = 0;
	while (p.nom!=bestiaire[i].nom)
	{
		i++;
	}

	cout << endl;
	cout << p.nom << "\n PV : " << p.PV << "\n XP : " << p.xp << "\n CP : " << p.CP << "\n evo : " << p.evo << "\n Type : "<< swap[bestiaire[i].type] << endl;
}

