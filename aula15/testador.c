#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hash.h"

#define TAMANHO 127 
#define MAX_TAM_STRING 45

int lePalavra(FILE *f, char *str){
    int i = 0, c = 0;

    while((c = fgetc(f)) != EOF){
        if(isalpha(c)) break;
    }
    if(c == EOF) return 0;

    str[i++] = c;

    while((c = fgetc(f)) != EOF && isalpha(c) && (i < (MAX_TAM_STRING - 1))){
        str[i++] = c;
    }
    str[i] = '\0';
    return 1;
}

int main(int argc, char *argv[]){
    
    if(argc <= 1){
        printf("informe o caminho do arquivo de entrada\n");
        return 0;
    }

    FILE *arq = fopen(argv[1], "r");
    assert(!arq, "falha na abertura de arquivo");


    tHash *tab = criaHash(TAMANHO);

    char str[MAX_TAM_STRING];

    while(lePalavra(arq, str)){
        //printf("%s\n", str);
        tPalavra *p = acessa(tab, str);
        incOcorrenciasPalavra(p);
    }

    imprimeHash(tab);
    

    liberaHash(tab);

    fclose(arq);
    return 0;
}