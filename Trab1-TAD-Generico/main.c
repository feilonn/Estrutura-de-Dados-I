#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include "menu.h"

typedef struct _jogador_{
    char nome[100];
    int matricula;
    float mediaPontos;
}Jogador;

void mostraTodos (void *elm){
    Jogador *player = (Jogador*)elm;
    printf("\n~*Dados do jogador*~:");
    printf("\nNome do Jogador: %s", player->nome);
    printf("\nMatricula do Jogador: %i", player->matricula); // matricula sempre levado como um inteiro
    printf("\nMedia de pontos do Jogador: %.2f", player->mediaPontos); // media de pontos como float
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
}                    

int cmp(void *elm, void *key){ // Funcao compara baseada na matricula(int)
    
    Jogador *pelm = (Jogador*)elm;
    int *pkey = (int*)key;
    
    if(pelm->matricula == pkey){
        return 1;
    }else{
        return 0;
    }
}

int main(void){

    int ativo = 9; // controlador de loop para intercao do usuario
    int qtdePlayer = 0, usuario, tamCol; // verificador do switch e variavel para o tamanho da colecao
    int* matricula;
    int* pegaMatricula;

    Colecao *c; // declaracao da colecao c do tipo Colecao
    c = NULL; 
    Jogador *player; // declaracao da colecao player do tipo Jogador

    while(ativo != 0){

       // scanf("%d",&usuario); // Funcao do arquivo menu.c. Um simples menu para interacao do usuario com o switch

        usuario = escolha();
        while(usuario < 1 || usuario > 6){ // teste switch
            printf("\nOperacao invalida! Insira uma opcao correspondente ao menu abaixo;");
           // scanf("%d", &usuario);
            usuario = escolha();
        }

        switch (usuario)
        {
        case 1: // Criar colecaoo
            if(c != NULL){
                printf("\nErro.A reserva ja foi criada!");
                break;
            };
            printf("Informe o tamanho da colecao: ");
            scanf("%i", &tamCol);

            c = colCriar(tamCol); // funcao do colecao.c, tamCol(maxItens) precisa ser > 0

            if(c != NULL){
                printf("A reserva foi criada!");
            }else{
                printf("Ocorreu um erro ao criar a reserva!");
            }

            break;
        case 2: // Inserir na colecao
            if(c == NULL){
                printf("\nAinda nao existe uma reserva. Crie uma antes de tentar inserir");
                break;
            }else if(qtdePlayer < tamCol){ // Verificando se ainda ha espaco para inserir na colecao
                player = (Jogador*)malloc(sizeof(Jogador));
                if(player != NULL){
                    printf("\n-=-=-=-=-Cadastro de Jogador-=-=-=-=-");

                    printf("\nNome do Jogador: ");
                    scanf("%s", &player->nome);

                    printf("\nMatricula do Jogador: "); // matricula sempre levado como um inteiro
                    scanf("%i", &player->matricula);

                    printf("\nMedia de pontos do Jogador: "); // media de pontos como float
                    scanf("%f", &player->mediaPontos);

                    if(colInserir(c, (void*)player) != 0){
                        printf("\nParabens. O jogador foi inserido!");
                        printf("\n-=-=-=-=-Dados do Jogador-=-=-=-=-");
                        printf("\nNome: %s", player->nome);
                        printf("\nMatricula: %i", player->matricula);
                        printf("\nMedia de pontos por partida: %.2f", player->mediaPontos);
                        qtdePlayer++;
                        break;
                    }
                }
            }else{
                printf("\nErro! A reserva esta cheia");
            };
            break;
        case 3: // Busca na colecao
            if(c == NULL){
                printf("\nAinda nao existe uma reserva. Crie uma antes de tentar buscar por um jogador");
                break;
            }else if(qtdePlayer == 0){
                printf("\nNao existe nenhum jogador na reserva!");
                break;
            }

            printf("\nInforme a matricula do jogador a ser procurado: ");
            scanf("%i", &matricula);

            int buscaPlayer = colBusca(c, matricula, cmp);
            if(buscaPlayer == matricula){
                printf("\nErro! nao foi possivel executar a busca");
                break;
            }else{
                printf("\nO jogador nao foi encontrado na reserva!");
            }
            break;
        case 4: // Remover da colecaoo
            if(c == NULL){
                printf("\nAinda nao existe uma reserva. Crie uma antes de tentar remover por um jogador");
                break;
            }else if(qtdePlayer == 0){
                printf("\nNao existe nenhum jogador na reserva!");
                break;
            }

            printf("\nInforme a matricula do jogador a ser removido: ");
            scanf("%i", &pegaMatricula);

            int removePlayer = colRemove(c, pegaMatricula, cmp);
            if(removePlayer == NULL){
                printf("\nErro!");
                break;
            }else{
                printf("\nNao foi possivel encontrar o jogador");
            }
            break;
        case 5: // Destruir colecaoo
            if(c == NULL){
                printf("\nAinda nao existe uma reserva. Crie uma antes de tentar destrui-la.");
                break;
            }

            if(colDestruir(c) == 1){
                printf("\nReserva destruida!");
            }else{
                printf("\nOcorreu um erro!");
            }
            break;
        case 6:
            if(c == NULL){
                printf("\nAinda nao existe uma reserva. Crie uma e insira jogadores antes de tentar listar.");
                break;
            }else if(qtdePlayer == 0){
                printf("\nErro! A reserva esta vazia");
                break;
            };
            printf("\n-=-=-=-=-Jogadores Matriculados-=-=-=-=-");
            mostraPlayer(c, mostraTodos);
            break;
        default:
            printf("\nErro no sistema!");
            break;
        }

        printf("\nPara sair do sistema digite 0(Zero). Para continuar pressione qualquer outro numero: ");
        scanf("%i", &ativo);
    }
   return 0;
}
