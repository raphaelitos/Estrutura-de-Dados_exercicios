#ifndef _HASHGEN_H_
#define _HASHGEN_H_

#include <stdlib.h>
#include "listaGen.h"

typedef struct hash tHash;

tHash* cria (int tam);

void libera(tHash* table);

tListaGen* busca (tHash* hash, void* key, int (*fhash)(void*), int (*comp)(void*,void*));

tListaGen* hash_insere (tHash* hash, void* key, tListaGen* objeto, int (*fhash)(void*), int(*comp)(void*,void*));

tListaGen** getVetHash(tHash *table);

int getTamHash(tHash *table);

void imprimeHashGen(tHash *t, void(*imprimeDado)(void*));

#endif 