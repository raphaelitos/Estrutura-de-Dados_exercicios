#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char *nome;
    int faltas;
    int presencas;
    tALuno *prox;
};

void assert(int exp, char *msg){
    if(!exp){
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}

tALuno *criaAluno(char *nome){
    tALuno *a = (tALuno*)calloc(1, sizeof(tALuno));
    assert(a != NULL, "falha na alocacao de aluno");
    
    a->nome = strdup(nome);
    a->prox = NULL;

    return a;
}

void liberaAluno(tALuno *a){
    tALuno *pop = NULL, *aux = a;
    while (aux){
        pop = aux;
        aux = aux->prox;
        free(pop->nome);
        free(pop);
    }
}

void imprimeAluno(tALuno *a){
    tALuno *aux;
    for(aux = a; aux != NULL; aux = aux->prox)
        printf("%s %dP %dF\n", aux->nome, aux->presencas, aux->faltas);
}

void incFaltaAluno(tALuno *a){
    assert(a != NULL, "aluno nulo em incFalta");
    (a->faltas)++;
}

void incPresencaAluno(tALuno *a){
    assert(a != NULL, "aluno nulo em incPresenca");
    (a->presencas)++;
}

int getFaltasAluno(tALuno *a){
    assert(a != NULL, "aluno nulo em getFaltas");
    return a->faltas;
}

int getPresencasAluno(tALuno *a){
    assert(a != NULL, "aluno nulo em getPresencas");
    return a->presencas;
}

char *getNomeAluno(tALuno *a){
    assert(a != NULL, "aluno nulo em getNome");
    return a->nome;
}

tALuno *buscaAluno(tALuno *lista, char *nome){
    tALuno *aux;
    for(aux = lista; aux != NULL; aux = aux->prox){
        if(!strcmp(aux->nome, nome)) return aux;
    }
    return NULL;
}

tALuno *insereAluno(tALuno *lista, tALuno *a){
    assert(a != NULL, "aluno nulo em insere");
    a->prox = lista;
    return a;
}