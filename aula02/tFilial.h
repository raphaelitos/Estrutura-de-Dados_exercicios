#ifndef _TFILIAL_H_
#define _TFILIAL_H_

typedef struct Filial tFilial;

#include "tEstoque.h"

tFilial *CriaFilial(char *nome);

void DesalocaFilial(void *dado);

void AcrescentaItemFilial(tFilial *f, tItem *i);

int getQtdEstoqueFilial(tFilial *f);

char *getNomeFilial(tFilial *f);

void ImprimeFilial(tFilial *f);

#endif