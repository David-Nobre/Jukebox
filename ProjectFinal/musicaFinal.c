#include <stdlib.h>
#include <string.h>

#include "iterador.h"
#include "dicionario.h"
#include "musica.h"



struct _musica{
    char *nome;
    char *autor;
    char *genero;
    int ano;
    int duracao;
    int vezesTocada;
    dicionario playlists;
};

musica criaMusica(char *nome, char *autor, char *genero, int ano, int duracao){

    musica m = (musica) malloc (sizeof (struct _musica));
    m->playlists = criaDicionario(3000, 1);
    m->nome = (char*)malloc(sizeof(char)*(strlen(nome) + 1));
    strcpy(m->nome, nome);
    m->autor = (char*) malloc( sizeof (char*)*(strlen(autor)+1));
    strcpy(m->autor, autor);
    m->genero = (char*) malloc (sizeof (char*)*(strlen(genero)+1));
    strcpy(m->genero, genero);
    m->ano = ano;
    m->duracao = duracao;
    m->vezesTocada = 0;

    return m;
}

void destroiMusica(musica m){
    free(m->nome);
    free(m->autor);
    free(m->genero);
    destroiDicionario(m->playlists);
    free(m);
}

void destroiMusicaGenerica(void* m){
    destroiMusica((musica) m);
}

void tocaMusica(musica m){
    m->vezesTocada++;
}

int RetornaNumPlaylistsMusica(musica m){
    return tamanhoDicionario(m->playlists);
}

char* RetornaNomeMusica(musica m){
    return m->nome;
}

char* RetornaAutorMusica(musica m){
    return m->autor;
}

char* RetornaGeneroMusica(musica m){
    return m->genero;
}

int RetornaAnoMusica(musica m){
    return m->ano;
}

int RetornaDuracaoMusica(musica m){
    return m->duracao;
}

int RetornaVezesTocadaMusica(musica m){
    return m->vezesTocada;
}

void adicionaPlaylistMusica(musica m, char *nomePlaylist){
    adicionaElemDicionario(m->playlists, nomePlaylist, nomePlaylist);
}

void RemovePlaylistMusica(musica m, char *nomePlaylist){
    removeElemDicionario(m->playlists, nomePlaylist);
}

iterador RetornaIteradorPlaylistsMusica(musica m){
    return iteradorChaveDicionario(m->playlists);
}
