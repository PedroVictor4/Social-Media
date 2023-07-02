#ifndef MENSAGEM_H
#define MENSAGEM_H
#include "shared.h"
struct Message {
    char mensagem[1000];
    char remetente[30];
    struct Message* prox;
};
/**
* brief A função enviarMensagem serve para enviar uma mensagem para outro usuário.
*
* param 1 remetente do tipo struct User.
*
* param 2 amigo do tipo struct User.
*
* param 3 mensagem do tipo string .A mensagem que será enviada
*
* return do tipo void . Pois só adiciona uma mensagem na lista de mensagens.
*
*/
void enviarMensagem(struct User **remetente, struct User **amigo, char *mensagem);
/**
* brief A função exibirCaixaEntrada exibe a caixa de entrada do usuário e apaga as mensagens.
*
* param 1 usuario do tipo struct User.
*
* return do tipo void . Pois apenas printa as mensagens.
*
*/
void exibirCaixaEntrada(struct User **usuario);
#endif