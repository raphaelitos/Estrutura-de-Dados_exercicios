#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct aluno tALuno;

void assert(int exp, char *msg);

tALuno *criaAluno(char *nome);

void liberaAluno(tALuno *a);

void imprimeAluno(tALuno *a);

void incFaltaAluno(tALuno *a);

void incPresencaAluno(tALuno *a);

int getFaltasAluno(tALuno *a);

int getPresencasAluno(tALuno *a);

char *getNomeAluno(tALuno *a);

tALuno *buscaAluno(tALuno *lista, char *nome);

tALuno *insereAluno(tALuno *lista, tALuno *a);

#endif