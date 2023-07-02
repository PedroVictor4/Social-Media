#include "amigos.h"

void listaAmigos(struct User **usuario){
    system("clear");
    printf("Amigos de %s:\n", (*usuario)->username);
    printf("------------------------------\n");
    struct Friend *amigoc = (*usuario) ->primeiroAmigo;
    while (amigoc != NULL) {
        printf("%s\n", amigoc ->user->username);
        amigoc = amigoc -> prox;
    }
    printf("------------------------------\n"); 
};

void adicionarAmigo(struct User **usuario, struct User **amigoUsuario) {
    if (validaAmigo(usuario, amigoUsuario)) {
        printf("%s já é seu amigo.\n", (*amigoUsuario)->username);
        return;
    }
    if((*usuario) ->username == (*amigoUsuario) ->username ){
        printf("Você não pode se adicionar\n");
        return;
    }

    struct Friend *novoAmigo = (struct Friend*)malloc(sizeof(struct Friend));
    struct Friend *novoAmigo1 = (struct Friend*)malloc(sizeof(struct Friend));
    novoAmigo->user = *amigoUsuario;
    // Copia o nome do amigo para a estrutura Friend
    strcpy(novoAmigo->nome, (*amigoUsuario)->username);  
    novoAmigo->prox = NULL;
    novoAmigo1->user = *usuario;
    // Copia o nome do usuário para a estrutura Friend
    strcpy(novoAmigo1->nome, (*usuario)->username); 
    novoAmigo1->prox = NULL;
    //Para adicionar em ordem alfabética
    if ((*usuario)->primeiroAmigo == NULL) {
        (*usuario)->primeiroAmigo = novoAmigo;
    } else {
        struct Friend *current = (*usuario)->primeiroAmigo;
        struct Friend *prev = NULL;
        
        while (current != NULL && strcmp(current->nome, novoAmigo->nome) < 0) {
            prev = current;
            current = current->prox;
        }
        
        if (prev == NULL) {
            novoAmigo->prox = (*usuario)->primeiroAmigo;
            (*usuario)->primeiroAmigo = novoAmigo;
        } else {
            prev->prox = novoAmigo;

            novoAmigo->prox = current;
        }
    }

    if ((*amigoUsuario)->primeiroAmigo == NULL) {
        (*amigoUsuario)->primeiroAmigo = novoAmigo1;
    } else {
        struct Friend *current = (*amigoUsuario)->primeiroAmigo;
        struct Friend *prev = NULL;
        
        while (current != NULL && strcmp(current->nome, novoAmigo1->nome) < 0) {
            prev = current;
            current = current->prox;
        }
        
        if (prev == NULL) {
            novoAmigo1->prox = (*amigoUsuario)->primeiroAmigo;
            (*amigoUsuario)->primeiroAmigo = novoAmigo1;
        } else {
            prev->prox = novoAmigo1;
            novoAmigo1->prox = current;
        }
    }

    printf("Amigo adicionado com sucesso!\n");
}




//Como eu crie essa função , mesmo não ultilizando decidi deixar ela comentada pois pode ser utíl
struct User *encontraAmigo(struct User **usuario, char nomeAmigo[]){
    struct Friend *aux;
    aux = (*usuario) ->primeiroAmigo;
    while (aux != NULL) {
        if (strcmp(nomeAmigo,aux->user->username) == 0) {
            return aux ->user;
            }
        aux = aux->prox;
    }
    return NULL;    
}


int validaAmigo(struct User **usuario, struct User**friendUser){
    struct Friend *aux;
    aux = (*usuario) ->primeiroAmigo;
    while (aux != NULL) {
        if (strcmp((*friendUser)->username ,aux->user->username) == 0) {
            return 1;
            }
        aux = aux->prox;
    }
    return 0;
}

