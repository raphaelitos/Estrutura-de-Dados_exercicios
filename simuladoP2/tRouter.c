#include <stdio.h>
#include <stdlib.h>
#include "tRouter.h"

struct router{
    int id;
    tTabela *table;
};

tRouter *criaRouter(int id){
    tRouter *r = (tRouter*)calloc(1, sizeof(tRouter));
    if(!r)exit(EXIT_FAILURE);
    r->id = id;
}

void desalocaRouter(tRouter *r){
    if(!r) return;
    desalocaTabela(r->table);
    free(r);
}

void printRouter(tRouter *r){
    if(!r) return;
    printf("\n### IMPRESSAO DE ROUTER ###\n");
    printf("ID: %d\n", r->id);
    printTabela(r->table);
}
