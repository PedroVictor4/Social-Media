#ifndef AMIGOS_H
#define AMIGOS_H
#include "shared.h"
struct Friend {
    char nome[50];
    struct User *user;
    struct Friend *prox;
};
/**
* brief A função listaAmigos lista os amigos de um usuário.
*
* param usuario do tipo struct User.
*
* return É void pois só printa o perfil de um usuário.
*
*/
void listaAmigos(struct User **usuario);
/**
* brief A função adiconaAmigos serve para adicionar amigos ao usuário.
*
* param usuario do tipo struct User.
*
* param 2 friendUser do tipo struct User.
*
* return É void pois ele modifica a lista encadeada primeiroAmigo.
*
*/
void adicionarAmigo(struct User **usuario, struct User **friendUser);
/**
* brief A função *encontraAmigo serve para encontrar um amigo na lista de amigos.
*
* param 1 usuario do tipo struct User.
*
* param 2 nomeAmigo do tipo string.
*
* return do tipo int . 1Um ponteiro para o amigo , NULL para se não forem amigos.
*
*/
struct User *encontraAmigo(struct User **usuario, char nomeAmigo[]);
/**
* brief A função validaAmigo serve para identificar se dois usuários são amigos.
*
* param 1 usuario do tipo struct User.
*
* param 2 friendUser do tipo struct User.
*
* return do tipo int . 1 Para se forem amigos , 0 para se não forem amigos.
*
*/
int validaAmigo(struct User **usuario, struct User **friendUser);
#endif
