#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

typedef struct celula tCelula;

struct celula{
    tCelula *prox;
    TProduto *prod;
};

static tCelula* criaCelula(TProduto *p){
    if(!p){
        printf("Produto invalido na funcao cria!\n");
        exit(EXIT_FAILURE);
    }
    
    tCelula *c = (tCelula*)calloc(1, sizeof(tCelula));
    c->prod = p;
    c->prox = NULL;

    return c;
}

static void desalocaCelula(tCelula *c){
    if(!c){
        printf("Celula invalida na funcao desaloca!\n");
        exit(EXIT_FAILURE);
    }
    free(c);
}

struct pedido{
    char *nomeDono;
    tCelula *prim;
    tCelula *ult;
};

static int EstaVaziaLista(TPedido *p){
    if(!p){
        printf("Pedido invalido em EstaVaziaLista!\n");
        exit(EXIT_FAILURE);
    }
    return(p->prim == NULL);
}

TPedido* InicPedido (char* dono){
    TPedido *p = (TPedido*)calloc(1, sizeof(TPedido));

    p->nomeDono = strdup(dono);

    p->prim = p->ult = NULL;

    return p;
}

static int EhMesmoProduto(TProduto *p1, TProduto *p2){
    if(!(p1 && p2)){
        printf("produto invalido em EhMesmoProd\n");
        exit(EXIT_SUCCESS);
    }
    return (!strcmp(RetornaNome(p1), RetornaNome(p2)));
}

void IncluiProdutoPedido (TPedido* pedido, TProduto* prod){
    if(!pedido || !prod){
        printf("pedido ou prod invalidos em IncluiProdutoPedido\n");
        exit(EXIT_FAILURE);
    }

    tCelula *cel = NULL;

    for(cel = pedido->prim; cel != NULL; cel = cel->prox){
        if(EhMesmoProduto(prod, cel->prod)){
            printf("Produto já existe no pedido\n");
            return;
        }
    }

    cel = criaCelula(prod);
    if(EstaVaziaLista(pedido)){
        pedido->prim = cel;
    }
    else{
        pedido->ult->prox = cel;
    }
    
    pedido->ult = cel;
}

void ImprimePedido (TPedido* pedido){
    if(!pedido){
        printf("pedido nulo na funcao Iprime!\n");
        exit(EXIT_FAILURE);
    }
    printf("\nDono do pedido: %s", pedido->nomeDono);
    for(tCelula *cel = pedido->prim; cel != NULL; cel = cel->prox){
        ImprimeIngredientes(cel->prod);
    }
}

void RetiraProdutoPedido (TPedido* pedido, char* prod){
    if(!pedido || !prod){
        printf("pedido ou char nulo em RetiraProduto\n");
        exit(EXIT_FAILURE);
    }
    if(EstaVaziaLista(pedido)){
        printf("Seu pedido ja esta vazio\n");
        return;
    }
    
    tCelula *cel = pedido->prim, *ant = NULL;

    while(cel && strcmp(RetornaNome(cel->prod), prod)){
        ant = cel;
        cel = cel->prox;
    }
    
    if(!cel){
        printf("ERRO na funcao retira: Produto nao encontrado\n");
        return;
    }
    
    if(cel == pedido->prim){
        pedido->prim = cel->prox;
    }
    else if(cel == pedido->ult){
        ant->prox = NULL;
        pedido->ult = ant;
    }
    else{
        ant->prox = cel->prox;
    }
    desalocaCelula(cel);
}

static int somaCaloriasPedido(TPedido *p){
    int soma = 0;
    for(tCelula *cel = p->prim; cel != NULL; cel = cel->prox){
        soma += Calorias(cel->prod);
    }
    return soma;
}

static int verificaRestricaoPedido(TPedido *p, char *restricaoAlimentar){
    if(!p || !restricaoAlimentar){
        printf("pedido ou char* nulo enviado para verificaRestricao\n");
        exit(EXIT_FAILURE);
    }
    tCelula *cel = p->prim;
    while(cel){
        if(VerificaIngrediente(cel->prod, restricaoAlimentar)){
            printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", RetornaNome(cel->prod));
            return 1;
        }
        cel = cel->prox;
    }
    return 0;
}

static void desalocaPedido(TPedido *p){
    if(!p){
        printf("pedido nulo em desaloca!\n");
    }
    tCelula *cel = p->prim, *ant = NULL;
    while(cel){
        ant = cel;
        cel = cel->prox;
        desalocaCelula(ant);
    }
    free(p->nomeDono);
    free(p);
}

int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar){
    if(!(pedido && restricao_alimentar)){
        printf("pedido ou char* nulo em EnviaPedido\n");
        exit(EXIT_FAILURE);
    }
    if(somaCaloriasPedido(pedido) > restricao_calorica){
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }
    if(verificaRestricaoPedido(pedido, restricao_alimentar)){
        return 0;
    }
    desalocaPedido(pedido);
    return 1;
}