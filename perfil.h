#ifndef PERFIL_H
#define PERFIL_H
#include "shared.h"
#include "mural.h"
#include "amigos.h"
#include "mensagem.h"
#include "grupo.h"
/**
* brief A função printaPerfil serve para printar o perfil do usuário.
*
* param 1 usercab do tipo struct User.
*
* param 2 usuario do tipo struct User
*
* param 3 groupcab do tipo struct Group
*
* return do tipo struct User *. O ponteito para o usuário ou NULL se não for encontrado o usuário .
*
*/
char printaPerfil(struct User **usercab,struct User **usuario,struct Group **groupcab);
/**
* brief A função alteraDados Altera os dados do usuário.
*
* param 1 usuario do tipo struct User.
*
* param 2 usercab do tipo struct User
*
* return do tipo void. Pois ela altera os dados do usuário .
*
*/
void alteraDados(struct User **usuario , struct User *usercab);
#endif