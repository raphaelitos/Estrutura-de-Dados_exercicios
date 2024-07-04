/**
 * testador feito com ajuda do chatGPT
 */

#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main() {
    // Criação da árvore binária de busca
    tAbb *arvore = criaABB();

    // Criação de alguns alunos
    tAluno *aluno1 = criaAluno("João", 123);
    tAluno *aluno2 = criaAluno("Maria", 456);
    tAluno *aluno3 = criaAluno("Pedro", 789);
    tAluno *aluno4 = criaAluno("Ana", 101);
    tAluno *aluno5 = criaAluno("Jao", 125);
    tAluno *aluno6 = criaAluno("Clodovil", 119);


    // Inserção dos alunos na árvore
    arvore = insere(arvore, aluno1);
    arvore = insere(arvore, aluno2);
    arvore = insere(arvore, aluno3);
    arvore = insere(arvore, aluno4);
    arvore = insere(arvore, aluno5);
    arvore = insere(arvore, aluno6);

    // Impressão da árvore em ordem crescente
    printf("Árvore em ordem crescente:\n");
    imprime(arvore);

    // Busca por um aluno específico
    int matriculaParaBuscar = 456;
    tAluno *encontrado = busca(arvore, matriculaParaBuscar);
    if (encontrado) {
        printf("\nAluno encontrado:\n");
        imprimeAluno(encontrado);
        //printf("\nAluno encontrado: %s, Matrícula: %d\n", encontrado->nome, encontrado->matricula);
    } else {
        printf("\nAluno com matrícula %d não encontrado.\n", matriculaParaBuscar);
    }

    // Remoção de um aluno da árvore
    int matriculaParaRemover = 123;
    arvore = retira(arvore, matriculaParaRemover);
    
    // Impressão da árvore após a remoção
    printf("\nÁrvore após a remoção do aluno com matrícula %d:\n", matriculaParaRemover);
    imprime(arvore);

    // Liberação da memória utilizada pela árvore
    liberaArvore(arvore);

    // Liberação da memória utilizada pelos alunos
    desalocaAluno(aluno1);
    desalocaAluno(aluno2);
    desalocaAluno(aluno3);
    desalocaAluno(aluno4);

    return 0;
}
