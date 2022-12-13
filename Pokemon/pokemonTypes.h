#pragma once
typedef enum {
	Normal, Fighting, Flying, Poison, Ground, Rock, Bug,
	Ghost, Steel, Fire, Grass, Water, Electric, Psychic,
	Ice, Dragon, Dark, Fairy,
} PokemonType;

typedef struct
{
	const char* nom;
	const char* evolvesTo;
	int nbBonbonsPourEvoluer;
	PokemonType type;
	bool estEvolue;

} EspecePokemon;

