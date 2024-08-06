#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define TAM_HASH 17
#define TAM_NOME_PAIS 4

int compara(const void *d1, const void *d2){
    if(!d1 || !d2) return 0;
    
    tPais *p1 = *(tPais**)d1; // Casting correto
    tPais *p2 = *(tPais**)d2;

    int diferenca = getOurosPais(p2) - getOurosPais(p1);

    if(diferenca == 0){
        diferenca = getPratasPais(p2) - getPratasPais(p1);
    }
    if(diferenca == 0){
        diferenca = getBronzesPais(p2) - getBronzesPais(p1);
    }

    return diferenca;
}

void imprimeVetPaises(tPais **vet, int tam){
    assert(!vet, "vet de paises nulo em imprime");
    for(int i = 0; i < tam; i++){
        printf("%s %d %d %d %d\n", getNomePais(vet[i]), getOurosPais(vet[i]), 
                        getPratasPais(vet[i]), getBronzesPais(vet[i]), totalMedalhasPais(vet[i]));
    }
}

int main(){
    
    FILE *entrada = fopen("input.txt", "r");
    assert(!entrada, "falha em abrir arquivo de entrada");
    
    FILE *saida = fopen("output.txt", "w");
    assert(!saida, "falha em abrir arquivo de saida");
    

    tHash *table = criaHash(TAM_HASH);
    
    char nome[TAM_NOME_PAIS];
    int ouros, pratas, bronzes, total;
    
    while((fscanf(entrada, "%s %d %d %d %d\n", nome, &ouros, &pratas, &bronzes, &total)) == 5){
        tPais *busca = criaPais(nome, ouros, pratas, bronzes);

        busca = acessa(table, busca);

        if(busca) liberaPais(busca);

    }

    imprimeArqHash(table, saida);

   int tam = getQtdPaisesHash(table);

    tPais **vet = dumpVet(table);

    qsort(vet, tam, sizeof(tPais*), compara);

    imprimeVetPaises(vet, tam);

    free(vet);
    liberaHash(table);

    fclose(entrada);
    fclose(saida);
    
    return 0;
}