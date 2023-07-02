#ifndef MURAL_H
#define MURAL_H
#include "shared.h"
#include "perfil.h"
struct Post{
    char conteudo[1000];
    char nome[30];
    struct Post* prox;    
};
/**
* brief A função criaPost serve para postar uma mensagem no Mural.
*
* param 1 usuario do tipo struct User.
*
* param 2 content do tipo char que é o conteúdo do post.
*
* return do tipo void . Pois ela apenas adiciona conteúdo nos posts do usuário.
*
*/
void criaPost(struct User **usuario, char content[]);
/**
* brief A função printMural serve para printar o mural do usuário.
*
* param 1 usuario do tipo struct User.
*
* return do tipo void . Pois ela apenas printa o mural.
*
*/
void printMural(struct User **usuario);
/**
* brief A função printMuralUsuario serve para printar o mural de outro usuário.
*
* param 1 usuario do tipo struct User.
*
* param 2 nomeAmigo do tipo string
*
* return do tipo void . Pois ela apenas printa o mural de outro usuário . Com a principal ultilidade de verificar se eles são amigos.
*
*/
void printMuralUsuario(struct User **usuario, char nomeAmigo[]);
#endif