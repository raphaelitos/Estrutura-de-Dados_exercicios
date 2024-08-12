#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

struct abb{
    tAluno *info;
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
    
    liberaAluno(abb->info);
    free(abb);
}

void imprimeAbb(tAbb *abb){
    if(!abb) return;
    
    imprimeAbb(abb->esq);
    imprimeAluno(abb->info);
    
    imprimeAbb(abb->dir);
}

tAluno *buscaAbb(tAbb *abb, char *str){
    if(!abb){    
        return NULL;
    }
    else if(strcmp(str, getNomeAluno(abb->info)) < 0){
        return buscaAbb(abb->esq, str);
    }
    else if(strcmp(str, getNomeAluno(abb->info)) > 0){
        return buscaAbb(abb->dir, str);
    }
    else{//achou
        return abb->info;
    }
}

tAbb *insereAbb(tAbb *abb, tAluno *a){
    
    if(!abb){//inserir nova folha    
        abb = (tAbb*)calloc(1, sizeof(tAbb));
        assert(abb != NULL, "falha na alocacao de abb");

        abb->esq = abb->dir = NULL;
        abb->info = a;
    }
    else if(strcmp(getNomeAluno(a), getNomeAluno(abb->info)) < 0){
        abb->esq = insereAbb(abb->esq, a);
    }
    else{
        abb->dir = insereAbb(abb->dir, a);
    }
    
    return abb;
}