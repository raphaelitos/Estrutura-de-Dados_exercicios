#include <stdio.h>
#include "tPilhaDupla.h"

int main() {
    // Criação da pilha dupla
    tPilhaD *pilha = criaPilhaD();
    
    // Dados para teste
    dataType dados1[] = {10, 20, 30, 40, 50};
    dataType dados2[] = {60, 70, 80, 90, 100};

    // Adicionando elementos na Pilha 1
    printf("Pushing to Pilha 1:\n");
    for (int i = 0; i < 5; i++) {
        printf("Pushing %d\n", dados1[i]);
        push(pilha, dados1[i], PILHA_1);
        imprimePilhaD(pilha);
    }

    // Adicionando elementos na Pilha 2
    printf("\nPushing to Pilha 2:\n");
    for (int i = 0; i < 5; i++) {
        printf("Pushing %d\n", dados2[i]);
        push(pilha, dados2[i], PILHA_2);
        imprimePilhaD(pilha);
    }

    // Pop dos elementos da Pilha 1
    printf("\nPopping from Pilha 1:\n");
    dataType item;
    for (int i = 0; i < 5; i++) {
        item = pop(pilha, PILHA_1);
        printf("Popped %d from Pilha 1\n", item);
        imprimePilhaD(pilha);
    }

    // Pop dos elementos da Pilha 2
    printf("\nPopping from Pilha 2:\n");
    for (int i = 0; i < 5; i++) {
        item = pop(pilha, PILHA_2);
        printf("Popped %d from Pilha 2\n", item);
        imprimePilhaD(pilha);
    }

    //casos de contorno
    pop(pilha, PILHA_1);
    push(pilha, 33, 3);
    push(pilha, 33, 2);

    imprimePilhaD(pilha);


    // Desaloca a memória da pilha
    desalocaPilhaD(pilha);

    return 0;
}
