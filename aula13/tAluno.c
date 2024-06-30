#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tAluno.h"

struct aluno{
    char *nome;
    int matricula;
};

tAluno *criaAluno(char *nome, int matricula){
    tAluno *a = (tAluno*) malloc(sizeof(tAluno));
    a->nome = strdup(nome);
    a->matricula = matricula;
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

char *getMatriculaAluno(tAluno *a){
    if(a) return a->matricula;
}

void imprimeAluno(tAluno *a){
    if(!a) return; 
    printf("Nome: %s", a->nome);
    printf("Matricula: %s", a->matricula);

}