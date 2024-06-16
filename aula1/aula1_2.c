#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

int* CriaVetor(int *vet, int *tam){
    
    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", tam);
    
    vet = (int*)malloc((*tam) * sizeof(int));
    return vet;
}

double* CriaPolinomio(double *vet, int *tam){
    
    printf("Digite o grau da equacao: ");
    scanf("%d", tam);
    (*tam)++; //espaco para o termo independente
    
    vet = (double*)malloc((*tam) * sizeof(double));
    return vet;
}

void preencheVetor(int *vet, int tam){
    
    if(!vet){
        printf("Vetor nulo na funcao preencheVetor!");
        exit(0);
    }

    for(int i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
        //while ((getchar()) != '\n');
    }
}

void preenchePolinomio(double *vet, int tam){
    
    if(!vet){
        printf("Vetor nulo na funcao preenchePolinomio!");
        exit(0);
    }

    for(int i = 0; i < tam; i++){
        scanf("%lf", &vet[i]);
        //while ((getchar()) != '\n');
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

int ehPar(int num){
    return !(num % 2);
}

void calc_esfera(float r, float* area, float* volume){
    (*volume) = 4 * PI * r * r;
    (*area) = (4 * PI * r * r *r)/3;
}

int raizes(float a, float b, float c, float* x1, float* x2){
    int delta = b*b - (4 * a * c);
    
    
    (*x1) = (-b + sqrt(delta))/2*a;
    (*x2) = (-b - sqrt(delta))/2*a;

    return delta;
}

int pares (int n, int* vet){
    if(!vet){
        printf("Ponteiro nulo na funcao pares!\n");
        exit(0);
    }
    
    int count = 0;
    for(int i = 0; i < n; i++){
        if(ehPar(vet[i])){
            count++;
        }
    }
    return count;
}

void inverte (int n, int* vet){
    int *copia = (int*) malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++){
        copia[i] = vet[i];
    }
    int a = 0;
    for(int j = (n - 1); j >= 0; j--){
        vet[a] = copia[j];
        a++;
    }
    free(copia);
}

double avalia (double* poli, int grau, double x){
    if(!poli){
        printf("Polinomio nulo na funcao avalia!");
        exit(0);
    }
    double result = 0.0;
    
    for(int i = grau ; i <= 0; i++){
        result += poli[i] * pow(x, (grau - i));
    }

    return result;
}

//MAIN DA 2.1
/*
int main(){
    float r = 0;
    float *area = (float*)malloc(sizeof(float));
    float *volume = (float*)malloc(sizeof(float));
    
    printf("Digite um valor para o raio da esfera: ");
    scanf("%f", &r);
    
    calc_esfera(r, area, volume);
    printf("Essa esfera possui area %.2f e volume %.2f!\n", (*area), (*volume));
    
    free(area);
    free(volume);

    return 0;
}
*/

//MAIN DA 2.2
/*
int main(){
    float a = 0.0, b = 0.0, c = 0.0;
    float *x1 = (float*) malloc(sizeof(float));
    float *x2 = (float*) malloc(sizeof(float));
    
    printf("Vamos resolver uma equacao de modelo ax^2 + bx + c = 0.\n");
    printf("Digite os valores de a, b e c (separados por espaco): ");
    scanf("%f %f %f", &a, &b, &c);
    
    int result = raizes(a, b, c, x1, x2);

    if(result < 0){
        printf("Essa equacao nao possui raiz real!");
    }

    else if(result > 0){
        printf("As raizes dessa equacao sao %.2f e %.2f.\n", (*x1), (*x2));
    }

    else{
        printf("Essa equacao possui uma unica solucao: %.2f.\n", (*x1));
    }

    free(x1);
    free(x2);

    return 0;
}
*/

//MAIN DA 2.3
/*
int main(){

    int tam = 0;
    int *vet = CriaVetor(vet, &tam);
    preencheVetor(vet, tam);
    printf("Digite (separados por espaco) os numeros que irao preencher o seu vetor: ");
    int resultado = pares(tam, vet);

    printf("O numero de elementos pares eh %d\n.", resultado);
    free(vet);
    return 0;
}
*/

//MAIN DA 2.4
/*
int main(){

    int tam = 0;
    int *vet = CriaVetor(vet, &tam);
    printf("Digite (separados por espaco) os numeros que irao preencher o seu vetor: ");
    preencheVetor(vet, tam);
    inverte(tam, vet);
    ImprimeVetor(tam, vet);

    free(vet);
    return 0;
}
*/

//MAIN DA 2.5
/*
int main(){

    int tam = 0;
    double *vet = CriaPolinomio(vet, &tam);

    printf("Digite os coeficientes da equacao (separados por espaco): ");
    //os coefifientes serao considerados em ordem decrescente ex.:
    //ax² + bx + c (onde a, b e c sao os coeficientes)
    preenchePolinomio(vet, tam);
    
    double x = 0.0;
    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    double result = avalia(vet, (tam - 1), x);
    printf("Sua equacao resultou em %.2lf\n!", result);

    free(vet);
    return 0;
}
*/