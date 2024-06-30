/*Implemente um TAD árvore binária de busca (ABB) de alunos, com as funcionalidades básicas de: criação, 
busca, impressão, inserção, retirada e liberação. Você escolhe o critério de ordenação para sua ABB.*/

#ifndef _TABB_H_
#define _TABB_H_

typedef struct abb tAbb;

#include "tAluno.h"

tAbb *criaABB();

tAluno *busca(tAbb *abb, int matricula);

void imprime(tAbb *abb);

tAbb* insere(tAbb *abb, tAluno *a);

tAbb *retira(tAbb *abb , int matricula);

void liberaArvore(tAbb *abb);

#endif