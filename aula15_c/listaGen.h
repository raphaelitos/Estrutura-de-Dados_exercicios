#ifndef LISTAGEN_H_
#define LISTAGEN_H_

typedef struct listagen tListaGen;

/// @brief inicializa uma lista generica
/// @return uma variavel do tipo tListaGen
/// devidamente alocada
tListaGen *criaListaGen();

/// @brief libera a memoria utilizada por l
/// @param l uma lista generica valida
/// @param liberaCelula callback para funcao que
/// libera uma celula de l
void liberaListaGen(tListaGen *l, void(*liberaCelula)(void *dado));

/// @brief imsere dado como primeira celula de l
/// @param l uma lista generica valida
/// @param dado um dado valido
/// @return a nova lista generica, com dado 
/// na primeira celula
tListaGen *insereListaGen(tListaGen *l, void *dado);

/// @brief retira uma celula de l com base
/// na comparacao feita por cb
/// @param l uma lista generica valida
/// @param cb uma funcao de comparacao
/// @param dado um dado valido
/// @return a lista sem o elemento procurado
tListaGen *retiraListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado);

/// @brief busca uma celula de l com base
/// na comparacao feita por cb
/// @param l uma lista generica valida
/// @param cb uma funcao de comparacao
/// @param dado um dado valido
/// @return o dado procurado (ou null caso
/// ele nao exista)
void *buscaListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado);

/// @brief percorre l executando cb
/// @param l uma lista generica valida
/// @param cb uma funcao de comparacao
/// @param dado um dado valido
/// @return 0, caso cb retorne 0 para alguma
/// celula; 1 caso contrario
int percorreListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado);

#endif