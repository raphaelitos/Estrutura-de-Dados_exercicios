#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLista.h"
#include "utils.h"

struct lista{
    tLista *prox;
    tLista *ant;
    tProduto *item;
};

static int EstaVaziaLista(tLista *l){
    return (l == NULL);
}

int EhMesmoCodigo(tProduto * p, char *cod){
    if(!p || !cod){
        TratarStructNula("EhMesmoCod", "produto ou char*");
    }
    return !strcmp(getCodigoProduto(p), cod);
}

tLista *criaLista(tProduto *p){
    tLista *l = (tLista*)calloc(1, sizeof(tLista));
    if(!l) TratarFalhaAlocacao("lista");
    l->prox = NULL;
    l->item = p;

    return l;
}

/*void desalocaLista(tLista *l){
    if(!EstaVaziaLista(l)){
        tLista *pos = l->prox;
        free(l);    
        desalocaLista(pos);
    }
}*/

void desalocaLista(tLista *l) {
    if (l != NULL) {
        desalocaLista(l->prox);
        free(l);
    }
}

void imprimeLista(tLista *l){
    if(!EstaVaziaLista(l)){
        printf("NOME: %s | PRECO: %.2f | CODIGO: %s\n", 
            getNomeProduto(l->item), getValorProduto(l->item), getCodigoProduto(l->item));
        imprimeLista(l->prox);
    }
}

tLista* retiraLista(tLista *l, char *codigo){
    if(!EstaVaziaLista(l)){
        if(EhMesmoCodigo(l->item, codigo)){
            tLista *pop = l;
            l = l->prox;
            free(pop);
        }
    }
    else{
        l->prox = retiraLista(l->prox, codigo);
    }
    return l;
}

tLista* insereLista(tLista *l, tProduto *p){
    if(!p){
        TratarStructNula("inserelista", "produto");
    }
    
    tLista *c = criaLista(p);
    
    if(!EstaVaziaLista(l)){
        l->ant = c;
    }
    
    c->prox = l;
    
    return c;
}