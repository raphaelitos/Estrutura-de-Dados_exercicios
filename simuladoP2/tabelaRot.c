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
    for(int i = 0; i < TAM_MAX; i++){
        t->enderecos[i] = NULL;
    }
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

tEndereco* acessaTabela(tTabela *t, int chave){
    tEndereco *aux = NULL;
    if(!t) return aux;

    int id = funcHash(chave);
    if(t->enderecos[id]);
    for(aux = t->enderecos[id]; aux != NULL; aux = getProxEndereco(aux)){
        if(chave == getDestination(aux)) return aux;
    }

    printf("O endereco com essa chave nao foi encontrado.\n");
    printf("deseja inserir um novo endereco com esse destination?\n[1 - sim | 0 - nao]\n");
    int op = 0;
    scanf("%d", &op);
    if(!op) return aux;

    int nh;
    printf("Insira o valor do NextHop para o novo endereco\n");
    scanf("%d", &nh);
    aux = criaEndereco(chave, nh);
    insereTabela(t, aux);
    return aux;
}

void printTabela(tTabela *t){
    if(!t) return;
    for(int i = 0; i < TAM_MAX; i++){
        printf("tab[%d]\n", i);
        if(t->enderecos[i]) printEndereco(t->enderecos[i]);
    }
}

void insereTabela(tTabela *t, tEndereco *e){
    if(!e || !t) exit(EXIT_FAILURE);
    
    int id = funcHash(getDestination(e));
    if(t->enderecos[id]){
        setProxEndereco(e, t->enderecos[id]);
    }
    t->enderecos[id] = e;
}