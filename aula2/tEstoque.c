#include <stdio.h>
#include <stdlib.h>
#include "tEstoque.h"
#include "vector.h"
#include "utils.h"

struct Estoque{
    int qtdTotal;
    Vector *itens;
};

tEstoque *CriaEstoque(){
    tEstoque *e = (tEstoque*)calloc(1, sizeof(tEstoque));
    if(!e){
        TratarFalhaAlocacao("estoque");
    }
    e->itens = VectorConstruct();
    return e;
}

void DesalocaEstoque(tEstoque *e){
    if(!e){
        TratarStructNula("DestroiEstoque", "Estoque");
    }
    VectorDestroy(e->itens, DesalocaItem);
    free(e);
}

void AcrescentaItemEstoque(tEstoque *e, tItem *i){
    if(!e || !i){
        TratarStructNula("AcrescentaItemEstoque", "Estoque ou item");
    }
    VectorPushBack(e->itens, i);        
   (e->qtdTotal) += getQtdItem(i);
}

int getQtdEstoque(tEstoque *e){
    if(!e){
        TratarStructNula("getQtd", "estoque");
    }
    return(e->qtdTotal);
}

void ImprimeEstoque(tEstoque *e){
    if(!e){
        TratarStructNula("Imprime", "Estoque");
    }
    tItem *item = NULL;
    printf("\tESTOQUE: %d\n", e->qtdTotal);
    for(int i = 0; i < VectorSize(e->itens); i++){
        item = VectorGet(e->itens, i);
        ImprimeItem(item);
    }
}