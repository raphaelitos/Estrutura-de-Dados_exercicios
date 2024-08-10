#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define NOME_ARQ_ENTRADA "entrada"
#define TAM_MAX_ALUNOS 100
#define TAM_MAX_NOME 97
#define PRESENCA 'P'

int ehPrimo(int num){
    for(int i = 2; i < num; i++){
        if(!(num % i)){
            return 0;
        }
    }
    return 1;
}

int achaPrimoProx(int num){
    int i = num;
    while(1){
        if(ehPrimo(i)){
            return i;
        }
        i++;
    }
    
}

int main(){
    char nomeArq[strlen(NOME_ARQ_ENTRADA) + 7];
    sprintf(nomeArq, "%s.txt", NOME_ARQ_ENTRADA);

    char **alunos = (char **)calloc(TAM_MAX_ALUNOS, sizeof(char*));
    assert(alunos != NULL, "falha em alocacao de vetor de nome de alunos");

    for(int i = 0; i < TAM_MAX_ALUNOS; i++){
        alunos[i] = NULL;
    }

    int n = 0;
    int c = 0;
    
    FILE *input = fopen(nomeArq, "r");
    assert(input != NULL, "falha em abertura de input");
    fscanf(input, "N %d", &n);//numero de aulas
    if((c = fgetc(input)) == EOF){
        fclose(input);
        return 0;
    }

    char nome[TAM_MAX_NOME];
    int count = 0;//numero de alunos

    while(fscanf(input, "%s", nome) == 1){
        while(((c = fgetc(input)) != '\n') && c != EOF);//limpeza de buffer
        alunos[count++] = strdup(nome);
    }    
    
    fclose(input);

    tALuno *a = NULL;
    tHash *tab = criaHash(achaPrimoProx(count * 2));

    for(int i = 0; i < count; i++){//insercao dos alunos na hash
        a = criaAluno(alunos[i]);
        if(!insereHash(tab, a)){
            printf("falha ao inserir aluno na hash! Encerrando programa...\n");
            exit(EXIT_FAILURE);
        };
    }

    char presenca;
    
    for(int i = 1; i <= n; i++){//marcando faltas e presencas
        sprintf(nomeArq, "%s%d.txt", NOME_ARQ_ENTRADA, i);
        FILE *input = fopen(nomeArq, "r");

        for(int j = 0; j < count; j++){
            fscanf(input, "%s %c", nome, &presenca);
            while(((c = fgetc(input)) != '\n') && c != EOF);

            a = acessaHash(tab, nome);
            if(!a) continue;
            (presenca == PRESENCA)? incPresencaAluno(a) : incFaltaAluno(a);
        }
        fclose(input);
    }

    imprimeHash(tab);

    liberaHash(tab);

    for(int i = 0; i < count; i++){
        if(alunos[i])
            free(alunos[i]);
    }
    free(alunos);

    return 0;
    
}