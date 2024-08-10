#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"

struct pais{
    char *nome;
    int ouros;
    int pratas;
    int bronzes;
    tPais *prox;
};

int totalMedalhasPais(tPais *p){
    assert (!p, "pais nulo em totalMedalhas");

    return(p->bronzes + p->pratas + p->ouros);
}

void assert(int exp, char *msg){
    if(exp) printf("%s\n", msg);
}

tPais *criaPais(char *nome, int ouros, int pratas, int bronzes){
    tPais *p = (tPais*)calloc(1, sizeof(tPais));
    assert(!p, "falha na alocacao de pais");
    
    p->nome = strdup(nome);
    p->ouros = ouros;
    p->pratas = pratas;
    p->bronzes = bronzes;
    p->prox = NULL;

    return p;
}

void liberaPais(tPais *p){
    if(!p) return;
    tPais *aux = p, *pop = NULL;
    while(aux){
        pop = aux;
        aux = aux->prox;
        free(pop->nome);
        free(pop);
    }
    
}

void imprimePais(tPais *p){
    if(!p)return;
    
    tPais *aux;
    for(aux = p; aux != NULL; aux = aux->prox){
        printf("%s %d %d %d %d\n", aux->nome, aux->ouros, 
                        aux->pratas, aux->bronzes, totalMedalhasPais(aux));
    }
}

void imprimeArqPais(tPais *p, FILE *arq){
    if(!p)return;
    assert(!arq, "arquivo nulo em imprimeArqPais");
    tPais *aux;
    for(aux = p; aux != NULL; aux = aux->prox){
        fprintf(arq, "%s %d %d %d %d\n", aux->nome, aux->ouros, 
                        aux->pratas, aux->bronzes, totalMedalhasPais(aux));
    }
}

tPais *inserePais(tPais *lista, tPais *p){
    assert(!p, "pais nulo em insere");
    p->prox = lista;
    return p;
}

tPais *buscaPais(tPais *lista, char *nome){
    tPais *aux;
    for(aux = lista; aux != NULL; aux = aux->prox){
        if(!strcmp(aux->nome, nome)) return aux;
    }
    return NULL;
}

int getOurosPais(tPais *p){
    assert(!p, "pais nulo em getOuros");
    return p->ouros;
}

int getPratasPais(tPais *p){
    assert(!p, "pais nulo em getpratas");
    return p->pratas;
}

int getBronzesPais(tPais *p){
    assert(!p, "pais nulo em getbronzes");
    return p->bronzes;
}

char *getNomePais(tPais *p){
    assert(!p, "pais nulo em getnome");
    return p->nome;
}

void atualizaMedalhasPais(tPais *p, int ouros, int pratas, int bronzes){
    assert(!p, "pais nulo em atualizaMedalhas");
    p->ouros = ouros;
    p->pratas = pratas;
    p->bronzes = bronzes;
}

int getTamListaPais(tPais *p){
    int soma = 0;
    tPais *aux;
    for(aux = p; aux != NULL; aux = aux->prox){
        soma++;
    }
    return soma;
}

void dumpVetPais(tPais *lista, tPais **vet, int *indice){
    tPais *aux, *in = NULL;
    for(aux = lista; aux != NULL; aux = aux->prox){
        vet[(*indice)] = aux;
        (*indice)++;
    }
}