#ifndef _HASH_H_
#define _HASH_H_

typedef struct hash tHash;

#include "pais.h"

tHash *criaHash(int tam);

void liberaHash(tHash *h);

tPais *acessa(tHash *h, tPais *p);

tPais **dumpVet(tHash *);

void imprimeHash(tHash *h);

int getQtdPaisesHash(tHash *h);

void imprimeArqHash(tHash *h, FILE *arq);

#endif