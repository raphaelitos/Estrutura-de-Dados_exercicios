#ifndef _TALUNO_H_
#define _TALUNO_H_

typedef struct aluno tAluno;

tAluno *criaAluno(char *nome);

void desalocaAluno(tAluno *a);

char *getNomeAluno(tAluno *a);

void imprimeAluno(tAluno *a);

#endif