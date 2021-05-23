#include <stdlib.h>
#include <string.h>

#include "iterador.h"
#include "musica.h"
#include "playlist.h"
#include "SequenciaLista.h"


struct _playlist{
    char *nomePlaylist;
    sequencia musicas;
    int MaxMusicas;
    int tempoAtual;
    int tempoMax;
    int timesPlayedPlaylist;
};

playlist criaPlaylist(char *nomePlaylist, int MaxMusicas, int tempoMax){
    playlist p = (playlist) malloc (sizeof (struct _playlist));
    if(p == NULL) return NULL;

    p->nomePlaylist = (char*) malloc (sizeof (char)*(strlen(nomePlaylist) + 2));
    strcpy(p->nomePlaylist, nomePlaylist);

    p->musicas = criaSequencia(MaxMusicas);
    if(p->musicas == NULL){
        free(p);
        return NULL;
    }
    p->MaxMusicas = MaxMusicas;
    p->tempoAtual = 0;
    p->tempoMax = tempoMax;
    p->timesPlayedPlaylist = 0;

    return p;
}

int NovaMusicaPlaylist(playlist p, musica m, int posMusica){
    if(p->tempoAtual + RetornaDuracaoMusica(m) > p->tempoMax)
        return 0;
    if(tamanhoSequencia(p->musicas) + 1 > p->MaxMusicas)
        return 1;
    adicionaPosSequencia(p->musicas, m, posMusica);
    p->tempoAtual = p->tempoAtual + RetornaDuracaoMusica(m);
    return 2;
}

void destroiPlaylist(playlist p){
    destroiSequencia(p->musicas);
    free(p->nomePlaylist);
    free(p);
}

void destroiPlaylistGenerica(void* p){
    destroiPlaylist((playlist) p);
}

char* RetornaNomePlaylist(playlist p){
    return p->nomePlaylist;
}

int RetornaNumMusicasPlaylist(playlist p){
    return tamanhoSequencia(p->musicas);
}

int RetornaTempoPlaylist(playlist p){
    return p->tempoAtual;
}

void tocaPlaylist(playlist p){
    p->timesPlayedPlaylist++;
    for(int i = 0; i < tamanhoSequencia(p->musicas); i++){
        tocaMusica(elementoPosSequencia(p->musicas, i + 1));
    }
}

int RetornaVezesTocadaPlaylist(playlist p){
    return p->timesPlayedPlaylist;
}

musica RetornaMusicaPlaylist(playlist p, int pos){
    return elementoPosSequencia(p->musicas, pos + 1);
}

musica RemoveMusicaPlaylist(playlist p, int pos){
    musica m = removePosSequencia(p->musicas, pos);
    p->tempoAtual = p->tempoAtual - RetornaDuracaoMusica(m);
    return m;
}

int PosMusicaPlaylist(playlist p, char *nomeMusica){
    int i = 1, pos = -1;
    while((i < tamanhoSequencia(p->musicas) + 1)&&(pos == -1)){
        if(!strcmp(nomeMusica, RetornaNomeMusica(elementoPosSequencia(p->musicas, i))))
            pos = i;
        i++;
    }
    return pos;
}

iterador RetornaIteradorMusicaPlaylist(playlist p){
    return iteradorSequencia(p->musicas);
}
