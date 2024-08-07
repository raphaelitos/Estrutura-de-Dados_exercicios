#ifndef _TALUNO_H_
#define _TALUNO_H_

typedef struct aluno tAluno;

tAluno *criaAluno(char *nome, int matricula);

void desalocaAluno(tAluno *a);

char *getNomeAluno(tAluno *a);

int getMatriculaAluno(tAluno *a);

void imprimeAluno(void *dado);

int comparaMatricula(void *chave, void *aluno);

int comparaNome(void *chave, void *aluno);

int comparaAlunoMatricula(void *a, void *b);

int comparaAlunoNome(void *a, void *b);

#endif