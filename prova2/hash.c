#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct hash{
    tPais **vet;
    int tam;
};

static int getTamHash(tHash *h){
    if(!h){
        printf("Hash nula em getTam");
        exit(EXIT_FAILURE);
    }
    return h->tam;
}

static int fHash(char *str){
    if(!str){
        printf("str nula em fHash");
        exit(EXIT_FAILURE);
    }
    int soma = 0;
    int tam = strlen(str);
    for(int i = 0; i < tam; i ++){
        soma += str[i];
    }
    return soma;
}

tHash *criaHash(int tam){
    tHash *h = (tHash*)calloc(1, sizeof(tHash));
    assert(!h, "falha em alocar hash");

    h->tam = tam;
    h->vet = (tPais**)calloc(tam, sizeof(tPais*));
    for(int i = 0; i < tam; i++){
        h->vet[i] = NULL;
    }

    return h;
}

void liberaHash(tHash *h){
    if(!h) return;
    for(int i = 0; i < h->tam; i++){
        liberaPais(h->vet[i]);
    }
    free(h->vet);
    free(h);
}

static void OverwriteMedalhasPais(tPais *p1, tPais *p2){
    assert((!p1 || !p2), "algum pais nulo em overwritemed");
    atualizaMedalhasPais(p1, getOurosPais(p2), getPratasPais(p2), getBronzesPais(p2));
}

tPais *acessa(tHash *h, tPais *p){
    assert((!h || !p), "pais ou hash nula em acessa");

    char *nome = getNomePais(p);
    int id = fHash(nome) % h->tam;

    tPais *alvo = buscaPais(h->vet[id], nome);
    if(alvo){
        OverwriteMedalhasPais(alvo, p);
        return p;
    }

    h->vet[id] = inserePais(h->vet[id], p);

    return NULL;
}

int getQtdPaisesHash(tHash *h){
    assert(!h, "hash nula em getQtdPaises");
    int soma = 0;
    for(int i = 0; i < h->tam; i++){
        if(h->vet[i]) soma += getTamListaPais(h->vet[i]);
    }
    return soma;
}

tPais **dumpVet(tHash *h){
    assert(!h, "hash nula em dumpVet");
    int tam = getQtdPaisesHash(h);
    
    //printf("tam = %d\n", tam);

    tPais **vet = (tPais**)calloc(tam, sizeof(tPais*));
    assert(!vet, "falha em alocar vet em dump");

    int indice = 0;
    for(int i = 0; i < h->tam; i++){
        dumpVetPais(h->vet[i], vet, &indice);
    }
    
    return vet;
}

void imprimeHash(tHash *h){
    assert(!h, "hash nula em imprime");
    for(int i = 0; i < h->tam; i++){
        if(h->vet[i]){
            imprimePais(h->vet[i]);
        }
    }    
}

void imprimeArqHash(tHash *h, FILE *arq){
    assert((!h || !arq), "hash ou arquivo nulo em imprime");

    for(int i = 0; i < h->tam; i++){
        if(h->vet[i]){
            imprimeArqPais(h->vet[i], arq);
        }
    } 

}