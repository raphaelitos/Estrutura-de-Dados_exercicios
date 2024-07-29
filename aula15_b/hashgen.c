#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashgen.h"

struct hash{
    void **vet;
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

    t->vet = (void**)calloc(tam, tam_item);
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

void* busca (tHash* hash, void* key, int (*fhash)(void*), int (*comp)(void*,void*)){
    asserto(!hash, "hash nula em busca");

    int id = fhash(key) % hash->tam;
    
    if(comp(hash->vet[id], key)) return hash->vet[id];

    for(int i = id; i < hash->tam; i++){
        if(comp(hash->vet[i], key)) return hash->vet[i];
    }
    for(int i = 0; i < id; i++){
        if(comp(hash->vet[i], key)) return hash->vet[i];
    }

    return NULL;
}

void* hash_insere (tHash* hash, void* key, void* objeto, int (*fhash)(void*), int(*comp)(void*,void*)){
    asserto(!hash, "hash nula em insere");

    int id = fhash(key);

    if(comp(hash->vet[id], key)) return objeto;

    for(int i = id; i < hash->tam; i++){
        if(!hash->vet[i]){
            hash->vet[i] = objeto;
            return objeto;
        }
    }
    
    for(int i = 0; i < id; i++){
        if(!hash->vet[i]){
            hash->vet[i] = objeto;
            return objeto;
        }
    }
    
    printf("nao foi possivel inserir o elemento na tabela\n");
    return NULL;
}

int getTamHash(tHash *table){
    asserto(!table, "hash nula em getVet");
    return table->tam;
}

void** getVetHash(tHash *table){
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