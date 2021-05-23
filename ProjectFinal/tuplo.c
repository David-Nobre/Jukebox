#include <stdlib.h>
#include <string.h>
#include "tuplo.h"

/* Tipo do TAD tuplo */
struct _tuplo {
	void * priElem;
	void * segElem;
};

tuplo criaTuplo(int tipoPri, void * pri, void * seg){
	tuplo aux = (tuplo) malloc(sizeof(struct _tuplo));
		if (aux == NULL)
			return NULL;
		if (tipoPri == 0){
			aux->priElem = (int *) malloc(sizeof(int));
			* ((int *)(aux->priElem)) = *((int*)pri);
		}
		else{
			aux->priElem = (char *) malloc((strlen((char*)pri)+1)*sizeof(char));
			strcpy(aux->priElem,pri);
		}
		aux-> segElem = seg;
		return aux;
	}

void destroiTuplo(tuplo t){
	free(t->priElem);
	free(t);
}

void * priTuplo(tuplo t){
	return t->priElem;
}

void * segTuplo(tuplo t){
	return t->segElem;
}
