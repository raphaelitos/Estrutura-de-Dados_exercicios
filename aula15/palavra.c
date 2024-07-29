#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

/// @brief lista sem sentinela de palavras
struct palavra{
    char *string;
    int ocorrencias;
    tPalavra *prox;
};

void assert(int exp, char *msg){
    if(exp){
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}

tPalavra* criaPalavra(char *str){
    assert(!str, "str nula na criacao de palavra");
    
    tPalavra *nova = (tPalavra*) calloc(1, sizeof(tPalavra));
    assert(!nova, "falha na criacao de palavra");

    nova->string = strdup(str);
    nova->prox = NULL;
    
    return nova;
}

void liberaPalavra(tPalavra *p){
    if(!p) return;

    tPalavra *pop, *aux = p;

    while(aux){
        pop = aux;
        aux = aux->prox;
        free(pop->string);
        free(pop);
    }
}

void imprimePalavra(tPalavra *p){
    assert(!p, "palavra nula na impressao\n");
    while(p){
        printf("Palavra: %s, Ocorrencias: %d\n", p->string, p->ocorrencias);
        p = p->prox;
    }
}

void incOcorrenciasPalavra(tPalavra *p){
    assert(!p, "palavra invalida para incremento\n");
    (p->ocorrencias)++;
}

int getOcorrenciasPalavra(tPalavra *p){
    assert(!p, "palavra invalida para ocorrencias\n");
    return p->ocorrencias;
}

char* getStrPalavra(tPalavra *p){
    assert(!p, "palavra invalida para getStr\n");
    return p->string;
}

int getTamListaPalavras(tPalavra *p){
    assert(!p, "palavra invalida para getTam\n");
    int tam = 0;
    for(tPalavra *aux = p; aux; aux = aux->prox){
        tam++;
    }
    return tam;
}

tPalavra* buscaPalavra(tPalavra *p, char *str){
    for(tPalavra *aux = p; aux != NULL; aux = aux->prox){
        if(!strcmp(aux->string, str)) return aux;
    }
    return NULL;
}

tPalavra* inserePalavraLista(tPalavra *lista, tPalavra *p){
    assert((!p), "palavra invalida em insere");
    p->prox = lista;
    return p;
}