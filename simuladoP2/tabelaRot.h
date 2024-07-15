#ifndef _TABELAROT_H_
#define _TABELAROT_H_

#include "tEendereco.h"

#define TAM_MAX 127

typedef struct tabela tTabela;

tTabela *criaTabela();

void desalocaTabela(tTabela *t);

tEndereco* acessaTabela(tTabela *t, int chave);

void printTabela(tTabela *t);

void insereTabela(tTabela *t, tEndereco *e);

#endif