//FEITO POR RAPHAEL CORREIA DORNELAS
#ifndef _PALAVRA_H_
#define _PALAVRA_H_

#include <stdlib.h>

typedef struct palavra tPalavra;

void assert(int exp, char *msg);

tPalavra *criaPalavra(char *str);

void liberaPalavra(tPalavra *p);

void imprimePalavra(tPalavra *p, FILE *arq);

void incFreqPalavra(tPalavra *p);

char *getStrPalavra(tPalavra *p);

int getFreqPalavra(tPalavra *p);

#endif