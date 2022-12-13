#include "pokemon.h"
#include "pokemonTypes.h"
#include <string>
#include <iostream>
using namespace std;

void tri(EspecePokemon bestiaire[])
{
    int ch;
    cout << "1 : Affichage par ordre naturel" << endl;
    cout << "2 : Affichage par ordre alphabetique" << endl;
    cin >> ch;

    if (ch==2)
    {
        const char* temp;
        int i = 0;
        while (i < 150)
        {
            for (int k = 0; k < 150; k++)
            {
                if (strcmp(bestiaire[i].nom, bestiaire[k].nom) < 0)
                {
                    temp = bestiaire[i].nom;
                    bestiaire[i].nom = bestiaire[k].nom;
                    bestiaire[k].nom = temp;
                }
            }
            i++;
        }
    }
    
}

void AfficheBestiaire(EspecePokemon bestiaire[],const char* typesLabel[])
{
    int i = 0;
    cout << endl;
    tri(bestiaire);
    for (i = 0; i < 150; i++)
    {
        if (bestiaire[i].evolvesTo == nullptr)
        {
            cout << bestiaire[i].nom << "\n Type : " << typesLabel[bestiaire[i].type] << "\n Ne peut pas evoluer" << endl;

        }
        else
        {
            cout << bestiaire[i].nom << "\n Type : " << typesLabel[bestiaire[i].type] << "\n Nombre de bonbons pour evolve : " << bestiaire[i].nbBonbonsPourEvoluer << "\n Espece post-evolve : " << bestiaire[i].evolvesTo << endl;
        }
    }
}
int PokeToBestiaire(Pokemon* p, EspecePokemon bestiaire[])
{
    int i = 0;
    while (p->nom != bestiaire[i].nom)
    {
        i++;
    }
    return i;
}

EspecePokemon lookupEspecePokemon(EspecePokemon bestiaire[], const char* nom) {

    int i = 0;
    while (i < 150) {
        if (strcmp(bestiaire[i].nom, nom) == 0) {
            return bestiaire[i];
        }
        i++;
    }

    // si l'on n'a pas trouvé l'espèce recherchée, on renvoie une espèce fictive
    EspecePokemon e;
    e.nom = "UNKNOWN";
    e.type = Normal;
    e.nbBonbonsPourEvoluer = 0;
    e.evolvesTo = nullptr;
    return e;

}

void initBestiaire(EspecePokemon bestiaire[])
{
    bestiaire[0].nom = "Bulbasaur";
    bestiaire[0].type = Grass;
    bestiaire[0].nbBonbonsPourEvoluer = 25;
    bestiaire[0].evolvesTo = "Ivysaur";

    bestiaire[1].nom = "Ivysaur";
    bestiaire[1].type = Grass;
    bestiaire[1].nbBonbonsPourEvoluer = 100;
    bestiaire[1].evolvesTo = "Venusaur";

    bestiaire[2].nom = "Venusaur";
    bestiaire[2].type = Grass;
    bestiaire[2].nbBonbonsPourEvoluer = 0;
    bestiaire[2].evolvesTo = nullptr;

    bestiaire[3].nom = "Charmander";
    bestiaire[3].type = Fire;
    bestiaire[3].nbBonbonsPourEvoluer = 25;
    bestiaire[3].evolvesTo = "Charmeleon";

    bestiaire[4].nom = "Charmeleon";
    bestiaire[4].type = Fire;
    bestiaire[4].nbBonbonsPourEvoluer = 100;
    bestiaire[4].evolvesTo = "Charizard";

    bestiaire[5].nom = "Charizard";
    bestiaire[5].type = Fire;
    bestiaire[5].nbBonbonsPourEvoluer = 0;
    bestiaire[5].evolvesTo = nullptr;

    bestiaire[6].nom = "Squirtle";
    bestiaire[6].type = Water;
    bestiaire[6].nbBonbonsPourEvoluer = 25;
    bestiaire[6].evolvesTo = "Wartortle";

    bestiaire[7].nom = "Wartortle";
    bestiaire[7].type = Water;
    bestiaire[7].nbBonbonsPourEvoluer = 100;
    bestiaire[7].evolvesTo = "Blastoise";

    bestiaire[8].nom = "Blastoise";
    bestiaire[8].type = Water;
    bestiaire[8].nbBonbonsPourEvoluer = 0;
    bestiaire[8].evolvesTo = nullptr;

    bestiaire[9].nom = "Caterpie";
    bestiaire[9].type = Bug;
    bestiaire[9].nbBonbonsPourEvoluer = 12;
    bestiaire[9].evolvesTo = "Metapod";

    bestiaire[10].nom = "Metapod";
    bestiaire[10].type = Bug;
    bestiaire[10].nbBonbonsPourEvoluer = 50;
    bestiaire[10].evolvesTo = "Butterfree";

    bestiaire[11].nom = "Butterfree";
    bestiaire[11].type = Bug;
    bestiaire[11].nbBonbonsPourEvoluer = 0;
    bestiaire[11].evolvesTo = nullptr;

    bestiaire[12].nom = "Weedle";
    bestiaire[12].type = Bug;
    bestiaire[12].nbBonbonsPourEvoluer = 12;
    bestiaire[12].evolvesTo = "Kakuna";

    bestiaire[13].nom = "Kakuna";
    bestiaire[13].type = Bug;
    bestiaire[13].nbBonbonsPourEvoluer = 50;
    bestiaire[13].evolvesTo = "Beedrill";

    bestiaire[14].nom = "Beedrill";
    bestiaire[14].type = Bug;
    bestiaire[14].nbBonbonsPourEvoluer = 0;
    bestiaire[14].evolvesTo = nullptr;

    bestiaire[15].nom = "Pidgey";
    bestiaire[15].type = Normal;
    bestiaire[15].nbBonbonsPourEvoluer = 12;
    bestiaire[15].evolvesTo = "Pidgeotto";

    bestiaire[16].nom = "Pidgeotto";
    bestiaire[16].type = Normal;
    bestiaire[16].nbBonbonsPourEvoluer = 50;
    bestiaire[16].evolvesTo = "Pidgeot";

    bestiaire[17].nom = "Pidgeot";
    bestiaire[17].type = Normal;
    bestiaire[17].nbBonbonsPourEvoluer = 0;
    bestiaire[17].evolvesTo = nullptr;

    bestiaire[18].nom = "Rattata";
    bestiaire[18].type = Normal;
    bestiaire[18].nbBonbonsPourEvoluer = 25;
    bestiaire[18].evolvesTo = "Raticate";

    bestiaire[19].nom = "Raticate";
    bestiaire[19].type = Normal;
    bestiaire[19].nbBonbonsPourEvoluer = 0;
    bestiaire[19].evolvesTo = nullptr;

    bestiaire[20].nom = "Spearow";
    bestiaire[20].type = Normal;
    bestiaire[20].nbBonbonsPourEvoluer = 50;
    bestiaire[20].evolvesTo = "Fearow";

    bestiaire[21].nom = "Fearow";
    bestiaire[21].type = Normal;
    bestiaire[21].nbBonbonsPourEvoluer = 0;
    bestiaire[21].evolvesTo = nullptr;

    bestiaire[22].nom = "Ekans";
    bestiaire[22].type = Poison;
    bestiaire[22].nbBonbonsPourEvoluer = 50;
    bestiaire[22].evolvesTo = "Arbok";

    bestiaire[23].nom = "Arbok";
    bestiaire[23].type = Poison;
    bestiaire[23].nbBonbonsPourEvoluer = 0;
    bestiaire[23].evolvesTo = nullptr;

    bestiaire[24].nom = "Pikachu";
    bestiaire[24].type = Electric;
    bestiaire[24].nbBonbonsPourEvoluer = 50;
    bestiaire[24].evolvesTo = "Raichu";

    bestiaire[25].nom = "Raichu";
    bestiaire[25].type = Electric;
    bestiaire[25].nbBonbonsPourEvoluer = 0;
    bestiaire[25].evolvesTo = nullptr;

    bestiaire[26].nom = "Sandshrew";
    bestiaire[26].type = Ground;
    bestiaire[26].nbBonbonsPourEvoluer = 50;
    bestiaire[26].evolvesTo = "Sandslash";

    bestiaire[27].nom = "Sandslash";
    bestiaire[27].type = Ground;
    bestiaire[27].nbBonbonsPourEvoluer = 0;
    bestiaire[27].evolvesTo = nullptr;

    bestiaire[28].nom = "Nidoran♀";
    bestiaire[28].type = Poison;
    bestiaire[28].nbBonbonsPourEvoluer = 25;
    bestiaire[28].evolvesTo = "Nidorina";

    bestiaire[29].nom = "Nidorina";
    bestiaire[29].type = Poison;
    bestiaire[29].nbBonbonsPourEvoluer = 100;
    bestiaire[29].evolvesTo = "Nidoqueen";

    bestiaire[30].nom = "Nidoqueen";
    bestiaire[30].type = Poison;
    bestiaire[30].nbBonbonsPourEvoluer = 0;
    bestiaire[30].evolvesTo = nullptr;

    bestiaire[31].nom = "Nidoran♂";
    bestiaire[31].type = Poison;
    bestiaire[31].nbBonbonsPourEvoluer = 25;
    bestiaire[31].evolvesTo = "Nidorino";

    bestiaire[32].nom = "Nidorino";
    bestiaire[32].type = Poison;
    bestiaire[32].nbBonbonsPourEvoluer = 100;
    bestiaire[32].evolvesTo = "Nidoking";

    bestiaire[33].nom = "Nidoking";
    bestiaire[33].type = Poison;
    bestiaire[33].nbBonbonsPourEvoluer = 0;
    bestiaire[33].evolvesTo = nullptr;

    bestiaire[34].nom = "Clefairy";
    bestiaire[34].type = Normal;
    bestiaire[34].nbBonbonsPourEvoluer = 50;
    bestiaire[34].evolvesTo = "Clefable";

    bestiaire[35].nom = "Clefable";
    bestiaire[35].type = Normal;
    bestiaire[35].nbBonbonsPourEvoluer = 0;
    bestiaire[35].evolvesTo = nullptr;

    bestiaire[36].nom = "Vulpix";
    bestiaire[36].type = Fire;
    bestiaire[36].nbBonbonsPourEvoluer = 50;
    bestiaire[36].evolvesTo = "Ninetales";

    bestiaire[37].nom = "Ninetales";
    bestiaire[37].type = Fire;
    bestiaire[37].nbBonbonsPourEvoluer = 0;
    bestiaire[37].evolvesTo = nullptr;

    bestiaire[38].nom = "Jigglypuff";
    bestiaire[38].type = Normal;
    bestiaire[38].nbBonbonsPourEvoluer = 50;
    bestiaire[38].evolvesTo = "Wigglytuff";

    bestiaire[39].nom = "Wigglytuff";
    bestiaire[39].type = Normal;
    bestiaire[39].nbBonbonsPourEvoluer = 0;
    bestiaire[39].evolvesTo = nullptr;

    bestiaire[40].nom = "Zubat";
    bestiaire[40].type = Poison;
    bestiaire[40].nbBonbonsPourEvoluer = 50;
    bestiaire[40].evolvesTo = "Golbat";

    bestiaire[41].nom = "Golbat";
    bestiaire[41].type = Poison;
    bestiaire[41].nbBonbonsPourEvoluer = 0;
    bestiaire[41].evolvesTo = nullptr;

    bestiaire[42].nom = "Oddish";
    bestiaire[42].type = Grass;
    bestiaire[42].nbBonbonsPourEvoluer = 25;
    bestiaire[42].evolvesTo = "Gloom";

    bestiaire[43].nom = "Gloom";
    bestiaire[43].type = Grass;
    bestiaire[43].nbBonbonsPourEvoluer = 100;
    bestiaire[43].evolvesTo = "Vileplume";

    bestiaire[44].nom = "Vileplume";
    bestiaire[44].type = Grass;
    bestiaire[44].nbBonbonsPourEvoluer = 0;
    bestiaire[44].evolvesTo = nullptr;

    bestiaire[45].nom = "Paras";
    bestiaire[45].type = Bug;
    bestiaire[45].nbBonbonsPourEvoluer = 50;
    bestiaire[45].evolvesTo = "Parasect";

    bestiaire[46].nom = "Parasect";
    bestiaire[46].type = Bug;
    bestiaire[46].nbBonbonsPourEvoluer = 0;
    bestiaire[46].evolvesTo = nullptr;

    bestiaire[47].nom = "Venonat";
    bestiaire[47].type = Bug;
    bestiaire[47].nbBonbonsPourEvoluer = 50;
    bestiaire[47].evolvesTo = "Venomoth";

    bestiaire[48].nom = "Venomoth";
    bestiaire[48].type = Bug;
    bestiaire[48].nbBonbonsPourEvoluer = 0;
    bestiaire[48].evolvesTo = nullptr;

    bestiaire[49].nom = "Diglett";
    bestiaire[49].type = Ground;
    bestiaire[49].nbBonbonsPourEvoluer = 50;
    bestiaire[49].evolvesTo = "Dugtrio";

    bestiaire[50].nom = "Dugtrio";
    bestiaire[50].type = Ground;
    bestiaire[50].nbBonbonsPourEvoluer = 0;
    bestiaire[50].evolvesTo = nullptr;

    bestiaire[51].nom = "Meowth";
    bestiaire[51].type = Normal;
    bestiaire[51].nbBonbonsPourEvoluer = 50;
    bestiaire[51].evolvesTo = "Persian";

    bestiaire[52].nom = "Persian";
    bestiaire[52].type = Normal;
    bestiaire[52].nbBonbonsPourEvoluer = 0;
    bestiaire[52].evolvesTo = nullptr;

    bestiaire[53].nom = "Psyduck";
    bestiaire[53].type = Water;
    bestiaire[53].nbBonbonsPourEvoluer = 50;
    bestiaire[53].evolvesTo = "Golduck";

    bestiaire[54].nom = "Golduck";
    bestiaire[54].type = Water;
    bestiaire[54].nbBonbonsPourEvoluer = 0;
    bestiaire[54].evolvesTo = nullptr;

    bestiaire[55].nom = "Mankey";
    bestiaire[55].type = Fighting;
    bestiaire[55].nbBonbonsPourEvoluer = 50;
    bestiaire[55].evolvesTo = "Primeape";

    bestiaire[56].nom = "Primeape";
    bestiaire[56].type = Fighting;
    bestiaire[56].nbBonbonsPourEvoluer = 0;
    bestiaire[56].evolvesTo = nullptr;

    bestiaire[57].nom = "Growlithe";
    bestiaire[57].type = Fire;
    bestiaire[57].nbBonbonsPourEvoluer = 50;
    bestiaire[57].evolvesTo = "Arcanine";

    bestiaire[58].nom = "Arcanine";
    bestiaire[58].type = Fire;
    bestiaire[58].nbBonbonsPourEvoluer = 0;
    bestiaire[58].evolvesTo = nullptr;

    bestiaire[59].nom = "Poliwag";
    bestiaire[59].type = Water;
    bestiaire[59].nbBonbonsPourEvoluer = 25;
    bestiaire[59].evolvesTo = "Poliwhirl";

    bestiaire[60].nom = "Poliwhirl";
    bestiaire[60].type = Water;
    bestiaire[60].nbBonbonsPourEvoluer = 100;
    bestiaire[60].evolvesTo = "Poliwrath";

    bestiaire[61].nom = "Poliwrath";
    bestiaire[61].type = Water;
    bestiaire[61].nbBonbonsPourEvoluer = 0;
    bestiaire[61].evolvesTo = nullptr;

    bestiaire[62].nom = "Abra";
    bestiaire[62].type = Psychic;
    bestiaire[62].nbBonbonsPourEvoluer = 25;
    bestiaire[62].evolvesTo = "Kadabra";

    bestiaire[63].nom = "Kadabra";
    bestiaire[63].type = Psychic;
    bestiaire[63].nbBonbonsPourEvoluer = 100;
    bestiaire[63].evolvesTo = "Alakazam";

    bestiaire[64].nom = "Alakazam";
    bestiaire[64].type = Psychic;
    bestiaire[64].nbBonbonsPourEvoluer = 0;
    bestiaire[64].evolvesTo = nullptr;

    bestiaire[65].nom = "Machop";
    bestiaire[65].type = Fighting;
    bestiaire[65].nbBonbonsPourEvoluer = 25;
    bestiaire[65].evolvesTo = "Machoke";

    bestiaire[66].nom = "Machoke";
    bestiaire[66].type = Fighting;
    bestiaire[66].nbBonbonsPourEvoluer = 100;
    bestiaire[66].evolvesTo = "Machamp";

    bestiaire[67].nom = "Machamp";
    bestiaire[67].type = Fighting;
    bestiaire[67].nbBonbonsPourEvoluer = 0;
    bestiaire[67].evolvesTo = nullptr;

    bestiaire[68].nom = "Bellsprout";
    bestiaire[68].type = Grass;
    bestiaire[68].nbBonbonsPourEvoluer = 25;
    bestiaire[68].evolvesTo = "Weepinbell";

    bestiaire[69].nom = "Weepinbell";
    bestiaire[69].type = Grass;
    bestiaire[69].nbBonbonsPourEvoluer = 100;
    bestiaire[69].evolvesTo = "Victreebel";

    bestiaire[70].nom = "Victreebel";
    bestiaire[70].type = Grass;
    bestiaire[70].nbBonbonsPourEvoluer = 0;
    bestiaire[70].evolvesTo = nullptr;

    bestiaire[71].nom = "Tentacool";
    bestiaire[71].type = Water;
    bestiaire[71].nbBonbonsPourEvoluer = 50;
    bestiaire[71].evolvesTo = "Tentacruel";

    bestiaire[72].nom = "Tentacruel";
    bestiaire[72].type = Water;
    bestiaire[72].nbBonbonsPourEvoluer = 0;
    bestiaire[72].evolvesTo = nullptr;

    bestiaire[73].nom = "Geodude";
    bestiaire[73].type = Rock;
    bestiaire[73].nbBonbonsPourEvoluer = 25;
    bestiaire[73].evolvesTo = "Graveler";

    bestiaire[74].nom = "Graveler";
    bestiaire[74].type = Rock;
    bestiaire[74].nbBonbonsPourEvoluer = 100;
    bestiaire[74].evolvesTo = "Golem";

    bestiaire[75].nom = "Golem";
    bestiaire[75].type = Rock;
    bestiaire[75].nbBonbonsPourEvoluer = 0;
    bestiaire[75].evolvesTo = nullptr;

    bestiaire[76].nom = "Ponyta";
    bestiaire[76].type = Fire;
    bestiaire[76].nbBonbonsPourEvoluer = 50;
    bestiaire[76].evolvesTo = "Rapidash";

    bestiaire[77].nom = "Rapidash";
    bestiaire[77].type = Fire;
    bestiaire[77].nbBonbonsPourEvoluer = 0;
    bestiaire[77].evolvesTo = nullptr;

    bestiaire[78].nom = "Slowpoke";
    bestiaire[78].type = Water;
    bestiaire[78].nbBonbonsPourEvoluer = 50;
    bestiaire[78].evolvesTo = "Slowbro";

    bestiaire[79].nom = "Slowbro";
    bestiaire[79].type = Water;
    bestiaire[79].nbBonbonsPourEvoluer = 0;
    bestiaire[79].evolvesTo = nullptr;

    bestiaire[80].nom = "Magnemite";
    bestiaire[80].type = Electric;
    bestiaire[80].nbBonbonsPourEvoluer = 50;
    bestiaire[80].evolvesTo = "Magneton";

    bestiaire[81].nom = "Magneton";
    bestiaire[81].type = Electric;
    bestiaire[81].nbBonbonsPourEvoluer = 0;
    bestiaire[81].evolvesTo = nullptr;

    bestiaire[82].nom = "Farfetch'd";
    bestiaire[82].type = Normal;
    bestiaire[82].nbBonbonsPourEvoluer = 0;
    bestiaire[82].evolvesTo = nullptr;

    bestiaire[83].nom = "Doduo";
    bestiaire[83].type = Normal;
    bestiaire[83].nbBonbonsPourEvoluer = 50;
    bestiaire[83].evolvesTo = "Dodrio";

    bestiaire[84].nom = "Dodrio";
    bestiaire[84].type = Normal;
    bestiaire[84].nbBonbonsPourEvoluer = 0;
    bestiaire[84].evolvesTo = nullptr;

    bestiaire[85].nom = "Seel";
    bestiaire[85].type = Water;
    bestiaire[85].nbBonbonsPourEvoluer = 50;
    bestiaire[85].evolvesTo = "Dewgong";

    bestiaire[86].nom = "Dewgong";
    bestiaire[86].type = Water;
    bestiaire[86].nbBonbonsPourEvoluer = 0;
    bestiaire[86].evolvesTo = nullptr;

    bestiaire[87].nom = "Grimer";
    bestiaire[87].type = Poison;
    bestiaire[87].nbBonbonsPourEvoluer = 50;
    bestiaire[87].evolvesTo = "Muk";

    bestiaire[88].nom = "Muk";
    bestiaire[88].type = Poison;
    bestiaire[88].nbBonbonsPourEvoluer = 0;
    bestiaire[88].evolvesTo = nullptr;

    bestiaire[89].nom = "Shellder";
    bestiaire[89].type = Water;
    bestiaire[89].nbBonbonsPourEvoluer = 50;
    bestiaire[89].evolvesTo = "Cloyster";

    bestiaire[90].nom = "Cloyster";
    bestiaire[90].type = Water;
    bestiaire[90].nbBonbonsPourEvoluer = 0;
    bestiaire[90].evolvesTo = nullptr;

    bestiaire[91].nom = "Gastly";
    bestiaire[91].type = Ghost;
    bestiaire[91].nbBonbonsPourEvoluer = 25;
    bestiaire[91].evolvesTo = "Haunter";

    bestiaire[92].nom = "Haunter";
    bestiaire[92].type = Ghost;
    bestiaire[92].nbBonbonsPourEvoluer = 100;
    bestiaire[92].evolvesTo = "Haunter";

    bestiaire[93].nom = "Gengar";
    bestiaire[93].type = Ghost;
    bestiaire[93].nbBonbonsPourEvoluer = 0;
    bestiaire[93].evolvesTo = nullptr;

    bestiaire[94].nom = "Onix";
    bestiaire[94].type = Rock;
    bestiaire[94].nbBonbonsPourEvoluer = 0;
    bestiaire[94].evolvesTo = nullptr;

    bestiaire[95].nom = "Drowzee";
    bestiaire[95].type = Psychic;
    bestiaire[95].nbBonbonsPourEvoluer = 50;
    bestiaire[95].evolvesTo = "Hypno";

    bestiaire[96].nom = "Hypno";
    bestiaire[96].type = Psychic;
    bestiaire[96].nbBonbonsPourEvoluer = 0;
    bestiaire[96].evolvesTo = nullptr;

    bestiaire[97].nom = "Krabby";
    bestiaire[97].type = Water;
    bestiaire[97].nbBonbonsPourEvoluer = 50;
    bestiaire[97].evolvesTo = "Kingler";

    bestiaire[98].nom = "Kingler";
    bestiaire[98].type = Water;
    bestiaire[98].nbBonbonsPourEvoluer = 0;
    bestiaire[98].evolvesTo = nullptr;

    bestiaire[99].nom = "Voltorb";
    bestiaire[99].type = Electric;
    bestiaire[99].nbBonbonsPourEvoluer = 50;
    bestiaire[99].evolvesTo = "Electrode";

    bestiaire[100].nom = "Electrode";
    bestiaire[100].type = Electric;
    bestiaire[100].nbBonbonsPourEvoluer = 0;
    bestiaire[100].evolvesTo = nullptr;

    bestiaire[101].nom = "Exeggcute";
    bestiaire[101].type = Grass;
    bestiaire[101].nbBonbonsPourEvoluer = 50;
    bestiaire[101].evolvesTo = "Exeggcutor";

    bestiaire[102].nom = "Exeggcutor";
    bestiaire[102].type = Grass;
    bestiaire[102].nbBonbonsPourEvoluer = 0;
    bestiaire[102].evolvesTo = nullptr;

    bestiaire[103].nom = "Cubone";
    bestiaire[103].type = Ground;
    bestiaire[103].nbBonbonsPourEvoluer = 50;
    bestiaire[103].evolvesTo = "Marowak";

    bestiaire[104].nom = "Marowak";
    bestiaire[104].type = Ground;
    bestiaire[104].nbBonbonsPourEvoluer = 0;
    bestiaire[104].evolvesTo = nullptr;

    bestiaire[105].nom = "Hitmonlee";
    bestiaire[105].type = Fighting;
    bestiaire[105].nbBonbonsPourEvoluer = 0;
    bestiaire[105].evolvesTo = nullptr;

    bestiaire[106].nom = "Hitmonchan";
    bestiaire[106].type = Fighting;
    bestiaire[106].nbBonbonsPourEvoluer = 0;
    bestiaire[106].evolvesTo = nullptr;

    bestiaire[107].nom = "Lickitung";
    bestiaire[107].type = Normal;
    bestiaire[107].nbBonbonsPourEvoluer = 0;
    bestiaire[107].evolvesTo = nullptr;

    bestiaire[108].nom = "Koffing";
    bestiaire[108].type = Poison;
    bestiaire[108].nbBonbonsPourEvoluer = 50;
    bestiaire[108].evolvesTo = "Weezing";

    bestiaire[109].nom = "Weezing";
    bestiaire[109].type = Poison;
    bestiaire[109].nbBonbonsPourEvoluer = 0;
    bestiaire[109].evolvesTo = nullptr;

    bestiaire[110].nom = "Rhyhorn";
    bestiaire[110].type = Ground;
    bestiaire[110].nbBonbonsPourEvoluer = 50;
    bestiaire[110].evolvesTo = "Rhydon";

    bestiaire[111].nom = "Rhydon";
    bestiaire[111].type = Ground;
    bestiaire[111].nbBonbonsPourEvoluer = 0;
    bestiaire[111].evolvesTo = nullptr;

    bestiaire[112].nom = "Chansey";
    bestiaire[112].type = Normal;
    bestiaire[112].nbBonbonsPourEvoluer = 0;
    bestiaire[112].evolvesTo = nullptr;

    bestiaire[113].nom = "Tangela";
    bestiaire[113].type = Grass;
    bestiaire[113].nbBonbonsPourEvoluer = 0;
    bestiaire[113].evolvesTo = nullptr;

    bestiaire[114].nom = "Kangaskhan";
    bestiaire[114].type = Normal;
    bestiaire[114].nbBonbonsPourEvoluer = 0;
    bestiaire[114].evolvesTo = nullptr;

    bestiaire[115].nom = "Horsea";
    bestiaire[115].type = Water;
    bestiaire[115].nbBonbonsPourEvoluer = 50;
    bestiaire[115].evolvesTo = "Seadra";

    bestiaire[116].nom = "Seadra";
    bestiaire[116].type = Water;
    bestiaire[116].nbBonbonsPourEvoluer = 0;
    bestiaire[116].evolvesTo = nullptr;

    bestiaire[117].nom = "Goldeen";
    bestiaire[117].type = Water;
    bestiaire[117].nbBonbonsPourEvoluer = 50;
    bestiaire[117].evolvesTo = "Seaking";

    bestiaire[118].nom = "Seaking";
    bestiaire[118].type = Water;
    bestiaire[118].nbBonbonsPourEvoluer = 0;
    bestiaire[118].evolvesTo = nullptr;

    bestiaire[119].nom = "Staryu";
    bestiaire[119].type = Water;
    bestiaire[119].nbBonbonsPourEvoluer = 50;
    bestiaire[119].evolvesTo = "Starmie";

    bestiaire[120].nom = "Starmie";
    bestiaire[120].type = Water;
    bestiaire[120].nbBonbonsPourEvoluer = 0;
    bestiaire[120].evolvesTo = nullptr;

    bestiaire[121].nom = "Mr.Mime";
    bestiaire[121].type = Psychic;
    bestiaire[121].nbBonbonsPourEvoluer = 0;
    bestiaire[121].evolvesTo = nullptr;

    bestiaire[122].nom = "Scyther";
    bestiaire[122].type = Bug;
    bestiaire[122].nbBonbonsPourEvoluer = 0;
    bestiaire[122].evolvesTo = nullptr;

    bestiaire[123].nom = "Jynx";
    bestiaire[123].type = Ice;
    bestiaire[123].nbBonbonsPourEvoluer = 0;
    bestiaire[123].evolvesTo = nullptr;

    bestiaire[124].nom = "Electabuzz";
    bestiaire[124].type = Electric;
    bestiaire[124].nbBonbonsPourEvoluer = 0;
    bestiaire[124].evolvesTo = nullptr;

    bestiaire[125].nom = "Magmar";
    bestiaire[125].type = Fire;
    bestiaire[125].nbBonbonsPourEvoluer = 0;
    bestiaire[125].evolvesTo = nullptr;

    bestiaire[126].nom = "Pinsir";
    bestiaire[126].type = Bug;
    bestiaire[126].nbBonbonsPourEvoluer = 0;
    bestiaire[126].evolvesTo = nullptr;

    bestiaire[127].nom = "Tauros";
    bestiaire[127].type = Normal;
    bestiaire[127].nbBonbonsPourEvoluer = 0;
    bestiaire[127].evolvesTo = nullptr;

    bestiaire[128].nom = "Magikarp";
    bestiaire[128].type = Water;
    bestiaire[128].nbBonbonsPourEvoluer = 400;
    bestiaire[128].evolvesTo = "Gyarados";

    bestiaire[129].nom = "Gyarados";
    bestiaire[129].type = Water;
    bestiaire[129].nbBonbonsPourEvoluer = 0;
    bestiaire[129].evolvesTo = nullptr;

    bestiaire[130].nom = "Lapras";
    bestiaire[130].type = Water;
    bestiaire[130].nbBonbonsPourEvoluer = 0;
    bestiaire[130].evolvesTo = nullptr;

    bestiaire[131].nom = "Ditto";
    bestiaire[131].type = Normal;
    bestiaire[131].nbBonbonsPourEvoluer = 0;
    bestiaire[131].evolvesTo = nullptr;

    bestiaire[132].nom = "Eevee";
    bestiaire[132].type = Normal;
    bestiaire[132].nbBonbonsPourEvoluer = 25;
    bestiaire[132].evolvesTo = "Vaporeon, Jolteon or Flareon (random chance)";

    bestiaire[133].nom = "Vaporeon";
    bestiaire[133].type = Water;
    bestiaire[133].nbBonbonsPourEvoluer = 0;
    bestiaire[133].evolvesTo = nullptr;

    bestiaire[134].nom = "Jolteon";
    bestiaire[134].type = Electric;
    bestiaire[134].nbBonbonsPourEvoluer = 0;
    bestiaire[134].evolvesTo = nullptr;

    bestiaire[135].nom = "Flareon";
    bestiaire[135].type = Fire;
    bestiaire[135].nbBonbonsPourEvoluer = 0;
    bestiaire[135].evolvesTo = nullptr;

    bestiaire[136].nom = "Porygon";
    bestiaire[136].type = Normal;
    bestiaire[136].nbBonbonsPourEvoluer = 0;
    bestiaire[136].evolvesTo = nullptr;

    bestiaire[137].nom = "Omanyte";
    bestiaire[137].type = Rock;
    bestiaire[137].nbBonbonsPourEvoluer = 50;
    bestiaire[137].evolvesTo = "Omastar";

    bestiaire[138].nom = "Omastar";
    bestiaire[138].type = Rock;
    bestiaire[138].nbBonbonsPourEvoluer = 0;
    bestiaire[138].evolvesTo = nullptr;

    bestiaire[139].nom = "Kabuto";
    bestiaire[139].type = Rock;
    bestiaire[139].nbBonbonsPourEvoluer = 50;
    bestiaire[139].evolvesTo = "Kabutops";

    bestiaire[140].nom = "Kabutops";
    bestiaire[140].type = Rock;
    bestiaire[140].nbBonbonsPourEvoluer = 0;
    bestiaire[140].evolvesTo = nullptr;

    bestiaire[141].nom = "Aerodactyl";
    bestiaire[141].type = Rock;
    bestiaire[141].nbBonbonsPourEvoluer = 0;
    bestiaire[141].evolvesTo = nullptr;

    bestiaire[142].nom = "Snorlax";
    bestiaire[142].type = Normal;
    bestiaire[142].nbBonbonsPourEvoluer = 0;
    bestiaire[142].evolvesTo = nullptr;

    bestiaire[143].nom = "Articuno";
    bestiaire[143].type = Ice;
    bestiaire[143].nbBonbonsPourEvoluer = 0;
    bestiaire[143].evolvesTo = nullptr;

    bestiaire[144].nom = "Zapdos";
    bestiaire[144].type = Electric;
    bestiaire[144].nbBonbonsPourEvoluer = 0;
    bestiaire[144].evolvesTo = nullptr;

    bestiaire[145].nom = "Moltres";
    bestiaire[145].type = Fire;
    bestiaire[145].nbBonbonsPourEvoluer = 0;
    bestiaire[145].evolvesTo = nullptr;

    bestiaire[146].nom = "Dratini";
    bestiaire[146].type = Dragon;
    bestiaire[146].nbBonbonsPourEvoluer = 25;
    bestiaire[146].evolvesTo = "Dragonair";

    bestiaire[147].nom = "Dragonair";
    bestiaire[147].type = Dragon;
    bestiaire[147].nbBonbonsPourEvoluer = 100;
    bestiaire[147].evolvesTo = "Dragonite";

    bestiaire[148].nom = "Dragonite";
    bestiaire[148].type = Dragon;
    bestiaire[148].nbBonbonsPourEvoluer = 0;
    bestiaire[148].evolvesTo = nullptr;

    bestiaire[149].nom = "Mewtwo";
    bestiaire[149].type = Psychic;
    bestiaire[149].nbBonbonsPourEvoluer = 0;
    bestiaire[149].evolvesTo = nullptr;

    for (int i = 0; i < 150; i++) {
        bestiaire[i].estEvolue = true;
    }
    bestiaire[0].estEvolue = 0;
    bestiaire[3].estEvolue = 0;
    bestiaire[6].estEvolue = 0;
    bestiaire[9].estEvolue = 0;
    bestiaire[12].estEvolue = 0;
    bestiaire[15].estEvolue = 0;
    bestiaire[18].estEvolue = 0;
    bestiaire[20].estEvolue = 0;
    bestiaire[22].estEvolue = 0;
    bestiaire[24].estEvolue = 0;
    bestiaire[26].estEvolue = 0;
    bestiaire[28].estEvolue = 0;
    bestiaire[31].estEvolue = 0;
    bestiaire[34].estEvolue = 0;
    bestiaire[36].estEvolue = 0;
    bestiaire[38].estEvolue = 0;
    bestiaire[40].estEvolue = 0;
    bestiaire[42].estEvolue = 0;
    bestiaire[45].estEvolue = 0;
    bestiaire[47].estEvolue = 0;
    bestiaire[49].estEvolue = 0;
    bestiaire[51].estEvolue = 0;
    bestiaire[53].estEvolue = 0;
    bestiaire[55].estEvolue = 0;
    bestiaire[57].estEvolue = 0;
    bestiaire[59].estEvolue = 0;
    bestiaire[62].estEvolue = 0;
    bestiaire[65].estEvolue = 0;
    bestiaire[68].estEvolue = 0;
    bestiaire[71].estEvolue = 0;
    bestiaire[73].estEvolue = 0;
    bestiaire[76].estEvolue = 0;
    bestiaire[78].estEvolue = 0;
    bestiaire[80].estEvolue = 0;
    bestiaire[82].estEvolue = 0;
    bestiaire[83].estEvolue = 0;
    bestiaire[107].estEvolue = 0;
    bestiaire[108].estEvolue = 0;
    bestiaire[110].estEvolue = 0;
    bestiaire[112].estEvolue = 0;
    bestiaire[113].estEvolue = 0;
    bestiaire[114].estEvolue = 0;
    bestiaire[115].estEvolue = 0;
    bestiaire[117].estEvolue = 0;
    bestiaire[119].estEvolue = 0;
    bestiaire[121].estEvolue = 0;
    bestiaire[122].estEvolue = 0;
    bestiaire[123].estEvolue = 0;
    bestiaire[124].estEvolue = 0;
    bestiaire[125].estEvolue = 0;
    bestiaire[126].estEvolue = 0;
    bestiaire[127].estEvolue = 0;
    bestiaire[128].estEvolue = 0;
    bestiaire[130].estEvolue = 0;
    bestiaire[131].estEvolue = 0;
    bestiaire[132].estEvolue = 0;
    bestiaire[136].estEvolue = 0;
    bestiaire[137].estEvolue = 0;
    bestiaire[139].estEvolue = 0;
    bestiaire[141].estEvolue = 0;
    bestiaire[142].estEvolue = 0;
    bestiaire[143].estEvolue = 0;
    bestiaire[144].estEvolue = 0;
    bestiaire[145].estEvolue = 0;
    bestiaire[146].estEvolue = 0;
    bestiaire[149].estEvolue = 0;
}