#ifndef LISTAGEN_H_
#ifndef LISTAGEN_H_

typedef struct listagen tListaGen;

tListaGen *criaListaGen();

void liberaListaGen(tListaGen *l);

tListaGen *insereListaGen(tListaGen *l, void *dado);

tListaGen *retiraListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado);

int percorreListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado);

#endif