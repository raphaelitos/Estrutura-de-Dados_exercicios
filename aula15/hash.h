#ifndef _HASH_H_
#define _HASH_H_

#include "palavra.h"

typedef struct hash tHash;

tHash *criaHash(int tam);

void liberaHash(tHash *t);

void imprimeHash(tHash *t);

tPalavra* acessa(tHash *t, char *str);

int getTamHash(tHash *t);

#endif