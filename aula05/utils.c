#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

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