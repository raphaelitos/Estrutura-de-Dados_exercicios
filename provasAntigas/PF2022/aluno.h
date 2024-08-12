#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct aluno tAluno;

void assert(int exp, const char *msg);

tAluno *criaAluno(char *nome);

void liberaAluno(tAluno *a);

void imprimeAluno(tAluno *a);

char *getNomeAluno(tAluno *a);

int getFaltasAluno(tAluno *a);

int getPresencasAluno(tAluno *a);

void incFaltaAluno(tAluno *a);

void incPresencaAluno(tAluno *a);

#endif