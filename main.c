#include "shared.h"
#include "login.h"
#include "perfil.h"
#include "mural.h"
#include "grupo.h"
int main(){
    system("clear");
    //inicialização das structs de dados
    struct User *usuario;
    struct User *usercab;
    struct Group *groupcab;
    char resp = '1';
    usercab = malloc(sizeof(struct User));
    usuario = malloc(sizeof(struct User));
    groupcab = malloc(sizeof(struct Group));
    groupcab = NULL;
    usercab ->prox = NULL;
    strcpy(usercab -> nome, "NULL");
    while(1){
        //chamada para printar na tela as opções
        while(resp != '0'){
        resp = printLogin(usercab,&usuario);
            // nesse caso o programa termina
            if(resp == '3'){
                return 0;
        }
        }
        resp = printaPerfil(&usercab,&usuario,&groupcab);
    }
    return 0;
}

