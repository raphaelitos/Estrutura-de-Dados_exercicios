#ifndef _TPRODUTO_H_
#define _TPRODUTO_H_

#define TAM_MAX_NOME 151
#define TAM_MAX_CODIGO 15

typedef struct Produto tProduto;

tProduto *CriaProduto();

tProduto *LeProduto();

void DesalocaProduto(tProduto *p);

void setNomeProduto(tProduto *p, char *nome);

char *getNomeProduto(tProduto *p);

void setValorProduto(tProduto *p, float valor);

float getValorProduto(tProduto *p);

void setCodigoProduto(tProduto *p, char *cod);

char *getCodigoProduto(tProduto *p);

#endif