//FEITO POR RAPHAEL CORREIA DORNELAS
#include <stdio.h>
#include <string.h>
#include "palavra.h"

struct palavra{
    char *str;
    int freq;
};

void assert(int exp, char *msg){
    if(!exp){
        if(msg)printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}

tPalavra *criaPalavra(char *str){
    assert(str != NULL, "str nula em criaPalavra");
    
    tPalavra *p = (tPalavra*)calloc(1, sizeof(tPalavra));
    assert(p != NULL, "falha na criacao de palavra");

    p->str = strdup(str);

    return p;
}

void liberaPalavra(tPalavra *p){
    if(!p) return;
    free(p->str);
    free(p);
}

void imprimePalavra(tPalavra *p, FILE *arq){
    if(!p)return;
    fprintf(arq, "%s %d\n", p->str, p->freq);
}

void incFreqPalavra(tPalavra *p){
    assert(p != NULL, "palavra nula em incFreq");
    (p->freq)++;
}

char *getStrPalavra(tPalavra *p){
    assert(p != NULL, "palavra nula em getStr");
    return p->str;
}

int getFreqPalavra(tPalavra *p){
    assert(p != NULL, "palavra nula em getFreq");
    return p->freq;
}