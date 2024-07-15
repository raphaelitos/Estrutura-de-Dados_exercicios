#include <stdio.h>
#include <stdlib.h>
#include "tabelaRot.h"
#include "tEendereco.h"

struct tabela{
    tEndereco **enderecos;
};

tTabela *criaTabela(){
    tTabela *t = (tTabela*)calloc(1, sizeof(tTabela));
    if(!t)exit(EXIT_FAILURE);
    t->enderecos = (tEndereco**)calloc(TAM_MAX, sizeof(tEndereco*));
    /*for(int i = 0; i < TAM_MAX; i++){
        t->enderecos[i] = criaEndereco(0, 0);
    }*/
    return t;
}

static int funcHash(int chave){
    return chave % TAM_MAX;
}

void desalocaTabela(tTabela *t){
    if(!t) return;
    for(int i = 0; i < TAM_MAX; i++){
        if(t->enderecos[i]){
            desalocaEndereco(t->enderecos[i]);
        }
    }
    free(t->enderecos);
    free(t);
}

int acessaTabela(tTabela *t, int chave);

void printTabela(tTabela *t);