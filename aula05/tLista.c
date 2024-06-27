#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLista.h"
#include "utils.h"

struct Celula{
    tProduto *produto;
    tCelula *prox;
    tCelula *ant;
};

//AUXILIARES//
int EstaVaziaLista(tCelula *l){
    return (l == NULL);
}

int EhMesmoCodigo(tProduto * p, char *cod){
    if(!p || !cod){
        TratarStructNula("EhMesmoCod", "produto ou char*");
    }
    return !strcmp(getCodigoProduto(p), cod);
}

//----*----//

/*FUNCOES CELULA*/

tCelula *CriaCelula(tProduto *p){
    if(!p){
        TratarStructNula("CriaCelula", "Produto");
    }
    
    tCelula *c = (tCelula *)calloc(1, sizeof(tCelula));
    if(!c){
        TratarFalhaAlocacao("Celula");
    }

    c->produto = p;
    c->prox = NULL;
    c->ant = NULL;

    return c;
}

void DestroiCelula(tCelula *c){
    if(!c){
        TratarStructNula("DestroiCelula", "celula");
    }
    free(c);
    printf("Celula liberada!\n");
}

void ImprimeCelula(tCelula *c){
    if(!c) TratarStructNula("Imprime", "Celula");
    printf("NOME: %s | PRECO: %.2f | CODIGO: %s\n", 
        getNomeProduto(c->produto), getValorProduto(c->produto), getCodigoProduto(c->produto));
}

//-----*-----//

tCelula *CriaLista(){
    tCelula *l = NULL;
    return l;
}

void DesalocaLista(tCelula *l){
    if(!l){ 
        printf("lista vazia na liberacao\n");
        return;
    }

    tCelula *c = l;
    tCelula* libera = NULL;
    
    while(c != NULL){
        libera = c;
        c = c->prox;
        free(libera);
    }
}

tCelula* InsereLista(tCelula *l, tProduto *p){
    if(!p){
        TratarStructNula("inserelista", "produto");
    }
    
    tCelula *c = CriaCelula(p);
    
    if(!EstaVaziaLista(l)){
        l->ant = c;
    }
    
    c->prox = l;
    
    return c;
}

tCelula* RetiraLista(tCelula *l, char *codigo){
    if(!codigo){
        TratarStructNula("RetiraLista", "char");
    }
    
    if(EstaVaziaLista(l)){
        printf("Sua lista ja estah vazia!\n");
        return l;
    }

    tCelula *pop = l;
    
    while(pop != NULL && !EhMesmoCodigo(pop->produto, codigo)){
        pop = pop->prox;
    }
    
    if(pop == NULL){//chegou ao ultimo prox
        printf("ERRO NA RETIRADA DE CELULA: codigo nao encontrado!\n");
        return l;
    }
    
    if(pop->ant == NULL){//esta na primeira celula
        l = pop->prox;
        if(l != NULL){ //verificando se existe outra celula
            l->ant = NULL;
        }
    }

    else if(pop->prox == NULL){//esta na ultima celula
        pop->ant->prox = NULL;
    }

    else{
        pop->prox->ant = pop->ant;
        pop->ant->prox = pop->prox;
    }
    
    DestroiCelula(pop);
    
    return l;
}

/*tCelula *ant = NULL, *cel = l->prim;

while(cel != NULL && !EhMesmoCodigo(cel->produto, codigo)){
    ant = cel;
    cel = cel->prox;
}

if(cel == NULL){//caso em que o codigo nao foi encontrado
    printf("ERRO NA RETIRADA DE CELULA: codigo nao encontrado!\n");
    return 0;
} 

else if(cel == l->prim && cel == l->ult){
    l->prim = l->ult = NULL;
    printf("Sua lista agora estah vazia!");
}

else if(cel == l->prim){
    l->prim = l->prim->prox;
}

else if(cel == l->ult){
    l->ult = ant;
    //aqui o prox do recem-ultimo precisa voltar a NULL
    l->ult->prox = NULL;
}

else{//caso trivial
    ant->prox = cel->prox;
}

DestroiCelula(cel);
return;*/

void ImprimeLista(tCelula *l){
    if(!l)printf("Lista vazia. Nao ha produtos para serem impressos!\n");
    
    tCelula *c = NULL;
    
    for(c = l; c != NULL; c = c->prox){
        ImprimeCelula(c);
    }
}