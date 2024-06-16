//
//  Noticia.c
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 18/11/22.
//

#include "Noticia.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct noticia{
    time_t hora_criada;
    char* texto;
    Autor* autor;
};

Noticia* criaNoticia(char* texto, Autor* autor){
    Noticia* n = malloc(sizeof(Noticia));
    n->hora_criada = time(NULL);
    n->texto = strdup(texto);
    n->autor = autor;
    
    return n;
}


void imprimeNoticia (Noticia* news){
    
    printf("\n\n***** Notícia: %s", news->texto);
    printf("\n***** Hora de Acontecimento: %s", ctime(&news->hora_criada));
    printf("***** Autor da Noticia: %s", retornaNomeAutor(retornaAutor(news)));
}



char* retornaTexto(Noticia* news){
    return news->texto;
}

Autor* retornaAutor(Noticia* news){
    return news->autor;
}

time_t retornaHora(Noticia* news){
    return news->hora_criada;
}

void liberaNoticia(Noticia* news){
    free(news->texto);
    free(news);
}

