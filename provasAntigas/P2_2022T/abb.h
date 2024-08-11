#ifndef _ABB_H_
#define _ABB_H_

#include "palavra.h"

typedef struct abb tAbb;

tAbb *criaAbb();

void liberaAbb(tAbb *abb);

void imprimeAbb(tAbb *abb);

tAbb *insereAbb(tAbb *abb, char *str);

void getInfoAbb(tAbb *abb, int *index, tPalavra **vet, int tam);

int tamAbb(tAbb *abb);

int qtdFrequenciasAbb(tAbb *abb);

tPalavra *getPalavraAbb(tAbb *abb);

void PalavraMaisFreqAbb(tAbb *abb, tPalavra **max);

#endif