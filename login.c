#include "login.h"
#include "perfil.h"
char printLogin(struct User *usercab,struct User **usuario) {
    char op = '0';
    printf("Digite uma opção:\n");
    printf("1 para realizar o login.\n");
    printf("2 para realizar o cadastro.\n");
    printf("3 para sair.\n");
    scanf(" %c", &op);
    
    if (op == '1') {
        getchar();
        char nome[30];
        char senha[30];
        printf("Digite o username :\n");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
        if(validateString(nome)){
            system("clear");
            printf("Você digitou apenas espaços !\n");
            return '1';
        }
        printf("Digite a senha:\n");
        ocultaSenha(senha);
        *usuario = usercab ->prox;
        //verificar se o usuário existe no sistema
        while (*usuario != NULL) {
            
            if (strcmp(nome,(*usuario)->username) == 0) {
                if (strcmp(senha,(*usuario)->senha)== 0) {
                    printf("Login realizado com sucesso.\n");
                    system("clear");
                    return '0';
                }
            }
            *usuario = (*usuario)->prox;
        }
        system("clear");
        printf("Usuario não encontrado tente novamente ! \n");
        return '1';
    } else if (op == '2') {
        system("clear");
        criaUser(usercab);
        return '1';
    } else if (op == '3'){
        return '3';
    } else{
        system("clear");
        printf("Digite uma opção válida !\n");
        return '1';
    }
    system("clear");
}
