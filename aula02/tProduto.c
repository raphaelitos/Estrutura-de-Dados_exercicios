#include <stdio.h>
#include <stdlib.h>
#include "tProduto.h"
#include "utils.h"

struct Produto{
    char* nome;
    float valor;
};

tProduto *CriaProduto(){
    tProduto *p = (tProduto*)calloc(1, sizeof(tProduto));

    if(!p){
        printf("Falha na alocacao de produto!\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

tProduto *LeProduto(){
    tProduto *p = CriaProduto();
    
    printf("Nome do produto: ");
    p->nome = LeNome();
    printf("Valor do produto: ");
    scanf("%f", &(p->valor));
    while(getchar() != '\n');

    return p;
}

void DesalocaProduto(tProduto *p){
    if(!p){
        printf("Produto nulo para liberacao!");
        exit(EXIT_FAILURE);
    }

    DesalocaNome(p->nome);
    free(p);
}

char *getNomeProduto(tProduto *p){
    if(!p){
        TratarStructNula("getNomeProduto", "produto");
    }
    return p->nome;
}

float getValorProduto(tProduto *p){
    if(!p){
        TratarStructNula("getNomeProduto", "produto");
    }
    return p->valor;
}