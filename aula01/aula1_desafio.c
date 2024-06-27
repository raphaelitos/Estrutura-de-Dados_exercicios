#include <stdio.h>
#include <stdlib.h>

int* CriaVetor(int *vet, int *tam){
    
    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", tam);
    
    vet = (int*)malloc((*tam) * sizeof(int));
    return vet;
}

void preencheVetor(int *vet, int tam){
    
    if(!vet){
        printf("Vetor nulo na funcao preencheVetor!");
        exit(0);
    }

    for(int i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }
}

void ImprimeVetor(int tam, int *vet){
    if(!vet){
        printf("Erro na funcao ImprimeVetor!\n");
        exit(0);
    }
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void ImprimePointPoint(int tam, int **vet){
    if(!vet){
        printf("Erro na funcao ImprimeVetor!\n");
        exit(0);
    }
    for(int i = 0; i < tam; i++){
        printf("%d ", (*vet[i]));
    }
    printf("\n");
}

int** inverte2 (int n, int*vet){

    int **inv = (int**)malloc(n * sizeof(int*));
    //COPIA
    for(int m = 0; m < n; m++){
        inv[m] = &vet[m];
    }
    //
    int i = 0, j = 0, trocou = 0;
    int *temp;
    
    for (i = 0; i < n - 1; i++) {
        trocou = 0;
       
        for (j = 0; j < n - i - 1; j++) {
            
            if((*inv[j]) < (*inv[j + 1])){
                temp = inv[j];
                inv[j] = inv[j + 1];
                inv[j + 1] = temp;
                trocou = 1;
            }
        }

        if (trocou == 0){
            break;
        }
    }

    return inv;
}

int main(){

    int tam = 0;
    int *vet = CriaVetor(vet, &tam);
    printf("Digite (separados por espaco) os numeros que irao preencher o seu vetor: ");
    preencheVetor(vet, tam);
    int **invert = inverte2(tam, vet);

    ImprimePointPoint(tam, invert);

    free(vet);
    free(invert);
    return 0;
}