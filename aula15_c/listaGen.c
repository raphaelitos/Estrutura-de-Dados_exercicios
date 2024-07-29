#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaGen.h"

struct listagen{
    void *dado;
    tListaGen *prox;
};

tListaGen *criaListaGen(){
    tListaGen *g = NULL;
    return g;
}

void liberaListaGen(tListaGen *l){
    tListaGen *aux = l, *pop;
    while(aux){
        pop = aux;
        aux = aux->prox;
        free(pop);
    }
}

tListaGen *insereListaGen(tListaGen *l, void *dado){
    tListaGen *nova = (tListaGen*)calloc(1, sizeof(tListaGen));
    if(!nova) exit(EXIT_FAILURE);
    nova->dado = dado;
    nova->prox = l;

    return nova;
}

tListaGen *retiraListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado){
    tListaGen *aux = l, *pre = NULL;

    while(aux && cb(aux->dado, dado)){
        pre = aux;
        aux = aux->prox;
    }
    if(!aux) return l;
    if(!pre){
        l = aux->prox;
    }
    pre->prox = aux->prox;
}

int percorreListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado);