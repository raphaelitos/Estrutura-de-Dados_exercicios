#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

struct palavra{
    char *str;
    int freq;
};

void assert(int exp, const char *msg){
    if(!exp){
        if(msg) printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}

tPalavra *criaPalavra(char *str){
    assert(str != NULL, "str nula em criaPalavra");
    
    tPalavra *p = calloc(1, sizeof(tPalavra));
    assert(p != NULL, "falha na alocacao de p");
    
    p->str = strdup(str);

    return p;
}

void liberaPalavra(tPalavra *p){
    if(!p) return;
    free(p->str);
    free(p);
}

void imprimePalavra(tPalavra *p){
    if(!p) return;
    printf("%s %d\n", p->str, p->freq);
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