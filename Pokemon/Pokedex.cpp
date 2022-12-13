#include "Pokedex.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include <stdio.h>

using namespace std;


Pokedex* initPokedex(const int size)
{
	Pokemon* tab = new Pokemon[size];
	Pokedex* pok = new Pokedex;
	pok->mesPokemons = tab;
	pok->capacity = size;
	pok->nbrPokemon = 0;
	return pok;
}

Ressource* initRss()
{
	Ressource* rss = new Ressource;
	rss->BonBon = 500;
	rss->poussieres = 5000;
	return rss;
}

void testFull(Pokedex* mnPokedex) 
{
	if (mnPokedex->capacity == mnPokedex->nbrPokemon)
	{
		int newcap = mnPokedex->capacity + mnPokedex->capacity * 0.5;
		Pokemon* tabP = new Pokemon[newcap];
		for (int i = 0; i < mnPokedex->capacity; i++)
		{
			tabP[i] = mnPokedex->mesPokemons[i];
		}
		delete [] mnPokedex->mesPokemons;
		mnPokedex->mesPokemons = tabP;
		mnPokedex->capacity = newcap;
	}
}

void triPokedex(Pokedex* poke)
{
	const char* temp;
	int i = 0;
	while (i < poke->nbrPokemon)
	{
		for (int k = 0; k < poke->nbrPokemon; k++)
		{
			if (strcmp(poke->mesPokemons[i].nom, poke->mesPokemons[k].nom) < 0)
			{
				temp = poke->mesPokemons[i].nom;
				poke->mesPokemons[i].nom = poke->mesPokemons[k].nom;
				poke->mesPokemons[k].nom = temp;
			}
		}
		i++;
	}
}

void insertionPokemon(Pokedex* monPokedex, Pokemon p)
{
	testFull(monPokedex);
	monPokedex->mesPokemons[monPokedex->nbrPokemon] = p;
	triPokedex(monPokedex);
	monPokedex->nbrPokemon += 1;
}

void displayPokedex(Pokedex* pokedex, EspecePokemon bestiaire[150], const char* typesLabel[18],Ressource* rss) 
{
	cout << endl << "Contenu du pokedex (Actuellement ";
	cout << pokedex->nbrPokemon << " pokemons capturés)" << endl;
	for (int i = 0; i < pokedex->nbrPokemon; i++) {
		display(pokedex->mesPokemons[i], bestiaire, typesLabel);
	}
	cout << "\n Nombre de bonbons : " << rss->BonBon << " Nombre de poussieres : " << rss->poussieres << endl;

}
int choixpoke(Pokedex* monPoke)
{
	bool test=false;
	int i,c;
	char* nom = new char[50];
	do
	{
		cout << "Saisir le nom du pokemon qui va recevoir l'amelioration, X pour quitter" << endl;
		cin >> nom;
		if (strcmp(nom,"X")!=0)
		{
			for (int i = 0; i < monPoke->nbrPokemon; i++)
			{
				if (strcmp(nom,monPoke->mesPokemons[i].nom)==0)
				{
					test = true;
					c = i;
				}
			}
		}
		else
		{
			c = -1;
		}
	} while (!test && strcmp(nom,"X")!=0);
	delete[] nom;
	return c;
}

void genererPokemon(EspecePokemon bestiaire[150], const char* typesLabel[18],Pokedex* monPokedex,Ressource* rss)
{
	srand(time(NULL));
	int i;
	int choix;
	do
	{
		i = rand() % 149;
	} while (bestiaire[i].estEvolue == 1);
	Pokemon pokem;
	pokem.xp = 0;
	pokem.CP = rand() % 800 + 200;
	pokem.PV = rand() % 470 + 30;
	pokem.evo = 1;
	pokem.nom = bestiaire[i].nom;
	display(pokem, bestiaire, typesLabel);
	cout << "1 : Capturer le pokemon" << endl;
	cout << "2 : Capturer un autre pokemon" << endl;
	cout << "3 : Revenir au menu" << endl;
	cin >> choix;
	switch (choix)
	{
	case 1: if (rand() % 100 < 40)
	{
		insertionPokemon(monPokedex, pokem);
		rss->BonBon += 3;
		rss->poussieres += 100;
		cout << "Vous venez de capturer un " << pokem.nom << " !" << endl;
	}
		  else
	{
		cout << "Echec de la capture" << endl;
	}
		break;
	case 2: genererPokemon(bestiaire, typesLabel,monPokedex,rss);
		break;
	default:
		break;
	}
}