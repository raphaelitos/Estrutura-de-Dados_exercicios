//
//  Autor.c
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 18/11/22.
//

#include "Autor.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct autor{
    char* nome;
    int premiado;
};

Autor* criaAutor(char* nome){
    Autor* autor = malloc(sizeof(Autor));
    autor->nome = strdup(nome);
    autor->premiado = 0;
    return autor;
}

int ehPremiado(Autor* autor){
    return autor->premiado;
}

void imprimeAutor(Autor* autor){
    printf("\nAutor: %s, Premiado: %d\n", autor->nome, autor->premiado);
}

char* retornaNomeAutor(Autor* autor){
    return autor->nome;
}
void premiaAutor(Autor* autor){
    autor->premiado = 1;
}

void liberaAutor(Autor* autor){
    free(autor->nome);
    free(autor);
}
