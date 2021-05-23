#include <stdlib.h>
# include "noSimples.h"

/* Tipo do TAD noSimples */
struct _noSimples{
	void * elem;
	struct _noSimples * seguinte;
};

/* Protótipos das funções associadas a um aluno - TAD noSimples */

/* Criação de um nó simples */
noSimples criaNoSimples(void * e, noSimples seg){
	noSimples aux = (noSimples) malloc(sizeof(struct _noSimples));
	if (aux == NULL)
		return NULL;
	aux->elem = e;
	aux-> seguinte = seg;
	return aux;
}

/* Destruição do nó Simples */
void destroiNoSimples(noSimples n){
	free(n);
}

/* Destruição do nó Simples e do seu elemento */
void destroiElemENoSimples(noSimples n, void (*destroi)(void *)){
	destroi(n->elem);
	free(n);
}

/* Atribuição de elemento e ao nó simples */
void atribuiElemNoSimples(noSimples n, void * e){
	n->elem = e;
}

/* Atribuição de seguinte seg ao nó simples */
void atribuiSegNoSimples(noSimples n, noSimples seg){
	n->seguinte = seg;
}

/* Consulta do elemento do nó simples n */
void * elemNoSimples(noSimples n){
	return n->elem;
}

/* Consulta do seguinte do nó simples n */
noSimples segNoSimples(noSimples n){
	return n->seguinte;
}
