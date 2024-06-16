//
//  Noticia.h
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 18/11/22.
//

#ifndef Noticia_h
#define Noticia_h

#include <stdio.h>
#include <time.h>
#include "Autor.h"

//Define o tipo notícia
typedef struct noticia Noticia;

//cria a noticia com um determinado texto e autor
Noticia* criaNoticia(char* texto, Autor* autor);

//retorna o texto da noticia
char* retornaTexto(Noticia* news);

//retorna o autor da noticia
Autor* retornaAutor(Noticia* news);

//libera dados da noticia
void liberaNoticia(Noticia* news);

//imprime os dados da noticia
void imprimeNoticia (Noticia* news);

//retorna o momento(timestamp) da criação da notícia.
time_t retornaHora(Noticia* news);


#endif /* Noticia_h */
