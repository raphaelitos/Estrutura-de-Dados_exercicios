#ifndef TGATO_H_
#define TGATO_H_

#define BRAVO 1
#define MANSO -1

typedef struct gato tGato;

tGato* inicGato(char *nome, int temperamento);

int EhMansoGato(tGato *g);

int getTemperamentoGato(tGato *g);

void atribuiNivelAgressividadeGato(tGato* g, int temperamento);

void imprimeGato(tGato *g);

float valorGato(tGato *g);

void liberaGato(tGato *g);

#endif