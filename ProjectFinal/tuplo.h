/*
 * tuplo.h
 *
 */
#ifndef TUPLO_H_
#define TUPLO_H_

/* Tipo do TAD tuplo */
typedef struct _tuplo * tuplo;

/* Prototipos das funcoes associadas a um tuplo - TAD tuplo */

/***********************************************
criaTuplo - Criacao da instancia da estrutura associada a um tuplo.
Parametros:
	tipoPri - 0 - inteiro, 1 - string
	pri - primeiro elemento a guardar no tuplo (void *)
	seg - segundo elemento a guardar no tuplo (void *)
Retorno: apontador para a instancia criada
Pre-condicoes: tipoPri==0 || tipoPri==1
***********************************************/
tuplo criaTuplo(int tipoPri, void * pri, void * seg);

/***********************************************
destroiTuplo - Liberta a memoria ocupada pela instancia da estrutura associada ao tuplo.
Parametros:
	t - tuplo a destruir
Retorno:
Pre-condicoes: t != NULL
***********************************************/
void destroiTuplo(tuplo t);

/***********************************************
priTuplo - Retorna o primeiro elemento no tuplo dado.
Parametros:
	t - tuplo
Retorno: elemento (void *)
Pre-condicoes: t != NULL
***********************************************/
void * priTuplo(tuplo t);

/***********************************************
segTuplo - Retorna o segundo elemento no tuplo dado.
Parametros:
	t - tuplo
Retorno: elemento (void *)
Pre-condicoes: t != NULL
***********************************************/
void * segTuplo(tuplo t);

#endif /* TUPLO_H_ */
