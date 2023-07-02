#include "grupo.h"
void criaGrupo(struct Group **groupcab, struct User **lider) {
    struct Group *novoGrupo = malloc(sizeof(struct Group));
    struct Group *anterior = NULL;
    struct Group *atual = *groupcab;

    novoGrupo->lider = NULL;
    printf("Digite o nome do grupo: ");
    getchar();
    fgets(novoGrupo->nome, sizeof(novoGrupo->nome), stdin);
    novoGrupo->nome[strcspn(novoGrupo->nome, "\n")] = '\0';

    if (verificaGrupo(groupcab, novoGrupo->nome) != NULL) {
        system("clear");
        printf("O grupo já existe!\n");
        free(novoGrupo);
        return;
    }

    novoGrupo->lider = *lider;
    novoGrupo->participantes = *lider;
    novoGrupo->prox = NULL;
    if((*lider) ->primeiroGrupo == NULL){
        (*lider) ->primeiroGrupo = novoGrupo;
        (*lider) ->primeiroGrupo ->prox = NULL;
    }else{
        struct Group *aux1 = (*lider) ->primeiroGrupo;
        while(aux1 != NULL ){
            aux1 = aux1 ->prox;
        }
        aux1 = novoGrupo;
        aux1 -> prox = NULL;
        
    }
    struct Group **aux = &(*groupcab);

    // Encontrar a posição correta para inserir o novo grupo em ordem alfabética
    while (*aux != NULL && strcmp(novoGrupo->nome, (*aux)->nome) > 0) {
        anterior = *aux;
        aux = &(*aux)->prox;
    }

    // Inserir o novo grupo na posição correta
    novoGrupo->prox = *aux;
    if (anterior != NULL) {
        anterior->prox = novoGrupo;
    } else {
        *groupcab = novoGrupo;
    }

    printf("Digite a descrição do grupo: ");
    fgets(novoGrupo->descricao, sizeof(novoGrupo->descricao), stdin);
    novoGrupo->descricao[strcspn(novoGrupo->descricao, "\n")] = '\0';
    system("clear");
    printf("Grupo criado com sucesso.\n");
}
void adicionaGrupo(struct User **usuario, struct Group **groupcab) {
    char nomeGrupo[30];
    printf("Digite o nome do grupo: ");
    getchar();
    fgets(nomeGrupo, sizeof(nomeGrupo), stdin);
    nomeGrupo[strcspn(nomeGrupo, "\n")] = '\0';

    struct Group *novoGrupo;
    novoGrupo = verificaGrupo(groupcab, nomeGrupo);
    if (novoGrupo == NULL) {
        system("clear");
        printf("Esse grupo não existe!\n");
        return;
    }

    if (verificaParticipante(usuario, &novoGrupo)) {
        system("clear");
        printf("Você já é um participante.\n");
        return;
    }

    struct User *novoParticipante = malloc(sizeof(struct User));

    novoParticipante->prox = NULL;
    novoParticipante->primeiroGrupo = NULL;

    // Atribuir o nome de usuário do usuário atual ao novo participante
    strncpy(novoParticipante->username, (*usuario)->username, sizeof(novoParticipante->username) - 1);
    novoParticipante->username[sizeof(novoParticipante->username) - 1] = '\0';

    // Adicionar o usuário à lista de participantes do grupo
    if (novoGrupo->participantes == NULL) {
        novoGrupo->participantes = novoParticipante;
    } else {
        struct User *participanteAux = novoGrupo->participantes;
        while (participanteAux->prox != NULL) {
            participanteAux = participanteAux->prox;
        }
        participanteAux->prox = novoParticipante;
    }

    // Adicionar o grupo à lista de grupos do usuário
    if ((*usuario)->primeiroGrupo == NULL) {
        (*usuario)->primeiroGrupo = novoGrupo;
    } else {
        struct Group *grupoAux = (*usuario)->primeiroGrupo;
        while (grupoAux->prox != NULL) {
            grupoAux = grupoAux->prox;
        }
        grupoAux->prox = novoGrupo;
    }

    system("clear");
    printf("Parabéns, você entrou no grupo!\n");
}


struct Group *verificaGrupo(struct Group **groupcab, char nomeGrupo[30]) {
    struct Group *aux;
    aux = (*groupcab);

    while (aux != NULL) {
        if (strcmp(aux->nome, nomeGrupo) == 0) {
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}


void listaGrupo(struct Group *groupcab){
    system("clear");
    printf("-----------Lista de grupos-----------\n");
    struct Group *aux = groupcab ;

    if (aux == NULL) {
        printf("Não há grupos cadastrados.\n");
    } else {
        while (aux != NULL && aux  != aux ->prox) {
            printf("Nome do Grupo: %s\n", aux->nome);
            printf("Liderado por: %s\n", aux->lider->username);
            aux = aux->prox;
        }
    }

    printf("--------------------------------------\n");
}


//Mesmo não sendo usada decidi deixar pois pode ser util
void listaParticipantes(struct Group *grupo) {
    struct User *aux;
    aux = grupo->participantes;

    while (aux != NULL) {
        printf("O participante é: %s\n", aux->nome);
        aux = aux->prox;
    }
}

int verificaParticipante(struct User **usuario, struct Group **grupo) {
    struct User *aux = (*grupo)->participantes;

    while (aux != NULL) {
        if (strcmp(aux->username, (*usuario)->username) == 0) {
            return 1;
        }
        aux = aux->prox;
    }

    return 0;
}

void adicionarPost(struct User **usuario, struct Group **grupo) {
    char conteudo[100];
    struct Post *novoPost = malloc(sizeof(struct Post));
    printf("Digite o post que deseja fazer: ");
    fgets(conteudo, sizeof(conteudo), stdin);
    conteudo[strcspn(conteudo, "\n")] = '\0';
    strcpy(novoPost->conteudo, conteudo);
    novoPost->prox = NULL;
    strcpy(novoPost->nome, (*usuario)->nome);

    if ((*grupo)->primeiroPost == NULL) {
        (*grupo)->primeiroPost = novoPost;
    } else {
        struct Post *Postc = (*grupo)->primeiroPost;
        while (Postc->prox != NULL) {
            Postc = Postc->prox;
        }
        Postc->prox = novoPost;
    }

    system("clear");
    printf("Post realizado com sucesso!\n");
}

void printMuralGrupo(struct Group **grupo) {
    system("clear");
    printf("Mural de %s:\n", (*grupo)->nome);
    printf("------------------------------\n");
    struct Post *Postc = (*grupo)->primeiroPost;
    while (Postc != NULL) {
        printf("Post feito por %s:\n", Postc->nome);
        printf("%s\n", Postc->conteudo);
        Postc = Postc->prox;
    }
    printf("------------------------------\n");
}

void listaGrupos(struct User **usuario) {
    system("clear");
    printf("-----------Lista de grupos que você pertence-----------\n");
    struct Group *grupoCab = (*usuario)->primeiroGrupo;
    struct Group *aux ;
    while (grupoCab != NULL) {
            if (verificaParticipante(usuario, &grupoCab)) {
                printf("%s\n", grupoCab->nome);
            }
            grupoCab = grupoCab->prox;
    }
    printf("------------------------------------------------------\n");
}



