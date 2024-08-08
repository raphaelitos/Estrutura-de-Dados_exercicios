#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashgen.h"

struct hash{
    tListaGen **vet;
    int tam;
};

static void asserto(int exp, char *msg){
    if(exp){
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}

tHash* cria (int tam, size_t tam_item){
    tHash *t = (tHash *)calloc(1, sizeof(tHash));
    asserto(!t, "falha na alocacao de hash");

    t->vet = (tListaGen**)calloc(tam, tam_item);
    for(int i = 0; i < tam; i++){
        t->vet[i] = NULL;
    }
    t->tam = tam;
    
    return t;
}

void libera(tHash* table){
    if(!table) return;
    free(table->vet);
    free(table);
}

tListaGen* busca (tHash* hash, void* key, int (*fhash)(void*), int (*comp)(void*,void*)){
    asserto(!hash, "hash nula em busca");

    int id = fhash(key) % hash->tam;

    return buscaListaGen(hash->vet[id], comp, key);
}

tListaGen* hash_insere (tHash* hash, void* key, tListaGen* objeto, int (*fhash)(void*), int(*comp)(void*,void*)){
    asserto(!hash, "hash nula em insere");

    int id = fhash(key) % hash->tam;

    if(buscaListaGen(hash->vet[id], comp, key)) return objeto;

    hash->vet[id] = insereListaGen(hash->vet[id], objeto);

    if(hash->vet[id]) return objeto;
    return NULL;
}

int getTamHash(tHash *table){
    asserto(!table, "hash nula em getVet");
    return table->tam;
}

tListaGen** getVetHash(tHash *table){
    asserto(!table, "hash nula em getTam");
    return table->vet;
}

void imprimeHashGen(tHash *t, void(*imprimeDado)(void*)){
    asserto(!t, "hash nula em imprime");
    for(int i = 0; i < t->tam; i++){
        if(t->vet[i]){
            printf("tabela[%d]\n", i);
            imprimeDado(t->vet[i]);
        }
    }
}