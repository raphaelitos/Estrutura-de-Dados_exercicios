#ifndef _TROUTER_H_
#define _TROUTER_H_

#include "tabelaRot.h"

typedef struct router tRouter;

tRouter *criaRouter(int id);

void desalocaRouter(tRouter *r);

void setProxRouter(tRouter *r, tRouter *prox);

void printRouter(tRouter *r);

#endif