#ifndef SHARED_H
#define SHARED_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

struct User{
    char ocupacao[1000];
    char endereco[1000];
    char bio[1000];
    char nome[30];
    char username[30];
    char senha[30];
    struct User *prox;
    struct Post *primeiropost;
    struct Friend *primeiroAmigo;
    struct Message *caixaEntrada;
    struct Group *primeiroGrupo;
};
/**
* \brief A função criaUser serve para criar um novo usuário .
*
* param 1 usercab do tipo struct User.
*
* return do tipo void . Pois ela apenas adiciona o usuário a lista.
*
*/
void criaUser(struct User *usercab);
/**
* brief A função ocultaSenha serve para ocultar a senha digitada.
*
* param 1 usuario do tipo string.
*
* return do tipo Void .
*
*/
void ocultaSenha(char *senha);
/**
* brief A função validaString verifica se a string não é nula.
*
* param 1 usuario do tipo string.
*
* return do tipo int . 1 Para se for so espaços , 0 para se não for só espaços.
*
*/
int validateString(const char* input);
/**
* brief A função validaUserName verifica se o username já não faz parte do sistema e se ele é válido.
*
* param 1 usercab do tipo struct User.
*
* param 2 nome do tipo string
*
* return do tipo int . 1 Para se for possível esse username , 0 para se não for possível esse username.
*
*/
int validaUserName(struct User *usercab,char nome[30]);
/**
* brief A função printUsuário serve para printar o perfil de outro usuário.
*
* param 1 usuario do tipo struct User.
*
* return do tipo void . Pois ela apenas printa o perfil de outro usuário.
*
*/
void printUsuario(struct User *usuario);
/**
* brief A função encontraUsuario serve para encontrar um usuário.
*
* param 1 usercab do tipo struct User.
*
* param 2 nome do tipo string
*
* return do tipo struct User *. O ponteito para o usuário ou NULL se não for encontrado o usuário .
*
*/
struct User *encontraUsuario(struct User **usercab,char nome[30]);
#endif
