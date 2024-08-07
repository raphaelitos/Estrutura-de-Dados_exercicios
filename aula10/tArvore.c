#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tArvore.h"

struct arvore{
    tAluno *aluno;
    tArvore *sae;
    tArvore *sad;
};

static int estaVaziaArvore(tArvore *a){
    return a == NULL;
}

static int ehFolha(tArvore *a){
    if(!estaVaziaArvore(a)){
        return(a->sad == NULL && a->sae == NULL);
    }
    return 0;
}

static int maior(int a, int b){
    return (a > b) ? a : b;
}

tArvore *criaVazia(){
    tArvore *a = NULL;
    return a;
}

tArvore *criaArvore(tAluno *a, tArvore *sae, tArvore *sad){
    tArvore *arv = (tArvore*)malloc(sizeof(tArvore));
    arv->aluno = a;
    arv->sad = sad;
    arv->sae = sae;
    return arv;
}

void desalocaArvore(tArvore *a){
    if(estaVaziaArvore(a)) return;
    desalocaArvore(a->sad);
    desalocaArvore(a->sae);
    free(a);
}

int calculaFolhas(tArvore* a){
    if(estaVaziaArvore(a)){
        return 0;
    }
    if(ehFolha(a)){
        return 1;
    }
    return calculaFolhas(a->sad) + calculaFolhas(a->sae);
}

int calculaOcorrencias(tArvore* a , char* nome){
    if(estaVaziaArvore(a)){
        return 0;
    }
    int valor = 0;
    if(!strcmp(getNomeAluno(a->aluno), nome)){
        valor = 1;
    }
    return valor + calculaOcorrencias(a->sad, nome) + calculaOcorrencias(a->sae, nome);
} 

int calculaAltura(tArvore* a){
    if (estaVaziaArvore(a)) return -1;
    return 1 + maior(calculaAltura(a->sae), calculaAltura(a->sad));
}

int pertenceAluno(tArvore* a , char* nome){
    if(estaVaziaArvore(a)){
        return 0;
    }
    return(!strcmp(getNomeAluno(a->aluno), nome)||
            pertenceAluno(a->sad, nome) || pertenceAluno(a->sae, nome));
}

void imprimeArvore(tArvore *a){
    if(estaVaziaArvore(a)) return;
    printf("<");
    imprimeAluno(a->aluno);
    imprimeArvore(a->sae);
    imprimeArvore(a->sad);
    printf(">");
}

tArvore* retiraAlunoArvore(tArvore *a, char *nome) {
    if (estaVaziaArvore(a)) return a;

    if (strcmp(getNomeAluno(a->aluno), nome) == 0) { // Encontrou o nó a ser removido
        if (ehFolha(a)) {
            desalocaAluno(a->aluno);
            free(a);
            return NULL;
        } else if (a->sae == NULL) {
            tArvore *temp = a->sad;
            desalocaAluno(a->aluno);
            free(a);
            return temp;
        } else if (a->sad == NULL) {
            tArvore *temp = a->sae;
            desalocaAluno(a->aluno);
            free(a);
            return temp;
        } else { // Nó com dois filhos
            tArvore *temp = a->sad;
            tArvore *parent = NULL;

            // Encontrar o menor nó na subárvore direita
            while (temp->sae != NULL) {
                parent = temp;
                temp = temp->sae;
            }

            // Substituir o conteúdo do nó a ser removido pelo conteúdo do menor nó encontrado
            a->aluno = temp->aluno;

            // Remover o menor nó encontrado
            if (parent != NULL) {
                parent->sae = retiraAlunoArvore(parent->sae, getNomeAluno(temp->aluno));
            } else {
                a->sad = retiraAlunoArvore(a->sad, getNomeAluno(temp->aluno));
            }

            return a;
        }
    } 
    else {
        a->sae = retiraAlunoArvore(a->sae, nome);
        a->sad = retiraAlunoArvore(a->sad, nome);
    }

    return a;
}
