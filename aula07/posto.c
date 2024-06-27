#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tFila.h"
#include "posto.h"
#include "utils.h"

struct posto{
    char *nome;
    tFila *naoProcessadas;
    tFila *negativas;
    tFila *positivas;
};

Posto* inicPosto(char* nome){
    if(!nome) TratarStructNula("inicPosto", "char*");
    Posto *p = (Posto*)calloc(1, sizeof(Posto));
    if(!p)TratarFalhaAlocacao("posto");

    p->nome = strdup(nome);
    p->naoProcessadas = criaFila();
    p->negativas = criaFila();
    p->positivas = criaFila();

    return p;
}

void imprimePosto(Posto* p){
    if(!p) TratarStructNula("imprime", "posto");
    printf("Dados do Posto: %s\n", p->nome);
    printf("Amostras nao processadas:\n");
    imprimeFila(p->naoProcessadas);
    printf("Amostras com resultados positivo:\n");
    imprimeFila(p->positivas);
    printf("Amostras com resultados negativo:\n");
    imprimeFila(p->negativas);
}

void realizaColeta(Posto* p, char* pessoa, int idade){
    if(!p || ! pessoa) TratarStructNula("realizaColeta", "posto ou pessoa");
    Amostra *a = inicAmostra(pessoa, idade);
    insereFila(p->naoProcessadas, a);
}

static void testaAmostra(Amostra *a, tFila *negativas, tFila *positivas){
    if(!(a && negativas && positivas)) TratarStructNula("testa", "amostra");

    if(retornaCargaViral(a) >= LIMITE_CARGA_VIRAL){
        registraResultado(a, POSITIVO);
        insereFila(positivas, a);
    }
    else{
        registraResultado(a, NEGATIVO);
        insereFila(negativas, a);
    }
}

void processaLoteAmostras(Posto* p){
    if(!p) TratarStructNula("processaLote", "posto");

    Amostra *a = NULL;
    int tam = getTamanhoFila(p->naoProcessadas);
    for(int i = 0; i < tam; i++){
        a = retiraFila(p->naoProcessadas);
        testaAmostra(a, p->negativas, p->positivas);
    }
}

void liberaPosto(Posto* p){
    if(!p) TratarStructNula("libera", "posto");
    free(p->nome);
    desalocaFila(p->naoProcessadas);
    desalocaFila(p->negativas);
    desalocaFila(p->positivas);
    free(p);
}