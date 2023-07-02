#include "mural.h"
void criaPost(struct User **usuario, char conteudo[]) {
    struct Post *novoPost = (struct Post*)malloc(sizeof( struct Post));
    strcpy(novoPost->conteudo, conteudo);
    novoPost ->prox = NULL;
    if(!validateString(conteudo)){
        if ((*usuario)->primeiropost == NULL) {
            (*usuario)->primeiropost = novoPost;
        } else {
            struct Post *Postc = (*usuario)->primeiropost;
            while (Postc ->prox != NULL) {
                Postc = Postc-> prox;
            }
            Postc-> prox = novoPost;
        }
        system("clear");
        printf("Post realizado com sucesso !\n");
        return;
    }
    printf("Você digitou apenas espaços !\n");
    system("clear");
}
void printMural(struct User **usuario){
    system("clear");
    printf("Mural de %s:\n", (*usuario)->username);
    printf("------------------------------\n");
    struct Post *Postc = (*usuario) ->primeiropost;
    while (Postc != NULL) {
        printf("%s\n", Postc -> conteudo);
        Postc = Postc -> prox;
    }
    printf("------------------------------\n");
};
// Decidi deixar essa função , pois mesmo não precisando identificar se os usuarios são amigos na hora de dar o print mural , essa função ainda pode ser utíl
void printMuralUsuario(struct User **usuario, char nomeAmigo[]){
    struct User *amigo = encontraUsuario(usuario, nomeAmigo);
    if (amigo != NULL) {
        printMural(&amigo);
    } else {
        printf("Amigo não encontrado!\n");
    }
}
