#ifndef DICORDENADO_H_INCLUDED
#define DICORDENADO_H_INCLUDED

/* Tipo de dados: dicionario ordenado ---> os elementos não podem ser repetidos com base num identificador (chave) dos elementos */
typedef struct _dicOrdenado * dicOrdenado;

/* Prototipos das funcoes associadas a um dicionario */

/***********************************************
criaDicOrdenado - Criacao da instancia da estrutura associada a um dicionario.
Parametros:
     cap - capacidade prevista do dicionario ordenado
     TipoChave – 0 – inteiro, 1 - string
Retorno: apontador para a  instancia criada
Pre-condicoes: cap >0 && (tipoChave == 0 || tipoChave == 1)
***********************************************/
dicOrdenado criaDicOrdenado(int cap, int tipoChave);

/***********************************************
destroiDicOrdenado - Liberta a memoria ocupada pela instancia da estrutura associada ao dicionario.
Parametros:	d - dicionario ordenado a destruir
Retorno:
Pre-condicoes: d != NULL
***********************************************/
void destroiDicOrdenado (dicOrdenado d );

/***********************************************
destroiDicOrdEElems - Liberta a memoria ocupada pela instancia da estrutura associada ao dicionario e os elementos.
Parametros:
	d - dicionario a destruir	destroi - funcao para destruicao os elementos
Retorno:
Pre-condicoes: d != NULL
***********************************************/
void destroiDicOrdEElems(dicOrdenado d, void (*destroi)(void *) );

/***********************************************
vazioDicOrdenado - Indica se o dicionario esta vazio.
Parametros:
	d - dicionario
Retorno: 1- caso dicionario vazio; 0 - caso contrario
Pre-condicoes: d != NULL
***********************************************/
int vazioDicOrdenado(dicOrdenado d);

/***********************************************
tamanhoDicOrdenado - Consulta o numero de elementos no dicionario.
Parametros:
	d - dicionario
Retorno: numero de elementos no dicionario
Pre-condicoes: d != NULL
***********************************************/
int tamanhoDicOrdenado(dicOrdenado d);

/***********************************************
existeElemDicOrdenado – Indica se o elemento  com a chave dada existe no dicionario.
Parametros:
	d – dicionario
	ch – endereco da chave do elemento
Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes: d != NULL && ch != NULL
***********************************************/
int existeElemDicOrdenado(dicOrdenado d, void * ch);

/***********************************************
elementoDicOrdenado - retorna o elemento no dicionario com a chave dada
Parametros:
	d – dicionario	ch - endereco da chave do elemento
Retorno: retorna o elemento
Pre-condicoes: d != NULL && ch != NULL
***********************************************/
void * elementoDicOrdenado(dicOrdenado d, void * ch);

/***********************************************
adicionaElemDicOrdenado - Adiciona o elemento dado no dicionario, se nao existir um elemento com a mesma chave.
Parametros:
	d – dicionario
	ch - endereço da chave do elemento
	elem - endereco do elemento
Retorno: Retorna 1 se adicionar, e 0, caso contrario
Pre-condicoes: d != NULL && ch != NULL && elem != NULL
***********************************************/
int adicionaElemDicOrdenado(dicOrdenado d, void * ch, void * elem);

/***********************************************
removeElemDicOrdenado - Remove o elemento com a chave dada no dicionario, se existir.
Parametros:
	d – dicionario	ch – endereco da chave
Retorno: Retorna o elemento, caso exista ou NULL, caso contrario
Pre-condicoes: d != NULL && ch != NULL
***********************************************/
void * removeElemDicOrdenado(dicOrdenado d, void * ch);

/***********************************************
iteradorDicOrdenado - Cria e devolve um iterador ordenado para os elementos guardados no dicionario.
Parametros:
d - dicionario
Retorno: iterador dos elementos do dicionario
Pre-condicoes: d != NULL && vazioDicionario(d)!=1
***********************************************/
iterador iteradorDicOrdenado(dicOrdenado d);

/***********************************************
iteradorChaveDicOrdenado - Cria e devolve um iterador ordenado para as chaves dos elementos guardados no dicionario.
Parametros: d - dicionario
Retorno: iterador das chaves dos elementos no dicionario
Pre-condicoes: d != NULL && vazioDicionario(d)!=1
***********************************************/
iterador iteradorChaveDicOrdenado(dicOrdenado d);

#endif // DICORDENADO_H_INCLUDED
