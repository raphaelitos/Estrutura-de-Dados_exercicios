#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char *nome;
    int faltas;
    int presencas;
};

void assert(int exp, const char *msg){
    if(!exp){
        if(msg)printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}

tAluno *criaAluno(char *nome){
    tAluno *a = (tAluno*)calloc(1, sizeof(tAluno));
    assert(a != NULL, "falha na alocacao de aluno");
    
    a->nome = strdup(nome);
    assert((a->nome) != NULL, 
            "falha na alocacao de nome de aluno");
    
    return a;
}

void liberaAluno(tAluno *a){
    if(!a) return;
    free(a->nome);
    free(a);
}

void imprimeAluno(tAluno *a){
    if(!a) return;
    printf("%s %dP %dF\n", a->nome, a->presencas, a->faltas);
}

char *getNomeAluno(tAluno *a){
    assert(a != NULL, "aluno nulo em getNome");
    return a->nome;
}

int getFaltasAluno(tAluno *a){
    assert(a != NULL, "aluno nulo em getFaltas");
    return a->faltas;
}

int getPresencasAluno(tAluno *a){
    assert(a != NULL, "aluno nulo em getPresencas");
    return a->presencas;
}

void incFaltaAluno(tAluno *a){
    assert(a != NULL, "aluno nulo em incFalta");
    (a->faltas)++;
}

void incPresencaAluno(tAluno *a){
    assert(a != NULL, "aluno nulo em incPresenca");
    (a->presencas)++;
}