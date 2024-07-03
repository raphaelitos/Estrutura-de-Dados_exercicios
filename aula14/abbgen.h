#ifndef _ABBGEN_H_
#define _ABBGEN_H_

typedef struct abbgen tAbbg;

/// @brief cria um ponteiro da estrutura tAbb
/// @return um ponteiro de tAbb com valor NULL
tAbbg *criaABB();

/// @brief busca um aluno na arvore com base 
/// em sua matricula
/// @param abb um ponteiro de tAbb
/// @param matricula a matricula do aluno buscado
/// @return ponteiro para aluno 
/// (null se ele nao existir na arvore)
/// @param comparaChave funcao para identificar 
/// o dado com base numa chave
void *buscaAbb(tAbbg *abb, void *chave, int (*comparaChave)(void*, void*));

/// @brief imprime uma arvore em ordem crescente
/// @param abb um ponteiro valido para tAbb
/// @param imprimeDado funcao para imprimir o dado
/// do no da arvore
void imprimeAbb(tAbbg *abb, void (*imprimeDado)(void *));

/// @brief insere um aluno na arvore
/// @param abb um ponteiro para tAbb
/// @param dado um dado valido
/// @param compara callback de comparacao
/// @return a arvore com o aluno inserido
tAbbg *insereAbb(tAbbg *abb, void *dado, int (*compara)(void *, void *));

/// @brief retira um aluno com base em sua matricula
/// @param abb um ponteiro para tAbb
/// @param chave a chave para buscar o aluno
/// a ser retirado
/// @param comparaChave funcao para identificar
/// o dado com base numa chave 
/// @return a arvore modificada, sem o aluno
tAbbg *retiraAbb(tAbbg *abb , void *chave, int (*comparaChave)(void*, void*));

/// @brief libera a memoria utilizada
/// por uma estrutura tAbb
/// @param abb a arvore que se deseja desalocar
void desalocaaAbb(tAbbg *abb);

#endif