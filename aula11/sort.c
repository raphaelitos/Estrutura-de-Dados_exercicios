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

/*void QuickSort(int* vet, int tam){
    if(tam <= 1){
        return;
    }
    
    int pivo = vet[tam - 1], aux;
    int menor = -1;  

    for(int i = 0; i < tam - 1; i++){
        if(vet[i] < pivo){
            menor++;
            if(i > menor){
                aux = vet[i];
                vet[i] = vet[menor];
                vet[menor] = aux;
            }
        }
    }

    aux = vet[menor];
    vet[menor] = vet[tam - 1];
    vet[tam - 1] = aux;

    // subvetor da esquerda
    QuickSort(vet, menor, ini);
    // subvetor da direita
    QuickSort(vet, tam, menor + 1);
}*/

void QuickSort(int* vet, int ini, int tam){
    if(ini >= tam){
        return;
    }
    
    int pivo = vet[tam - 1], aux;
    int menor = ini;  

    for(int i = ini; i < (tam - 1); i++){
        if(vet[i] < pivo){
            if(i != menor){
                aux = vet[i];
                vet[i] = vet[menor];
                vet[menor] = aux;
            }
            menor++;
        }
    }

    aux = vet[menor];
    vet[menor] = vet[tam - 1];
    vet[tam - 1] = aux;

    // subvetor da esquerda
    QuickSort(vet, ini, menor - 1);
    // subvetor da direita
    QuickSort(vet, menor + 1, tam);
}

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

int RecBinSch(int *vet, int n, int x){
    if(n <= 0) return -1;
    int meio = n/2;

    if(x < vet[meio]) return RecBinSch(vet, meio, x);

    else if(x > vet[meio]){
        int r = RecBinSch((vet + meio + 1), (n - meio -1), x);
        if(r < 0) return -1;
        return meio + r + 1;
    }
    else return meio;    
}

int LinearSch(int vet[], int tam, int x){
    for(int i = 0; i < tam; i++){
        if(vet[i] == x){
            return i;
        }
    }
    return -1; //not found
}

void PrintVet(int vet[], int tam){
    printf("[ ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("]");
    printf("\n\n");
}

void TestaOrdenacao(int vet[], int tam){
    printf("Testando Bubble Sort:\n");
    PrintVet(vet, tam);
    BubbleSort(vet, tam);
    PrintVet(vet, tam);
    
    inicializaVetAleatorio(vet, tam, tam);
    
    printf("Testando Quick Sort:\n");
    PrintVet(vet, tam);
    QuickSort(vet, 0, tam);
    PrintVet(vet, tam);
}

void ExibeTempoOrdenacoes(int vet[], int tam){
    printf("### Bubble Sort ###\n");
    clock_t inicio = clock();
    BubbleSort(vet, tam);
    clock_t fim = clock();
    long double dif = ((long double)fim - (long double)inicio) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao (%d posicoes): %Lf segundos\n", tam, dif);
    
    inicializaVetAleatorio(vet, tam, tam);
    
    printf("### Quick Sort ###\n");
    inicio = clock();
    QuickSort(vet, tam, 0);
    fim = clock();
    dif = ((long double)fim - (long double)inicio) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao (%d posicoes): %Lf segundos\n\n", tam, dif);
}

void TestaBusca(int vet[], int tam, int x){
    clock_t inicio = clock();
    int id = BinSch(vet, tam, x);
    clock_t fim = clock();
    long double dif = ((long double)fim - (long double)inicio) / CLOCKS_PER_SEC;
    
    printf("Tempo de busca [binaria nao recursiva, %d posicoes]: %Lf segundos\n", tam, dif);
    
    if(id != -1) printf("O id do elemento %d eh %d!\n\n", x, id);
    else printf("Elemento %d nao esta no vetor :(\n\n", x);


    inicio = clock();
    id = RecBinSch(vet, tam, x);
    fim = clock();
    dif = ((long double)fim - (long double)inicio) / CLOCKS_PER_SEC;

    printf("Tempo de busca [binaria recursiva, %d posicoes]: %Lf segundos\n", tam, dif);

    if(id != -1) printf("O id do elemento %d eh %d!\n\n", x, id);    
    else printf("Elemento %d nao esta no vetor :(\n\n", x);

    inicio = clock();
    id = LinearSch(vet, tam, x);
    fim = clock();
    dif = ((long double)fim - (long double)inicio) / CLOCKS_PER_SEC;
    
    printf("Tempo de busca [linear, %d posicoes]: %Lf segundos\n", tam, dif);
    
    if(id != -1) printf("O id do elemento %d eh %d!\n\n", x, id);
    else printf("Elemento %d nao esta no vetor :(\n\n", x);
}

int main(){
    inicializaGeradorAleatorio();

    int tamanho = 10000;
    int *vet = (int *)malloc(tamanho * sizeof(int));
    if(!vet){
        printf("falha na alocacao de vetor grande\n");
        exit(EXIT_FAILURE);
    }
    inicializaVetAleatorio(vet, tamanho, tamanho);

    int pequeno[8] = {0, 3, 5, 3, 2, 7, 8, 9};
    TestaOrdenacao(pequeno, 8);

    inicializaVetAleatorio(pequeno, 8, 8);
    ExibeTempoOrdenacoes(pequeno, 8);

    TestaBusca(pequeno, 8, -1);
    TestaBusca(pequeno, 8, 7);

    ExibeTempoOrdenacoes(vet, tamanho);

    TestaBusca(vet, tamanho, -1);
    TestaBusca(vet, tamanho, vet[rand() % tamanho]);

    free(vet);
    
    return 0;
}