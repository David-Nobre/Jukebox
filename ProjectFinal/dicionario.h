/*
 * dicionario.h
 */
#ifndef _H_DICIONARIO
#define _H_DICIONARIO
/* Tipo de dados: dicionario ---> os elementos não podem ser repetidos com base num identificador (chave) dos elementos */
typedef struct _dicionario * dicionario;

/* Prototipos das funcoes associadas a um dicionario */

/***********************************************
criaDicionario - Criacao da instancia da estrutura associada a um dicionario.
Parametros:
     cap - capacidade prevista do dicionario
     TipoChave – 0 – inteiro, 1 - string
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
dicionario criaDicionario(int cap, int tipoChave);

/***********************************************
destroiDicionario - Liberta a memoria ocupada pela instancia da estrutura associada ao dicionario.
Parametros:	d - dicionario a destruir
Retorno:
Pre-condicoes: d != NULL
***********************************************/
void destroiDicionario (dicionario d );

/***********************************************
destroiDicEElems - Liberta a memoria ocupada pela instancia da estrutura associada ao dicionario e os elementos.
Parametros:
	d - dicionario a destruir	destroi - funcao para destruicao os elementos
Retorno:
Pre-condicoes: d != NULL
***********************************************/
void destroiDicEElems(dicionario d, void (*destroi)(void *) );

/***********************************************
vazioDicionario - Indica se o dicionario esta vazio.
Parametros:
	d - dicionario
Retorno: 1- caso dicionario vazio; 0 - caso contrario
Pre-condicoes: d != NULL
***********************************************/
int vazioDicionario(dicionario d);

/***********************************************
tamanhoDicionario - Consulta o numero de elementos no dicionario.
Parametros:
	d - dicionario
Retorno: numero de elementos no dicionario
Pre-condicoes: d != NULL
***********************************************/
int tamanhoDicionario(dicionario d);

/***********************************************
existeElemDicionario – Indica se o elemento  com a chave dada existe no dicionario.
Parametros:
	d – dicionario
	ch – endereço da chave do elemento
Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes: d != NULL && ch != NULL
***********************************************/
int existeElemDicionario(dicionario d, void * ch);

/***********************************************
elementoDicionario - retorna o elemento no dicionario com a chave dada
Parametros:
	d – dicionario	ch - endereco da chave do elemento
Retorno: retorna o elemento
Pre-condicoes: d != NULL && ch != NULL
***********************************************/
void * elementoDicionario(dicionario d, void * ch);

/***********************************************
adicionaElemDicionario - Adiciona o elemento dado no dicionario, se não existir um elemento com a mesma chave.
Parametros:
	d – dicionario
	ch - endereco da chave do elemento
	elem - endereco do elemento
Retorno: Retorna 1 se adicionar, e 0, caso contrário
Pre-condicoes: d != NULL && ch != NULL && elem != NULL
***********************************************/
int adicionaElemDicionario(dicionario d, void * ch, void * elem);

/***********************************************
removeElemDicionario - Remove o elemento com a chave dada no dicionario, se existir.
Parametros:
	d – dicionario	ch – endereco da chave
Retorno: Retorna o elemento, caso exista ou NULL, caso contrario
Pre-condicoes: d != NULL && ch != NULL
***********************************************/
void * removeElemDicionario(dicionario d, void * ch);

/***********************************************
iteradorDicionario - Cria e devolve um iterador para os elementos guardados no dicionario.
Parametros:
d - dicionario
Retorno: iterador dos elementos do dicionario
Pre-condicoes: d != NULL && vazioDicionario(d)!=1
***********************************************/
iterador iteradorDicionario(dicionario d);

/***********************************************
iteradorChaveDicionario - Cria e devolve um iterador para as chaves dos elementos guardados no dicionario.
Parametros: d - dicionario
Retorno: iterador das chaves dos elementos no dicionario
Pre-condicoes: d != NULL && vazioDicionario(d)!=1
***********************************************/
iterador iteradorChaveDicionario(dicionario d);

#endif
