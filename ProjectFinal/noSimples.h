/*
 * noSimples.h
 */

#ifndef NOSIMPLES_H_
#define NOSIMPLES_H_

/* Tipo do TAD noSimples */
typedef struct _noSimples * noSimples;

/* Protótipos das funções associadas a um aluno - TAD noSimples */

/***********************************************
criaNoSimples - Criação da instância da estrutura associada a um nó simples.
Parâmetros:
	e - elemento a guardar no nó (void *)
	seg - endereço do seguinte nó
Retorno: apontador para a instância criada
Pré-condições:
***********************************************/
noSimples criaNoSimples(void * e, noSimples seg);

/***********************************************
destroiNoSimples - Liberta a memória ocupada pela instância da estrutura associada ao nó.
Parâmetros:
	n - nó a destruir
Retorno:
Pré-condições: n != NULL
***********************************************/
void destroiNoSimples(noSimples n);

/***********************************************
destroiElemENoSimples - Liberta a memória ocupada pela instância da estrutura associada ao nó.
Parâmetros:
	n - nó a destruir
	destroi - função para destruir o elemento
Retorno:
Pré-condições: n != NULL
***********************************************/
void destroiElemENoSimples(noSimples n, void (*destroi)(void *));

/***********************************************
atribuiElemNoSimples - Guarda o elemento dado no nó.
Parâmetros:
	n - nó
	e - elemento (void *)
Retorno:
Pré-condições: n != NULL
***********************************************/
void atribuiElemNoSimples(noSimples n, void * e);

/***********************************************
atribuiSegNoSimples - Guarda o endereço do nó seguinte dado no nó.
Parâmetros:
	n - nó
	seg - endereço do nó seguinte
Retorno:
Pré-condições: n != NULL
***********************************************/
void atribuiSegNoSimples(noSimples n, noSimples seg);

/***********************************************
elemNoSimples - Retorna o elemento no nó dado.
Parâmetros:
	n - nó
Retorno: elemento (void *)
Pré-condições: n != NULL
***********************************************/
void * elemNoSimples(noSimples n);

/***********************************************
segNoSimples - Retorna o endereço do nó seguinte ao nó dado.
Parâmetros:
	n - nó
Retorno: endereço do nó seguinte
Pré-condições: n != NULL
***********************************************/
noSimples segNoSimples(noSimples n);

#endif /* NOSIMPLES_H_ */
