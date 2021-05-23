#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED

/** Estrutura que guarda dados do tipo playlist**/
typedef struct _playlist *playlist;

/***********************************************
criaPlaylist - cria a instancia da estrutura playlist.
Parametros:	nomePlaylist - nome da playlist a criar.
            MaxMusicas - Capacidade maxima de musicas na playlist.
            tempoMax - Capaciadade maxima temporal da playlist
Retorno: apontador para a instancia criada
Pre-condicoes: nomePlaylist != NULL
***********************************************/

playlist criaPlaylist(char *nomePlaylist, int MaxMusicas, int tempoMax);

/***********************************************
NovaMusicaPlaylist - Adiciona uma musica numa posicao da playlist.
Parametros:	p - playlist a modificar.
            m - musica a adicionar.
            posMusica - posicao onde adicionar a musica
Retorno: 0 - Excedeu tempo || 1 - Excedeu Capacidade de musicas || 2 - Adicionada
Pre-condicoes: p != NULL && m != NULL && posMusica > 0 && posMusica <= tamanho da playlist + 1
***********************************************/

int NovaMusicaPlaylist(playlist p, musica m, int posMusica);

/***********************************************
RetornaNomePlaylist - Retorna nome da playlist.
Parametros:	p - playlist a analisar.
Retorno: nome da playlist.
Pre-condicoes: p != NULL
***********************************************/

char* RetornaNomePlaylist(playlist p);

/***********************************************
destroiPlaylist - Envia para ser destruida um apontador generico (que devera conter tipo de dado playlist).
Parametros:	p - playlist a destruir.
Retorno:
Pre-condicoes: p != NULL
***********************************************/

void destroiPlaylistGenerica(void* p);

/***********************************************
RetornaNumeroMusicasPlaylist - Retorna o numero de musicas na playlist.
Parametros:	p - playlist a analisar.
Retorno: numero de musicass existentes na playlist
Pre-condicoes: p != NULL
***********************************************/

void destroiPlaylist(playlist p);

int RetornaNumMusicasPlaylist(playlist p);

/***********************************************
RetornaTempoPlaylist - Retorna o tempo total da playlist.
Parametros:	p - playlist a analisar.
Retorno: tempo total
Pre-condicoes: p != NULL
***********************************************/

int RetornaTempoPlaylist(playlist p);

/***********************************************
tocaPlaylist - toca todas as musicas presentes na playlist.
Parametros:	p - playlist a analisar.
Retorno:
Pre-condicoes: p != NULL
***********************************************/

void tocaPlaylist(playlist p);

/***********************************************
RetornaVezesTocadaPlaylist - Retorna quantas vezes a playlist foi tocada.
Parametros:	p - playlist a analisar.
Retorno:
Pre-condicoes: p != NULL
***********************************************/

int RetornaVezesTocadaPlaylist(playlist p);

/***********************************************
RetornaMusicaPlaylist - Retorna a musica de uma dada posicao na playlist.
Parametros:	p - playlist a analisar.
            pos - pos da musica a retornar
Retorno: apontador para a musica pretendida
Pre-condicoes: p != NULL && pos > 0 && pos <= tamanho da playlist
***********************************************/

musica RetornaMusicaPlaylist(playlist p, int pos);

/***********************************************
RemoveMusicaPlaylist - Remove a musica numa posicao dada da playlist.
Parametros:	p - playlist a analisar.
            pos - posicao da musica a remover
Retorno: apontador para a musica pretendida
Pre-condicoes: p != NULL && pos > 0 && pos <= tamanho da playlist
***********************************************/

musica RemoveMusicaPlaylist(playlist p, int pos);


/***********************************************
PosMusicaPlaylist - Retorna a posicao de uma musica na playlist.
Parametros:	p - playlist a analisar.
            nomeMusica - nome da musica a encontrar a posicao
Retorno: -1 - Nao existe || posicao da musica
Pre-condicoes: p != NULL && nomeMusica != NULL
***********************************************/

int PosMusicaPlaylist(playlist p, char *nomeMusica);

iterador RetornaIteradorMusicaPlaylist(playlist p);

#endif // PLAYLIST_H_INCLUDED
