#include <stdlib.h>
#include "matriz.h"

struct smatriz{
    int nlin;
    int ncol;
    int **mat;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    if(nlinhas == 0 || ncolunas == 0){
        printf("Nao podem haver linhas ou matrizes nulas!\n");
        Matriz *m = NULL;
        return m;
    }
    
    Matriz *m = (Matriz*)calloc(1, sizeof(Matriz));
    if(!m){
        printf("Falha na criacao de matriz\n");
        exit(EXIT_FAILURE);
    }
    
    m->nlin = nlinhas;
    m->ncol = ncolunas;
    
    m->mat = (int**)calloc(nlinhas, sizeof(int*));
    for(int i = 0; i < nlinhas; i++){
        m->mat[i] = (int*)calloc(ncolunas, sizeof(int));                                         
    }
    
    return m;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    if(!mat){
        printf("Matriz nula na funcao modificaelemento\n");
        exit(EXIT_FAILURE);
    }
    /*if(!((linha >= 0 && linha < mat->nlin) && (coluna >= 0 && coluna < mat->ncol))){
        printf("Voce digitou linha ou coluna invalida!\n");
        exit(EXIT_FAILURE);
    }*/

    while(!((linha >= 0 && linha < mat->nlin) && (coluna >= 0 && coluna < mat->ncol))){
        printf("Linha ou coluna invalida! Tente novamente\n");
        printf("Digite a posicao ['linha coluna'] do elemento: ");
        scanf("%d %d", &linha, &coluna);
        while(getchar() != '\n');
    }

    for(int i = 0; i < mat->nlin; i++){
        for(int j = 0; j < mat->ncol; j++){
            if(linha == i && coluna == j){
                mat->mat[i][j] = elem;
                return;
            }
        }
    }
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    if(!mat){
        printf("Matriz nula na funcao recuperaelemento\n");
        exit(EXIT_FAILURE);
    }
    while(!((linha >= 0 && linha < mat->nlin) && (coluna >= 0 && coluna < mat->ncol))){
        printf("Linha ou coluna invalida! Tente novamente\n");
        printf("Digite a posicao ['linha coluna'] do elemento: ");
        scanf("%d %d", &linha, &coluna);
        while(getchar() != '\n');
    }
    for(int i = 0; i < mat->nlin; i++){
        for(int j = 0; j < mat->ncol; j++){
            if(linha == i && coluna == j){
                return (mat->mat[i][j]);
            }
        }
    }
}

int recuperaNColunas (Matriz* mat){
    if(!mat){
        printf("Matriz nula na funcao recuperancolunas\n");
        exit(EXIT_FAILURE);
    }
    return(mat->ncol);
}

int recuperaNLinhas (Matriz* mat){
    if(!mat){
        printf("Matriz nula na funcao recuperanlinhas\n");
        exit(EXIT_FAILURE);
    }
    return(mat->nlin);
}

Matriz* transposta (Matriz* mat){
    if(!mat){
        printf("Matriz nula na funcao transposta\n");
        exit(EXIT_FAILURE);
    }
    Matriz *trans = inicializaMatriz(mat->ncol, mat->nlin); 
    
    for(int i = 0; i < mat->nlin; i++){
        for(int j = 0; j < mat->ncol; j++){
            trans->mat[j][i] = mat->mat[i][j];
        }
    }
    return trans;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if(!mat1 || !mat2){
        printf("Matriz(es) nula(s) na funcao multiplicacao\n");
        exit(EXIT_FAILURE);
    }
    if(mat1->ncol != mat2->nlin){
        printf("Dimensoes de matrizes improprias para multiplicacao!\n");
        Matriz *m = NULL;
        return m;
    }
    //Amxn * Bnxr = Cmxr
    Matriz *mult = inicializaMatriz(mat1->nlin, mat2->ncol);

    int temp = 0;
    for(int i = 0; i < mat1->nlin; i++){
        for(int j = 0; j < mat2->ncol; j++){
            temp = 0;
            for(int k = 0; k < mat1->ncol; k++){
                temp += mat1->mat[i][k] * mat2->mat[k][j];
            }
            mult->mat[i][j] = temp;
        }
    }
    return mult;
}

void imprimeMatriz(Matriz* mat){
    if(!mat){
        printf("Matriz nula na funcao imrpimematriz\n");
        exit(EXIT_FAILURE);
    }
    for(int a = 0; a < mat->nlin; a++){
        for(int b = 0; b < mat->ncol; b++){
            printf(" %d", (mat->mat[a][b]));
        }
        printf("\n");
    }
}

void imprimeLinhas (Matriz* mat, int indice){
    if(!mat){
        printf("Matriz nula na funcao imrpimelinha\n");
        exit(EXIT_FAILURE);
    }
    while(indice < 0 || indice >= mat->nlin){
        printf("Indice invalido para impressao de linha dessa matriz! Tente novamente\n");
        scanf("%d", &indice);
        while(getchar() != '\n');
    }
    for(int a = 0; a < mat->nlin; a++){
        if(a == indice){
            for(int b = 0; b < mat->ncol; b++){
                printf(" %d", (mat->mat[a][b]));
            }
            printf("\n");
            return;
        }
    }
}

void destroiMatriz (Matriz* mat){
    if(!mat){
        printf("Matriz nula na funcao destroimatriz\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < mat->nlin; i++){
        free(mat->mat[i]);
    }
    free(mat->mat);
    free(mat);
}