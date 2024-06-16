#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Jornal.h"

typedef struct celula tCelula;

struct celula{
    Noticia *item;
    tCelula *prox;
    tCelula *ant;
    time_t publicada;
};

static tCelula* criaCelula(Noticia *n){
    if(!n){
        printf("noticia nulo enviado para criacao de celula\n");
        exit(EXIT_FAILURE);
    }
   
    tCelula *c = (tCelula*)calloc(1, sizeof(tCelula));
    if(!c){
        printf("Falha na alocacao de celula\n");
        exit(EXIT_FAILURE);
    }
    
    c->item = n;
    c->prox = c->ant = NULL;

    return c;
}

static void desalocaCelula(tCelula *c){
    free(c);
}

struct jornal{
    char *nome;
    tCelula *prim;
    tCelula *ult;
    int tam;
};

static int EstaVazioJornal(Jornal *j){
    return(j->tam == 0);
}

Jornal* criaJornal(char* nome){
    Jornal *j = (Jornal*)calloc(1, sizeof(Jornal));
    if(!j){
        printf("Falha na alocacao de jornal\n");
        exit(EXIT_FAILURE);
    }
    j->nome = strdup(nome);
    j->prim = j->ult = NULL;
    return j;
}

void insereNoticia(Jornal* j, Noticia* news){
    time_t publicacao = time(NULL);
    double dif = difftime(publicacao, retornaHora(news));
    
    if(dif <= TEMPO_PREMIACAO){
        premiaAutor(retornaAutor(news));
    }

    tCelula *c = criaCelula(news);
    c->publicada = publicacao;

    if(EstaVazioJornal(j)){
        j->prim = c;
    }
    else{
        j->ult->prox = c;
        c->ant = j->ult;
    }
    j->ult = c;
    (j->tam)++;
}

static int ehVelhaNoticia(tCelula *c, time_t agr){
    return(difftime(agr, c->publicada) >= TEMPO_NOTICIA_VELHA);
}

static void removeNoticia(Jornal *j, tCelula *c){
    if(EstaVazioJornal(j)){
        return;
    }
    /*tCelula *pop = j->prim, *ant = NULL;
    while (pop && pop != c){
        ant = pop;
        pop = pop->prox;
    }
    
    if(pop == NULL){
        printf("ERRO - noticia nao encontrada\n");
        return;
    }
    
    if(pop == j->prim){
        j->prim = pop->prox;
    }
    else if(pop == j->ult){
        ant->prox = NULL;
        j->ult = ant;
    }
    else{
        ant->prox = pop->prox;
    }*/
    
    tCelula *ant = c->ant, *pos = c->prox;

    if(c == j->prim){
        if(pos){
            pos->ant = NULL;
        }
        j->prim = pos;
    }
    else if(c == j->ult){
        j->ult = ant;
        if(ant){
            ant->prox = NULL;
        }
    }
    else{
        if(ant){
            ant->prox = c->prox;
        }
        if(pos){
            pos->ant = c->ant;
        }
    }

    liberaNoticia(c->item);
    desalocaCelula(c);
    (j->tam)--;
}

void removeNoticiasVelhas(Jornal* j){
    if(EstaVazioJornal(j)){
        return;
    }
    time_t agr = time(NULL);

    tCelula *cel = j->prim, *ant = NULL;
    /*for(c = j->prim; c != NULL; c = c->prox){
        if(ehVelhaNoticia(c, agr)){
            removeNoticia(j, c);
        }
    }*/
    while(cel){
        ant = cel;
        cel = cel->prox;
        if(ehVelhaNoticia(ant, agr)){
            removeNoticia(j, ant);
        }
    }
}

void imprimeNoticiasJornal(Jornal* j){
    if(EstaVazioJornal(j)){
        return;
    }
    tCelula *c = NULL;
    printf("Notícias do Jornal %s\n", j->nome);
    for(c = j->prim; c != NULL; c = c->prox){
        imprimeNoticia(c->item);
    }
}

void imprimeNoticiasAutoresPremiados(Jornal* j){
    if(EstaVazioJornal(j)){
        return;
    }
    tCelula *c = NULL;
    //printf("Notícias premiadas do Jornal %s\n", j->nome);
    for(c = j->prim; c != NULL; c = c->prox){
        if(ehPremiado(retornaAutor(c->item))){
            imprimeNoticia(c->item);
        }
    }
}

int retornaNumeroNoticias(Jornal* j){
    if(!j){
        printf("Jornal nulo em retornaNumero\n");
        exit(EXIT_FAILURE);
    }
    return(j->tam);
}

void liberaJornal(Jornal* j){
    if(!j){
        printf("jornal nulo enviado para libera\n");
        return;
    }
    tCelula *cel = j->prim, *ant = NULL;
    while(cel){
        ant = cel;
        cel = cel->prox;
        liberaNoticia(ant->item);
        desalocaCelula(ant);
    }
    free(j->nome);
    free(j);
}