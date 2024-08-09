#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaGen.h"

struct listagen{
    void *info;
    tListaGen *prox;
};

tListaGen *criaListaGen(void *info){
    tListaGen *g = (tListaGen *)calloc(1, sizeof(tListaGen));
    if(!g)exit(EXIT_FAILURE);
    
    g->info = info;
    g->prox = NULL;

    return g;
}

void liberaListaGen(tListaGen *l, void(*liberaCelula)(void *dado)){
    tListaGen *aux = l, *pop;
    while(aux){
        pop = aux;
        aux = aux->prox;
        liberaCelula(pop->info);
        free(pop);
    }
}

tListaGen *insereListaGen(tListaGen *l, tListaGen *dado){
    if(!dado){
        printf("dado invalido em insereListaGen");
        exit(EXIT_FAILURE);
    }
    if(dado->prox){
        printf("dado pra insercao ja e' uma lista\n");
        exit(EXIT_FAILURE);
    }
    dado->prox = l;
    return dado;
}

tListaGen *retiraListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado, void(*liberaCelula)(void *dado)){
    tListaGen *aux = l, *pre = NULL;

    while(aux && cb(aux->info, dado)){
        pre = aux;
        aux = aux->prox;
    }
    if(!aux) return l;
    if(!pre){
        l = aux->prox;
    }
    else{
        pre->prox = aux->prox;
    }
    liberaCelula(aux->info);
    free(aux);

    return l;
}

int percorreListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado){
    tListaGen *aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        if(!(cb(aux->info, dado))) return 0;
    }
    return 1;
}

tListaGen *buscaListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado){
    tListaGen *aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        if(!(cb(aux->info, dado))){
            return aux;
        }
    }
    return NULL;
}