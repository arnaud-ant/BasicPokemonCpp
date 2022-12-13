#include "historique.h"

#include <iostream>

using namespace std;

void insertHisto(historique* histo, Evolution* evo)
{
		evo->prochain = histo->debut;
		histo->debut = evo;
		histo->nombre += 1;
}

historique* initHisto(void)
{
	historique* histo = new historique;
	histo->nombre = 0;
	histo->debut = NULL;
	return histo;
}

void afficheHisto(historique* histo)
{
	Evolution* temp = new Evolution;
	temp = histo->debut;

	for (int i = 0; i < histo->nombre; i++)
	{
		cout << temp->nomav << " | " << temp->nomap << endl;
		temp = temp->prochain;
	}
}