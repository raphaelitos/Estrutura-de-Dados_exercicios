#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "tCachorro.h"

struct cachorro{
    char* nome;
    int temperamento;
};

tCachorro* inicCachorro(char *nome, int temperamento){
    if(!nome){
        TratarStructNula("inicCachorro", "nome");
    }
    
    tCachorro *c = calloc(1, sizeof(tCachorro));
    c->nome = strdup(nome);
    c->temperamento = temperamento;

    return c;
}

int EhMansoCachorro(tCachorro *c){
    if(!c){
        TratarStructNula("ehmanso", "cachorro");
    }
    return (c->temperamento == MANSO);
}

int getTemperamentoCachorro(tCachorro *c){
    if(!c) TratarStructNula("gettemperamento", "Cachorro");
    return c->temperamento;
}

void atribuiNivelAgressividadeCachorro(tCachorro* c, int temperamento){
    if(!c){
        TratarStructNula("atribuiTempCachorro", "Cachorro");
    }
    c->temperamento = temperamento;
}

char *converteTemperamento(int temperamento){
   if(temperamento == MANSO) return "MANSO";//strcpy(temp, "MANSO");
    else return "BRAVO";//strcpy(temp, "BRAVO");
}

void imprimeCachorro(tCachorro *c){
    if(!c) TratarStructNula("imprime", "Cachorro");

    printf("\tEspecie: CACHORRO | Nome: %s | Temperamento: %s\n", c->nome, converteTemperamento(c->temperamento));
}

void liberaCachorro(tCachorro *c){
    if(!c){
        TratarStructNula("liberaCachorro", "Cachorro");
    }
    free(c->nome);
    free(c);
}