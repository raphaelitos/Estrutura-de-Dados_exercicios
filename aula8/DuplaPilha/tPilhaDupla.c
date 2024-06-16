#include <stdio.h>
#include <stdlib.h>
#include "tPilhaDupla.h"

#define MAX_TAM 20
#define QTD_PILHAS 2


struct PilhaD{
    dataType vet[MAX_TAM];
    int base1, base2;
    int topo1, topo2;
};

static int EstaVazia1(tPilhaD *p){
    return p->topo1 == -1;
}

static int EstaVazia2(tPilhaD *p){
    return p->topo2 == MAX_TAM;
}

tPilhaD *criaPilhaD(){
    tPilhaD *p = (tPilhaD*)malloc(sizeof(tPilhaD));
    if(!p){
        printf("Falha na alocacao de nova pilha\n");
        exit(EXIT_FAILURE);
    }

    p->base1 = 0;
    p->topo1 = -1;
    p->base2 = MAX_TAM - 1;
    p->topo2 = MAX_TAM;

    return p;
}

void desalocaPilhaD(tPilhaD *p){
    free(p);
}

static dataType pop1(tPilhaD *p){
    dataType d = 0;
    if(EstaVazia1(p)){
        printf("Pilha 1 esta vazia!\n");
        return d;
    }
    d = p->vet[p->topo1];
    (p->topo1--);
    return d;
}

static dataType pop2(tPilhaD *p){
    dataType d = 0;
    if(EstaVazia2(p)){
        printf("Pilha 2 esta vazia!\n");
        return d;
    }
    d = p->vet[p->topo2];
    (p->topo2++);
    return d;
}

dataType pop(tPilhaD *p, int idPilha){
    if(!p){
        printf("Pilha nula enviada para pop!\n");
        exit(EXIT_FAILURE);
    }
    dataType d = 0;

    if(idPilha != PILHA_1 && idPilha != PILHA_2){
        printf("Id de pilha invalido!\n");
        return d;
    }

    if(idPilha == PILHA_1) return pop1(p);

    return pop2(p);
}

static void push1(tPilhaD *p, dataType d){
    if(p->topo1 == (p->topo2 - 1)){
        printf("pilha1 esta cheia!\n");
        return;
    }
    p->vet[p->topo1 + 1] = d;
    (p->topo1)++;
}

static void push2(tPilhaD *p, dataType d){
    if(p->topo2 == (p->topo1 + 1)){
        printf("pilha2 esta cheia!\n");
        return;
    }
    p->vet[p->topo2 - 1] = d;
    (p->topo2)--;
}

void push(tPilhaD *p, dataType d, int idPilha){
    if(!p || !d){
        printf("pilha ou dado nulo enviado para push!\n");
        return;
    }
    if(idPilha != PILHA_1 && idPilha != PILHA_2){
        printf("Id de pilha invalido!\n");
        return;
    }

    if(idPilha == PILHA_1){
        push1(p, d);
        return;
    }
    push2(p, d);
}

void imprimePilhaD(tPilhaD *p){
    if(!p){
        printf("pilha nula enviada para impressao!\n");
        exit(EXIT_FAILURE);
    }
    printf("PILHA 1:\n");
    for(int i = p->topo1; i >= p->base1; i--){
        printf("%d\n", p->vet[i]);
    }
    printf("PILHA 2:\n");
    for(int j = p->topo2; j <= p->base2; j++){
        printf("%d\n", p->vet[j]);
    }
}