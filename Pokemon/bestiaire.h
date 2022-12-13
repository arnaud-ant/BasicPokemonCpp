#pragma once
#include "pokemonTypes.h"
void tri(EspecePokemon bestiaire[]);
int PokeToBestiaire(Pokemon* p, EspecePokemon bestiaire[]);
void initBestiaire(EspecePokemon bestiaire[]);
void AfficheBestiaire(EspecePokemon bestiaire[],const char* typesLabel[]);
EspecePokemon lookupEspecePokemon(EspecePokemon bestiaire[], const char* nom);