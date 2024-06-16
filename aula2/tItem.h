#ifndef _TITEM_H_
#define _TITEM_H_

#include "tProduto.h"

typedef struct Item tItem;

tItem *CriaItem(tProduto *p);

tItem *LeItem();

void DesalocaItem(void *dado);

char *getNomeItem(tItem *i);

float getValorItem(tItem *i);

int getQtdItem(tItem *i);

void ImprimeItem(tItem *i);

#endif