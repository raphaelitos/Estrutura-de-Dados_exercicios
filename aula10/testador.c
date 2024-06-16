#include <stdio.h>
#include "tArvore.h"

int main(){
    
    tAluno *rapha = criaAluno("Raphael");
    tAluno *tanque = criaAluno("Victao");
    tAluno *chico = criaAluno("Arthur");
    tAluno *gobbi = criaAluno("DaniGobbi");
    tAluno *corona = criaAluno("Dan");
    tAluno *conras = criaAluno("Conrado");


    tArvore *arv = criaArvore(corona, 
                    criaArvore(gobbi, criaArvore(chico, criaVazia(), criaVazia()), criaVazia()),
                    criaArvore(tanque, criaArvore(rapha, criaVazia(), criaVazia()),
                    criaArvore(conras, criaVazia(), criaVazia())));

    printf("Qtd de folhas: %d\n", calculaFolhas(arv));
    printf("Altura: %d\n", calculaAltura(arv));

    char *nome = getNomeAluno(rapha);

    printf("Ocorrencias de %s: %d\n", nome, calculaOcorrencias(arv, nome));

    imprimeArvore(arv);
    
    desalocaArvore(arv);
    
    desalocaAluno(rapha);
    desalocaAluno(tanque);
    desalocaAluno(chico);
    desalocaAluno(gobbi);
    desalocaAluno(corona);
    desalocaAluno(conras);

    return 0;
}