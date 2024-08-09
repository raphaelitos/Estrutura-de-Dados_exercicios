#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

typedef struct cel{
    char *str;
    int ocorrencias;
}pCelula;

static pCelula *criapCel(char *str){
    pCelula *nova = (pCelula*)calloc(1, sizeof(pCelula));
    assert(!nova, "falha na alocacao de celula");
    
    nova->str = (char*)calloc((strlen(str) + 1), sizeof(char));
    assert(!(nova->str), "falha na alocacao de str em celula");
    strcpy(nova->str, str);
    
    return nova;
}

void liberapCel(void *dado){
    if(!dado)return;
    pCelula *cel = (pCelula*)dado;
    free(cel->str);
    free(cel);
} 

/// @brief lista sem sentinela de palavras
struct palavra{
    void *info;
    tPalavra *prox;
};

void assert(int exp, char *msg){
    if(exp){
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}

tPalavra* criaPalavra(char *str){
    pCelula *c = criapCel(str);
    return (tPalavra*)criaListaGen((void*)c);
}

void liberaPalavra(tPalavra *p){
   liberaListaGen((tListaGen*)p, liberapCel);
}

int imprime(void *info, void *dado){
    assert(!info, "palavra nula em imprime");
    
    pCelula *c = (pCelula*)info;
    
    assert(!c, "info nula em palavra enviada para imprime");

    printf("Palavra: %s, Ocorrencias: %d\n", c->str, c->ocorrencias);
    
    return 1; //pra continuar no loop
}

void imprimePalavra(void *dado){
    if(!dado){
        printf("dado nulo em imprime!\n");
        return;
    }
    tPalavra *p = (tPalavra*)dado;

    percorreListaGen((tListaGen*)p, imprime, NULL);
}

void incOcorrenciasPalavra(tPalavra *p){
    //assert(!p, "palavra invalida para incremento\n");
    if(!p) return;
    pCelula *c = (pCelula*)p->info;
    (c->ocorrencias)++;
}

int getOcorrenciasPalavra(tPalavra *p){
    assert(!p, "palavra invalida para ocorrencias\n");
    pCelula *c = (pCelula*)p->info;
    return c->ocorrencias;
}

char* getStrPalavra(tPalavra *p){
    assert(!p, "palavra invalida para getStr\n");
    pCelula *c = (pCelula*)p->info;
    return c->str;
}

int getTamListaPalavras(tPalavra *p){
    assert(!p, "palavra invalida para getTam\n");
    int tam = 0;
    for(tPalavra *aux = p; aux != NULL; aux = aux->prox){
        tam++;
    }
    return tam;
}

tPalavra* buscaPalavra(tPalavra *p, char *str){
    return (tPalavra*)buscaListaGen((tListaGen*)p, compPalavra ,(void*) str);
}

tPalavra* inserePalavraLista(tPalavra *lista, tPalavra *p){
    return (tPalavra*)insereListaGen((tListaGen*)lista, (tListaGen*)p);
}

int compPalavra(void *dado, void *key){
    assert(!key, "chave nula em compPalavra");
    if(!dado) return 1;
    
    pCelula *c = (pCelula*)dado;
    
    assert(c == NULL, "info nula em CompPalavra");

    return strcmp(c->str, (char*)key);
}