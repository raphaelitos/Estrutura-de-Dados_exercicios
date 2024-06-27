#ifndef TCACHORRO_H_
#define TCACHORRO_H_

#define BRAVO 1
#define MANSO -1

typedef struct cachorro tCachorro;

tCachorro* inicCachorro(char *nome, int temperamento);

int EhMansoCachorro(tCachorro *c);

int getTemperamentoCachorro(tCachorro *c);

void atribuiNivelAgressividadeCachorro(tCachorro* c, int temperamento);

void imprimeCachorro(tCachorro *c);

void liberaCachorro(tCachorro *c);

#endif