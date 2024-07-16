/**
 * Testador feito com auxilio do ChatGPT
 * 15/07/24
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabelaRot.h"

int main() {
    tTabela *tabela = criaTabela();
    srand(time(NULL)); // Inicializa a semente para números randômicos
    int teste = 0;

    // Inserindo 20 endereços na tabela com valores randômicos
    for (int i = 0; i < 53; i++) {
        int destination = rand() % 1000; // destination randômico entre 0 e 999
        int nextHop = rand() % 100;      // nextHop randômico entre 0 e 99
        teste = destination;
        tEndereco *e = criaEndereco(destination, nextHop);
        insereTabela(tabela, e);
    }

    // Imprimindo a tabela após inserções
    printf("Tabela de endereços inicial:\n");
    printTabela(tabela);

    // Testando acesso a alguns endereços randômicos
    for (int i = 0; i < 5; i++) {
        int chave = rand() % 1000; // chave randômica entre 0 e 999
        tEndereco *end = acessaTabela(tabela, chave);
        if (end) {
            printf("Endereço encontrado: Destination %d, NextHop %d\n", getDestination(end), getNextHop(end));
        }
    }

    // Testando acesso a um endereço certamente existente
    int chaveExistente = teste;
    tEndereco *endExistente = acessaTabela(tabela, chaveExistente);
    if (endExistente != NULL){
        printf("Endereço encontrado: Destination %d, NextHop %d\n", getDestination(endExistente), getNextHop(endExistente));
    }

    // Imprimindo a tabela após acessos e inserções
    printf("Tabela de endereços após acessos e inserções:\n");
    printTabela(tabela);

    // Desalocando a tabela
    desalocaTabela(tabela);

    return 0;
}
