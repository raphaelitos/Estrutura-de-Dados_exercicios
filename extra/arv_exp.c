#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv_exp.h"

struct arv{
    char operador;
    float valor;
    tArv *esq;
    tArv *dir;
};

static void assert(int exp, const char *msg){
    if(!exp){
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}

static int ehFolha(tArv *a){
    if(!a) return 0;
    return (!(a->esq && a->dir));
}

static int ehOperador(tArv *a){
    if(!a) return 0;
    return (a->operador != '\0');
}

static int ehOperando(tArv *a){
    if(!a) return 0;
    return (a->operador == '\0');
}

static int maior(int a, int b){
    return (a > b) ? a : b;
}

static float opera(int a, int b, char c){
    switch (c){
    case '*':
        return a * b;
        break;
    
    case '/':
        return a / b;
        break;
    
    case '+':
        return a + b;
        break;
    
    case '-':
        return a - b;
        break;
    
    default:
        break;
    }
    return 0;
}

tArv* CriaVazia(void){
    return NULL;
}

static void imprimeOperador(tArv *a){
    if(!a) return;
    printf("%c", a->operador);
}

static void imprimeOperando(tArv *a){
    if(!a) return;
    printf("%.2f", a->valor);
}

tArv* CriaOperador(char c, tArv* esq, tArv* dir){
    tArv *a = (tArv*)calloc(1, sizeof(tArv));
    assert(a != NULL, "falha na alocacao de no operador");
    
    a->operador = c;
    a->esq = esq;
    a->dir = dir;

    return a;
}

tArv* CriaOperando(int valor){
    tArv *a = (tArv*)calloc(1, sizeof(tArv));
    assert(a != NULL, "falha na alocacao de no operador");
    
    a->operador = '\0';
    a->esq = a->dir = CriaVazia();
    a->valor = (float)valor;

    return a;    
}

void Imprime(tArv* arv){
    if(!arv) return;
    if(ehFolha(arv)){
        imprimeOperando(arv);
        return;
    }
    printf("(");
    Imprime(arv->esq);
    printf(")");
    imprimeOperador(arv);
    printf("(");
    Imprime(arv->dir);
    printf(")");
}

tArv* Libera (tArv* arv){
    if(!arv){
        return NULL;
    }
    Libera(arv->esq);
    Libera(arv->dir);
    free(arv);
    return NULL;
}

float Avalia(tArv* arv){
    if(!arv){
        return 0.00;
    }
    if(ehFolha(arv)){
        return arv->valor;
    }

    arv->valor = opera(Avalia(arv->esq), Avalia(arv->dir), arv->operador);
    
    return arv->valor;
}

int Folhas(tArv* arv){
    if(!arv){
        return 0;
    }
    if(ehFolha(arv)){
        return 1;
    }

    int result = 0;
    result += Folhas(arv->esq);
    result += Folhas(arv->dir);

    //return Folhas(arv->esq) + Folhas(arv->dir);

    return result;
}

int Altura(tArv* arv){
    if(!arv) return 0;
    if(ehFolha(arv)) return -1;
    
    int h;
    h = 1 + maior(Altura(arv->esq), Altura(arv->dir));

    return h;
}