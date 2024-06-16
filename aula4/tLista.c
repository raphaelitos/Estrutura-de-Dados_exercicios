#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLista.h"
#include "utils.h"

struct Celula{
    tProduto *produto;
    tCelula *prox;
};

struct Lista{
    tCelula *prim;
    tCelula *ult;
};

//AUXILIARES//
int EstaVaziaLista(tLista *l){
    if(!l){
        TratarStructNula("EstaVazia", "Lista");
    }
    return (l->prim == NULL);
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

tLista *CriaLista(){
    tLista *l = (tLista*)calloc(1, sizeof(tLista));
    if(!l){
        TratarFalhaAlocacao("tLista");
    }
    
    l->prim = NULL; 
    l->ult = NULL;

    return l;
}

void DesalocaLista(tLista *l){
    
    if(!l) TratarStructNula("desaloca", "Lista");

    tCelula *c = l->prim;
    tCelula* libera = NULL;
    while(c != NULL){
        libera = c;
        c = c->prox;
        free(libera);
    }
    free(l);
}

void InsereLista(tLista *l, tProduto *p){
    if(!l || !p){
        TratarStructNula("inserelista", "lista ou produto");
    }
    
    tCelula *c = CriaCelula(p);
    
    if(EstaVaziaLista(l)){
        l->prim = c;
    }
    else{
        //aqui o ultimo prox adquire um valor diferente de NULL
        l->ult->prox = c;
    }
    //atualizando ultima posicao da lista
    l->ult = c;
}

int RetiraLista(tLista *l, char *codigo){
    if(!l || !codigo){
        TratarStructNula("RetiraLista", "lista ou char");
    }
    
    if(EstaVaziaLista(l)){
        printf("Sua lista ja estah vazia!\n");
        return -1;
    }

    tCelula *ant = NULL, *cel = l->prim;

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
    return 1;
}

void ImprimeLista(tLista *l){
    if(!l) TratarStructNula("imprimeLista", "lista");
    
    tCelula *c = NULL;
    
    for(c = l->prim; c != NULL; c = c->prox){
        ImprimeCelula(c);
    }
}