#include <stdio.h>
#include <stdlib.h>
#include "abbgen.h"

struct abbgen{
    tAbbg *sad;
    tAbbg *sae;
    void *info;
};

tAbbg *criaABB(){
    tAbbg *nova = NULL;
    return nova;
}

void *buscaAbb(tAbbg *abb, void *chave, int (*comparaChave)(void*, void*)){
    if(!abb) return NULL;
    if(comparaChave(chave, abb->info) < 0){
        return buscaAbb(abb->sae, chave, comparaChave);
    }
    else if(comparaChave(chave, abb->info) > 0){
        return buscaAbb(abb->sad, chave, comparaChave);
    }
    else return abb->info;
}

void imprimeAbb(tAbbg *abb, void (*imprimeDado)(void *)){
    if(!abb) return;
    imprimeAbb(abb->sae, imprimeDado);
    imprimeDado(abb->info);
    imprimeAbb(abb->sad, imprimeDado);
}

tAbbg *insereAbb(tAbbg *abb, void *dado, int (*compara)(void*, void*)){
    if(!dado) return NULL;
    if(!abb){
        abb = (tAbbg*)calloc(1, sizeof(tAbbg));
        if(!abb) exit(EXIT_FAILURE);
        abb->info = dado;
        abb->sad = abb->sae = NULL;
    }
    else if(compara(dado, abb->info) <= 0){
        abb->sae = insereAbb(abb->sae, dado, compara);
    }
    else{
        abb->sad = insereAbb(abb->sad, dado, compara);
    }
    return abb;
}

tAbbg *retiraAbb(tAbbg *abb , void *chave, int (*comparaChave)(void*, void*)){
    if(!abb) return NULL;
    if(comparaChave(chave, abb->info) < 0){
        abb->sae = retiraAbb(abb->sae, chave, comparaChave);
    }
    else if(comparaChave(chave, abb->info) > 0){
        abb->sad = retiraAbb(abb->sad, chave, comparaChave);
    }
    else{
        if(!abb->sae && !abb->sad){//nenhum filho
            free(abb);
            abb = NULL;
        }
        else if(!abb->sad){//filho so na esquerda
            tAbbg *temp = abb;
            abb = abb->sae;
            free(temp);
        }
        else if(!abb->sae){//filho so na direita
            tAbbg *temp = abb;
            abb = abb->sad;
            free(temp);
        }
        else{ // dois filho :P
            tAbbg *temp = abb->sae;
            while(temp->sad != NULL){
                temp = temp->sad;
                //o antecessor eh o no mais a direita
                //da subarvore da esquerda
            }
            //troca informacoes
            void *aux = abb->info;
            abb->info = temp->info;
            temp->info = aux;
            abb->sae = retiraAbb(abb->sae, chave, comparaChave);
        }
    }
    return abb;
}

void desalocaaAbb(tAbbg *abb){
    if(!abb) return;
    desalocaaAbb(abb->sae);
    desalocaaAbb(abb->sad);
    free(abb);
}