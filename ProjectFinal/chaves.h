/*
 * chaves.h
 */

#ifndef _H_CHAVES
#define _H_CHAVES

/***********************************************
igualChaves - Indica se duas chaves de um dado tipo sao iguais.
Parametros:
	ch1 - chave (void *)
	ch2 - chave (void *)
	tipo - 0 - inteiro; 1- string
Retorno: 1 - caso as chaves sejam iguais; 0- caso contrario
Pre-condicoes: a1 != NULL && a2 != NULL && (tipo==0 || tipo==1)
**********************************************/
int igualChaves (void * ch1, void * ch2, int tipo);

/***********************************************
compChaves - Compara duas chaves de um dado tipo sao iguais.
Parametros:
	ch1 - chave (void *)
	ch2 - chave (void *)
	tipo - 0 - inteiro; 1- string
Retorno: 0 - ch1 == ch2; -1 - ch1 < ch2; 1 - ch1 > ch2
Pre-condicoes: a1 != NULL && a2 != NULL && (tipo==0 || tipo==1)
**********************************************/
int compChaves (void * ch1, void * ch2, int tipo);

/***********************************************
dispersao - Retorna o valor associado a funcao de dispersao
aplicada a chave dada do tipo dado, numa tabela de dispersao
com dimensao dada.
Parametros:
	chave - endereço da chave (void *)
	tamV - dimensao da tabela de dispersao
	tipo - tipo da chave 0 - inteiro; 1- string
Retorno: valor da funcao de dispersao (posicao na tabela de dispersao)
Pre-condicoes: chave != NULL && (tipo==0 || tipo==1)
**********************************************/
int dispersao(void * chave, int tamV,int tipo);

#endif /* CHAVES_H_ */
