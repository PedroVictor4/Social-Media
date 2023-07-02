#ifndef GRUPO_H
#define GRUPO_H
#include "shared.h"
#include "mural.h"
struct Group {
    struct User *lider;
    struct Group *prox;
    struct User *participantes;
    struct Post *primeiroPost;
    char nome[30];
    char descricao[1000];
};

/**
* brief A função criaGrupo adiciona um novo grupo na lista de grupos.
*
* param 1 groupcab do tipo struct Group.
*
* param 2 lider do tipo struct User.
*
* return void. Pois ela adiciona na lista encadeada.
*
*/
void criaGrupo(struct Group **groupcab,struct User **lider);
/**
* brief A função adicionaGrupo adiciona um novo grupo na lista de grupos do usuario , e um novo usario na lista de participantes.
*
* param 1 usuario do tipo struct User.
*
* param 2 groupcab do tipo struct Group.
*
* return void. Pois ela adiciona na lista encadeada.
*
*/
void adicionaGrupo(struct User **usuario,struct Group **groupcab);
/**
* brief A função verificaGrupo verifica se aquele grupo já não existe no sistema.
*
* param 1 groupcab do tipo struct Group.
*
* param 2 nomeGrupo do time string.
*
* return struct Group *. Ou um ponteiro para o grupo caso ele exista ou NULL caso não exista.
*
*/
struct Group *verificaGrupo(struct Group **groupcab,char nomeGrupo[30]);
/**
* brief A função listaGrupo lista os grupos existentes.
*
* param 1 groupcab do tipo struct Group.
*
* return void. Pois ela printa a lista encadeada de grupos.
*
*/
void listaGrupo(struct Group *groupcab);
/**
* brief A função listaParticipantes lista os participantes de um grupo.
*
* param 1 grupo do tipo struct Group.
*
* return void. Pois ela printa a lista encadeada de participantes.
*
*/
void listaParticipantes(struct Group *grupo);
/**
* brief A função verificaParticipante verifica se um participante pertence a aquele grupo.
*
* param 1 usuario do tipo struct User .
*
* param 2 grupo do tipo struct Group.
*
* return int 1 para pertence 0 para não pertence.
*
*/
int verificaParticipante(struct User **usuario,struct Group **grupo);
/**
* brief A função adicionarPost adiciona um novo post no mural do grupo.
*
* param 1 usuario do tipo struct User .
*
* param 2 grupo do tipo struct Group.
*
* return void pois ela adiciona o novo post no mural.
*
*/
void adicionarPost(struct User **usuario, struct Group **grupo);
/**
* brief A função printMuralGrupo printa o mural daquele grupo.
*
* param 1 grupo do tipo struct Group.
*
* return void pois ela adiciona um novo post no Mural.
*
*/
void printMuralGrupo(struct Group **grupo);
/**
* brief A função listaGrupos lista os grupos que o usuário pertence.
*
* param 1 usuario do tipo struct User.
*
* return void pois ela apenas printa os grupos.
*
*/
void listaGrupos(struct User **usuario);
#endif