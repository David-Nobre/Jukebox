#include <stdlib.h>
#include <string.h>

#include "iterador.h"
#include "dicOrdenado.h"
#include "dicionario.h"
#include "musica.h"
#include "playlist.h"
#include "jukebox.h"

#define MAX_MUSICAS 1000
#define MAX_PLAYLISTS 1000

struct _jukebox{
    dicOrdenado musicas;
    dicionario playlists;
    int capacidadeMusicasPlaylist;
    int capacidadeTempoPlaylist;
};

jukebox criaJukebox(int MaxMusicasPlaylist, int MaxTempoPlaylist){
    jukebox j = (jukebox) malloc (sizeof(struct _jukebox));
    if (j == NULL) return NULL;
    j->musicas = criaDicOrdenado(MAX_MUSICAS, 1);
    if (j->musicas == NULL){
        free(j);
        return NULL;
    }
    j->playlists = criaDicionario(MAX_PLAYLISTS, 1);
    if (j->playlists == NULL){
        destroiDicOrdenado(j->musicas);
        free(j);
        return NULL;
    }
    j->capacidadeMusicasPlaylist = MaxMusicasPlaylist;
    j->capacidadeTempoPlaylist = MaxTempoPlaylist;

    return j;
}

void destroiJukeboxEMusicasEPlaylists(jukebox j){
    destroiDicOrdEElems(j->musicas, destroiMusicaGenerica);
    destroiDicionario(j->playlists);
    free(j);
}

int NovaMusicaJukebox(jukebox j, char *nome, char *autor, char *genero, int ano, int duracao){
    musica m;
    if(existeElemDicOrdenado(j->musicas, nome) == 1)
        return 0; // a musica ja existe
    m = criaMusica(nome, autor, genero, ano, duracao);
    if (adicionaElemDicOrdenado(j->musicas, nome, m) == 0)
        return 0; // falhou a adicionar
    return 1; // criou a musica e adicionou a jukebox
}

musica ApagaMusicaJukebox(jukebox j, char *nomeMusica){
    musica m = (musica) removeElemDicOrdenado(j->musicas, nomeMusica);
    if (m == NULL) return NULL;
    if (RetornaNumPlaylistsMusica(m) != 0){
        iterador iteraPlaylists = RetornaIteradorPlaylistsMusica(m);
        while(temSeguinteIterador(iteraPlaylists)){
            char* nomePlaylist = (char*) seguinteIterador(iteraPlaylists);
            playlist p = elementoDicionario(j->playlists, nomePlaylist);
            int pos = PosMusicaPlaylist(p, nomeMusica);
            while(pos != -1){
                RemoveMusicaPlaylist(p, pos);
                pos = PosMusicaPlaylist(p, nomeMusica);
                RemovePlaylistMusica(m, RetornaNomePlaylist(p));
            }
        }
    }
    return m;
}

musica ObtemMusicaJukebox(jukebox j, char *nomeMusica){
    musica m = (musica) elementoDicOrdenado(j->musicas, nomeMusica);
    if (m == NULL) return NULL;
    return m;
}

int MaiorNumPlaylistsJukebox(jukebox j){ // numMusicas != 0 && numPlaylist != 0
    int maior = 0;
    musica m;
    iterador it = iteradorDicOrdenado(j->musicas);
    while(temSeguinteIterador(it)){
        m = (musica)seguinteIterador(it);
        int numPl = RetornaNumPlaylistsMusica(m);
        if (maior < numPl)
            maior = numPl;
    }
    return maior;
}

int criaPlaylistJukebox(jukebox j, char *nomePlaylist){
    playlist p;
    if(existeElemDicionario(j->playlists, nomePlaylist) == 1)
        return 0; // Playlist existente
    p = criaPlaylist(nomePlaylist, j->capacidadeMusicasPlaylist, j->capacidadeTempoPlaylist);
    adicionaElemDicionario(j->playlists, nomePlaylist, p);
    return 1;
}

int destroiPlaylistJukebox(jukebox j, char *nomePlaylist){
    playlist p = (playlist)removeElemDicionario(j->playlists, nomePlaylist);
    if(p == NULL) return 0;
    iterador it = RetornaIteradorMusicaPlaylist(p);
    while(temSeguinteIterador(it)){
        musica m = (musica) seguinteIterador(it);
        RemoveMusicaPlaylist(p, 1);
        if(PosMusicaPlaylist(p, RetornaNomeMusica(m)) == -1)
            RemovePlaylistMusica(m, RetornaNomePlaylist(p));
    }
    destroiPlaylist(p);
    return 1;
}

int NovaMusicaPlaylistJukebox(jukebox j, char *nomeMusica, char *nomePlaylist, int posMusica){
    playlist p = (playlist) elementoDicionario(j->playlists, nomePlaylist);
    if (p == NULL) return -1; /**Playlist inexistente**/
    musica m = elementoDicOrdenado(j->musicas, nomeMusica);
    if(m == NULL) return 0; /**Musica inexistente**/
    if(PosMusicaPlaylist(p, RetornaNomeMusica(m)) == -1)
        adicionaPlaylistMusica(m, nomePlaylist);
    int ctr = NovaMusicaPlaylist(p, m, posMusica);
    if(ctr == 0) {
        RemovePlaylistMusica(m, RetornaNomePlaylist(p));
        return 1;/**excedeu tempo**/
    }
    if(ctr == 1){
        RemovePlaylistMusica(m, RetornaNomePlaylist(p));
        return 2; /**excedeu dimensao**/
    }
    return 3;
}

musica RemoveMusicaPlaylistJukebox(jukebox j, char *nomePlaylist, int pos){ // playlist existente
    playlist p = elementoDicionario(j->playlists, nomePlaylist);
    musica m = RemoveMusicaPlaylist(p, pos);
    if(PosMusicaPlaylist(p, RetornaNomeMusica(m)) == -1)
        RemovePlaylistMusica(m, RetornaNomePlaylist(p));

    return m;
}

int RetornaNumMusicasJukebox(jukebox j){
    return tamanhoDicOrdenado(j->musicas);
}

int RetornaNumPlaylistsJukebox(jukebox j){
    return tamanhoDicionario(j->playlists);
}

playlist RetornaPlaylistJukebox(jukebox j, char *nomePlaylist){
    playlist p = (playlist)elementoDicionario(j->playlists, nomePlaylist);
    if(p == NULL) return NULL;
    return p;
}

int RetornaMaxMusicasJukebox(jukebox j){
    return j->capacidadeMusicasPlaylist;
}

iterador RetornaIteradorMusicasJukebox(jukebox j){
    iterador it = iteradorDicOrdenado(j->musicas);
    return it;
}

