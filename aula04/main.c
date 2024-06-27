#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLista.h"
#include "utils.h"

void RetiraCelulaLista(tLista *l){
    if(!l) TratarStructNula("RetiraCelula", "lista");
    
    printf("Codigo do produto a ser retirado: ");
    
    char codigo[TAM_MAX_CODIGO];
    scanf("%14[^\n]", codigo);
    while(getchar() != '\n');
    
    RetiraLista(l, codigo);
}

int main(){

    tProduto *p1 = LeProduto();
    tProduto *p2 = LeProduto();
    tProduto *p3 = LeProduto();
    tProduto *p4 = LeProduto();
    printf("Quatro produtos criados!\n");

    tLista *lis = CriaLista();

    InsereLista(lis, p1);
    InsereLista(lis, p2);
    InsereLista(lis, p3);
    InsereLista(lis, p4);
    printf("Todos os produtos foram inseridos na lista!\n");

    int opcao = 0;
    
    printf("Deseja retirar algum item da lista?\n");
    printf("\t1-sim\n\t0-nao\n");
    scanf("%d", &opcao);
    while(getchar() != '\n');
    
    while(opcao){
        RetiraCelulaLista(lis);
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