#ifndef _TSUPERMERCADO_H_
#define _TSUPERMERCADO_H_

typedef struct Supermercado tSupermercado;

#include "tFilial.h"

tSupermercado *CriaSupMercado();

void DesalocaSuperMercado(tSupermercado *sm);

void AdicionaFilialSuperMercado(tSupermercado *sm);

void AdicionaItemFilialSM(tSupermercado *sm);

int getEstoqueSM(tSupermercado *sm);

void ProduzRelatorio(tSupermercado *sm);

#endif