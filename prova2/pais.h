#ifndef _PAIS_H_
#define _PAIS_H_

typedef struct pais tPais;

#include <stdlib.h>

int totalMedalhasPais(tPais *p);

void assert(int exp, char *msg);

tPais *criaPais(char *nome, int ouros, int pratas, int bronzes);

void liberaPais(tPais *p);

void imprimePais(tPais *p);

void imprimeArqPais(tPais *p, FILE *arq);

tPais *inserePais(tPais *lista, tPais *p);

tPais *buscaPais(tPais *lista, char *nome);

int getOurosPais(tPais *p);

int getPratasPais(tPais *p);

int getBronzesPais(tPais *p);

char *getNomePais(tPais *p);

void atualizaMedalhasPais(tPais *p, int ouros, int pratas, int bronzes);

int getTamListaPais(tPais *p);

void dumpVetPais(tPais *lista, tPais **vet, int *indice);

#endif