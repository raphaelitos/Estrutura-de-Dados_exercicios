#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct hash{
    tPalavra **vet;
    int tam;
};

static int fHash(char *str, int tam){
    assert(!str, "string invalida em fhash");
    int soma = 0;
    for(int i = 0; i < strlen(str); i++){
        soma += (int)str[i];
    }
    //printf("%d\n", soma);
    return (soma % tam);
}

tHash *criaHash(int tam){
    tHash *t = (tHash*)calloc(1, sizeof(tHash));
    assert(!t,"falha na alocacao de hashh");

    t->vet = (tPalavra**)calloc(tam, sizeof(tPalavra*));
    for(int i = 0; i < tam; i++){
        t->vet[i] = NULL;
    }
    t->tam = tam;

    return t;
}

void liberaHash(tHash *t){
    if(!t) return;
    
    for(int i = 0; i < t->tam; i++){
        liberaPalavra(t->vet[i]);
    }
    
    free(t->vet);
    free(t);
}

void imprimeHash(tHash *t){
    assert(!t, "tabela nula em impressao");
    for(int i = 0; i < t->tam; i++){
        if(t->vet[i]){
            printf("tab[%d]:", i);
            imprimePalavra(t->vet[i]);
        }
    }
}

tPalavra* acessa(tHash *t, char *str){
    assert((!t || !str), "tabela ou string nula em acessa");

    int id = fHash(str, t->tam);
    //printf("id = %d\n", id);
    tPalavra *p = buscaPalavra(t->vet[id], str);

    if(p){
        return p;
    } 
    
    p = criaPalavra(str);
    t->vet[id] = inserePalavraLista(t->vet[id], p);
    return p;
}

int getTamHash(tHash *t){
    assert(!t, "tabela nula em getTam");
    return t->tam;
}