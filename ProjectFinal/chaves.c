/*
 * chaves.c
 */

#include <string.h>
#include "chaves.h"

int igualChaves (void * ch1, void * ch2, int tipo){
	switch (tipo){
	case 0:
		if ( *((int*) ch1) == *((int*) ch2))
			return 1;
		return 0;
	case 1:
		if (strcmp ((char*) ch1, (char *)ch2) == 0)
			return 1;
		return 0;
	}
	return 0;
}

int compChaves (void * ch1, void * ch2, int tipo){
    switch (tipo){
	case 0:
		if ( *((int*) ch1) == *((int*) ch2))
			return 0;
        if ( *((int*) ch1) < *((int*) ch2))
			return -1;
		return 1;
	case 1:
		return strcmp ((char*) ch1, (char *)ch2);
	}
	return 0;
}

int dispersaoChar(char * v, int n){
	int i, num=0;
	for(i=0;i<strlen(v);i++)
	    num= num + v[i];
	return num %n;
}

int dispersaoInt(int * v, int n){
	return *v % n;
}

int dispersao(void * chave, int tamV,int tipoChave){
	switch (tipoChave) {
	  case 1: return dispersaoChar((char*) chave,tamV);
	  case 0: return dispersaoInt((int *) chave,tamV);
	}
	return 0;
}
