#ifndef ARV_H_
#define ARV_H_

/*Tipo que define a arvore(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD. */
typedef struct arv tArv;

/*Cria uma arvore vazia, ou seja, retorna NULL
* inputs: nenhum
* output: NULL
*/
tArv* CriaVazia(void);

/*cria um n� raiz de operador dados o operador e as duas sub-�rvores, a da esquerda e a da direita
* inputs: o operador, as sub-arvores da esquerda e da direita
* output: o endere�o do n� raiz criado
*/
tArv* CriaOperador(char c, tArv* esq, tArv* dir);

/*cria um n� operando dado o valor do no (como o operando � um n� folha, as sub-arvores da esquerda e da direita s�o nulas
* inputs: o operando
* output: o endere�o do n� raiz criado
*/
tArv* CriaOperando(int valor);

/*Imprime a �rvore em nota��o InOrder (esq, raiz, direita)
* inputs: o endere�o da raiz da �rvore
* output: nenhum
*/
void Imprime(tArv* arv);

/* Libera mem�ria alocada pela estrutura da �rvore
as sub-�rvores devem ser liberadas antes de se liberar o n� raiz
* inputs: o endere�o da raiz da �rvore
* output: uma �rvore vazia, representada por NULL
*/
tArv* Libera (tArv* arv);


/* Retorna o valor correspondente � avalia��o da express�o representada na �rvore
* inputs: o endere�o da raiz da �rvore
* output: o valor da express�o
*/
float Avalia(tArv* arv);


/* Retorna o n�mero de folhas da �rvore
* inputs: o endere�o da raiz da �rvore
* output: o n�mero de folhas
*/
int Folhas(tArv* arv);

/* Retorna a altura da �rvore
* inputs: o endere�o da raiz da �rvore
* output: a altura da �rvore
*/
int Altura(tArv* arv);


#endif /* ARV_H_ */
