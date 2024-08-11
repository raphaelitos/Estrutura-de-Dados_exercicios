#ifndef _PALAVRA_H_
#define _PALAVRA_H_

typedef struct palavra tPalavra;

void assert(int exp, const char *msg);

tPalavra *criaPalavra(char *str);

void liberaPalavra(tPalavra *p);

void imprimePalavra(tPalavra *p);

void incFreqPalavra(tPalavra *p);

char *getStrPalavra(tPalavra *p);

int getFreqPalavra(tPalavra *p);

#endif