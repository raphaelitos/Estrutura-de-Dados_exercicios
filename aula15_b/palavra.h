#ifndef _PALAVRA_H_
#define _PALAVRA_H_

typedef struct palavra tPalavra;

void assert(int exp, char *msg);

tPalavra* criaPalavra(char *str);

void liberaPalavra(tPalavra *p);

void imprimePalavra(void *dado);

void incOcorrenciasPalavra(tPalavra *p);

int getOcorrenciasPalavra(tPalavra *p);

char* getStrPalavra(tPalavra *p);

int getTamListaPalavras(tPalavra *p);

tPalavra* buscaPalavra(tPalavra *p, char *str);

tPalavra* inserePalavraLista(tPalavra *lista, tPalavra *p);

int compPalavra(void *dado, void *key);

#endif