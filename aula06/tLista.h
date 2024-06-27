#ifndef TLISTA_H_
#define TLISTA_H_

typedef struct lista tLista;

#include "tGato.h"
#include "tCachorro.h"

tLista *criaLista();

void desalocaLista(tLista *l);

void insereListaGato(tLista *l, tGato *g);

void insereListaCachorro(tLista *l, tCachorro *g);

//NAO EXISTE MUDANCA SUBSTANCIAL ENTRE ESSES RETIRA. AVALIAR NECESSIDADE DE DOIS.

void retiraListaGato(tLista *l, tGato *g);

void retiraListaCachorro(tLista *l, tCachorro *c);

void imprimeLista(tLista *l);

int getTamLista(tLista *l);

float calculaReceitaLista(tLista *l);

#endif