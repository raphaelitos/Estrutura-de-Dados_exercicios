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

void setProxEndereco(tEndereco *e, tEndereco *prox){
    if(!e) return;
    e->prox = prox;
}

void printEndereco(tEndereco *e){
    if(!e) return;
    printf("\n### IMPRESSAO DE ENDERECO ###\n");
    printf("Destination - %d |NextHop - %d\n\n",e->destination, e->nextHop);
    if(e->prox){
        printf("PROXIMO:\n");
        printEndereco(e->prox);
    }
}

int getDestination(tEndereco *e){
    return e->destination;
}

int getNextHop(tEndereco *e){
    return e->nextHop;
}

tEndereco* getProxEndereco(tEndereco *e){
    return e->prox;
}