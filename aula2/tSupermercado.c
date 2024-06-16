#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tSupermercado.h"
#include "vector.h"
#include "utils.h"

struct Supermercado{
    char *nome;
    Vector *filiais;
    int qtdTotalEstoque;
};

//Auxiliares//

tFilial *SelecionaFilialMercado(tSupermercado *sm, char *nome){
    if(!sm){
        TratarStructNula("SelecionaFilial", "supermercado");
    }
    tFilial *f = NULL;
    for(int i = 0; i < VectorSize(sm->filiais); i++){
        f = (tFilial*)VectorGet(sm->filiais, i);
        if(!strcmp(nome, getNomeFilial(f))){
            return f;
        }
    }
    f = NULL;
    return f;
}

//----*----//

tSupermercado *CriaSupMercado(){
    tSupermercado *sm = (tSupermercado*)calloc(1, sizeof(tSupermercado));
    if(!sm){
        TratarFalhaAlocacao("Supermercado");
    }
    sm->filiais = VectorConstruct();
    printf("Digite o nome do seu SuperMercado: ");
    sm->nome = LeNome();
    return sm;
}

void DesalocaSuperMercado(tSupermercado *sm){
    if(!sm){
        TratarStructNula("Desaloca", "Supermercado");
    }
    VectorDestroy(sm->filiais, DesalocaFilial);
    DesalocaNome(sm->nome);
    free(sm);
}

void AdicionaFilialSuperMercado(tSupermercado *sm){
    if(!sm){
        TratarStructNula("adicionaFilial", "supermercado");
    }
    
    char *nome = NULL;
    printf("Digite o nome da filial: ");

    while(1){
        nome = LeNome();
        if(!SelecionaFilialMercado(sm, nome)){
            tFilial *f = CriaFilial(nome);
            VectorPushBack(sm->filiais, f);
            printf("Filial adicionada com sucesso!\n\n");
            DesalocaNome(nome);
            break;
        }
        
        printf("Uma filial com esse nome ja existe! Digite novamente\n");
        DesalocaNome(nome);
    }

}

void AdicionaItemFilialSM(tSupermercado *sm){
    if(!sm){
        TratarStructNula("adicionaItemFilialSM", "supermercado");
    }

    printf("Digite o nome de uma filial cadastrada: ");
    
    while (1){
        char *nome = LeNome();
        tFilial *f = SelecionaFilialMercado(sm, nome); 
        DesalocaNome(nome);
        tItem *i = NULL;
        if(f != NULL){
            int opcao = 0;
            while(1){
                i = LeItem();
                AcrescentaItemFilial(f, i);
                (sm->qtdTotalEstoque) += getQtdItem(i);        
                printf("Deseja adcionar mais um item a essa filial?\n");
                printf("1-SIM\n0-NAO\n");
                scanf("%d", &opcao);
                while(getchar() != '\n');
                if(!opcao){
                    printf("#############################\n");
                    break;
                }
            }    
            break;
        }
        else{
            printf("Filial nao encontrada! Tente novamente\n");
        }
    }
}

int getEstoqueSM(tSupermercado *sm){
    if(!sm){
        TratarStructNula("getEstoque", "Supermercado");
    }
    return sm->qtdTotalEstoque;
}

void ProduzRelatorio(tSupermercado *sm){
    if(!sm){
        TratarStructNula("ProduzRelatorio", "Supermercado");
    }
    printf("#####RELATORIO GERAL#####\n");
    printf("NOME: %s | ESTOQUE TOTAL: %d\n\n", sm->nome, sm->qtdTotalEstoque);
    tFilial *f = NULL;
    for(int i = 0; i < VectorSize(sm->filiais); i++){
        f = (tFilial *)VectorGet(sm->filiais, i);
        ImprimeFilial(f);
    }
    printf("#########################\n");
}