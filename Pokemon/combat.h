#pragma once
#include "Pokedex.h"
#include "pokemonTypes.h"

typedef struct CombatEspece
{
	const char* nature;
	const char* strongAgainst[5];
	const char* weakAgainst[5];
	CombatEspece* next;
};

typedef struct CombatHash
{
	int size;
	CombatEspece* table[26];

};

CombatHash* initCombatHash();
CombatEspece* get(CombatHash* hashtable, const char* key);
bool contains(CombatHash* hashtable, CombatEspece* c);
void insert(CombatEspece* c, CombatHash* hashtable);
const char* pokemonTypeToString(PokemonType t);
int hashf(const char* str);
bool tableContains(const char* tab[5], const char* val);
void fight(CombatHash* hashtable,Pokedex* pokedex, EspecePokemon bestiaire[150]);