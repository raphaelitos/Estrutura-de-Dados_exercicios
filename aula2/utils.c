#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define CHUNK_NOME 16

/**
 * Le a entrada ate que seja dada uma quebra de linha
 * e a registra dinamicamente
*/
char *LeNome(){
    char *nome = (char*)calloc(CHUNK_NOME, sizeof(char));
    int idx = 0, tam = CHUNK_NOME;
    char letra;
    
    while (1){
        if(idx == (tam - 1)){
            nome = (char*)realloc(nome, (tam + CHUNK_NOME) * sizeof(char));
            tam += CHUNK_NOME;
        }
        scanf("%c", &letra);
        if(letra == '\n'){
            nome[idx] = '\0';
            //while(getchar() != '\n');
            break;
        }
        nome[idx] = letra;
        idx++;
    }
    
    return nome;
}

void DesalocaNome(char *nome){
    free(nome);
}

/**
 * Se uma estrutura nula for detectada, encerra o programa apos
 * avisar a funcao onde isso ocorreu e de qual estrutura se trata
*/
void TratarStructNula(const char *nomeFuncao, const char *nomeVariavel){
	printf("%s nula na funcao %s!\n", nomeVariavel, nomeFuncao);
	exit(EXIT_FAILURE);
}

/**
 * No caso de uma alocacao falhar, encerra o programa apos indicar 
 * o tipo de dado que estava sendo alocado
*/
void TratarFalhaAlocacao(const char *nomeStruct){
	printf("Falha na criacao de %s", nomeStruct);
	exit(EXIT_FAILURE);
}