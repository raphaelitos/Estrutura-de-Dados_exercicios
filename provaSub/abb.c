//FEITO POR RAPHAEL CORREIA DORNELAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

struct abb{
    tPalavra *info;
    tAbb *esq;
    tAbb *dir;
};

tAbb *criaAbb(){
    tAbb *a = NULL;
    return a;
}

void liberaAbb(tAbb *abb){
    if(!abb) return;
    
    liberaAbb(abb->esq);
    liberaAbb(abb->dir);
    
    liberaPalavra(abb->info);
    free(abb);
}

tAbb *insereAbb(tAbb *abb, char *str){
    if(!abb){
        abb = (tAbb*)calloc(1, sizeof(tAbb));
        assert(abb != NULL, "falha em alocar abb");

        tPalavra *p = criaPalavra(str);
        incFreqPalavra(p);//primeira aparicao

        abb->esq = abb->dir = NULL;
        abb->info = p;
    }
    else if(strcmp(str, getStrPalavra(abb->info)) < 0){
        abb->esq = insereAbb(abb->esq, str);
    }
    else if(strcmp(str, getStrPalavra(abb->info)) > 0){
        abb->dir = insereAbb(abb->dir, str);
    }
    else{//achou a palavra
        incFreqPalavra(abb->info);
    }
    
    return abb;
}

int qtdPlvAbb(tAbb *abb){
    if(!abb) return 0;

    return 1 + qtdPlvAbb(abb->esq) + qtdPlvAbb(abb->dir);
}

int somaFreqAbb(tAbb *abb){
    if(!abb) return 0;

    return getFreqPalavra(abb->info) + somaFreqAbb(abb->esq) + 
            somaFreqAbb(abb->dir);
}

void maxFreqPlvAbb(tAbb *abb, tPalavra **max){
    if(!abb) return;
   
    if(getFreqPalavra(abb->info) > getFreqPalavra((*max))){
        (*max) = abb->info;
    }
    
    maxFreqPlvAbb(abb->esq, max);
    maxFreqPlvAbb(abb->dir, max);
}

tPalavra *getPlvAbb(tAbb *abb){
    if(!abb) return NULL;
    return abb->info;
}

void getInfoAbb(tAbb *abb, tPalavra **vet, int *index){
    if(!abb) return;
    
    getInfoAbb(abb->esq, vet, index);
    
    assert((*index) >= 0, "id nulo em getInfo");
    vet[(*index)++] = abb->info;

    getInfoAbb(abb->dir, vet, index);
}