#ifndef _MULTIPLILHAS_H_
#define _MULTIPLILHAS_H_

typedef struct MultiPilha tMultipilha;
typedef int* dataType;

#define MAX_TAM 100
#define N 10
#define CHUNK MAX_TAM/N

tMultipilha *criaPilha();

void desalocaPilha(tMultipilha *p);

void push(tMultipilha *p, dataType  d, int idPilha);

dataType pop(tMultipilha *p,  int idPilha);

void imprimePilha(tMultipilha *p);

#endif