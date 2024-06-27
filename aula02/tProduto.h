#ifndef _TPRODUTO_H_
#define _TPRODUTO_H_

typedef struct Produto tProduto;

tProduto *CriaProduto();

tProduto *LeProduto();

void DesalocaProduto(tProduto *p);

char *getNomeProduto(tProduto *p);

float getValorProduto(tProduto *p);

#endif