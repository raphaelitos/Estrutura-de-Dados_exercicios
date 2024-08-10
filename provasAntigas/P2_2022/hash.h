#ifndef _HASH_H_
#define _HASH_H_

#include "aluno.h"

typedef struct hash tHash;

tHash *criaHash(int tam);

void liberaHash(tHash *h);

void imprimeHash(tHash *h);

tALuno *acessaHash(tHash *h, char *nome);

tALuno *insereHash( tHash *h, tALuno *a);

#endif