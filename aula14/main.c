/**
 * Feita com base no arquivo main do exercicio 13
*/

#include <stdio.h>
#include "abbgen.h"
#include "tAluno.h"

int main() {
    // Criação da árvore binária de busca
    tAbbg *arvore = criaABB();

    // Criação de alguns alunos
    tAluno *aluno1 = criaAluno("João", 123);
    tAluno *aluno2 = criaAluno("Maria", 456);
    tAluno *aluno3 = criaAluno("Pedro", 789);
    tAluno *aluno4 = criaAluno("Ana", 101);

    // Inserção dos alunos na árvore
    arvore = insereAbb(arvore, aluno1);
    arvore = insereAbb(arvore, aluno2);
    arvore = insereAbb(arvore, aluno3);
    arvore = insereAbb(arvore, aluno4);

    // Impressão da árvore em ordem crescente
    printf("Árvore em ordem crescente:\n");
    imprime(arvore);

    // Busca por um aluno específico
    int matriculaParaBuscar = 456;
    tAluno *encontrado = buscaAbb(arvore, matriculaParaBuscar);
    if (encontrado) {
        printf("\nAluno encontrado:\n");
        imprimeAluno(encontrado);
        //printf("\nAluno encontrado: %s, Matrícula: %d\n", encontrado->nome, encontrado->matricula);
    } else {
        printf("\nAluno com matrícula %d não encontrado.\n", matriculaParaBuscar);
    }

    // Remoção de um aluno da árvore
    int matriculaParaRemover = 456;
    arvore = retiraAbb(arvore, matriculaParaRemover);
    
    // Impressão da árvore após a remoção
    printf("\nÁrvore após a remoção do aluno com matrícula %d:\n", matriculaParaRemover);
    imprimeAbb(arvore);

    // Liberação da memória utilizada pela árvore
    desalocaaAbb(arvore);

    // Liberação da memória utilizada pelos alunos
    desalocaAluno(aluno1);
    desalocaAluno(aluno2);
    desalocaAluno(aluno3);
    desalocaAluno(aluno4);

    return 0;
}