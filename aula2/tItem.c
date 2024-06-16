#include <stdio.h>
#include <stdlib.h>
#include "tItem.h"
#include "utils.h"

struct Item{
    tProduto *produto;
    int qtd;
};

tItem *CriaItem(tProduto *p){
    
    if(!p){
        TratarStructNula("criaItem", "produto");
    }
    
    tItem *i = (tItem *)calloc(1, sizeof(tItem));
    if(!i){
        TratarFalhaAlocacao("Item");
    }
    i->produto = p;

    return i;
}

tItem *LeItem(){
    tProduto *p = LeProduto();
    tItem *i = CriaItem(p);
    printf("Defina a quantidade desse item de estoque: ");
    scanf("%d", &(i->qtd));
    while(getchar() != '\n');
    return i;
}

void DesalocaItem(void *dado){
    if(!dado){
        TratarStructNula("DeslocaItem", "Item");
    }
    tItem *i = (tItem *)dado;
    DesalocaProduto(i->produto);
    free(i);
}

char *getNomeItem(tItem *i){
    if(!i){
        TratarStructNula("GetNome", "item");
    }
    return getNomeProduto(i->produto);
}

float getValorItem(tItem *i){
    if(!i){
        TratarStructNula("GetValor", "item");
    }
    return getValorProduto(i->produto);
}

int getQtdItem(tItem *i){
    if(!i){
        TratarStructNula("GetQtd", "item");
    }
    return i->qtd;
}

void ImprimeItem(tItem *i){
    if(!i){
        TratarStructNula("Imprime", "item");
    }
    printf("\t\tItem: %s | VALOR: %.2f | QTD: %d\n", getNomeProduto(i->produto), getValorProduto(i->produto), i->qtd);
}