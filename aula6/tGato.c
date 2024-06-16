#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "tGato.h"

struct gato{
    char* nome;
    int temperamento;
};

tGato* inicGato(char *nome, int temperamento){
    if(!nome){
        TratarStructNula("inicGato", "nome");
    }
    
    tGato *g = calloc(1, sizeof(tGato));
    g->nome = strdup(nome);
    g->temperamento = temperamento;

    return g;
}

int EhMansoGato(tGato *g){
    return(g->temperamento == MANSO);
}

int getTemperamentoGato(tGato *g){
    if(!g) TratarStructNula("gettemperamento", "gato");
    return g->temperamento;
}

void atribuiNivelAgressividadeGato(tGato* g, int temperamento){
    if(!g){
        TratarStructNula("atribuiTempGato", "gato");
    }
    g->temperamento = temperamento;
}

char *converteTemperamentog(int temperamento){
    //char temp[7];
    
    if(temperamento == MANSO) return "MANSO";//strcpy(temp, "MANSO");
    else return "BRAVO";//strcpy(temp, "BRAVO");
    
}

void imprimeGato(tGato *g){
    if(!g) TratarStructNula("imprime", "gato");

    printf("\tEspecie: GATO | Nome: %s | Temperamento: %s\n", g->nome, converteTemperamentog(g->temperamento));
}

float valorGato(tGato *g){
    if(!g) TratarStructNula("valor", "gato");
}

void liberaGato(tGato *g){
    if(!g){
        TratarStructNula("liberaGato", "gato");
    }
    free(g->nome);
    free(g);
}