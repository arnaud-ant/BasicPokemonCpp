#include "combat.h"
#include "pokedex.h"
#include "bestiaire.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const char* pokemonTypeToString(PokemonType t) 
{
		if(t == Normal)
		{
		return "Normal";
		} 
		else  
		if(t == Fighting) 
			{
			return "Fighting";
			} else 
				if(t == Flying) {
				return "Flying";
				} else 
					if(t == Poison) {
					return "Poison";
					} else 
						if(t == Ground) {
						return "Ground";
						} else 
							if(t == Rock) {
							return "Rock";
							} else 
								if(t == Bug) {
								return "Bug";
								} else 
									if(t == Ghost) {
									return "Ghost";
									} else 
										if(t == Steel) {
										return "Steel";
										} else
											if(t == Fire) {
											return "Fire";
											} else 
												if(t == Grass) {
												return "Grass";
												} else 
													if(t == Water) {
													return "Water";
													} else 
														if(t == Electric) {
														return "Electric";
														} else 
															if(t == Psychic) {
															return "Psychic";
															} else 
																if(t == Ice) {
																return "Ice";
																} else 
																	if(t == Dragon) {
																	return "Dragon";
																	} else 
																		if(t == Dark) {
																		return "Dark";
																		} else{
																		return "Fairy";
																		}
}

int hashf(const char* str,CombatHash*hashtable)
{
		unsigned long hash = 5381;
	int c;
		while (c = *str++)
			hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash % hashtable->size;
}

CombatEspece* get(CombatHash* hashtable, const char* key)
{
    int alveole = hashf(key, hashtable);

    CombatEspece* current = hashtable->table[alveole];
    while (current != nullptr && strcmp(current->nature, key) != 0) {
        current = current->next;
    }

    return current;
}

bool contains(CombatHash* hashtable, CombatEspece* c)
{
	CombatEspece* element = get(hashtable, c->nature);
	return (element != nullptr);
}
void insert(CombatEspece* c, CombatHash* hashtable)
{
    if (!contains(hashtable, c)) {
        int alveole = hashf(c->nature, hashtable);

        CombatEspece* current = hashtable->table[alveole];
        if (current == nullptr) {
            hashtable->table[alveole] = c;
        }
        else {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = c;
        }

    }
    else {
        // silently do nothing : it is already there.
    }
}

/* Quick factorization of the code that checks whether a string
 belongs to a static table of 5 strings (possibly null strings).*/
bool tableContains(const char* tab[5],const char* val) {

    for (int i = 0; i < 5; i++) {
        if (tab[i] != nullptr && strcmp(tab[i], val) == 0) {
            return true;
        }
    }
    return false;
}

void fight(CombatHash* hashtable,Pokedex* pokedex,EspecePokemon bestiaire[150]) {
    srand(time(NULL));
    int idPokemon1 = -1;
    do {
        cout << "Choisir l'identifiant du premier combattant." << endl;
        cin >> idPokemon1;
    } while (idPokemon1 < 0);

    int idPokemon2 = -1;
    do {
        cout << "Choisir l'identifiant du second combattant." << endl;
        cin >> idPokemon2;
    } while (idPokemon2 < 0);


    // récupérons le pointeur vers le pokemon que l'on souhaite modifier.
    Pokemon* a = &(pokedex->mesPokemons[idPokemon1]);
    Pokemon* b = &(pokedex->mesPokemons[idPokemon2]);

    cout << "Début du combat entre " << a->nom << " et " << b->nom << " ! " << endl;

    // déterminer qui est fort/faible contre qui
    EspecePokemon eA = lookupEspecePokemon(bestiaire, a->nom);
    EspecePokemon eB = lookupEspecePokemon(bestiaire, b->nom);

    const char* natureA = pokemonTypeToString(eA.type);
    const char* natureB = pokemonTypeToString(eB.type);

    CombatEspece* cbtEA = get(hashtable, natureA);
    CombatEspece* cbtEB = get(hashtable, natureB);

    /* nous devrions tester ici si cbtEA ou cbtEB est le pointeur null,
    ce qui est peu probable mais une vérification s'impose.
    A des fins de lisibilité et d'accessibilité, nous laisserons cette
    vérification à implémenter au lecteur. */

    bool aStrongVersusB = tableContains(cbtEA->strongAgainst, natureB);
    bool bStrongVersusA = tableContains(cbtEB->strongAgainst, natureA);

    if (aStrongVersusB) {
        cout << a->nom << " est fort contre " << b->nom << endl;
    }

    if (bStrongVersusA) {
        cout << b->nom << " est fort contre " << a->nom << endl;
    }


    // qui commence ? 1 chance sur 2
    bool aAttacks = true;
    if (rand() % 2 == 0) {
        aAttacks = false;
    }

    if (aAttacks) {
        cout << endl << a->nom << " commence !" << endl;
    }
    else {
        cout << endl << b->nom << " commence !" << endl;
    }

    const int baseDamage = 30;
    while (a->PV > 0 && b->PV > 0) {
        if (aAttacks) {
            int damage = (int)(baseDamage + (baseDamage * aStrongVersusB * 2));
            b->PV = b->PV - damage;
            cout << a->nom << " inflige " << damage << " points de dommage à " << b->nom << endl;
        }
        else {
            int damage = (int)(baseDamage + (baseDamage * bStrongVersusA * 2));
            a->PV = a->PV - damage;
            cout << b->nom << " inflige " << damage << " points de dommage à " << a->nom << endl;
        }

        // let's switch who attacks next round
        aAttacks = !aAttacks;
    }

    if (a->PV < 0) {
        cout << endl << b->nom << " wins !! " << endl;
        a->PV = 0; // les PVs du perdant ont pu passés en négatif.
    }
    else {
        cout << endl << a->nom << " wins !! " << endl;
        b->PV = 0; // les PVs du perdant ont pu passés en négatif.
    }

}

CombatHash* initCombatHash() {

    CombatHash* hashtable = new CombatHash;
    hashtable->size = 18;

    CombatEspece* bug = new CombatEspece;
    bug->nature = "Bug";
    bug->next = nullptr;
    bug->strongAgainst[0] = "Dark";
    bug->strongAgainst[1] = "Grass";
    bug->strongAgainst[2] = "Psychic";
    bug->weakAgainst[0] = "Fire";
    bug->weakAgainst[1] = "Flying";
    bug->weakAgainst[2] = "Rock";
    insert(bug, hashtable);

    CombatEspece* dark = new CombatEspece;
    dark->nature = "Dark";
    dark->next = nullptr;
    dark->strongAgainst[0] = "Ghost";
    dark->strongAgainst[1] = "Psychic";
    dark->weakAgainst[0] = "Bug";
    dark->weakAgainst[1] = "Fairy";
    dark->weakAgainst[2] = "Fight";
    insert(dark, hashtable);

    CombatEspece* dragon = new CombatEspece;
    dragon->nature = "Dragon";
    dragon->next = nullptr;
    dragon->strongAgainst[0] = "Dragon";
    dragon->weakAgainst[0] = "Dragon";
    dragon->weakAgainst[1] = "Fairy";
    dragon->weakAgainst[2] = "Ice";
    insert(dragon, hashtable);

    CombatEspece* electric = new CombatEspece;
    electric->nature = "Electric";
    electric->next = nullptr;
    electric->strongAgainst[0] = "Flying";
    electric->strongAgainst[1] = "Water";
    electric->weakAgainst[0] = "Ground";
    insert(electric, hashtable);

    CombatEspece* fairy = new CombatEspece;
    fairy->nature = "Fairy";
    fairy->next = nullptr;
    fairy->strongAgainst[0] = "Dark";
    fairy->strongAgainst[1] = "Dragon";
    fairy->strongAgainst[2] = "Fight";
    fairy->weakAgainst[0] = "Poison";
    fairy->weakAgainst[1] = "Steel";
    insert(fairy, hashtable);

    CombatEspece* fighting = new CombatEspece;
    fighting->nature = "Fighting";
    fighting->next = nullptr;
    fighting->strongAgainst[0] = "Dark";
    fighting->strongAgainst[1] = "Ice";
    fighting->strongAgainst[2] = "Normal";
    fighting->strongAgainst[3] = "Rock";
    fighting->strongAgainst[4] = "Steel";
    fighting->weakAgainst[0] = "Fairly";
    fighting->weakAgainst[1] = "Flying";
    fighting->weakAgainst[2] = "Psychic";
    insert(fighting, hashtable);

    CombatEspece* fire = new CombatEspece;
    fire->nature = "Fire";
    fire->next = nullptr;
    fire->strongAgainst[0] = "Bug";
    fire->strongAgainst[1] = "Grass";
    fire->strongAgainst[2] = "Ice";
    fire->strongAgainst[3] = "Steel";
    fire->weakAgainst[0] = "Ground";
    fire->weakAgainst[1] = "Rock";
    fire->weakAgainst[2] = "Water";
    insert(fire, hashtable);

    CombatEspece* flying = new CombatEspece;
    flying->nature = "Flying";
    flying->next = nullptr;
    flying->strongAgainst[0] = "Bug";
    flying->strongAgainst[1] = "Fight";
    flying->strongAgainst[2] = "Grass";
    flying->weakAgainst[0] = "Electric";
    flying->weakAgainst[1] = "Ice";
    flying->weakAgainst[2] = "Rock";
    insert(flying, hashtable);

    CombatEspece* ghost = new CombatEspece;
    ghost->nature = "Ghost";
    ghost->next = nullptr;
    ghost->strongAgainst[0] = "Ghost";
    ghost->strongAgainst[1] = "Psychic";
    ghost->weakAgainst[0] = "Dark";
    ghost->weakAgainst[1] = "Ghost";
    insert(ghost, hashtable);

    CombatEspece* grass = new CombatEspece;
    grass->nature = "Grass";
    grass->next = nullptr;
    grass->strongAgainst[0] = "Ground";
    grass->strongAgainst[1] = "Rock";
    grass->strongAgainst[2] = "Water";
    grass->weakAgainst[0] = "Bug";
    grass->weakAgainst[1] = "Fire";
    grass->weakAgainst[2] = "Flying";
    grass->weakAgainst[3] = "Ice";
    grass->weakAgainst[4] = "Poison";
    insert(grass, hashtable);

    CombatEspece* ground = new CombatEspece;
    ground->nature = "Ground";
    ground->next = nullptr;
    ground->strongAgainst[0] = "Electric";
    ground->strongAgainst[1] = "Fire";
    ground->strongAgainst[2] = "Poison";
    ground->strongAgainst[3] = "Rock";
    ground->strongAgainst[4] = "Steel";
    ground->weakAgainst[0] = "Grass";
    ground->weakAgainst[1] = "Ice";
    ground->weakAgainst[2] = "Water";
    insert(ground, hashtable);

    CombatEspece* ice = new CombatEspece;
    ice->nature = "Ice";
    ice->next = nullptr;
    ice->strongAgainst[0] = "Dragon";
    ice->strongAgainst[1] = "Flying";
    ice->strongAgainst[2] = "Grass";
    ice->strongAgainst[3] = "Ground";
    ice->weakAgainst[0] = "Fight";
    ice->weakAgainst[1] = "Fire";
    ice->weakAgainst[2] = "Rock";
    ice->weakAgainst[3] = "Steel";
    insert(ice, hashtable);

    CombatEspece* normal = new CombatEspece;
    normal->nature = "Normal";
    normal->next = nullptr;
    normal->weakAgainst[0] = "Fight";
    insert(normal, hashtable); // correction ici.

    CombatEspece* poison = new CombatEspece;
    poison->nature = "Poison";
    poison->next = nullptr;
    poison->strongAgainst[0] = "Fairy";
    poison->strongAgainst[1] = "Grass";
    poison->weakAgainst[0] = "Ground";
    poison->weakAgainst[1] = "Psychic";
    insert(poison, hashtable);

    CombatEspece* psychic = new CombatEspece;
    psychic->nature = "Psychic";
    psychic->next = nullptr;
    psychic->strongAgainst[0] = "Fight";
    psychic->strongAgainst[1] = "Poison";
    psychic->weakAgainst[0] = "Bug";
    psychic->weakAgainst[1] = "Dark";
    psychic->weakAgainst[2] = "Ghost";
    insert(psychic, hashtable);

    CombatEspece* rock = new CombatEspece;
    rock->nature = "Rock";
    rock->next = nullptr;
    rock->strongAgainst[0] = "Bug";
    rock->strongAgainst[1] = "Fire";
    rock->strongAgainst[2] = "Flying";
    rock->strongAgainst[3] = "Ice";
    rock->weakAgainst[0] = "Fight";
    rock->weakAgainst[1] = "Grass";
    rock->weakAgainst[2] = "Ground";
    rock->weakAgainst[3] = "Steel";
    rock->weakAgainst[3] = "Water";
    insert(rock, hashtable);

    CombatEspece* steel = new CombatEspece;
    steel->nature = "Steel";
    steel->next = nullptr;
    steel->strongAgainst[0] = "Fairy";
    steel->strongAgainst[1] = "Ice";
    steel->strongAgainst[2] = "Rock";
    steel->weakAgainst[0] = "Fight";
    steel->weakAgainst[1] = "Fire";
    steel->weakAgainst[2] = "Ground";
    insert(steel, hashtable);


    CombatEspece* water = new CombatEspece;
    water->nature = "Water";
    water->next = nullptr;
    water->strongAgainst[0] = "Fire";
    water->strongAgainst[1] = "Ground";
    water->strongAgainst[2] = "Rock";
    water->weakAgainst[0] = "Electric";
    water->weakAgainst[1] = "Grass";
    insert(water, hashtable);

    return hashtable;

}