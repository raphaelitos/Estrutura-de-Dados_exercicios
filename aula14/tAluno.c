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

int getMatriculaAluno(tAluno *a){
    if(a) return a->matricula;
}

void imprimeAluno(void *dado){
    if(!dado) return; 
    tAluno *a = (tAluno*)dado;
    printf("Nome: %s\n", a->nome);
    printf("Matricula: %d\n\n", a->matricula);

}

int comparaMatricula(void *chave, void *aluno){
    int *matricula = (int*)chave;
    tAluno *a = (tAluno*)aluno;
    return ((*matricula) - a->matricula);
}

int comparaNome(void *chave, void *aluno){
    char *nome = (char*)chave;
    tAluno *a = (tAluno*)aluno;
    return strcmp(nome, a->nome);
}

int comparaAlunoMatricula(void *a, void *b){
    tAluno *a1 = (tAluno*)a;
    tAluno *a2 = (tAluno*)b;
    return a1->matricula - a2->matricula;
}

int comparaAlunoNome(void *a, void *b){
    tAluno *a1 = (tAluno*)a;
    tAluno *a2 = (tAluno*)b;
    return strcmp(a1->nome, a2->nome);
}