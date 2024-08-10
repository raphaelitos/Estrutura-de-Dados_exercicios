#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct hash{
    tALuno **vet;
    int tam;
};

static int fHash(char *nome){
    assert(nome != NULL, "nome nulo em fHash");
    int soma = 0;
    for(int i = 0; i < strlen(nome); i++){
        soma += (int)nome[i];
    }
    return soma;
}

tHash *criaHash(int tam){
    tHash *h = (tHash*)calloc(1, sizeof(tHash));
    assert(h != NULL, "falha na criacao de hash");

    h->tam = tam;
    h->vet = (tALuno**)calloc(tam, sizeof(tALuno*));
    for(int i = 0; i < tam; i++){
        h->vet[i] = NULL;
    }

    return h;
}

void liberaHash(tHash *h){
    if(!h) return;
    for(int i = 0; i < h->tam; i++){
        if(h->vet[i]) liberaAluno(h->vet[i]);
    }
    free(h->vet);
    free(h);
}

void imprimeHash(tHash *h){
    assert(h != NULL, "hash nula em imprime");
    for(int i = 0; i < h->tam; i++){
        if(h->vet[i])
            imprimeAluno(h->vet[i]);
    }
}

tALuno *acessaHash(tHash *h, char *nome){
    int id = fHash(nome) % h->tam;
    return buscaAluno(h->vet[id], nome);
}

tALuno *insereHash( tHash *h, tALuno *a){
    assert(a != NULL, "aluno nulo em insere hash");
    int id = fHash(getNomeAluno(a)) % h->tam;
    h->vet[id] = insereAluno(h->vet[id], a);
    return h->vet[id];
}