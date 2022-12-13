#include "pokemon.h"
#include "pokemonTypes.h"
#include "bestiaire.h"
#include "Pokedex.h"
#include "historique.h"
#include "combat.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main()
{
	cout << "                                   .::.                            " << endl;
	cout << "                                 .;:**'                            " << endl;
	cout << "                                 `                                 " << endl;
	cout << "     .:XHHHHk.              db.   .;;.     dH  MX                  " << endl;
	cout << "   oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN       " << endl;
	cout << "   QMMMMMb  \"MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM  " << endl;
	cout << "     `MMMM.  )M> :X!Hk. MMMM   XMM.o\"  .  MMMMMMM X?XMMM MMM>!MMP  " << endl;
	cout << "      'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `\" MX MMXXMM   " << endl;
	cout << "       ~MMMMM~ XMM. .XM XM`\"MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP   " << endl;
	cout << "        ?MMM>  YMMMMMM! MM   `?MMRb.    `\"\"\"   !L\"MMMMM XM IMMM    " << endl;
	cout << "         MMMX   \"MMMM\"  MM       ~%:           !Mh.\"\"\" dMI IMMP    " << endl;
	cout << "         'MMM.                                             IMX     " << endl;
	cout << "          ~M!M                                             IMP     " << endl << endl;

	srand(time(NULL));
	//CombatHash* hashtabl = initCombatHash();
	Ressource* rss = initRss();
	Pokedex* monPokedex= initPokedex(3);
	historique* histo = initHisto();
	const char* swap[18] = { "Normal","Fighting","Flying","Poison","Ground","Rock","Bug","Ghost","Steel","Fire","Grass","Water","Electric","Psychic","Ice","Dragon","Dark","Fairy" };
	EspecePokemon bestiaire[150];
	Pokemon tmp;
	int i;
	Pokemon a,b;
	a.nom = "Dratini";
	a.xp = 1;
	a.CP = 4;
	a.evo = 1;
	a.PV = 23;
	insertionPokemon(monPokedex, a);
	b.nom = "Kabuto";
	b.xp = 1;
	b.CP = 4;
	b.evo = 1;
	b.PV = 23;
	insertionPokemon(monPokedex, b);
	int choix = 7;
	do
	{
		AfficheMenu();
		Evolution* evol = new Evolution;
		evol->prochain = NULL;
		initBestiaire(bestiaire);
		cin >> choix;
		switch (choix)
		{
		case 1:	AfficheBestiaire(bestiaire,swap);
			break;
		case 2:	displayPokedex(monPokedex, bestiaire, swap, rss);
			break;
		case 3: genererPokemon(bestiaire, swap, monPokedex, rss);
			break;
		case 4: cout << "Power-up" << endl;
			displayPokedex(monPokedex, bestiaire, swap, rss);
			i = choixpoke(monPokedex);
			if (i!=-1)
			{
				tmp = monPokedex->mesPokemons[i];
				powerup(&tmp, rss);
				monPokedex->mesPokemons[i] = tmp;
			}
			break;
		case 5: cout << "Evolve" << endl;
			displayPokedex(monPokedex, bestiaire, swap, rss);
			i = choixpoke(monPokedex);
			if (i != -1)
			{

				tmp = monPokedex->mesPokemons[i];
				evol->nomav = tmp.nom;
				evolve(&tmp, rss, bestiaire);
				monPokedex->mesPokemons[i] = tmp;
				evol->nomap = tmp.nom;
				insertHisto(histo, evol);
			}
			break;
		case 6: cout << "Combat" << endl;
			displayPokedex(monPokedex, bestiaire, swap, rss);
		//	fight(hashtabl, monPokedex, bestiaire);
			break;
		case 7: cout << "Historique" << endl;
			if (histo->nombre!=0)
			{
				afficheHisto(histo);
			}
			else
			{
				cout << "\nPas d'evolution depuis le debut du jeu" << endl;
			}
			break;
		case 8: cout << "Quitter" << endl;
			break;
		default: cout << "Choisir un nombre entre 1 et 8" << endl;
			break;
		}
	} while (choix != 8);
	delete rss;
	delete monPokedex;
	delete histo;
	return 0;
}