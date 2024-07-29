#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashgen.h"
#include "palavra.h"

#define TAMANHO 127 
#define MAX_TAM_STRING 45

int fHash(void *dado){
    assert(!dado, "string invalida em fhash");
    char *str = (char*)dado;
    int soma = 0;
    for(int i = 0; i < strlen(str); i++){
        soma += (int)str[i];
    }
    //printf("%d\n", soma);
    return soma;
}

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


    tHash *tab = cria(TAMANHO, sizeof(tPalavra*));

    char str[MAX_TAM_STRING];

    while(lePalavra(arq, str)){
        tPalavra *p = (tPalavra*)busca(tab, (void*)str, fHash, compPalavra);
        if(!p){
            p = criaPalavra(str);
            p = (tPalavra *)hash_insere(tab, (void*)str, (void*)p, fHash, compPalavra);
        }
        if(p) incOcorrenciasPalavra(p);
    }

    imprimeHashGen(tab, imprimePalavra);
    
    void **vet = getVetHash(tab);

    for(int i = 0; i < getTamHash(tab); i++){
        if(vet[i]){
            liberaPalavra((tPalavra*)vet[i]);
        }
    }

    libera(tab);

    fclose(arq);
    return 0;
}