#include "shared.h"

void criaUser(struct User *usercab) {
    struct User *aux;
    struct User *aux1;
    char nome[30];
    aux = usercab;
    aux1 = malloc(sizeof(struct User));
    printf("Digite o nome completo :  ");
    getchar();
    fgets(nome,sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    strcpy(aux1->nome,nome);
    printf("Digite um username : ");
    fgets(nome,sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    if(validateString(nome)){
        system("clear");
        printf("Você digitou apenas espaços !\n");
        free(aux1);
        return;
    }
    if(validaUserName(usercab,nome)){
        system("clear");
        printf("Já existe uma conta com esse nome !\n");
        free(aux1);
        return;
    }

    strcpy(aux1->username,nome);
    printf("Digite a ocupação :  ");
    fgets(aux1 ->ocupacao,sizeof(aux1->ocupacao), stdin);
    aux1->ocupacao[strcspn(aux1->ocupacao, "\n")] = '\0';
 
    printf("Digite o endereço :  ");
    fgets(aux1 ->endereco,sizeof(aux1->endereco), stdin);
    aux1->endereco[strcspn(aux1->endereco, "\n")] = '\0';

    printf("Digite sua bio :  ");
    fgets(aux1 ->bio,sizeof(aux1->bio), stdin);
    aux1->bio[strcspn(aux1->bio, "\n")] = '\0';

    printf("Digite a senha :  ");
    ocultaSenha(aux1 ->senha);
    if(validateString(aux1 ->senha)){
        system("clear");
        printf("Você digitou apenas espaços !\n");
        free(aux1);
        return;
    }
    aux1 ->primeiropost = NULL;
    aux1 ->primeiroAmigo = NULL;
    aux1 ->primeiroGrupo = NULL;
    //aux1 ->primeiroamigo = NULL;
    aux1 -> prox = aux ->prox;
    aux -> prox = aux1;
    system("clear");
}

void ocultaSenha(char *senha) {
    int i = 0;
    char ch;
    struct termios old, new;
    tcgetattr(fileno(stdin), &old);
    new = old;
    new.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), TCSAFLUSH, &new);

    fgets(senha, 31, stdin);
    size_t len = strlen(senha);
    if (len > 0 && senha[len - 1] == '\n') {
        senha[len - 1] = '\0';
    }

    tcsetattr(fileno(stdin), TCSAFLUSH, &old);
}


int validateString(const char* input) {
    int i;
    // Para verificar se a string contém apenas espaços em branco
    for (i = 0; input[i] != '\0'; i++) {
        if (!isspace(input[i])) {
            return 0;  
        }
    }
    return 1;  
}
int validaUserName(struct User *usercab,char nome[30]){
    struct User *aux;
    aux = usercab;
    while (aux != NULL) {
    if (strcmp(nome,aux->username) == 0) {
        return 1;
        }
    aux = aux->prox;
    }
    return 0;
}
struct User *encontraUsuario(struct User **usercab,char nome[30]){
    struct User *aux;
    aux = (*usercab);
    while (aux != NULL) {
        if (strcmp(nome,aux->username) == 0) {
            return aux;
            }
        aux = aux->prox;
    }
    return NULL;    
}
void printUsuario(struct User *usuario){
    system("clear");
    if(usuario != NULL){
        printf("-----------Bem vindo ao seu perfil de %s !----------\n",usuario ->username);
        printf("Nome : %s\n",usuario ->nome);
        printf("Username : %s\n",usuario ->username);
        printf("Ocupação : %s\n",usuario ->ocupacao);
        printf("Endereço : %s\n",usuario ->endereco);
        printf("Bio : %s\n",usuario ->bio);
        return;
    }
    printf("Usuário não encontrado ! \n");
}   

