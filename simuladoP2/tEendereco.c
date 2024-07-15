#include <stdio.h>
#include <stdlib.h>
#include "tEendereco.h"

struct endereco{
    int destination;
    int nextHop;
    tEndereco *prox;
};

tEndereco *criaEndereco(int destination, int nextHop){
    tEndereco *e = (tEndereco*)calloc(1, sizeof(tEndereco));
    if(!e) exit(EXIT_FAILURE);
    
    e->destination = destination;
    e->nextHop = nextHop;
    e->prox = NULL;

    return e;
}

void desalocaEndereco(tEndereco *e){
    if(!e) return;
    desalocaEndereco(e->prox);
    free(e);
}

void setProxEndereco(tEndereco *e, tEndereco *prox);

void printEndereco(tEndereco *e);