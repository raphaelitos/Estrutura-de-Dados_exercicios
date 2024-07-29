#ifndef _HASHGEN_H_
#define _HASHGEN_H_

typedef struct hash tHash;

#include <stdlib.h>

tHash* cria (int tam, size_t tam_item);

void libera(tHash* table);

void* busca (tHash* hash, void* key, int (*fhash)(void*), int (*comp)(void*,void*));

void* hash_insere (tHash* hash, void* key, void* objeto, int (*fhash)(void*), int(*comp)(void*,void*));

void** getVetHash(tHash *table);

int getTamHash(tHash *table);

void imprimeHashGen(tHash *t, void(*imprimeDado)(void*));

#endif 