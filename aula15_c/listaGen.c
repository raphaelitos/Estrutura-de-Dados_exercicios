#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaGen.h"

struct listagen{
    void *info;
    tListaGen *prox;
};

tListaGen *criaListaGen(){
    /*tListaGen *g = NULL;
    return g;*/
    tListaGen *g = (tListaGen *)calloc(1, sizeof(tListaGen));
    if(!g)exit(EXIT_FAILURE);
    
    g->info = NULL;
    g->prox = NULL;

    return g;
}

void liberaListaGen(tListaGen *l, void(*liberaCelula)(void *dado)){
    tListaGen *aux = l, *pop;
    while(aux){
        pop = aux;
        aux = aux->prox;
        liberaCelula(aux->info);
        free(pop);
    }
}

tListaGen *insereListaGen(tListaGen *l, void *dado){
    tListaGen *nova = (tListaGen*)calloc(1, sizeof(tListaGen));
    if(!nova) exit(EXIT_FAILURE);
    nova->info = dado;
    nova->prox = l;

    return nova;
}

tListaGen *retiraListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado){
    tListaGen *aux = l, *pre = NULL;

    while(aux && cb(aux->info, dado)){
        pre = aux;
        aux = aux->prox;
    }
    if(!aux) return l;
    if(!pre){
        l = aux->prox;
    }
    pre->prox = aux->prox;
}

int percorreListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado){
    tListaGen *aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        if(!(cb(aux->info, dado))) return 0;
    }
    return 1;
}

void *buscaListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado){
    tListaGen *aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        if(!(cb(aux->info, dado))) return aux;
    }
    return NULL;
}