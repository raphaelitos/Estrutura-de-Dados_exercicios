#ifndef _ENDERECO_H_
#define _ENDERECO_H_

typedef struct endereco tEndereco;

tEndereco *criaEndereco(int destination, int nextHop);

void desalocaEndereco(tEndereco *e);

void setProxEndereco(tEndereco *e, tEndereco *prox);

void printEndereco(tEndereco *e);

#endif