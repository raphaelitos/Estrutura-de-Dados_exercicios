//FEITO POR RAPHAEL CORREIA DORNELAS
//PODE TESTAR AS DUAS ETAPAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abb.h"

#define TAM_MAX_PLV 51 
#define NOME_ARQ_ENTRADA1 "entrada1.txt"
#define NOME_ARQ_SAIDA1 "saida1.txt"
#define NOME_ARQ_ENTRADA2 "entrada2.txt"
#define NOME_ARQ_SAIDA2 "saida2.txt"


int lePalavra(FILE *arq , char *str){
    int i = 0, c;
    while((c = fgetc(arq)) != EOF){//pulando oq nao eh letra
        if(isalpha(c)) break;
    }
    if(c == EOF) return 0;

    str[i++] = (char)c;

    while((c = fgetc(arq)) != EOF && isalpha(c) && i < (TAM_MAX_PLV - 1)){
        str[i++] = (char)c;
    }
    str[i] = '\0';
    return 1;
}

int compara(const void *d1, const void *d2){
    assert((d1 && d2), "dados nulos em compara");

    tPalavra *p1 = (*(tPalavra**)d1);
    tPalavra *p2 = (*(tPalavra**)d2);

    return (getFreqPalavra(p1) - getFreqPalavra(p2));
}

void output(tAbb *abb, char *nomeArqOut){
    tPalavra **vet = (tPalavra**)calloc(qtdPlvAbb(abb), sizeof(tPalavra*));
    assert(vet != NULL, "falha em alocacao de vet de palavras");
    int id = 0, tam = qtdPlvAbb(abb);
    getInfoAbb(abb, vet, &id);
        
    tPalavra *p = getPlvAbb(abb);
    maxFreqPlvAbb(abb, &p);

    FILE *out = fopen(nomeArqOut, "w");
    assert(out != NULL, "falha na abertura de arquivo de saida");

    qsort(vet, tam, sizeof(tPalavra*), compara);

    for(int i = 0; i < tam; i++){
        imprimePalavra(vet[i], out);
    }

    fprintf(out, "\n------------------------\n");
    fprintf(out, "%d palavras distintas encontradas\n", tam);
    fprintf(out, "%d palavras no total\n", somaFreqAbb(abb));
    fprintf(out, "'%s' é a palavra de maior frequência (%d)", 
            getStrPalavra(p), getFreqPalavra(p));

    free(vet);
    fclose(out);
}

void teste(char *nomeArqIn, char *nomeArqOut){
    assert((nomeArqIn && nomeArqOut), "nome nulo em teste");
    
    FILE *arqIn = fopen(nomeArqIn, "r");
    assert(arqIn != NULL, "falha em abrir arquivo entrada");

    char str[TAM_MAX_PLV];
    tAbb *abb = criaAbb();
    while(lePalavra(arqIn, str)){
        abb = insereAbb(abb, str);
    }
    
    output(abb, nomeArqOut);
    
    fclose(arqIn);
    liberaAbb(abb);
}

int main(){

    teste(NOME_ARQ_ENTRADA1, NOME_ARQ_SAIDA1);
    teste(NOME_ARQ_ENTRADA2, NOME_ARQ_SAIDA2);

}