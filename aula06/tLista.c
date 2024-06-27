#include <stdio.h>
#include <stdlib.h>
#include "tLista.h"
#include "utils.h"

#define PRECO_GATO 30
#define PRECO_CACHORRO 40
#define ACRESCIMO_AGRESSIVO 5

typedef enum especie{
    GATO,
    CACHORRO
}eEspecie;

typedef struct celula tCelula;

struct celula{
    void * item;
    eEspecie especie;
    tCelula *prox;
    tCelula *ant;
};

typedef struct lista tLista;

struct lista{
    tCelula *prim;
    tCelula *ult;
    int tam;
};

//AUXILIARES\\

int EstaVaziaLista(tLista *l){
    if(!l){
        TratarStructNula("EstaVazia", "Lista");
    }
    return (l->prim == NULL && l->ult == NULL);
}

/***********/

//FUNCOES DE CELULA\\

tCelula *criaCelulaGato(tGato *g){
    if(!g){
        TratarStructNula("criaCelula", "gato");
    }
    tCelula *c = (tCelula*)calloc(1,sizeof(tCelula));
    if(!c){
        TratarFalhaAlocacao("celula");
    }
    
    c->especie = GATO;
    c->item = (void*)g;
    c->prox = c->ant = NULL;

    return c;
}

tCelula *criaCelulaCachorro(tCachorro *d){
    if(!d){
        TratarStructNula("criaCelula", "cachorro");
    }
    tCelula *c = (tCelula*)calloc(1,sizeof(tCelula));
    if(!c){
        TratarFalhaAlocacao("celula");
    }
    
    c->especie = CACHORRO;
    c->item = (void*)d;
    c->prox = c->ant = NULL;

    return c;
}

void ImprimeCelula(tCelula *c){
    if(!c) TratarStructNula("imprime", "celula");
    
    if(c->especie == CACHORRO) imprimeCachorro((tCachorro*)c->item);
    else imprimeGato((tGato*)c->item);
}

void desalocaCelula(tCelula *c){
    free(c);
}

int ehGatoCelula(tCelula *c){
    if(!c) TratarStructNula("ehgato", "celula");
    return(c->especie == GATO);
}

/**********/

tLista *criaLista(){
    tLista *l = (tLista*)calloc(1,sizeof(tLista));
    if(!l){
        TratarFalhaAlocacao("lista");
    }
    
    l->prim = l->ult = NULL;
    
    return l;
}

void desalocaLista(tLista *l){
    if(!l) TratarStructNula("desaloca", "lista");
    
    tCelula *c = l->prim;
    tCelula* libera = NULL;
    while(c != NULL){
        libera = c;
        c = c->prox;
        free(libera);
    }
    free(l);
}

void insereListaGato(tLista *l, tGato *g){
    if(!(l && g)){
        TratarStructNula("inserelista", "lista ou gato");
    }
    
    tCelula *c = criaCelulaGato(g);

    if(EstaVaziaLista(l)){
        l->prim = c;
    }
    else{
        l->ult->prox = c;
        c->ant = l->ult;
    }
    l->ult = c;
    (l->tam)++;
}

void insereListaCachorro(tLista *l, tCachorro *d){
    if(!(l && d)){
        TratarStructNula("inserelista", "lista ou Cachorro");
    }
    
    tCelula *c = criaCelulaCachorro(d);

    if(EstaVaziaLista(l)){
        l->prim = c;
    }
    else{
        l->ult->prox = c;
        c->ant = l->ult;
    }
    l->ult = c;
    (l->tam)++;
}

void retiraListaGato(tLista *l, tGato *g){
    if(!(l && g)){
        TratarStructNula("retiralista", "lista ou gato");
    }
    if(EstaVaziaLista(l)){
        printf("Sua lista ja esta vazia!\n");
        return;    
    }
    tCelula *pop = l->prim;
    
    while(pop && (tGato*)pop->item != g){
        pop = pop->prox;
    }

    if(pop == NULL){
        printf("ERRO NA RETIRADA DE CELULA: gato nao encontrado!\n");
        return;
    }

    if(pop->ant == NULL){//primeira celula
        l->prim = pop->prox;
        if(pop->prox != NULL){//verificando se ha mais de uma celula
            l->prim->ant = NULL; //segunda celula se torna a primeira
        }
    }
    else if(pop->prox == NULL){//ultima celula
        l->ult = pop->ant;
    }
    else{
        pop->prox->ant = pop->ant;//anterior do proximo de pop se torna o anterior de pop
        pop->ant->prox = pop->prox;
    }

    desalocaCelula(pop);
    (l->tam)--;
}

void retiraListaCachorro(tLista *l, tCachorro *c){
    if(!(l && c)){
        TratarStructNula("retiralista", "lista ou cachorro");
    }
    if(EstaVaziaLista(l)){
        printf("Sua lista ja esta vazia!\n");
        return;    
    }
    tCelula *pop = l->prim;
    
    while(pop && (tCachorro*)pop->item != c){
        pop = pop->prox;
    }

    if(pop == NULL){
        printf("ERRO NA RETIRADA DE CELULA: cachorro nao encontrado!\n");
        return;
    }

    if(pop->ant == NULL){//primeira celula
        l->prim = pop->prox;
        if(pop->prox != NULL){//verificando se ha mais de uma celula
            l->prim->ant = NULL; //segunda celula se torna a primeira
        }
    }
    else if(pop->prox == NULL){//ultima celula
        l->ult = pop->ant;
    }
    else{
        pop->prox->ant = pop->ant;//anterior do proximo de pop se torna o anterior de pop
        pop->ant->prox = pop->prox;
    }

    desalocaCelula(pop);
    (l->tam)--;
}

void imprimeLista(tLista *l){
    if(!l) TratarStructNula("imprime", "lista");
    
    tCelula *c = NULL;
    for(c = l->prim; c != NULL; c = c->prox){
        if(c->especie == GATO) imprimeGato((tGato*)c->item);
        else imprimeCachorro((tCachorro*)c->item);
    }

}

/*float calculaPrecoGato(tGato *g){
    if(EhMansoGato(g)) return PRECO_GATO;
    else return PRECO_GATO + ACRESCIMO_AGRESSIVO;
}

float calculaPrecoCachorro(tCachorro *g){
    if(EhMansoCachorro(g)) return PRECO_CACHORRO;
    else return PRECO_CACHORRO + ACRESCIMO_AGRESSIVO;
}*/

int getTamLista(tLista *l){
    if(!l)TratarStructNula("getTam", "lista");
    return l->tam;
}

float calculaReceitaLista(tLista *l){
    if(!l) TratarStructNula("calculaReceita", "lista");
    tCelula *c = NULL;
    float receita = 0;
    for(c = l->prim; c != NULL; c = c->prox){
        if(c->especie == GATO) receita += PRECO_GATO;
        else receita += PRECO_CACHORRO;
    }
    return receita;
}