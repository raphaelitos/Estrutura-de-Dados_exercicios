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
    if(!abb)return;
    liberaAbb(abb->esq);
    liberaAbb(abb->dir);
    liberaPalavra(abb->info);
    free(abb);
}

void imprimeAbb(tAbb *abb){
    if(!abb) return;
    imprimeAbb(abb->esq);
    imprimePalavra(abb->info);
    imprimeAbb(abb->dir);
}

tAbb *insereAbb(tAbb *abb, char *str){
    assert(str != NULL, "str nula em insere");
    
    if(!abb){
        abb = (tAbb*)calloc(1, sizeof(tAbb));
        assert(abb != NULL, "falha em alocar abb");
        
        tPalavra *p = criaPalavra(str);
        
        abb->dir = abb->esq = NULL;
        abb->info = p;
        incFreqPalavra(abb->info);
    }

    else if(strcmp(str, getStrPalavra(abb->info)) < 0){
        abb->esq = insereAbb(abb->esq, str);
    }
    else if(strcmp(str, getStrPalavra(abb->info)) > 0){
        abb->dir = insereAbb(abb->dir, str);
    }
    else{
        incFreqPalavra(abb->info);
    }

    return abb;

}

tAbb *insereAbbFreq(tAbb *abb, tPalavra *p){
    assert(p != NULL, "palavra nula em criaAbbFreq");

    if(!abb){
        abb = (tAbb*)calloc(1, sizeof(tAbb));
        assert(abb != NULL, "falha em alocar abb");
                
        abb->dir = abb->esq = NULL;
        abb->info = p;
    }

    else if(getFreqPalavra(abb->info) < getFreqPalavra(p)){
        abb->esq = insereAbbFreq(abb->esq, p);
    }
    else{
        abb->dir = insereAbbFreq(abb->dir, p);
    }
    
    return abb;
}

tAbb *reformaAbbFreq(tAbb *a1, tAbb *a2){
    if(!a1) return NULL;

    a2 = reformaAbbFreq(a1->esq, a2);
    insereAbbFreq(a2, a1->info);
    a2 = reformaAbbFreq(a1->dir, a2);

    return a2;
}

int tamAbb(tAbb *abb){
    if(!abb) return 0;
    return 1 + tamAbb(abb->esq) + tamAbb(abb->dir);
}

int qtdFrequenciasAbb(tAbb *abb){
    if(!abb) return 0;
    
    return getFreqPalavra(abb->info) + qtdFrequenciasAbb(abb->esq) + 
    qtdFrequenciasAbb(abb->dir);

}

void getInfoAbb(tAbb *abb, int *index, tPalavra **vet, int tam){
    assert(((*index) >= 0 && (*index) < tam), "index invalido em getInfo");

    if(!abb){
        return;
    }
    getInfoAbb(abb->esq, index, vet, tam);
    getInfoAbb(abb->dir, index, vet, tam);
    vet[(*index)++] = abb->info;
}

tPalavra *getPalavraAbb(tAbb *abb){
    if(!abb) return NULL;
    return abb->info;
}

void PalavraMaisFreqAbb(tAbb *abb, tPalavra **max){
    if(!abb) return;
    
    if(getFreqPalavra(abb->info) > getFreqPalavra((*max))){
        (*max) = abb->info;
    }
    
    PalavraMaisFreqAbb(abb->esq, max);
    PalavraMaisFreqAbb(abb->dir, max);
}