//
//  Autor.h
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 18/11/22.
//

#ifndef Autor_h
#define Autor_h

#include <stdio.h>

//Define o tipo Autor
typedef struct autor Autor;

//cria autor com um determinado nome
Autor* criaAutor(char* nome);

//retorna se é premiado (1) ou não (0)
int ehPremiado(Autor* autor);

//define o autor como premiado
void premiaAutor(Autor* autor);

//imprime os dados do autor
void imprimeAutor(Autor* autor);

//retorna o nome do autor
char* retornaNomeAutor(Autor* autor);

//libera os dados do autor
void liberaAutor(Autor* autor);





#endif /* Autor_h */
