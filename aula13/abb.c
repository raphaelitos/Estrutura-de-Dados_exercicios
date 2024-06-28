#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct abb{
    
};

tAbb *criaABB();

tAluno *busca(tAbb *abb, int matricula);

void imprime(tAbb *abb);

void insere(tAbb *abb, tAluno *a);

tAluno *retira(tAbb *abb , int matricula);

void liberaArvore(tAbb *abb);
