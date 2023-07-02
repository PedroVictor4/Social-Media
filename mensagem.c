#include "mensagem.h"
void enviarMensagem(struct User** remetente, struct User **amigo, char* mensagem) {
    struct Message* novaMensagem = (struct Message*)malloc(sizeof(struct Message));
    strcpy(novaMensagem->remetente, (*remetente)->username);
    strcpy(novaMensagem->mensagem, mensagem);
    novaMensagem->prox = NULL;

    if ((*amigo)->caixaEntrada == NULL) {
        (*amigo)->caixaEntrada = novaMensagem;
    } else {
        struct Message* current = (*amigo)->caixaEntrada;
        while (current->prox != NULL) {
            current = current->prox;
        }
        current->prox = novaMensagem;
    }
};


void exibirCaixaEntrada(struct User** usuario) {
    if ((*usuario)->caixaEntrada == NULL) {
        printf("Caixa de entrada vazia.\n");
        return;
    }

    struct Message* current = (*usuario)->caixaEntrada;
    while (current != NULL) {
        printf("Amigo: %s\n", current->remetente);
        printf("Mensagem: %s\n", current->mensagem);
        struct Message* temp = current;
        current = current->prox;
        // Libera a memória da mensagem visualizada
        free(temp);
    }
    (*usuario)->caixaEntrada = NULL;  
}
