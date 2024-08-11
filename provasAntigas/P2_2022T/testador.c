#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "abb.h"

#define MAX_TAM_PLV 50
#define NOME_ARQ_ENTRADA "entrada.txt"

int compara(const void *d1, const void *d2){
    assert((d1 && d2), "dados nulos na ordenacao");
    tPalavra *p1 = (*((tPalavra**)d1));
    tPalavra *p2 = (*((tPalavra**)d2));

    return getFreqPalavra(p1) - getFreqPalavra(p2);
}

int lePalavra(char *str, FILE *arq){
    int c = 0, i = 0;

    while((c = fgetc(arq)) != EOF){ //pulando oq nao eh caractere
        if(isalpha(c)) break;
    }

    if(c == EOF) return 0;

    str[i++] = (char)c;

    while(((c = fgetc(arq)) != EOF) && isalpha(c) && (i < (MAX_TAM_PLV - 2))){
        str[i++] = (char)c;
    }
    str[i] = '\0';
    return 1;
}

tPalavra **criaVetPalavraAbb(tAbb *abb){
    if(!abb) return NULL;
    int tam = tamAbb(abb);
    tPalavra **vet = (tPalavra**)calloc(tam, sizeof(tPalavra*));
    assert(vet != NULL, "falha em alocacao de vet para dump");
    
    int id = 0;
    getInfoAbb(abb, &id, vet, tam);
    
    return vet;
}

void ImprimeVetPalavra(tPalavra **vet, int tam){
    if(!vet)return;
    for(int i = 0; i < tam; i++){
        imprimePalavra(vet[i]);
    }
}

void output(tAbb *abb){
    if(!abb) return;
    tPalavra *max = getPalavraAbb(abb);
    PalavraMaisFreqAbb(abb, &max);
    
    int tam = tamAbb(abb);

    tPalavra **vet = criaVetPalavraAbb(abb);
    
    qsort(vet, tam, sizeof(tPalavra*), compara);


    printf("arvore em ordem alfabetica:\n");
    imprimeAbb(abb);
    printf("\n----------\n");
    printf("arvore ordenada por frequencia:\n");
    ImprimeVetPalavra(vet, tam);
    printf("\n----------\n");
    printf("%d palavras distintas encontradas\n", tam);
    printf("%d palavras no total\n", qtdFrequenciasAbb(abb));
    printf("%s é a palavra de maior frequência (%d)\n", getStrPalavra(max), getFreqPalavra(max));
    
    free(vet);
}

int main(){
    FILE *arq = fopen("entrada.txt", "r");
    assert(arq != NULL, "falha em abertura de arquivo");
    
    char str[MAX_TAM_PLV];
    tAbb *abb = criaAbb();

    while (lePalavra(str, arq)){
        abb = insereAbb(abb, str);
    }

    output(abb);

    liberaAbb(abb);
    
    fclose(arq);
    
    return EXIT_SUCCESS;
}