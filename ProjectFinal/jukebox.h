#ifndef JUKEBOX_H_INCLUDED
#define JUKEBOX_H_INCLUDED

/** Estrutura que guarda tipos de dado jukebox **/
typedef struct _jukebox *jukebox;

/***********************************************
criaJukebox - cria a instancia da estrutura associada a uma jukebox.
Parametros:
Retorno: apontador para a instancia criada.
Pre-condicoes:
***********************************************/

jukebox criaJukebox();

/***********************************************
NovaMusicaJukebox - cria uma musica e adiciona a jukebox.
Parametros: j - jukebox a acrescentar a musica.
            nome - nome da musica.
            autor - autor da musica.
            genero - genero da musica.
            ano - ano de lancamento da musica.
            duracao - duracao da musica em segundos.
Retorno: 0 - ja existente  ||  1 - efetuado com sucesso
Pre-condicoes: j != NULL
***********************************************/

int NovaMusicaJukebox(jukebox j, char *nome, char *autor, char *genero, int ano, int duracao);

/***********************************************
criaPlaylistJukebox - cria uma playlist e adiciona a jukebox.
Parametros:	j - jukebox a acrescentar a playlist.
            nomePlaylist - nome da playlist a ser criada.
            MaxMusicas - Capacidade maxima de numero de musicas que a playlist pode ter.
            MaxTempo - Capacidade maxima temporal de musicas que a playlist pode ter.
Retorno: 0 - Playlist ja existente   ||   1 - Playlist criada.
Pre-condicoes: j != NULL
***********************************************/

int criaPlaylistJukebox(jukebox j, char *nomePlaylist);

/***********************************************
destroiJukeboxEMusicasEPlaylist - destroi a jukebox, as musicass existentes na jukebox e as playlists existentes na jukebox.
Parametros:	j - jukebox a destruir
Retorno:
Pre-condicoes: j != NULL
***********************************************/

void destroiJukeboxEMusicasEPlaylists(jukebox j);

/***********************************************
NovaMusicaPlaylistJukebox - Adiciona uma musica na posicao pretendida a uma playlist da jukebox.
Parametros:	j - jukebox a modificar, nome da playlist a acrescentar a musica, nome da musica a acrescentar e a pos onde a acrescentar
Retorno: -1 - playlist nao existe || 0 - Musica n existe || 1 - Excedeu tempo maximo da playlist || 2 - Excedeu o maximo de numero de musicas na playlist || 3 - Adicionou
Pre-condicoes: j != NULL && nomePlaylist != NULL && nomeMusica != NULL && posMusica <= tamanho Playlist
***********************************************/

int NovaMusicaPlaylistJukebox(jukebox j, char *nomePlaylist, char *nomeMusica, int posMusica);

/***********************************************
destroiPlaylistJukebox - destroi uma playlist da jukebox.
Parametros:	j - jukebox a a analisar
            nomePlaylist - Nome da playlist a destruir
Retorno: 0 - Playlist Nao existe || 1 - Playlist destruida
Pre-condicoes: j != NULL && nomePlaylist != NULL
***********************************************/

int destroiPlaylistJukebox(jukebox j, char *nomePlaylist);

/***********************************************
ApagaMusicaJukebox - Apaga uma musica da jukebox.
Parametros:	j - jukebox a a modificar.
            nomeMusica - Nome da musica a destruir
Retorno: musica destruida
Pre-condicoes: j != NULL && nomeMusica != NULL
***********************************************/

musica ApagaMusicaJukebox(jukebox j, char *nomeMusica);

/***********************************************
ObtemMusicaJukebox - Obtem a musica com o nome enviado.
Parametros:	j - jukebox a analisar
            nomeMusica - nome da musica pretendida
Retorno: NULL - Musica nao existe || apontador para a musica pretendida
Pre-condicoes: j != NULL && nomeMusica != NULL
***********************************************/

musica ObtemMusicaJukebox(jukebox j, char *nomeMusica);

/***********************************************
RetornaNumeroMusicasJukebox- Retorna o numero de musicas existentes na jukebox.
Parametros:	j - jukebox a analisar
Retorno: numero de musicas existente
Pre-condicoes: j != NULL
***********************************************/

int RetornaNumMusicasJukebox(jukebox j);

/***********************************************
RetornaIteradorMusicasJukebox - Retorna um iterador das musicas existentes na jukebox por ordem alfabetica.
Parametros:	j - jukebox a analisar
Retorno: iterador ordenado por ordem alfabetica das musicas.
Pre-condicoes: j != NULL
***********************************************/

iterador RetornaIteradorMusicasJukebox(jukebox j);


/***********************************************
RetornaNumeroMusicasJukebox- Retorna o numero de playlists existentes na jukebox.
Parametros:	j - jukebox a analisar
Retorno: numero de playlists existente
Pre-condicoes: j != NULL
***********************************************/

int RetornaNumPlaylistsJukebox(jukebox j);

/***********************************************
RetornaPlaylistJukebox - Retorna a playlist com o nome pretendido na jukebox.
Parametros:	j - jukebox a analisar
            nomePlaylist - nome da playlist pretendida.
Retorno: NULL - Playlist nao existe || apontador para a playlist pretendida
Pre-condicoes: j != NULL && nomePlaylist != NULL
***********************************************/

playlist RetornaPlaylistJukebox(jukebox j, char *nomePlaylist);


/***********************************************
RemoveMusicaPlaylistJukebox - Remove uma musica pretendida de uma playlist pretendida na jukebox.
Parametros:	j - jukebox a analisar
            nomePlaylist - nome da playlist a modificar
            pos - pos da musica a retirar
Retorno: musica removida
Pre-condicoes: j != NULL && nomePlaylist existir na jukebox && pos > 0 && pos <= tamanho da playlist
***********************************************/

musica RemoveMusicaPlaylistJukebox(jukebox j, char *nomePlaylists, int pos);

/***********************************************
MaiorNumPlaylistsJukebox - Retorna o numero de playlists em que a musica com mais playlists tem.
Parametros:	j - jukebox a analisar
Retorno: -2 - Sem Musicas || -1 - Sem Playlists || Maior numero de playlists em uma musica
Pre-condicoes: j != NULL
***********************************************/

int MaiorNumPlaylistsJukebox(jukebox j);

/***********************************************
RetornaMaxMusicasJukebox - Retorna a capacidade maxima de musicas de uma playlist.
Parametros:	j - jukebox a analisar
Retorno: capacidade de musicas maximas numa playlist
Pre-condicoes: j != NULL
***********************************************/

int RetornaMaxMusicasJukebox(jukebox j);

#endif // JUKEBOX_H_INCLUDED

