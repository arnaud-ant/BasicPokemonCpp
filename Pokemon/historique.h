#pragma once

typedef struct Evolution {
	const char* nomav;
	const char* nomap;
	Evolution* prochain;
};


typedef struct {
	int nombre;
	Evolution* debut;
} historique;

historique* initHisto(void);
void insertHisto(historique* histo, Evolution* evo);
void afficheHisto(historique* histo);
