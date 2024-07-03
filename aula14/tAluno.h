#ifndef _TALUNO_H_
#define _TALUNO_H_

typedef struct aluno tAluno;

tAluno *criaAluno(char *nome, int matricula);

void desalocaAluno(tAluno *a);

char *getNomeAluno(tAluno *a);

int getMatriculaAluno(tAluno *a);

void imprimeAluno(void *dado);

int comparaMatricula(void *a, void *b);

int comparaNome(void *a, void *b);

#endif