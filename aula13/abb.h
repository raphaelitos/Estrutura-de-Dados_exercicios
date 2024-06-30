/*Implemente um TAD árvore binária de busca (ABB) de alunos, com as funcionalidades básicas de: criação, 
busca, impressão, inserção, retirada e liberação. Você escolhe o critério de ordenação para sua ABB.*/

#ifndef _TABB_H_
#define _TABB_H_

typedef struct abb tAbb;

#include "tAluno.h"

/// @brief cria um ponteiro da estrutura tAbb
/// @return um ponteiro de tAbb com valor NULL
tAbb *criaABB();

/// @brief busca um aluno na arvore com base 
/// em sua matricula
/// @param abb um ponteiro de tAbb
/// @param matricula a matricula do aluno buscado
/// @return ponteiro para aluno 
/// (null se ele nao existir na arvore)
tAluno *busca(tAbb *abb, int matricula);

/// @brief imprime uma arvore em ordem crescente
/// @param abb um ponteiro valido para tAbb
void imprime(tAbb *abb);

/// @brief insaere um aluno na arvore
/// @param abb um ponteiro para tAbb
/// @param a um aluno valido
/// @return a arvore com o aluno inserido
tAbb* insere(tAbb *abb, tAluno *a);

/// @brief retira um aluno com base em sua matricula
/// @param abb um ponteiro para tAbb
/// @param matricula a matricula do aluno que se 
/// deseja retirar
/// @return a arvore modificada, sem o aluno
tAbb *retira(tAbb *abb , int matricula);

/// @brief libera a memoria utilizada
/// por uma estrutura tAbb
/// @param abb a arvore que se deseja desalocar
void liberaArvore(tAbb *abb);

#endif