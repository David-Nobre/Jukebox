#ifndef MUSICA_H_INCLUDED
#define MUSICA_H_INCLUDED

typedef struct _musica *musica;

/***********************************************
criaMusica - Criacao da instancia da estrutura associada a uma musica.
Parametros:
     nome - nome da musica.
     autor - autor da musica.
     genero - genero da musica.
     ano - ano de lancamento da musica.
     duracao - duracao da musica em segundos.
     playlists - dicionario que contem os nomes das playlists as quais a musica pertence
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/

musica criaMusica(char *nome, char *autor, char *genero, int ano, int duracao);

/***********************************************
destroiMusica - Liberta a memoria ocupada pela instancia da estrutura associada a musica.
Parametros:	m - musica a destruir
Retorno:
Pre-condicoes: m != NULL
***********************************************/

void destroiMusica(musica m);

/***********************************************
RetornaNomeMusica - Retrona o nome da musica.
Parametros:	m - musica a analisar.
Retorno: nome da musica.
Pre-condicoes: m != NULL
***********************************************/

char* RetornaNomeMusica(musica m);

/***********************************************
RetornaAutorMusica - Retrona o autor da musica.
Parametros:	m - musica a analisar.
Retorno: autor da musica.
Pre-condicoes: m != NULL
***********************************************/

char* RetornaAutorMusica(musica m);

/***********************************************
RetornaGeneroMusica - Retrona o genero da musica.
Parametros:	m - musica a analisar.
Retorno: genero da musica.
Pre-condicoes: m != NULL
***********************************************/

char* RetornaGeneroMusica(musica m);

/***********************************************
RetornaAnoMusica - Retrona o ano da musica.
Parametros:	m - musica a analisar.
Retorno: ano da musica.
Pre-condicoes: m != NULL
***********************************************/

int RetornaAnoMusica(musica m);

/***********************************************
RetornaDuracaoMusica - Retrona a duracao da musica.
Parametros:	m - musica a analisar.
Retorno: duracao da musica.
Pre-condicoes: m != NULL
***********************************************/

int RetornaDuracaoMusica(musica m);

/***********************************************
RetornaTimesPlayedMusica - Retrona as vezes que uma musica foi tocada.
Parametros:	m - musica a analisar.
Retorno: numero de vezes que a musica foi tocada.
Pre-condicoes: m != NULL
***********************************************/

int RetornaVezesTocadaMusica(musica m);

/***********************************************
destroiMusicaGenerica - funcao que reencaminha um apontador generico para a funcao destroiMusica.
Parametros:	m - apontador generico para a musica.
Retorno:
Pre-condicoes: m != NULL
***********************************************/

void destroiMusicaGenerica(void* m);

/***********************************************
TocaMusica - Incrementa as vezes que uma musica foi tocada.
Parametros:	m - musica a analisar.
Retorno:
Pre-condicoes: m != NULL
***********************************************/

void tocaMusica(musica m);

/***********************************************
NovaPlaylistMusica - Adiciona o nome da playlist a estrutura da musica.
Parametros:	m - musica a analisar.
            nomePlaylist - nome da playlist onde a musica foi adicionada.
Retorno:
Pre-condicoes: m != NULL && nomePlaylist != NULL
***********************************************/

void adicionaPlaylistMusica(musica m, char *nomePlaylist);

/***********************************************
RemovePlaylistMusica - Remove o nome da playlist da estrutura musica.
Parametros:	m - musica a analisar.
            nomePlaylist - nome da playlist ao qual a musica deixou de pertencer
Retorno:
Pre-condicoes: m != NULL && nomePlaylist != NULL
***********************************************/

void RemovePlaylistMusica(musica m, char *nomePlaylist);

/***********************************************
RetornaNumPlaylistsMusica - Retorna o numero de playlists ao qual uma musica pertence.
Parametros:	m - musica a analisar.
Retorno: numero de playlists ao qual uma musica pertence
Pre-condicoes: m != NULL
***********************************************/

int RetornaNumPlaylistsMusica(musica m);

/***********************************************
RetornaIteradorPlaylistsMusica - Retorna todos os nomes das playlists ao qual uma musica pertence.
Parametros:	m - musica a analisar.
Retorno: iterador que contem todos os nomes das playlists ao qual a musica pertence.
Pre-condicoes: m != NULL
***********************************************/

iterador RetornaIteradorPlaylistsMusica(musica m);

#endif // MUSICA_H_INCLUDED
