#ifndef LISTA_H_
#define LISTA_H_

#include "tProduto.h"

typedef struct Lista tLista;
typedef struct Celula tCelula;


/// @brief Cria uma lista vazia
/// @return A lista criada
tLista *CriaLista();

/// @brief Desaloca uma lista 
/// @param l lista a ser desalocada
void DesalocaLista(tLista *l);

/// @brief Insere um item no final da lista
/// @param l uma lista valida
/// @param p um produto valido
void InsereLista(tLista *l, tProduto *p);

/// @brief Retira um item da lista com base no seu codigo
/// @param l uma lista valida  
/// @param codigo o codigo do produto a ser retirado
/// @return 1 se foi bem sucedido, 0 caso contrario
int RetiraLista(tLista *l, char *codigo);

/// @brief Imprime as celulas de uma lista
/// @param l uma lista valida
void ImprimeLista(tLista *l);

#endif