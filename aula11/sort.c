#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializaGeradorAleatorio() {
    srand(time(NULL));
}

/// @brief inicializa um vetor com valores aleatorios
/// feito pelo chatGPT
/// @param vetor o vetor a ser preenchido
/// @param tamanho o tamanho do vetor
/// @param maxValor maior valor possivel
void inicializaVetAleatorio(int* vetor, int tamanho, int maxValor) {
    // Preenche o vetor com valores aleatórios
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % maxValor; // Gera um número entre 0 e maxValor-1
    }
}

void QuickSort(int* vet, int tam, int ini){
    if(ini >= tam - 1){
        return;
    }
    
    int pivo = vet[tam - 1], aux;
    int menor = ini;  

    for(int i = ini; i < tam - 1; i++){
        if(vet[i] < pivo){
            aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
            menor++;
        }
    }

    aux = vet[menor];
    vet[menor] = vet[tam - 1];
    vet[tam - 1] = aux;

    // subvetor da esquerda
    QuickSort(vet, menor, ini);
    // subvetor da direita
    QuickSort(vet, tam, menor + 1);
}

void NoRecQuickSort(int *vet, int tam);//tentar implementacao nao recursiva

void BubbleSort(int vet[], int tam){
    int swap = 0, aux;
    for(int i = 0; i < tam - 1; i++){
        swap = 0;
        for(int j = 0; j < (tam - i - 1); j++){
            if(vet[j] > vet[j + 1]){
                aux = vet[j + 1];
                vet[j + 1] = vet[j];
                vet[j] = aux;
                swap = 1;
            }//troca
        }
        if(!swap){
            break;
        }
    }
}

int BinSch(int vet[], int tam, int x){
    int ini = 0;
    int fim = tam - 1;;
    int meio;

    while(ini <= fim){
        meio = (ini + fim)/2;
        if(x < vet[meio]) fim = meio - 1;

        else if(x > vet[meio]) ini = meio + 1;

        else return meio;
    }
    return -1; //not found
}

void RecBinSch();//implementar recursão

int LinearSch(int vet[], int tam, int x){
    for(int i = 0; i < tam; i++){
        if(vet[i] == x){
            return i;
        }
    }
    return -1; //not found
}

void PrintVet(int vet[], int tam){
    printf("Imprimindo vetor de %d posicoes:\n", tam);
    printf("[ ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("]");
    printf("\n\n");
}

void TestaOrdenacao(int vet[], int tam){
    printf("Testando Bubble Sort:\n");
    clock_t inicio = clock();
    BubbleSort(vet, tam);
    clock_t fim = clock();
    double dif = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %lf segundos\n", dif);
    PrintVet(vet, tam);
    
    inicializaVetAleatorio(vet, tam, tam);
    printf("Testando Quick Sort:\n");
    inicio = clock();
    QuickSort(vet, tam, 0);
    fim = clock();
    dif = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %lf segundos\n", dif);
    PrintVet(vet, tam);
}

void TestaBusca(int vet[], int tam, int x){
    clock_t inicio = clock();
    int id = BinSch(vet, tam, x);
    clock_t fim = clock();
    double dif = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de busca [binaria]: %lf segundos\n", dif);
   
    if(id != -1) printf("O id do elemento %d eh %d!\n", x, id);
    
    else printf("Elemento %d nao esta no vetor :(\n", x);

    inicio = clock();
    id = LinearSch(vet, tam, x);
    fim = clock();
    dif = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de busca [linear]: %lf segundos\n", dif);

    if(id != -1) printf("O id do elemento %d eh %d!\n", x, id);
    
    else printf("Elemento %d nao esta no vetor :(\n", x);
}

int main(){
    inicializaGeradorAleatorio();

    int tamanho = 10000;
    int *vet = (int *)malloc(tamanho * sizeof(int));
    int pequeno[8] = {0, 3, 5, 3, 2, 7, 8, 9};
    if(!vet){
        printf("falha na alocacao de vetor grande\n");
        exit(EXIT_FAILURE);
    }

    inicializaVetAleatorio(vet, tamanho, tamanho);

    TestaOrdenacao(pequeno, 8);

    TestaBusca(pequeno, 8, -1);
    TestaBusca(pequeno, 8, 7);

    TestaOrdenacao(vet, tamanho);

    TestaBusca(vet, tamanho, -1);
    TestaBusca(vet, tamanho, vet[rand() % tamanho]);

    /*
    double dif;
    
    ini = time(NULL);
    QuickSort(pequeno, 8, 0);
    fim = time(NULL);
    dif = (float)ini - (float) fim;
    printf("Tempo de ordenacao [pequeno]: %f", dif);
    
    clock_t inicio = clock();
    //QuickSort(vet, tamanho, 0);
    clock_t fim = clock();

    dif = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    //printf("Tempo de ordenação [grande] com Quick: %f segundos\n", dif);
    
    inicio = clock();
    BubbleSort(vet, tamanho);
    fim = clock();

    dif = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de ordenação [grande] com Bubble: %f segundos\n", dif);


    //PrintVet(pequeno, 8);
    //PrintVet(vet, tamanho);*/

    free(vet);
    
    return 0;
}