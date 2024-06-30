#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct abb{
    tAluno *info;
    tAbb *sae;
    tAbb *sad;
};

tAbb *criaABB(){
    tAbb *nova = NULL;
    return nova;
}

tAluno *busca(tAbb *abb, int matricula){
    if(!abb) return NULL;
    if(getMatriculaAluno(abb->info) > matricula){
        return busca(abb->sae, matricula);
    }
    else if(getMatriculaAluno(abb->info) > matricula){
        return busca(abb->sae, matricula);
    }
    else return abb->info;
}

void imprimeNo(tAbb *a){
    if(a) imprimeAluno(a->info);
}

void imprime(tAbb *abb){
    if(!abb) return;
    imprime(abb->sae);
    imprimeNo(abb);
    imprime(abb->sad);
}

tAbb* insere(tAbb *abb, tAluno *a){
    if(!a) return;
    if(!abb){
        abb = (tAbb*)malloc(sizeof(tAbb));
        abb->info = a;
        abb->sad = abb->sae = NULL;
        return;
    }
    if(getMatriculaAluno(a) < getMatriculaAluno(abb->info)){
        abb->sae = insere(abb->sae, a);
    }
    else{
        abb->sad = insere(abb->sad, a);
    }
    return abb;
}

tAbb*retira(tAbb *abb , int matricula){
    if(!abb) return NULL;
    if(matricula > getMatriculaAluno(abb->info)){
        abb->sad = retira(abb->sad, matricula);
    }
    else if(matricula < getMatriculaAluno(abb->info)){
        abb->sae = retira(abb->sae, matricula);
    }
    else{
        if(!abb->sae && !abb->sad){//nenhum filho
            liberaArvore(abb);
            abb = NULL;
        }
        else if(!abb->sad){//filho so na esquerda
            tAbb *temp =  abb;
            abb = abb->sad;
            free(temp);
        }
        else if(!abb->sae){//filho so na direita
            tAbb *temp =  abb;
            abb = abb->sae;
            free(temp);
        }
        else{ // dois filho :P
            tAbb *temp = abb->sae;
            while(temp != NULL){
                temp = temp->sad;
                //o antecessor eh o no mais a direita
                //da subarvore da esquerda
            }
            tAluno *aux = abb->info;
            abb->info = temp->info;
            temp->info = aux;
            abb->sae = retira(abb->sad, matricula);
        }
    }
    return abb;

}

void liberaArvore(tAbb *abb){
    if(!abb) return;
    liberaArvore(abb->sae);
    liberaArvore(abb->sad);
    free(abb);
}
