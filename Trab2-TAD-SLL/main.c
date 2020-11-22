#include <stdio.h>
#include <stdlib.h>
#include "Sll.h"
#include "menu.h"

typedef struct _jogador_{
    char nome[100];
    int matricula;
    float mediaPontos;
}Jogador;

void mostraTodos(void *elm){
    printf("Meia noite eu te conto.");
}

int cmp(void *elm, void *key){
    
    Jogador *pelm = (Jogador*)elm;
    int  *pkey = (int*)key;
    if(pelm->matricula == *pkey){
        return 1;
    }else{
        return 0;
    } 
}
    
int main(void){
    
    int ativo = -1;
    int usuario, matricula, pegaMatricula;
    int qtdeplayer = 0;

    Sllist *l;
    l = NULL;
    Jogador *player;

    while(ativo != 0){

        usuario = escolha();
        while(usuario < 1 || usuario > 6){ // teste switch
            printf("\nOperacao invalida! Insira uma opcao correspondente ao menu abaixo;");
            usuario = escolha();
        }
            switch (usuario){
                case 1: // Criar lista
                    if(l != NULL){
                        printf("\nErro.A reserva ja foi criada!");
                        break;
                    };
                    l = sllCreate();

                    if(l != NULL){
                        printf("A reserva foi criada!");
                    }else{
                        printf("Ocorreu um erro ao criar a reserva!");
                    }
                break;
                case 2:
                    if(l == NULL){
                        printf("\nAinda nao existe uma reserva. Crie uma antes de tentar inserir");
                        break;
                    }
                    player = (Jogador*)malloc(sizeof(Jogador));
                    if(player != NULL){
                        printf("\n-=-=-=-=-Cadastro de Jogador-=-=-=-=-");

                        printf("\nNome do Jogador: ");
                        scanf("%s", &player->nome);

                        printf("\nMatricula do Jogador: "); // matricula sempre levado como um inteiro
                        scanf("%i", &player->matricula);

                        printf("\nMedia de pontos do Jogador: "); // media de pontos como float
                        scanf("%f", &player->mediaPontos);
                    }
                    if(sllInsert(l, (void*)player) != 0){
                        printf("\nParabens. O jogador foi inserido!");
                        printf("\n-=-=-=-=-Dados do Jogador-=-=-=-=-");
                        printf("\nNome: %s", player->nome);
                        printf("\nMatricula: %i", player->matricula);
                        printf("\nMedia de pontos por partida: %.2f", player->mediaPontos);
                        qtdeplayer++;
                    }
                break;
                case 3:
                    if(l == NULL){
                        printf("\nAinda nao existe uma reserva. Crie uma antes de tentar buscar por um jogador");
                        break;
                    }else if(qtdeplayer == 0){
                        printf("\nNao existe nenhum jogador na reserva!");
                        break;
                    }
                    printf("\nInforme a matricula do jogador a ser procurado: ");
                    scanf("%i", &matricula);

                    int* buscaPlayer = sllQuery(l, (void*)&matricula, cmp);
                    if(buscaPlayer != NULL){
                        printf("\nO jogador %i esta na reserva!", *buscaPlayer);
                        break;
                    }else{
                        printf("\nO jogador nao foi encontrado na reserva!");
                    }
                break;
                case 4:
                    if(l == NULL){
                        printf("\nAinda nao existe uma reserva. Crie uma antes de tentar remover por um jogador");
                        break;
                    }else if(qtdeplayer == 0){
                        printf("\nNao existe nenhum jogador na reserva!");
                        break;
                    }

                    printf("\nInforme a matricula do jogador a ser removido: ");
                    scanf("%i", &pegaMatricula);

                    int* removePlayer = sllRemove(l);
                    if(removePlayer != NULL){
                        printf("\nO jogador %i foi removido!", *removePlayer);
                        qtdeplayer--;
                        break;
                    }else{
                        printf("\nNao foi possivel encontrar o jogador");
                    }
                break;
                case 5:
                    if(l == NULL){
                        printf("\nAinda nao existe uma reserva. Crie uma antes de tentar destrui-la.");
                        break;
                    }

                    if(sllDestroy(l) == 1){
                        printf("\nReserva foi aposentada!");
                    }else{
                        printf("\nOcorreu um erro!");
                    }
                break;
                case 6:
                    if(l == NULL){
                        printf("\nAinda nao existe uma reserva. Crie uma e insira jogadores antes de tentar listar.");
                        break;
                    }else if(qtdeplayer == 0){
                        printf("\nErro! A reserva esta vazia");
                        break;
                    };
                    printf("\n-=-=-=-=-Jogadores Matriculados-=-=-=-=-");
                    printf("\nMeia noite eu te conto");
                break;
                default:
                    printf("\nErro no sistema! Opcao invalida!");
                break;
            }
            printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
            printf("\nPara sair do sistema digite 0(Zero). Para continuar pressione qualquer outro numero: ");
            scanf("%i", &ativo);
    }
    return 0;
}