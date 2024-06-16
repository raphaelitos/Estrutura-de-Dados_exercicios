//
//  main.c
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 18/11/22.
//

#include <stdio.h>
#include "Jornal.h"
#include <unistd.h>

int main(int argc, const char * argv[]) {

    //criar autores
    
    Autor* patricia = criaAutor("Patricia");
    Autor* edu = criaAutor("Edu");
    Autor* luis = criaAutor("Luis");
    
    //criar noticias
    
    Noticia* enade = criaNoticia("Curso da UFES é premiado no ENADE", patricia);
    Noticia* assalto = criaNoticia("Assalto na UFES assusta comunidade acadêmica", edu);
    Noticia* covid = criaNoticia("UFES recomenda uso de mascaras", luis);
    
    //agora cria o jornal da ufes
    Jornal* ufes = criaJornal("Jornal da UFES");
    
    insereNoticia(ufes, enade);
    insereNoticia(ufes, assalto);
    //"dorme" 10 segundos para testar os apectos temporais
    sleep(10);
    insereNoticia(ufes, covid);
    
    int tam = retornaNumeroNoticias(ufes);
    
    //enquanto houver notícias no jornal, testa funcionalidade de remover notícias velhas
    while (tam>0){

        //imprime todas as notícias do jornal
        imprimeNoticiasJornal(ufes);
    
        
        //imprime as notícias dos autores premiados
        imprimeNoticiasAutoresPremiados(ufes);
    
        //remove as notícias consideradas "velhas"
        removeNoticiasVelhas(ufes);
        
        tam = retornaNumeroNoticias(ufes);

    }

    //libera tudo (lembrando que notícias são liberadas no "retira" do jornal)
    liberaJornal(ufes);
    liberaAutor(patricia);
    liberaAutor(luis);
    liberaAutor(edu);
    
    return 0;
}
