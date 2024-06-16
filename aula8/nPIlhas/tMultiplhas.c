#include <stdio.h>
#include <stdlib.h>
#include "tMultiplhas.h"

typedef struct{
    int topo, base;
}tIndicePilha;

/// @brief estrutura que contem um vetor
/// dividido em N pilhas, que possuem
/// um id correspondente a sua posicao no vetor
/// (vao de 0 a (N - 1)).
struct MultiPilha{
    dataType vet[MAX_TAM];
    tIndicePilha Pilha[N];
};

static tIndicePilha inicIndice(int topo, int base){
    tIndicePilha i;
    i.topo = topo;
    i.base = base;
    return i;
}

tMultipilha *criaPilha(){
    tMultipilha *p = (tMultipilha*)malloc(sizeof(tMultipilha));
    if(!p){
        printf("Falha na alocacao de pilha!\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while(i < N){
        p->Pilha[i] = inicIndice((i*CHUNK - 1), i*CHUNK);
        i++;
    }
    return p;
}

void desalocaPilha(tMultipilha *p){
    free(p);
}

void push(tMultipilha *p, dataType  d,  int idPilha){
    if(!p){
        printf("Pilha nula enviada para push\n");
        exit(EXIT_FAILURE);
    }

    if(idPilha >= N || idPilha < 0){
        printf("indice de pilha invalido!\n");
        return;
    }
    if(p->Pilha[idPilha].topo == ((idPilha+1)*CHUNK - 1)){
        printf("A pilha escolhida esta cheia!\n");
        return;
    }
    p->vet[(p->Pilha[idPilha].topo) + 1] = d;
    (p->Pilha[idPilha].topo)++;

}

dataType pop(tMultipilha *p,  int idPilha){
    if(!p){
        printf("Pilha nula enviada para pop\n");
        exit(EXIT_FAILURE);
    }
    dataType d = NULL;
    if(idPilha >= N || idPilha < 0){
        printf("indice de pilha invalido!\n");
        return d;
    }
    if(p->Pilha[idPilha].topo == (p->Pilha[idPilha].base - 1)){
        printf("A pilha escolhida esta vazia!\n");
        return d;
    }
    d = p->vet[(p->Pilha[idPilha].topo)];
    (p->Pilha[idPilha].topo)--;
    return d;
}

void imprimePilha(tMultipilha *p){
    if(!p){
        printf("pilha nula enviada para impressao!\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < N; i++){
        tIndicePilha subpilha = p->Pilha[i];
        printf("Pilha %d\n", i);
        int flag = 0;
        for(int j = subpilha.topo; j >= subpilha.base; j--){
            printf("%d ", *(p->vet[j]));
            flag = 1;
        }
        if(flag) printf("\n");
    }
}