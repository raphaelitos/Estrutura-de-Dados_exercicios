#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define CHUNKV 5

struct Vector{
    DataType* vetor;
    int alocated;
    int numElem;
};

Vector *VectorConstruct(){
    Vector *veti = (Vector*) malloc(sizeof(Vector));
    if(veti == NULL){
        printf("Falha na criacao de novo vector\n");
        exit(0);
    }
    
    veti->vetor = (DataType*)malloc(CHUNKV * sizeof(DataType));
    if(veti->vetor == NULL){
        printf("Falha na criacao de vetor em novo vector\n");
        exit(0);
    }
    
    veti->alocated = CHUNKV;
    veti->numElem = 0;
   
    return veti;
}

void VectorPushBack(Vector *v, DataType val){
    
    if(v->numElem == v->alocated){
        v->vetor = (DataType*)realloc(v->vetor, (v->alocated + CHUNKV) * sizeof(DataType));
        if (v->vetor == NULL) {
            printf("Falha ao alocar nova chunkV no vetor\n");
            exit(0);
        }
        (v->alocated) += CHUNKV;
    }
    
    (v->numElem)++;
    v->vetor[(v->numElem) - 1] = val;
}

/*DataType VectorPopFront(Vector *v){
    
    if(v->numElem == 0){
        printf("erro no pop: vetor vazio\n");
        return NULL;
    }
    
    DataType retorno = v->vetor[0];

    for(int p = 0; p < (v->numElem - 1); p++){
        v->vetor[p] = v->vetor[p + 1];
    }

    (v->numElem)--;

    v->vetor = (DataType*)realloc(v->vetor, (v->numElem) * sizeof(DataType));

    return retorno;
}*/

DataType VectorGet(Vector *v, int i){
    if(!v || (i > (v->numElem - 1)) || i < 0){
        printf("Vector e/ou indice invalido!\n");
        exit(EXIT_FAILURE);
    }

    return(v->vetor[i]);
}

int VectorSize(Vector *v){
    if(v){
        return(v->numElem);
    }
    exit(EXIT_FAILURE);
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    if(v == NULL){
        return;
    }
    
    if(v->vetor){
        for(int i = 0; i < v->numElem; i++){
            destroy(v->vetor[i]);
        }
    
        free(v->vetor);
    }
    free(v);
}