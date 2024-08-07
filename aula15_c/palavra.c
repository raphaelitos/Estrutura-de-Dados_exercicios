#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

//typedef tPalavra tListaGen;

typedef struct cel{
    char *str;
    int ocorrencias;
}pCelula;

static pCelula *criapCel(char *str){
    pCelula *nova = (pCelula*)calloc(1, sizeof(pCelula));
    nova->str = strdup(str);

    return nova;
}

static void liberapCel(void *dado){
    if(!dado)return;
    pCelula *cel = (pCelula*)dado;
    free(cel->str);
    free(cel);
} 

/// @brief lista sem sentinela de palavras
struct palavra{
    pCelula *info;
    tPalavra *prox;
};

void assert(int exp, char *msg){
    if(exp){
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}

tPalavra* criaPalavra(){
    /*tPalavra *nova = NULL;    
    return nova;*/
    return (tPalavra*)criaListaGen();
}

void liberaPalavra(tPalavra *p){
    /*if(!p) return;

    tPalavra *pop, *aux = p;

    while(aux){
        pop = aux;
        aux = aux->prox;
        free(pop->info);
        free(pop);
    }*/
   liberaListaGen((tListaGen*)p, liberapCel);
}

int imprime(void *palavra, void *dado){
    assert(!palavra, "palavra nula em imprime");
    tPalavra *p = (tPalavra*)palavra;
    printf("Palavra: %s, Ocorrencias: %d\n", p->info->str, p->info->ocorrencias);
    return 1;
}

void imprimePalavra(void *dado){
    assert(!dado, "palavra nula na impressao\n");
    /*tPalavra *p = (tPalavra*) dado;
    while(p){
        printf("Palavra: %s, Ocorrencias: %d\n", p->string, p->ocorrencias);
        p = p->prox;
    }*/
   percorreListaGen((tListaGen*)dado, imprime, NULL);
}

void incOcorrenciasPalavra(tPalavra *p){
    assert(!p, "palavra invalida para incremento\n");
    (p->info->ocorrencias)++;
}

int getOcorrenciasPalavra(tPalavra *p){
    assert(!p, "palavra invalida para ocorrencias\n");
    return p->info->ocorrencias;
}

char* getStrPalavra(tPalavra *p){
    assert(!p, "palavra invalida para getStr\n");
    return p->info->str;
}

int getTamListaPalavras(tPalavra *p){
    assert(!p, "palavra invalida para getTam\n");
    int tam = 0;
    for(tPalavra *aux = p; aux; aux = aux->prox){
        tam++;
    }
    return tam;
}

int pBusca(void *palavra, void *dado){
    tPalavra *p = (tPalavra*)palavra;
    char *str = (char*)dado;
    
    if(!strcmp(p->info->str, str)) return 1;
    return 0;
}

tPalavra* buscaPalavra(tPalavra *p, char *str){
    /*for(tPalavra *aux = p; aux != NULL; aux = aux->prox){
        if(!strcmp(aux->info->str, str)) return aux;
    }
    return NULL;*/
    return (tPalavra*)buscaListaGen((tListaGen*)p, pBusca ,(void*) str);
}

tPalavra* inserePalavraLista(tPalavra *lista, char *str){
    /*assert((!p), "palavra invalida em insere");
    p->prox = lista;
    return p;*/
    tPalavra *p = criaPalavra();
    p->info = criapCel(str);
    return (tPalavra*)insereListaGen((tListaGen*)lista, (void*)p);
}

int compPalavra(void *dado, void *key){
    assert(!key, "chave nula em compPalavra");
    if(!dado) return 0;
    tPalavra *p = (tPalavra*)dado;
    return !strcmp(p->info->str, key);
}