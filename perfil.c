#include "perfil.h"
#include "grupo.h"
char printaPerfil(struct User **usercab,struct User **usuario,struct Group **groupcab){
    char op[2];
    char nomeAmigo[30];
    struct User *aux;
    printf("-----------Bem vindo ao seu perfil !----------\n");
    printf("Nome : %s\n",(*usuario) ->nome);
    printf("Username : %s\n",(*usuario) ->username);
    printf("Ocupação : %s\n",(*usuario) ->ocupacao);
    printf("Endereço : %s\n",(*usuario) ->endereco);
    printf("Bio : %s\n",(*usuario) ->bio);
    printf("Digite :  1 para ver o perfil de outro usuário | 2 para editar o perfil | 3 para entrar no mural | 4 para ver e adicionar amigos | 5 para ver ou enviar mensagens | 6 para entrar na aba de grupos | 7 para deslogar\n");
    fgets(op, sizeof(op), stdin);
    op[strcspn(op, "\n")] = '\0';
    switch(op[0]){
        case '1':
            system("clear");
            printf("Digite o username do usuário que vc deseja ver o perfil : \n");
            getchar();
            fgets(nomeAmigo,sizeof(nomeAmigo), stdin);
            nomeAmigo[strcspn(nomeAmigo, "\n")] = '\0';
            printUsuario(encontraUsuario(usercab,nomeAmigo));
            printf("Aperte 1 para sair ! \n");
            getchar();
            fgets(op, sizeof(op), stdin);
            system("clear");
            return '0';
        case '2':
            alteraDados(usuario,*usercab);
            return '0';
        case '3':
            char post[1000];
            char nomeMural[30];
            system("clear");
            printMural(usuario);
            printf("\nDigite : 1 para fazer um novo poste | 2 para ver o mural de outro usuário | 3 para voltar \n");
            getchar();
            fgets(op, sizeof(op), stdin);
            switch(op[0]){
                case '1':
                    system("clear");
                    printf("Digite o post que deseja fazer : ");
                    getchar();
                    fgets(post,sizeof(post), stdin);
                    post[strcspn(post, "\n")] = '\0';
                    criaPost(usuario,post);
                    break;
                case '2':
                    system("clear");
                    printf("Digite o mural de quem vc deseja ver : ");
                    getchar();
                    fgets(nomeMural,sizeof(nomeMural), stdin);
                    nomeMural[strcspn(nomeMural, "\n")] = '\0';
                    struct User *aux;
                    aux = encontraUsuario(usercab,nomeMural);
                    
                    if(aux != NULL){
                        printMural(&aux);
                        printf("Digite 1 para voltar : ");
                        fgets(op, sizeof(op), stdin);
                        getchar();
                        system("clear");
                        return '0';
                    }
                    system("clear");
                    printf("Usuario não encontrado !\n");
                    break;
                case '3':
                    system("clear");
                    getchar();
                    break;
            }
            return '0';
        case '4':
            printf("Seus amigos : \n");
            listaAmigos(usuario);
            printf("Digite : 1 para adicionar um amigo | 2 para ver a lista de amigos de outro usuário | 3 para voltar \n");
            getchar();
            fgets(op, sizeof(op), stdin);
            
            switch(op[0]){
                case '1':
                    system("clear");
                    aux = (*usercab) ->prox;
                    printf("Digite o username da pesssoa que deseja adicionar : ");
                    getchar();
                    fgets(nomeAmigo,sizeof(nomeAmigo), stdin);
                    nomeAmigo[strcspn(nomeAmigo, "\n")] = '\0';
                    while (aux != NULL) {
                        if (strcmp(nomeAmigo,aux->username) == 0) {
                                
                                system("clear");
                                adicionarAmigo(usuario,&aux);
                                return '0';
                        }
                        aux = aux->prox;
                    }
                    system("clear");
                    
printf("Esse usuário não existe !\n");
                    return '0';
                
                case '2':
                    printf("Digite o nome da pesssoa que deseja ver a lista de amigos : ");
                    getchar();
                    fgets(nomeAmigo,sizeof(nomeAmigo), stdin);
                    nomeAmigo[strcspn(nomeAmigo, "\n")] = '\0';
                    struct User *amigo;
                    amigo = encontraUsuario(usercab,nomeAmigo);
                    if(amigo != NULL){
                        listaAmigos(&amigo);
                        printf("Digite 1 para voltar : ");
                        fgets(op, sizeof(op), stdin);
                        getchar();
                        system("clear");
                        return '0';
                    }
                    system("clear");
                    printf("Usuário não encontrado !\n");
                    return '0';
            }
            getchar();
            system("clear");
            return '0';   
        case '5':
            struct User *amigo;
            char mensagem[1000];
            system("clear");
            exibirCaixaEntrada(usuario);
            printf("Digite : 1 para enviar uma mensagem | 2 para voltar\n");
            getchar();
            fgets(op, sizeof(op), stdin);
            
            if(op[0] == '1'){
                printf("Digite o nome da pesssoa que deseja enviar uma mensagem : ");
                getchar();
                fgets(nomeAmigo,sizeof(nomeAmigo), stdin);
                nomeAmigo[strcspn(nomeAmigo, "\n")] = '\0';
                
                printf("Digite a mensagem que deseja enviar : ");
                fgets(mensagem,sizeof(mensagem), stdin);
                mensagem[strcspn(mensagem, "\n")] = '\0';
                amigo = encontraUsuario(usercab,nomeAmigo);
                if(amigo != NULL){
                    enviarMensagem(usuario,&amigo,mensagem);
                    system("clear");
                    printf("Mensagem enviada !\n");
                    return '0';
                }
                system("clear");
                printf("Usuário não encontrado !\n");

                return '0';
            }
            getchar();
            system("clear");
            return '0';  
        case '6':
            system("clear");
            listaGrupos(usuario);
            printf("Digite : 1 para criar grupo | 2 para entrar em um grupo | 3 para ver o mural de um grupo | 4 para fazer um post | 5 para voltar\n");
            getchar();
            fgets(op, sizeof(op), stdin);
            switch(op[0]){
                char nomeGrupo[30];
                struct Group *grupo;
                case '1':
                    system("clear");
                    criaGrupo(groupcab,usuario);
                    
                    return '0';
                case '2':
                    system("clear");
                    printf("Grupos existentes : \n");
                    listaGrupo(*(groupcab));
                    adicionaGrupo(usuario,groupcab);
                    
                    return '0';
                
                case '3':
                    
                    printf("Digite o nome do grupo: ");
                    getchar();
                    fgets(nomeGrupo, sizeof(nomeGrupo), stdin);
                    nomeGrupo[strcspn(nomeGrupo, "\n")] = '\0';
                    
                    grupo = verificaGrupo(groupcab,nomeGrupo);
                    if(grupo!= NULL){  
                        system("clear");         
                        printMuralGrupo(&grupo);
                    }
                    else{
                        system("clear");
                        printf("Grupo não encontrado ! \n");
                    }
                    
                    return '0';
                    break;
                case '4':
                   
                    printf("Digite o nome do grupo que deseja fazer um post: ");
                    getchar();
                    fgets(nomeGrupo, sizeof(nomeGrupo), stdin);
                    nomeGrupo[strcspn(nomeGrupo, "\n")] = '\0';
                    
                    grupo = verificaGrupo(groupcab,nomeGrupo);
                    if(grupo!= NULL){           
                          
                        if(verificaParticipante(usuario,&grupo)){
                            
                            adicionarPost(usuario,&grupo);
                            
                            return '0';
                        }
                        system("clear");
                        printf("Vc não é um participante ! \n");
                        return '0';
                    }
                    system("clear");
                    printf("Esse grupo não existe !\n");
                    return '0';
            }
            system("clear");
            getchar();
            return '0';
        case '7':
            system("clear");
            return '2'; 
        default:
            system("clear");
            printf("Digite uma opção válida ! \n");
            return '0';       
        }
    return op[0];
}

void alteraDados(struct User **usuario,  struct User *usercab) {
    char op[2];
    system("clear");
    printf("----------Qual parte do perfil deseja editar?----------\n");
    printf("Digite a opção que deseja alterar: 1 Nome | 2 Username | 3 Ocupação | 4 Endereço | 5 Bio | 6 Senha | 7 para voltar \n");
    getchar();
    fgets(op, sizeof(op), stdin);
    switch (op[0]) {
        case '1':
            char nome[30];
            printf("Digite o novo nome:\n");
            getchar();
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';
            strcpy((*usuario)->nome, nome);
            system("clear");
            printf("Nome alterado com sucesso !\n");
            break;
        case '2':
            char username[30];
            printf("Digite o novo username:\n");
            getchar();
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = '\0';
            if(!validateString(username)){
                if (!validaUserName(usercab,username)) {
                    system("clear");
                    strcpy((*usuario)->username, username);
                }
                else {
                system("clear");
                printf("Usuário já existe\n");
                }
            }else{
                system("clear");
                printf("Você digitou apenas espaços\n");
            }
            system("clear");
            printf("Username alterado com sucesso !\n");
            break;
        case '3':
            char ocupacao[1000];
            printf("Digite a nova ocupação:\n");
            getchar();
            fgets(ocupacao, sizeof(ocupacao), stdin);
            ocupacao[strcspn(ocupacao, "\n")] = '\0';
            strcpy((*usuario)->ocupacao, ocupacao);
            system("clear");
            printf("Ocupação alterado com sucesso !\n");
            break;
        case '4':
        char endereco[1000];
            printf("Digite o novo endereço:\n");
            getchar();
            fgets(endereco, sizeof(endereco), stdin);
            endereco[strcspn(endereco, "\n")] = '\0';
            strcpy((*usuario)->endereco, endereco);
            system("clear");
            printf("Endereço alterado com sucesso !\n");
            break;
        case '5':
            char bio[1000];
            printf("Digite a nova Bio:\n");
            getchar();
            fgets(bio, sizeof(bio), stdin);
            bio[strcspn(bio, "\n")] = '\0';
            strcpy((*usuario)->bio, bio);
            system("clear");
            printf("Bio alterado com sucesso !\n");
            break;
        case '6':
            char senha[30];
            system("clear");
            printf("Digite sua senha antiga : \n");
            getchar();
            ocultaSenha(senha);
            if(strcmp((*usuario) -> senha , senha) == 0){
                printf("Digite a nova senha:\n");
                ocultaSenha(senha);
                if(!validateString(senha)){
                    strcpy((*usuario)->senha, senha);
                    system("clear");
                    printf("Senha alterado com sucesso !\n");
                    break;
                }
            }
            system("clear");
            printf("Senha incorreta !\n");
            break;
        case '7':
            system("clear");
            getchar();
            break;
        default:
            system("clear");
            printf("Digite uma opção válida !");
            return;
    }
}





