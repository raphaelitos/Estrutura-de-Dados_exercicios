#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tBanhoTosa.h"
#include "tLista.h"
#include "utils.h"

struct banhotosa{
    char* nome;
    tLista *mansos;
    tLista *bravos;
};

tBanhoTosa* inicBanhoTosa(char* nome){
    if(!nome){
        TratarStructNula("inicBanhoTosa", "char*");
    }
    tBanhoTosa *bt = (tBanhoTosa*)calloc(1, sizeof(tBanhoTosa));
    if(!bt){
        TratarFalhaAlocacao("BanhoTosa");
    }
    bt->nome = strdup(nome);
    bt->mansos = criaLista();
    bt->bravos = criaLista();

    return bt;
}

void cadastraCachorro(tBanhoTosa* loja, tCachorro* dog){
    if(!(loja && dog)) TratarStructNula("cadastra", "loja ou cachorro");
    
    if(EhMansoCachorro(dog)) insereListaCachorro(loja->mansos, dog);

    else insereListaCachorro(loja->bravos, dog);    
}

void cadastraGato(tBanhoTosa* loja, tGato* cat){
    if(!(loja && cat)) TratarStructNula("cadastra", "loja ou Gato");
    
    if(EhMansoGato(cat)) insereListaGato(loja->mansos, cat);

    else insereListaGato(loja->bravos, cat);    
}

void atualizaSituacaoGato(tBanhoTosa* loja, tGato* cat){
    if(!(loja && cat)) TratarStructNula("atualizasituacao", "loja ou gato");

    if(EhMansoGato(cat)){
        retiraListaGato(loja->bravos, cat);
        insereListaGato(loja->mansos, cat);
    }
    else{
        retiraListaGato(loja->mansos, cat);
        insereListaGato(loja->bravos, cat);
    }
}

void atualizaSituacaoCachorro(tBanhoTosa* loja, tCachorro* dog){
    if(!(loja && dog)) TratarStructNula("atualizasituacao", "loja ou Cachorro");

    if(EhMansoCachorro(dog)){
        retiraListaCachorro(loja->bravos, dog);
        insereListaCachorro(loja->mansos, dog);
    }
    else{
        retiraListaCachorro(loja->mansos, dog);
        insereListaCachorro(loja->bravos, dog);
    }
}

void imprimeBanhoTosa(tBanhoTosa* loja){
    if(!loja) TratarStructNula("imprime", "banhotosa");
    printf("#############IMPRESSAO DE LOJA#################\n");
    printf("NOME: %s\n", loja->nome);
    printf("ANIMAIS ATENDIDOS:\n");
    printf("\t[BRAVOS]\n");
    imprimeLista(loja->bravos);
    printf("\t[MANSOS]\n");
    imprimeLista(loja->mansos);
    printf("######################################\n");
}

float calculaReceita(tBanhoTosa* loja){
    if(!loja) TratarStructNula("calculareceita", "loja");
    float receita = 0;

    receita += calculaReceitaLista(loja->mansos);
    receita += calculaReceitaLista(loja->bravos);
    receita += 5 * (getTamLista(loja->bravos));
    return receita;
}

void liberaBanhoTosa(tBanhoTosa* loja){
    if(!loja) TratarStructNula("libera", "loja");
    desalocaLista(loja->mansos);
    desalocaLista(loja->bravos);
    free(loja->nome);
    free(loja);
}