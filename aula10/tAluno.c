#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tAluno.h"

struct aluno{
    char *nome;
};

tAluno *criaAluno(char *nome){
    tAluno *a = (tAluno*) malloc(sizeof(tAluno));
    a->nome = strdup(nome);
    return a;
}

void desalocaAluno(tAluno *a){
    if(a){
        free(a->nome);
    }
    free(a);
}

char *getNomeAluno(tAluno *a){
    if(a) return a->nome;
}

void imprimeAluno(tAluno *a){
    if(a) printf("%s", a->nome);
}