#ifndef _TPILHADUPLA_H_
#define _TPILHADUPLA_H_

typedef struct PilhaD tPilhaD;
typedef int dataType;

typedef enum idPilha{
    PILHA_1 = 1,
    PILHA_2
}eIdPilha;

tPilhaD *criaPilhaD();

void desalocaPilhaD(tPilhaD *p);

dataType pop(tPilhaD *p, int idPilha);

void push(tPilhaD *p, dataType d, int idPilha);

void imprimePilhaD(tPilhaD *p);

#endif