//
//  Jornal.h
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 18/11/22.
//

#ifndef Jornal_h
#define Jornal_h

#include <stdio.h>
#include "Noticia.h"

//define intervalo de tempo, em segundos, entre publicacão e criação da notícia
//para poder premiar o autor
#define TEMPO_PREMIACAO 5

//Define intervalor de tempo, em segundos, que torna a noticia velha.
//se ("agora" - tempo de publicação) for >=TEMPO_NOTICIA_VELHA, a notícia é considerada "velha"
#define TEMPO_NOTICIA_VELHA 10

//Define a estrutura do jornal... parte da prova pensar no que é necessário
typedef struct jornal Jornal;

//Cria um tipo Jornal, dado o nome do jornal
//pré-condição: nome é uma string válida
//pós-condição: Estrutura Jornal alocada e considerada "vazia"
Jornal* criaJornal(char* nome);

//Insere notícia "news" no jornal "j"
//A notícia já tem um timestamp de criação. Deve alocar também um timestamp de publicação
//Caso o intervalo entre tempo de criação e publicação seja <=TEMPO_PREMIACAO
//O autor deve ser premiado
void insereNoticia(Jornal* j, Noticia* news);

//Remove as notícias "velhas" do jornal j
//Se ("agora" - tempo de publicação) for >=TEMPO_NOTICIA_VELHA, a notícia é considerada "velha"
//ATENÇÃO: Deve-se liberar a memória das notícias removidas do jornal
void removeNoticiasVelhas(Jornal* j);

//Imprime as notícias do jornal no seguinte formato
/*Notícias do Jornal Jornal da UFES

***** Notícia: UFES recomenda uso de mascaras
***** Hora de Acontecimento: Sun Nov 20 19:45:36 2022
***** Autor da Noticia: Luis
***** Hora de Publicação: Sun Nov 20 19:45:46 2022

***** Notícia: Assalto na UFES assusta comunidade acadêmica
***** Hora de Acontecimento: Sun Nov 20 19:45:36 2022
***** Autor da Noticia: Edu
***** Hora de Publicação: Sun Nov 20 19:45:36 2022

***** Notícia: Curso da UFES é premiado no ENADE
***** Hora de Acontecimento: Sun Nov 20 19:45:36 2022
***** Autor da Noticia: Patricia
***** Hora de Publicação: Sun Nov 20 19:45:36 2022 */
void imprimeNoticiasJornal(Jornal* j);

//Imprime as notícias como especificado acima, porém, somente de autores premiados
void imprimeNoticiasAutoresPremiados(Jornal* j);

//Retorna o número de notícias do jornal naquele momento
int retornaNumeroNoticias(Jornal* j);

//Libera memória de todo jornal, inclusive das notícias.
void liberaJornal(Jornal* j);


#endif /* Jornal_h */
