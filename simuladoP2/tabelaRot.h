#ifndef _TABELAROT_H_
#define _TABELAROT_H_

#define TAM_MAX 127

typedef struct tabela tTabela;

tTabela *criaTabela();

void desalocaTabela(tTabela *t);

int acessaTabela(tTabela *t, int chave);

void printTabela(tTabela *t);

#endif