#ifndef _TLISTA_H_
#define _TLISTA_H_

#include "tProduto.h"

typedef struct lista tLista;

tLista* criaLista(tProduto *p);

void desalocaLista(tLista *l);

void imprimeLista(tLista *l);

tLista* retiraLista(tLista *l, char *codigo);

tLista* insereLista(tLista *l, tProduto* p);

#endif