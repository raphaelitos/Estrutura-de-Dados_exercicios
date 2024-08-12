#ifndef _ABB_H_
#define _ABB_H_

#include "aluno.h"

typedef struct abb tAbb;

tAbb *criaAbb();

void liberaAbb(tAbb *abb);

void imprimeAbb(tAbb *abb);

tAluno *buscaAbb(tAbb *abb, char *str);

tAbb *insereAbb(tAbb *abb, tAluno *a);

#endif