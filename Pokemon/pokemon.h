#pragma once
#include "pokemonTypes.h"

typedef struct Pokemon
{
	const char* nom;
	int xp;
	int evo;
	int PV;
	int CP;

} Pokemon;

typedef struct
{
	int poussieres;
	int BonBon;
}Ressource;

void AfficheMenu(void);
void evolve(Pokemon* Poke, Ressource* rss,EspecePokemon bestiaire[]);
void powerup(Pokemon* Poke,Ressource* rss);
void display(Pokemon p,EspecePokemon bestiaire[],const char*swap[]);