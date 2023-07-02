#ifndef LOGIN_H
#define LOGIN_H
#include "shared.h"
/**
* brief A função printLogin serve para printar a aba login do sistema.
*
* param 1 usuario do tipo struct User é o inicio da lista encadeada de usuários do sistema.
*
* param 2 usuario do tipo struct User.
*
* return char . 1 para voltar para login , 0 para dar login , 3 para sair do programa.
*
*/
char printLogin(struct User *usercab,struct User **usuario);
#endif