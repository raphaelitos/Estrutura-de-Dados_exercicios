#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
A ideia geral:

1. **Escolha do Pivô**: Seleciona-se um elemento da lista como pivô. O pivô é usado para dividir a lista em duas partes.

2. **Particionamento**: Reorganiza a lista de modo que todos os elementos menores que o pivô fiquem antes dele, e todos os elementos maiores fiquem depois dele. 
Após esse processo, o pivô está em sua posição final na lista ordenada.

3. **Recursão**: Aplica-se recursivamente o mesmo processo às sublistas de elementos menores e maiores que o pivô.

4. **Combinação**: Não é necessário fazer nada na etapa de combinação no Quick Sort, pois a lista é ordenada "in place". Após todas as recursões,
a lista estará ordenada.

Esse processo é repetido até que todas as partições tenham tamanho zero ou um (sublistas vazias ou com um único elemento), o que significa que a lista 
está ordenada por completo.

Sim, na primeira iteração do algoritmo Quick Sort, é comum escolher o primeiro elemento da lista como pivô. Esta abordagem é simples e direta:

1. **Escolha do Pivô**: Seleciona-se o primeiro elemento da lista como pivô.

2. **Particionamento**: Reorganiza-se a lista de modo que todos os elementos menores que o pivô fiquem antes dele, e todos os elementos maiores fiquem depois dele. 
Após essa etapa, o pivô estará em sua posição final na lista ordenada.

3. **Recursão**: Aplica-se recursivamente o mesmo processo às sublistas de elementos menores e maiores que o pivô.

4. **Combinação**: Como o Quick Sort ordena "in place", não é necessário nenhuma ação específica na etapa de combinação.

A escolha do primeiro elemento como pivô na primeira iteração é eficiente em termos de implementação e é frequentemente utilizada em versões simples do algoritmo. 
No entanto, é importante notar que essa escolha pode levar a um desempenho menos ideal em certos casos específicos de entrada, como listas já parcialmente ordenadas.
*/

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
            }//swap
        }
        if(!swap){//already sorted
            break;
        }
    }
}

int BinSch(int vet[], int tam, int x){
    int ini = 0;
    int fim = 0;
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
    printf("[ ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("]");
    printf("\n\n");
}

void TestaOrdenacao(int vet[], int tam){
    PrintVet(vet, tam);
    printf("Testando Bubble Sort:");
    BubbleSort(vet, tam);
    PrintVet(vet, tam);
    
    inicializaVetAleatorio(vet, tam, 15);
    printf("Testando Quick Sort:");
    QuickSort(vet, tam, 0);
    PrintVet(vet, tam);
}

void TestaBusca(int vet[], int tam);

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