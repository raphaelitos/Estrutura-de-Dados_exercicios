#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "abb.h"

#define TAM_MAX_PLV 81
#define NUM_MAX_ALUNOS 150
#define NOME_ARQ_ENTRADA "entrada"
#define PRESENCA 'P'

int main(){
    char nomeArq[strlen(NOME_ARQ_ENTRADA) + 7];
    sprintf(nomeArq, "%s.txt", NOME_ARQ_ENTRADA);
    
    FILE *arq = fopen(nomeArq, "r");
    assert(arq != NULL, "falha na abertura de arquivo de entrada");

    int n, c, count = 0;
    fscanf(arq, "N %d", &n);//n arquivos
    while(((c = fgetc(arq)) != '\n') && c != EOF);//limpeza de buffer

    if(c == EOF){
        fclose(arq);
        return 0;
    }

    //char **nomes = (char**)calloc(NUM_MAX_ALUNOS, sizeof(char*));
    //assert(nomes != NULL, "falha na alocacao para nomes de alunos");

    char plv[TAM_MAX_PLV];
    tAbb *abb = criaAbb();
    tAluno *a = NULL;
    char presenca;

    while(fscanf(arq, "%s", plv) == 1){//leitura de nome de alunos
        while(((c = fgetc(arq)) != '\n') && c != EOF);//limpeza de buffer
        if(c == EOF) break;

        a = criaAluno(plv);
        abb = insereAbb(abb, a);
        count++;//numero de alunos
    }
    
    fclose(arq);
    
    for(int i = 1; i <= n; i++){//contabilizando faltas e presencas
        sprintf(nomeArq, "%s%d.txt", NOME_ARQ_ENTRADA, i);
        arq = fopen(nomeArq, "r");
        assert(arq != NULL, "falha na abertura de arquivo de entradaN");
        
        for(int j = 0; j < count; j++){
            fscanf(arq, "%s %c", plv, &presenca);
            while(((c = fgetc(arq)) != '\n') && c != EOF);
            
            a = buscaAbb(abb, plv);
            if(!a) continue;
            (presenca == PRESENCA)? incPresencaAluno(a) : incFaltaAluno(a);
            
            if(c == EOF) break;
        }

        fclose(arq);
    }

    imprimeAbb(abb);

    liberaAbb(abb);

    return EXIT_SUCCESS;
}