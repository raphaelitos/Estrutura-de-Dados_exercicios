#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tFilial.h"
#include "vector.h"
#include "utils.h"

struct Filial{
    char *nome;
    tEstoque *estoque;
};

tFilial *CriaFilial(char *nome){
    tFilial *f = (tFilial *)calloc(1, sizeof(tFilial));
    if(!f){
        TratarFalhaAlocacao("filial");
    }
    f->estoque = CriaEstoque();
    f->nome = strdup(nome);

    return f;
}

void DesalocaFilial(void *dado){
    if(!dado){
        TratarStructNula("DesalocaFilial", "filial");
    }
    tFilial *f = (tFilial*)dado;
    DesalocaNome(f->nome);
    DesalocaEstoque(f->estoque);
    free(f);
}

void AcrescentaItemFilial(tFilial *f, tItem *i){
    if(!f || !i){
        TratarStructNula("AcrescentaItemFilial", "filial ou item");
    }
    AcrescentaItemEstoque(f->estoque, i);
}

int getQtdEstoqueFilial(tFilial *f){
    if(!f){
        TratarStructNula("getQtd", "filial");
    }
    return getQtdEstoque(f->estoque);
}

char *getNomeFilial(tFilial *f){
    if(!f){
        TratarStructNula("getNome", "filial");
    }
    return (f->nome);
}

void ImprimeFilial(tFilial *f){
    if(!f){
        TratarStructNula("Imprime", "Filial");
    }
    printf("\tFILIAL: %s\n", f->nome);
    ImprimeEstoque(f->estoque);
}