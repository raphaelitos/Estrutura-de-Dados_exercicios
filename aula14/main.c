/**
 * Feita com base no arquivo main do exercicio 13
*/

#include <stdio.h>
#include "abbgen.h"
#include "tAluno.h"

int main() {
    // Criação da árvore binária de busca
    tAbbg *arvore1 = criaABB();
    tAbbg *arvore2 = criaABB();


    // Criação de alguns alunos
    tAluno *aluno1 = criaAluno("João", 123);
    tAluno *aluno2 = criaAluno("Maria", 456);
    tAluno *aluno3 = criaAluno("Pedro", 789);
    tAluno *aluno4 = criaAluno("Ana", 101);
    tAluno *aluno5 = criaAluno("Milena", 777);
    tAluno *aluno6 = criaAluno("Sara", 142);
    tAluno *aluno7 = criaAluno("Iarlen", 897);


    // Inserção dos alunos na árvore ordenada por matricula
    arvore1 = insereAbb(arvore1, aluno1, comparaAlunoMatricula);
    arvore1 = insereAbb(arvore1, aluno2, comparaAlunoMatricula);
    arvore1 = insereAbb(arvore1, aluno3, comparaAlunoMatricula);
    arvore1 = insereAbb(arvore1, aluno4, comparaAlunoMatricula);
    arvore1 = insereAbb(arvore1, aluno5, comparaAlunoMatricula);
    arvore1 = insereAbb(arvore1, aluno6, comparaAlunoMatricula);
    arvore1 = insereAbb(arvore1, aluno7, comparaAlunoMatricula);

    // Inserção dos alunos na árvore ordenada por nome
    arvore2 = insereAbb(arvore2, aluno1, comparaAlunoNome);
    arvore2 = insereAbb(arvore2, aluno2, comparaAlunoNome);
    arvore2 = insereAbb(arvore2, aluno3, comparaAlunoNome);
    arvore2 = insereAbb(arvore2, aluno4, comparaAlunoNome);
    arvore2 = insereAbb(arvore2, aluno5, comparaAlunoNome);
    arvore2 = insereAbb(arvore2, aluno6, comparaAlunoNome);
    arvore2 = insereAbb(arvore2, aluno7, comparaAlunoNome);

    // Impressão da árvore em ordem crescente
    printf("Árvore em ordem crescente [matricula]:\n");
    imprimeAbb(arvore1, imprimeAluno);

    // Impressão da árvore em ordem crescente
    printf("Árvore em ordem crescente [nome]:\n");
    imprimeAbb(arvore2, imprimeAluno);

    // Busca por um aluno específico
    int matriculaParaBuscar = 456;
    tAluno *encontrado = buscaAbb(arvore1, (void*)(&matriculaParaBuscar), comparaMatricula);
    if (encontrado) {
        printf("\nAluno encontrado:\n");
        imprimeAluno(encontrado);
    } else {
        printf("\nAluno com matrícula %d não encontrado.\n", matriculaParaBuscar);
    }
    char *nomeBusca = "Sara";
    encontrado = buscaAbb(arvore2, (void*)(nomeBusca), comparaNome);
    if (encontrado) {
        printf("\nAluno encontrado:\n");
        imprimeAluno(encontrado);
    } else {
        printf("\nAluno com nome %s não encontrado.\n", nomeBusca);
    }

    // Remoção de um aluno da árvore
    int matriculaParaRemover = 456;
    arvore1 = retiraAbb(arvore1, (void*)(&matriculaParaRemover), comparaMatricula);
    printf("\nÁrvore após a remoção do aluno com matrícula %d:\n", matriculaParaRemover);
    imprimeAbb(arvore1, imprimeAluno);
    
    char *nomeRemove = "Milena";
    arvore2 = retiraAbb(arvore2, (void*)nomeRemove, comparaNome);
    printf("\nÁrvore após a remoção do aluno com nome %s:\n", nomeRemove);
    imprimeAbb(arvore2, imprimeAluno);

    // Liberação da memória utilizada pela árvore
    desalocaaAbb(arvore1);
    desalocaaAbb(arvore2);

    // Liberação da memória utilizada pelos alunos
    desalocaAluno(aluno1);
    desalocaAluno(aluno2);
    desalocaAluno(aluno3);
    desalocaAluno(aluno4);
    desalocaAluno(aluno5);
    desalocaAluno(aluno6);
    desalocaAluno(aluno7);

    return 0;
}