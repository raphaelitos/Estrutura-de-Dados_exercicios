#ifndef _TESTOQUE_H_
#define _TESTOQUE_H_

typedef struct Estoque tEstoque; 

#include "tItem.h"

tEstoque *CriaEstoque();

void DesalocaEstoque(tEstoque *e);

void AcrescentaItemEstoque(tEstoque *e, tItem *i);

int getQtdEstoque(tEstoque *e);

void ImprimeEstoque(tEstoque *e);

#endif