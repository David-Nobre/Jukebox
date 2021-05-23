/*
 * dicOrdVector.c
 */
#include <stdlib.h>
#include "iterador.h"
#include "dicOrdenado.h"
#include "chaves.h"
#include "noSimples.h"
#include "tuplo.h"

struct _dicOrdenado{
	noSimples * elems; // apontador para vector de noSimples (lista com cabeça)
	int numElems;
	int capacidade; // capacidade prevista
	int tamanho; // tamanho do vector criado
	int tipoCh; // 0-inteiro; 1-string
};

int primoDicOrdenado(int n){
	int primo = 0, counter;
	n++; // n e impar (2n+1) logo reduzimos o numero de comparacoes em metade
	while(!primo){
        counter = 0;
        for(int i = 3; i*i < n; i += 2){ // comparar todos os numeros impares inferiores a raiz de n
            if(n%i == 0){
                counter++; // indicador de fatores 0 - nenhum fator 1 - existem fatores
                break;
            }
        }
        if(counter == 0)
            primo = n; // se nao existem fatores atribuir n a primo
        n+=2; // aumentar n para o numero impar consecutivo
	}
	return primo;
}

dicOrdenado criaDicOrdenado(int cap, int tipoChave){
	dicOrdenado d;
	int i;
	d = (dicOrdenado) malloc(sizeof(struct _dicOrdenado));
	if ( d == NULL) return NULL;
	d->tamanho = primoDicOrdenado(2*cap);
	d->elems = (noSimples*)malloc(sizeof(noSimples) * d->tamanho);
	if (d->elems == NULL){
		free(d);
		return NULL;
	}
	for (i=0;i<d->tamanho;i++)
		d->elems[i] = NULL;
	d->numElems = 0;
	d->capacidade = cap;
	d->tipoCh =tipoChave;
	return d;
}

void destroiDicOrdenado (dicOrdenado d ){
	int i = 0;
	noSimples  aux;
	tuplo t;
	for(;i<d->tamanho;i++){
		aux = d->elems[i];
		while (aux != NULL){
			d->elems[i] = segNoSimples(aux);
			t = (tuplo) elemNoSimples(aux);
			destroiNoSimples(aux);
			destroiTuplo(t);
			aux = d->elems[i];
		}
	}
	free(d);
}
void destroiDicOrdEElems(dicOrdenado d, void (*destroi)(void *) ){
	int i = 0;
	noSimples  aux;
	tuplo t;
	for(;i<d->tamanho;i++){
		aux = d->elems[i];
		while (aux != NULL){
			d->elems[i] = segNoSimples(aux);
			t = elemNoSimples(aux);
			destroi(segTuplo(t));
			destroiNoSimples(aux);
			destroiTuplo(t);
			aux = d->elems[i];
		}
	}
	free(d);
}


int vazioDicOrdenado(dicOrdenado d){
	if (d->numElems == 0)
		return 1;
	return 0;
}

int tamanhoDicOrdenado(dicOrdenado d){
	return d->numElems;
}

int existeElemDicOrdenado(dicOrdenado d, void * ch){
	if (elementoDicOrdenado(d,ch) != NULL)
        return 1;
	return 0;
}

void * elementoDicOrdenado(dicOrdenado d, void * ch){
	tuplo t;
	noSimples auxNo;
	int pos = dispersao(ch,d->tamanho,d->tipoCh);
	auxNo = d->elems[pos];
	while (auxNo != NULL){
		t = elemNoSimples(auxNo);
		if (igualChaves(priTuplo(t), ch,d->tipoCh) == 1)
			return segTuplo(t);
		auxNo = segNoSimples(auxNo);
	}
	return NULL;
}

int adicionaElemDicOrdenado(dicOrdenado d, void * ch, void * elem){
	int pos;
	noSimples auxNo;
	if (existeElemDicOrdenado(d,ch) == 1)
		return 0;
	pos = dispersao(ch,d->tamanho,d->tipoCh);
	tuplo t = criaTuplo(d->tipoCh, ch, elem);
    auxNo = criaNoSimples(t, NULL);
    if(d->elems[pos] == NULL)
        d->elems[pos] = auxNo;
    else{
        atribuiSegNoSimples(auxNo, d->elems[pos]);
        d->elems[pos] = auxNo;
    }
	d->numElems++;
	return 1;
}

void * removeElemDicOrdenado(dicOrdenado d, void * ch){
	tuplo t;
	void * elem;
	void * auxCh;
	noSimples auxNo, antNo = NULL;
	int pos = dispersao(ch,d->tamanho,d->tipoCh);
	auxNo = d->elems[pos];
	if (auxNo == NULL)
		return NULL;
	while(auxNo != NULL){
        t = elemNoSimples(auxNo);
        auxCh = priTuplo(t);
        if(igualChaves(ch, auxCh, d->tipoCh) == 1){
            elem = segTuplo(t);
            if(antNo == NULL)
                d->elems[pos] = segNoSimples(auxNo);
            else
                atribuiSegNoSimples(antNo, segNoSimples(auxNo));
            destroiTuplo(t);
            destroiNoSimples(auxNo);
            d->numElems--;
            return elem;
        }
        antNo = auxNo;
        auxNo = segNoSimples(auxNo);
	}
	return NULL;
}

void troca(void **Elem1, void **Elem2){
  void *aux = *Elem1;
  *Elem1 = *Elem2;
  *Elem2 = aux;
}

void ordenaDicOrdenado(void *v[],int esq,int dir, int tipoCh){
    int i = esq;
    int j = dir;
    void * p = priTuplo(v[(i+j) / 2]); //pivot é o ponto médio
    do {
        while (compChaves(priTuplo(v[i]),(p), tipoCh) < 0) // v[i]<p
            i++;
        while (compChaves(p,priTuplo(v[j]), tipoCh) < 0) // p<v[j]
            j--;
        if (i <= j)
            troca(&v[i++], &v[j--]); // troca
    } while (i<=j);
    if (esq<j)
        ordenaDicOrdenado(v,esq,j, tipoCh);
    if (i<dir)
        ordenaDicOrdenado(v,i,dir, tipoCh);
}

iterador iteradorDicOrdenado(dicOrdenado d){
	void * * vector = malloc(sizeof(void*)* d->numElems);
	int j = 0;
	for(int i = 0; i < d->tamanho; i++){
        noSimples auxNo = d->elems[i];
        while(auxNo != NULL){
            tuplo t = elemNoSimples(auxNo);
            vector[j] = t;
            auxNo = segNoSimples(auxNo);
            j++;
        }
	}
	ordenaDicOrdenado(vector, 0, d->numElems-1, d->tipoCh);
	for (int k = 0; k < d->numElems; k++)
        vector[k] = segTuplo(vector[k]);
	return criaIterador(vector,d->numElems);
}

iterador iteradorChaveDicOrdenado(dicOrdenado d){
	void * * vector = malloc(sizeof(void*)* d->numElems);
	int j = 0;
	for(int i = 0; i < d->tamanho; i++){
        noSimples auxNo = d->elems[i];
        while(auxNo != NULL){
            tuplo t = elemNoSimples(auxNo);
            vector[j] = t;
            auxNo = segNoSimples(auxNo);
            j++;
        }
	}
	ordenaDicOrdenado(vector, 0, d->numElems-1, d->tipoCh);
	for(int k =0 ;k<d->numElems;k++)
		vector[k]=priTuplo(vector[k]);
	return criaIterador(vector,d->numElems);
}
