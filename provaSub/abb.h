//FEITO POR RAPHAEL CORREIA DORNELAS
#ifndef _ABB_H_
#define _ABB_H_

#include "palavra.h"

typedef struct abb tAbb;

tAbb *criaAbb();

void liberaAbb(tAbb *abb);

tAbb *insereAbb(tAbb *abb, char *str);

int qtdPlvAbb(tAbb *abb);

int somaFreqAbb(tAbb *abb);

void maxFreqPlvAbb(tAbb *abb, tPalavra **max);

tPalavra *getPlvAbb(tAbb *abb);

void getInfoAbb(tAbb *abb, tPalavra **vet, int *index);

#endif