#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tProduto.h"
#include "utils.h"

struct Produto{
    char* nome;
    char* codigo;
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
    char nome[TAM_MAX_NOME];
    scanf("%150[^\n]", nome);
    while(getchar() != '\n');
    p->nome = strdup(nome);

    printf("Codigo do produto: ");
    char cod[TAM_MAX_CODIGO];
    scanf("%14[^\n]", cod);
    while(getchar() != '\n');
    p->codigo = strdup(cod);
    
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

    free(p->nome);
    free(p->codigo);
    free(p);
}

void setNomeProduto(tProduto *p, char *nome){
    if(!p){
        TratarStructNula("setNomeProduto", "produto");
    }
    p->nome = strdup(nome);
}

char *getNomeProduto(tProduto *p){
    if(!p){
        TratarStructNula("getNomeProduto", "produto");
    }
    return p->nome;
}

void setValorProduto(tProduto *p, float valor){
    if(!p){
        TratarStructNula("setValorProduto", "produto");
    }
    p->valor = valor;
}

float getValorProduto(tProduto *p){
    if(!p){
        TratarStructNula("getNomeProduto", "produto");
    }
    return p->valor;
}

void setCodigoProduto(tProduto *p, char *cod){
    if(!p || !cod){
        TratarStructNula("setCodigo", "Produto ou char");
    }
    p->codigo = strdup(cod);
}

char *getCodigoProduto(tProduto *p){
    if(!p){
        TratarStructNula("getCodigoProduto", "produto");
    }
    return p->codigo;
}