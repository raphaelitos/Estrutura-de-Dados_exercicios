#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tMultiplhas.h"

#define NUM_ELEMENTOS 100

int main() {
    // Criar a estrutura MultiPilha
    tMultipilha *pilha = criaPilha();
    
    // Vetor estático com NUM_ELEMENTOS inteiros
    int valores[NUM_ELEMENTOS];
    
    // Inicializar o gerador de números aleatórios
    srand(time(NULL));

    // Preencher o vetor com valores aleatórios
    for (int i = 0; i < NUM_ELEMENTOS; i++) {
        valores[i] = rand() % 100; // Valores aleatórios entre 0 e 99
    }

    // Teste de push em diferentes pilhas
    printf("Realizando operacoes de push...\n");
    for (int i = 0; i < NUM_ELEMENTOS; i++) {
        int idPilha = i % N; // Distribuir elementos entre as pilhas
        printf("Inserindo valor %d na pilha %d...\n", valores[i], idPilha);
        push(pilha, &valores[i], idPilha); // Realizar o push
    }

    push(pilha, &valores[10], 11);
    push(pilha, &valores[10], 0);
    push(pilha, &valores[8], 0);
    push(pilha, &valores[9], 0);


    // Impressão das pilhas
    printf("\nConteudo das pilhas apos push:\n");
    imprimePilha(pilha);

    // Teste de pop em diferentes pilhas
    printf("\nRealizando operacoes de pop...\n");
    for (int i = 0; i < N; i++) {
        printf("Removendo valor da pilha %d...\n", i);
        int *valor_removido = pop(pilha, i);
        if (valor_removido != NULL) {
            printf("Valor removido: %d\n", *valor_removido);
        } else {
            printf("Nenhum valor removido. A pilha estava vazia.\n");
        }
    }

    int p = 0;
    for(int j = 0; j < 11; j++){
        printf("Removendo valor da pilha %d...\n", p);
        int *valor_removido = pop(pilha, p);
        if (valor_removido != NULL) {
            printf("Valor removido: %d\n", *valor_removido);
        } else {
            printf("Nenhum valor removido. A pilha estava vazia.\n");
        }
    }

    // Impressão das pilhas após pop
    printf("\nConteudo das pilhas apos pop:\n");
    imprimePilha(pilha);

    // Desalocação da estrutura MultiPilha
    desalocaPilha(pilha);

    return 0;
}
