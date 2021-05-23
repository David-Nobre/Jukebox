#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "iterador.h"
#include "musica.h"
#include "playlist.h"
#include "jukebox.h"
#define MAX 100

#define QUIT 0
#define UPLOAD 1
#define DELETE 2
#define VIEW 3
#define MUSIC 4
#define CREATE 5
#define PLAY 6
#define PLAYLIST 7
#define MODIFY 8
#define DESTROY 9
#define DADOS_INVALIDOS -1
#define CMD_INEXISTENTE -2

void interpertador(jukebox j);
void UploadMusica(jukebox j);
void DeleteMusica(jukebox j, char linha[MAX]);
void ViewMusica(jukebox j, char linha[MAX]);
void MusicMusica(jukebox j, char linha[MAX]);
void CreatePlaylist(jukebox j, char linha[MAX]);
void PlayPlaylist(jukebox j, char linha[MAX]);
void PlaylistPlaylist(jukebox j, char linha[MAX]);
void ModifyPlaylist(jukebox j, char linha[MAX]);
void DestroyPlaylist(jukebox j, char linha[MAX]);

int main(){
    char Dados_iniciais[MAX];
    int MaxNumMusicasPlaylist, MaxTempoMusicasPlaylist;

    fgets(Dados_iniciais, MAX, stdin);
    if (sscanf(Dados_iniciais, "%d %d", &MaxNumMusicasPlaylist, &MaxTempoMusicasPlaylist) != 2)
        return 1;
    jukebox j = criaJukebox(MaxNumMusicasPlaylist, MaxTempoMusicasPlaylist);
    if (j == NULL)
        return 1;
    printf("Jukebox aberta.\n");
    interpertador(j);
    destroiJukeboxEMusicasEPlaylists(j);
    printf("Jukebox encerrada.\n");
    return 0;
}

int obtemComando(char *linha){
    char cmd[10], parametro[MAX];
    char *comandos1[2] = {"QUIT", "UPLOAD"};
    char *comandos2[8] = {"DELETE", "VIEW", "MUSIC", "CREATE", "PLAY", "PLAYLIST", "MODIFY", "DESTROY"};
    int i, j;

    if(sscanf(linha, "%s %s", cmd, parametro) == 1){
        for(int k = 0; k < strlen(cmd); k++)
            cmd[k] = toupper(cmd[k]);
        for(i = 0; i < 2; i++)
            if(!strcmp(cmd, comandos1[i]))
                return i;
        for(j = 0; j < 8; j++)
            if(!strcmp(cmd, comandos2[j]))
            return -1;
    }
    else{
        for(int k = 0; k < strlen(cmd); k++)
            cmd[k] = toupper(cmd[k]);
        for(j = 0; j < 8; j++)
            if(!strcmp(cmd, comandos2[j]))
                return 2+j;
    }
    return -2;
}

char* obtemParametro(char linha[MAX], char comando[MAX]){
    char *parametro;
    int i = 0, j = 0, ctr = 1;


    while(ctr){
        while(toupper(linha[i]) == comando[j]){
            if(j == strlen(comando)-1)
                ctr = 0;
            i++;
            j++;
        }
        j = 0;
        i++;
    }
    parametro = (char*)malloc (sizeof(char)*(strlen(linha)-i+2));
        for(; i<strlen(linha)+1; i++){
        parametro[j] = linha[i];
        j++;
    }
    return parametro;
}

void interpertador(jukebox j){
    char linha[MAX];
    int chave;

    printf("> ");
    fgets(linha, MAX, stdin);
    linha[strlen(linha)-1] = '\0';
    chave = obtemComando(linha);

    while(chave != QUIT){
        switch(chave){
            case UPLOAD: UploadMusica(j); break;
            case DELETE: DeleteMusica(j, linha); break;
            case VIEW: ViewMusica(j, linha); break;
            case MUSIC: MusicMusica(j, linha); break;
            case CREATE: CreatePlaylist(j, linha); break;
            case PLAY: PlayPlaylist(j, linha); break;
            case PLAYLIST: PlaylistPlaylist(j, linha); break;
            case MODIFY: ModifyPlaylist(j, linha); break;
            case DESTROY: DestroyPlaylist(j, linha); break;
            case CMD_INEXISTENTE: printf("Comando inexistente.\n"); break;
            case DADOS_INVALIDOS: printf("Dados invalidos.\n"); break;
        }
        printf("> ");
        fgets(linha, MAX, stdin);
        linha[strlen(linha)-1] = '\0';
        chave = obtemComando(linha);
    }
}

void UploadMusica(jukebox j){ /** adicionar uma musica a jukebox**/
    char nome[MAX], autor[MAX], genero[MAX];
    int ano, duracao;

    fgets(nome, MAX, stdin);
    nome[strlen(nome)-1] = '\0';
    fgets(autor, MAX, stdin);
    autor[strlen(autor)-1] = '\0';
    fgets(genero, MAX, stdin);
    genero[strlen(genero)-1] = '\0';
    scanf ("%d", &ano);
    getchar();
    scanf ("%d", &duracao);
    getchar();

    if(NovaMusicaJukebox(j, nome, autor, genero, ano, duracao) == 1) /** return 1 caso tenha sido adicionada. return 0 caso ja seja existente**/
        printf("Musica %s adicionada.\n", nome);
    else
         printf("Musica ja existente.\n");
}

void DeleteMusica(jukebox j, char linha[MAX]){ /** Apagar uma musica da jukebox**/
    char nomeMusica[MAX];
    musica m;

    strcpy(nomeMusica, obtemParametro(linha, "DELETE")); /** Obter o nome da musica**/
    m = ApagaMusicaJukebox(j, nomeMusica); /** return NULL caso inexistente. Return musica caso existente**/
    if(m == NULL)
        printf("Musica inexistente.\n");
    else
        printf("Musica %s removida.\n", nomeMusica);
}

void ViewMusica(jukebox j, char linha[MAX]){ /** Vizualizar os detalhes de uma musica na jukebox**/
    char nomeMusica[MAX];
    musica m;

    strcpy(nomeMusica, obtemParametro(linha, "VIEW")); /** Obter o nome da musica**/
    m = ObtemMusicaJukebox(j, nomeMusica);
    if(m == NULL)
        printf("Musica inexistente.\n");
    else{
        printf("%s\n%s\n%d\n%d\n", RetornaAutorMusica(m), RetornaGeneroMusica(m), RetornaAnoMusica(m), RetornaDuracaoMusica(m));
        printf("Tocada %d vezes.\n", RetornaVezesTocadaMusica(m));
    }
}

void MusicMusica(jukebox j, char linha[MAX]){ /** comandos variados dependendo do input**/
    char comando[10], cmd;
    iterador it;
    musica m;
    int counter = 0;

    if(sscanf(linha, "%s %c", comando, &cmd) == 2){
        cmd = tolower(cmd);
        if (cmd == 'a'){ /** Music a (print dos nomes de todas as musicas)**/
            if (RetornaNumMusicasJukebox(j) != 0){
                it = RetornaIteradorMusicasJukebox(j);
                while(temSeguinteIterador(it)){
                    m = (musica)seguinteIterador(it);
                    printf("%s\n", RetornaNomeMusica(m));
                }
                destroiIterador(it);
            }
            printf("Total de musicas %d.\n", RetornaNumMusicasJukebox(j));
        }
        else if (cmd == 'i'){ /** Music i (print dos nomes de todas as musicas de um autor)**/
            char autor[MAX];
            fgets(autor, MAX, stdin);
            autor[strlen(autor)-1] = '\0';
            if(RetornaNumMusicasJukebox(j) == 0)
                printf("Sem musicas.\n");
            else{
                it = RetornaIteradorMusicasJukebox(j);
                while(temSeguinteIterador(it)){
                    m = (musica)seguinteIterador(it);
                    if(!strcmp(autor, RetornaAutorMusica(m))){
                        printf("%s\n", RetornaNomeMusica(m));
                        counter++;
                    }
                }
                if(counter == 0)
                    printf("Autor desconhecido.\n");
                destroiIterador(it);
            }
        }
        else if (cmd == 'g'){ /** Music g (print dos nomes de todas as musicas de um genero)**/
            char genero[MAX];
            fgets(genero, MAX, stdin);
            genero[strlen(genero)-1] = '\0';
            if(RetornaNumMusicasJukebox(j) == 0)
                printf("Sem musicas.\n");
            else{
                it = RetornaIteradorMusicasJukebox(j);
                while(temSeguinteIterador(it)){
                    m = (musica)seguinteIterador(it);
                    if(!strcmp(genero, RetornaGeneroMusica(m))){
                        printf("%s\n", RetornaNomeMusica(m));
                        counter++;
                    }
                }
                if(counter == 0)
                    printf("Genero desconhecido.\n");
                destroiIterador(it);
            }
        }
        else if (cmd == 'p'){ /** Music p (print dos nomes de todas as musicas com o maior numero de playlists)**/
            if(RetornaNumMusicasJukebox(j) == 0)
                printf("Sem musicas.\n");
            else if(RetornaNumPlaylistsJukebox(j) == 0)
                printf("Sem playlists.\n");
            else{
                int MaiorNumPlaylists = MaiorNumPlaylistsJukebox(j);
                it = RetornaIteradorMusicasJukebox(j);
                while(temSeguinteIterador(it)){
                    m = (musica)seguinteIterador(it);
                    if(RetornaNumPlaylistsMusica(m) == MaiorNumPlaylists)
                        printf("%s\n", RetornaNomeMusica(m));
                }
                printf("Em %d playlists.\n", MaiorNumPlaylists);
                destroiIterador(it);
            }
        }
        else if (cmd == 't'){ /** Music t (print dos nomes das musicas no top3 mais tocadas)**/
            if(RetornaNumMusicasJukebox(j) == 0)
                printf("Sem musicas.\n");
            else if(RetornaNumPlaylistsJukebox(j) == 0)
                printf("Sem playlists.\n");
            else{
                int ctr, maisTocada1 = 0, maisTocada2 = 0, maisTocada3 = 0;
                it = RetornaIteradorMusicasJukebox(j);

                while(temSeguinteIterador(it)){
                    m = (musica)seguinteIterador(it);
                    if(RetornaVezesTocadaMusica(m) > maisTocada1){
                        maisTocada3 = maisTocada2;
                        maisTocada2 = maisTocada1;
                        maisTocada1 = RetornaVezesTocadaMusica(m);
                    }
                    else if((RetornaVezesTocadaMusica(m) > maisTocada2)&&(RetornaVezesTocadaMusica(m) < maisTocada1)){
                        maisTocada3 = maisTocada2;
                        maisTocada2 = RetornaVezesTocadaMusica(m);
                    }
                    else if((RetornaVezesTocadaMusica(m) > maisTocada3)&&(RetornaVezesTocadaMusica(m) < maisTocada2))
                        maisTocada3 = RetornaVezesTocadaMusica(m);
                }
                destroiIterador(it);

                if(maisTocada1 == 0)
                    printf("Nenhuma musica foi tocada.\n");
                else{
                    for ( int i = 0; i < 3; i++){
                        switch(i){
                            case 0: ctr = maisTocada1;break;
                            case 1: ctr = maisTocada2;break;
                            case 2: ctr = maisTocada3;break;
                            default: printf("DEFAULT\n");
                        }
                        if(ctr != 0){
                            iterador it1 = RetornaIteradorMusicasJukebox(j);
                            while(temSeguinteIterador(it1)){
                                m = (musica)seguinteIterador(it1);
                                if (RetornaVezesTocadaMusica(m) == ctr)
                                    printf("%s tocada %d vezes.\n", RetornaNomeMusica(m), ctr);
                            }
                            destroiIterador(it1);
                        }
                    }
                }
            }
        }
        else
            printf("Dados invalidos.\n");
    }
}

void CreatePlaylist(jukebox j, char linha[MAX]){ /** Cria uma Playlist**/
    char nomePlaylist[MAX], nomeMusica[MAX], comando[10];
    int i, tamanhoPlaylist, criada;

    if(sscanf(linha, "%s %d", comando, &tamanhoPlaylist) !=2)
        printf("Dados invalidos.\n");
    else if (tamanhoPlaylist == 0)
        printf("Dados invalidos.\n");
    else{
        fgets(nomePlaylist, MAX, stdin);
        nomePlaylist[strlen(nomePlaylist)-1] = '\0';
        if(criaPlaylistJukebox(j, nomePlaylist) == 0)
            printf("Playlist ja existente.\n");
        else if(tamanhoPlaylist > RetornaMaxMusicasJukebox(j)){
            printf("Playlist excedeu dimensao.\n");
            printf("Playlist nao criada.\n");
        }
        else{
            for(i = 0; i < tamanhoPlaylist; i++){
                fgets(nomeMusica, MAX, stdin);
                nomeMusica[strlen(nomeMusica)-1] = '\0';
                int ctr = NovaMusicaPlaylistJukebox(j, nomeMusica, nomePlaylist, i+1);
                if(ctr == 0){
                    printf("Musica %s inexistente.\n", nomeMusica);
                    destroiPlaylistJukebox(j, nomePlaylist);
                    criada = 0;
                    break;
                }
                else if(ctr == 1){
                    printf("Playlist excedeu tempo.\n");
                    destroiPlaylistJukebox(j, nomePlaylist);
                    criada = 0;
                    break;
                }
                else
                    criada = 1;
            }
            if(criada == 1)
                printf("Playlist %s criada.\n", nomePlaylist);
            else
                printf("Playlist nao criada.\n");
        }
    }
}

void PlayPlaylist(jukebox j, char linha[MAX]){ /** Toca uma Playlist **/
    char nomePlaylist[MAX];
    playlist p;

    strcpy(nomePlaylist, obtemParametro(linha, "PLAY"));
    p = RetornaPlaylistJukebox(j, nomePlaylist);
    if (p == NULL)
        printf("Playlist inexistente.\n");
    else if (RetornaNumMusicasPlaylist(p) == 0)
        printf("Playlist vazia.\n");
    else{
        printf("Playlist %s tem %d musicas e %d segundos.\n", RetornaNomePlaylist(p), RetornaNumMusicasPlaylist(p), RetornaTempoPlaylist(p));
        tocaPlaylist(p);
    }
}

void PlaylistPlaylist(jukebox j, char linha[MAX]){ /** lista os nomes e as duracoes das musicas numa playlist**/
    char nomePlaylist[MAX];
    playlist p;

    strcpy(nomePlaylist, obtemParametro(linha, "PLAYLIST"));
    p = RetornaPlaylistJukebox(j, nomePlaylist);
    if(p == NULL)
        printf("Playlist inexistente.\n");
    else if(RetornaNumMusicasPlaylist(p) == 0)
        printf("Playlist vazia.\n");
    else{
        for (int i = 0; i < RetornaNumMusicasPlaylist(p); i++){
            musica m = RetornaMusicaPlaylist(p, i);
            printf("%s %d\n", RetornaNomeMusica(m), RetornaDuracaoMusica(m));
        }
        printf("Tempo total %d, tocada %d vezes.\n", RetornaTempoPlaylist(p), RetornaVezesTocadaPlaylist(p));
    }
}

void ModifyPlaylist(jukebox j, char linha[MAX]){ /** comandos variados dependendo do input **/
    char comando[MAX], nomePlaylist[MAX], nomeMusica[MAX], op;
    int pos;
    playlist p;
    musica m;

    if (sscanf(linha, "%s %c %d", comando, &op, &pos) != 3)
        printf("Dados invalidos.\n");
    else if(pos == 0)
        printf("Dados invalidos.\n");
    else{
        op = tolower(op);
        fgets(nomePlaylist, MAX, stdin);
        nomePlaylist[strlen(nomePlaylist)-1] = '\0';
        p = RetornaPlaylistJukebox(j, nomePlaylist);
        if (p == NULL)
            printf("Playlist inexistente.\n");
        else if(op == 'r'){  /** remove uma musica da playlist**/
            if(RetornaNumMusicasPlaylist(p) >= pos){
                m = RemoveMusicaPlaylistJukebox(j, nomePlaylist, pos);
                printf("%s removida.\n", RetornaNomeMusica(m));
            }
            else
                printf("Posicao invalida.\n");
        }
        else if(op == 'i'){ /** acrescenta uma musica a uma playlist**/
            if ((RetornaNumMusicasPlaylist(p) + 1 >= pos)){
                fgets(nomeMusica, MAX, stdin);
                nomeMusica[strlen(nomeMusica) - 1] = '\0';
                int ctr = NovaMusicaPlaylistJukebox(j, nomeMusica, nomePlaylist, pos);
                if (ctr == 1)
                    printf("Playlist excedeu tempo.\n");
                else if (ctr == 2)
                    printf("Playlist excedeu dimensao.\n");
                else if (ctr == 3)
                    printf("Musica adicionada.\n");
            }
            else
                printf("Posicao invalida.\n");
        }
        else
            printf("Dados invalidos.\n");
    }
}

void DestroyPlaylist(jukebox j, char linha[MAX]){ /** destroi uma Playlist**/
    char nomePlaylist[MAX];

    strcpy(nomePlaylist, obtemParametro(linha, "DESTROY"));
    if(destroiPlaylistJukebox(j, nomePlaylist) == 0)
        printf("Playlist inexistente.\n");
    else
        printf("Playlist eliminada.\n");
}
