#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLista.h"
#include "utils.h"

tCelula* RetiraCelulaLista(tCelula *l){
    if(!l) TratarStructNula("RetiraCelula", "lista");
    
    printf("Codigo do produto a ser retirado: ");
    
    char codigo[TAM_MAX_CODIGO];
    scanf("%14[^\n]", codigo);
    while(getchar() != '\n');
    
    l = RetiraLista(l, codigo);
    return l;
}

int main(){

    tProduto *p1 = LeProduto();
    tProduto *p2 = LeProduto();
    tProduto *p3 = LeProduto();
    tProduto *p4 = LeProduto();
    printf("Quatro produtos criados!\n");

    tCelula *lis = CriaLista();

    lis = InsereLista(lis, p1);
    lis = InsereLista(lis, p2);
    lis = InsereLista(lis, p3);
    lis = InsereLista(lis, p4);
    printf("Todos os produtos foram inseridos na lista!\n");

    int opcao = 0;
    
    printf("Deseja retirar algum item da lista?\n");
    printf("\t1-sim\n\t0-nao\n");
    scanf("%d", &opcao);
    while(getchar() != '\n');
    
    while(opcao){
        lis = RetiraCelulaLista(lis);
        printf("Deseja repetir a operacao?\n");
        printf("\t1-sim\n\t0-nao\n");
        scanf("%d", &opcao);
        while(getchar() != '\n');

    }

    ImprimeLista(lis);
    DesalocaLista(lis);

    DesalocaProduto(p1);
    DesalocaProduto(p2);
    DesalocaProduto(p3);
    DesalocaProduto(p4);

    return 0;
}