#pragma once
#include "pokemonTypes.h"
#include "pokemon.h"

typedef struct
{
	Pokemon* mesPokemons;
	int nbrPokemon;
	int capacity;

}Pokedex;


Pokedex* initPokedex(const int size);
Ressource* initRss();
void testFull(Pokedex* mnPokedex);
void triPokedex(Pokedex* Poke);
void insertionPokemon(Pokedex* monPokedex, Pokemon p);
void displayPokedex(Pokedex* pokedex, EspecePokemon bestiaire[150], const char* typesLabel[18],Ressource* rss);
void genererPokemon(EspecePokemon bestiaire[150],const char* typesLabel[18],Pokedex* monPokedex,Ressource* rss);
int choixpoke(Pokedex* monPoke);

