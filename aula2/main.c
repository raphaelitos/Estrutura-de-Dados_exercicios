#include <stdio.h>
#include <stdlib.h>
#include "tSupermercado.h"
#include "utils.h"

//AUXILIARES//

void processaAdicaoDeFiliais(tSupermercado *sm){
    if(!sm){
        TratarStructNula("processaAdicaoFiliais", "supermercado");
    }
    printf("#####ADICAO DE FILIAIS#####\n");
    while(1){
        int opcao = 0;
        AdicionaFilialSuperMercado(sm);
        printf("Deseja adicionar mais uma filial?\n");
        printf("\t1-SIM\n\t0-NAO\n");
        scanf("%d", &opcao);
        while(getchar() != '\n');

        if(!opcao){
            printf("###########################\n");
            break;
        }
    }
}

void processaAdicaoDeItens(tSupermercado *sm){
    if(!sm){
        TratarStructNula("processaAdicaoItens", "supermercado");
    }

    while(1){
        int opcao = 0;
        printf("#####ADICAO DE ITENS#####\n");
        AdicionaItemFilialSM(sm);
        printf("Deseja adicionar itens a outra filial?\n");
        printf("\t1-SIM\n\t0-NAO\n");
        scanf("%d", &opcao);
        while(getchar() != '\n');

        if(!opcao){
            printf("#########################\n");
            break;
        }
    }
}

//-----*-----//
int main(){
    tSupermercado *sm = CriaSupMercado();

    processaAdicaoDeFiliais(sm);
    processaAdicaoDeItens(sm);
    ProduzRelatorio(sm);

    DesalocaSuperMercado(sm);
}