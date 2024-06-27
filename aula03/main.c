#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

/*#define RECUPERA_ELEMENTO 1
#define RECUPERA_NCOL 2
#define RECUPERA_NLIN 3
#define TRANSPOSTA 4
#define MULTIPLICA 5
#define IMPRIMEMAT 6
#define IMPRIMELINHAS 7
#define ENCERRA 8
*/

typedef enum {
    RECUPERA_ELEMENTO = 1,
    RECUPERA_NCOL,
    RECUPERA_NLIN,
    TRANSPOSTA,
    MULTIPLICA,
    IMPRIMEMAT,
    IMPRIMELINHAS,
    ENCERRA
} Operacao;


//AUXILIARES//

Matriz *LeMatriz(){
    int linhas, colunas;
    printf("Dimensoes da sua matriz [separadas por espaco]: ");
    scanf("%d %d", &linhas, &colunas);
    while(getchar() != '\n');

    Matriz *m = inicializaMatriz(linhas, colunas);
    printf("Uma matriz preenchida de zeros foi criada.\n");
    int opcao = 0;

    printf("Deseja alterar elementos da sua matriz?\n");
    printf("\t1-SIM\n\t0-NAO\n");
    scanf("%d", &opcao);
    if(opcao){
        while(1){
            int elemento;
            printf("Valor do elemento: ");
            scanf("%d", &elemento);
            printf("Digite a posicao ['linha coluna'] do elemento: ");
            scanf("%d %d", &linhas, &colunas);
            while(getchar() != '\n');
            modificaElemento(m, linhas, colunas, elemento);
            
            printf("Deseja alterar outro elemento?\n");
            printf("\t1-SIM\n\t0-NAO\n");
            scanf("%d", &opcao);        
            while(getchar() != '\n');
            if(!opcao){
                break;
            }

        }
    }
    return m;
}

void ProcessaMultiplicacao(Matriz *m){
    if(!m){
        printf("Matriz principal nula enviada para multiplicacao\n");
        exit(EXIT_FAILURE);
    }
    printf("Leitura da matriz que sera multiplicada\n");
    Matriz *m2 = LeMatriz();
    
    Matriz *mult = multiplicacao(m, m2);
    
    if(mult){
        printf("Resultado:\n");
        imprimeMatriz(mult);
        destroiMatriz(mult);
    }
    destroiMatriz(m2);
}

void ProcessaRetornoElemento(Matriz *m){
    if(!m){
        printf("Matriz principal nula enviada para retorno de elemento\n");
        exit(EXIT_FAILURE);
    }
    int linha, coluna;
    printf("Digite a posicao ['linha coluna'] do elemento: ");
    scanf("%d %d", &linha, &coluna);
    while(getchar() != '\n');
    int e = recuperaElemento(m, linha, coluna);
    printf("O elemento a(%d%d) eh %d!\n", linha, coluna, e);
}

void ProcessaTransposta(Matriz *m){
    if(!m){
        printf("Matriz nula enviada para funcao transposta");
        exit(EXIT_FAILURE);
    }
    Matriz *trans = transposta(m);
    printf("Matriz transposta:\n"); 
    imprimeMatriz(trans);
    destroiMatriz(trans);
}

void ProcessaImpressaoLinha(Matriz *m){
    if(!m){
        printf("Matriz nula enviada para impressao de linha\n");
        exit(EXIT_FAILURE);
    }
    int id;
    printf("Digite a linha a ser impressa: ");
    scanf("%d", &id);
    imprimeLinhas(m, id);
}

void ImprimeMenu(){
    printf("###MENU DE OPERACOES MATRICIAIS###\n");
    printf("\t1 - RECUPERAR ELEMENTO\n");
    printf("\t2 - NUMERO DE COLUNAS\n");
    printf("\t3 - NUMERO DE LINHAS\n");
    printf("\t4 - CALCULO DE TRANSPOSTA\n");
    printf("\t5 - MULTIPLICACAO\n");
    printf("\t6 - IMPRIMIR MATRIZ\n");
    printf("\t7 - IMPRIMIR LINHA DE MATRIZ\n");
    printf("\t8 - ENCERRAR PROGRAMA\n");
    printf("Digite a operacao desejada: ");
}

//----*----//

int main(){
    printf("Leitura de matriz principal\n");
    Matriz *mat = LeMatriz();
    
    int op = 0;

    while(1){
        ImprimeMenu();
        scanf("%d", &op);
        while(getchar() != '\n');

        switch (op)
        {
        case RECUPERA_ELEMENTO:
            
            ProcessaRetornoElemento(mat);
            break;
        
        case RECUPERA_NCOL:
            
            printf("O numero de colunas dessa matriz eh %d\n", recuperaNColunas(mat));
            break;

        case RECUPERA_NLIN:
            
            printf("O numero de linhas dessa matriz eh %d\n", recuperaNLinhas(mat));
            break;

        case TRANSPOSTA:
            
            ProcessaTransposta(mat);
            break;
        
        case MULTIPLICA:
        
            ProcessaMultiplicacao(mat);
            break;
        
        case IMPRIMEMAT:
        
            imprimeMatriz(mat);
            break;
        
        case IMPRIMELINHAS:
        
            ProcessaImpressaoLinha(mat);
            break;
        
        case ENCERRA:
        
            printf("Encerrando programa...\n");
            destroiMatriz(mat);
            return 0;
            break;

        default:
        
            printf("Opcao Invalida!\n");
            break;
        
        }
    }
}