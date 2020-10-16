#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include "menu.h"


int main(void){

    int ativo = 9; // controlador de loop para intercao do usuario
    int usuario, tamCol; // verificador do switch e variavel para o tamanho da colecao

    Colecao *c; // declaracao da colecao c do tipo Colecao
    c = NULL; 

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
                printf("\nErro.A colecao ja foi criada!");
                break;
            };
            printf("Informe o tamanho da colecao: ");
            scanf("%i", &tamCol);

            c = colCriar(tamCol); // funcao do colecao.c, tamCol(maxItens) precisa ser > 0

            if(c != NULL){
                printf("A colecao foi criada!");
            }else{
                printf("Ocorreu um erro ao criar a colecao!");
            }

            break;
        case 2: // Inserir na colecao
            if(c == NULL){
                printf("\nAinda nao existe uma colecao. Crie uma antes de tentar inserir");
                break;
            }else if(c->numItens < c->maxItens){ // Verificando se ainda ha espaco para inserir na colecao
                Jogador *player; // declaracao da colecao jogador do tipo Jogador
                player = (Jogador*)malloc(sizeof(Jogador));
                if(player != NULL){
                    printf("\n-=-=-=-=-Cadastro de Jogador-=-=-=-=-");

                    printf("\nNome do Jogador: ");
                    scanf("%s", &player->nome);

                    printf("\nMatricula(inteiro) do Jogador: "); // matricula sempre levado como um inteiro
                    scanf("%i", &player->matricula);

                    printf("\nMedia de pontos(float) do Jogador: "); // media de pontos como float
                    scanf("%f", &player->mediaPontos);

                    if(colInserir(c, (void*)player) != 0){
                        printf("\nParabens. O jogador foi inserido!");
                        printf("\n-=-=-=-=-Dados do Jogador-=-=-=-=-");
                        printf("\nNome: %s", player->nome);
                        printf("\nMatricula: %i", player->matricula);
                        printf("\nMedia de pontos por partida: %.2f", player->mediaPontos);
                        break;
                    }
                }
            }else{
                printf("\nErro! A colecao esta cheia");
            };
            break;
        case 3: // Busca na colecao
            if(c == NULL){
                printf("\nAinda nao existe uma colecao. Crie uma antes de tentar buscar por um jogador");
                break;
            }else if(c->numItens == 0){
                printf("\nNao existe nenhum jogador na colecao!");
                break;
            }

            int matricula;

            printf("\nInforme a matricula do jogador a ser procurado: ");
            scanf("%i", &matricula);

            Jogador *buscaPlayer;
            buscaPlayer = (Jogador*)malloc(sizeof(Jogador)); //Alocando de forma dinamica para buscar
            if(buscaPlayer == NULL){
                printf("\nErro! nao foi possivel executar a busca");
                break;
            }

            buscaPlayer = (Jogador*)colBusca(c, (void*)matricula); //Buscando jogador por matricula
            if(buscaPlayer != NULL){
                printf("\nO jogador foi encontrado na colecao!");
                printf("\n-=-=-=-=-Dados da Busca-=-=-=-=-");
                printf("\nNome: %s", buscaPlayer->nome);
                printf("\nMatricula: %i", buscaPlayer->matricula);
                printf("\nMedia de pontos por partida: %.2f", buscaPlayer->mediaPontos);
            }else{
                printf("\nO jogador nao foi encontrado na colecao!");
            }
            break;
        case 4: // Remover da colecaoo
            if(c == NULL){
                printf("\nAinda nao existe uma colecao. Crie uma antes de tentar remover por um jogador");
                break;
            }else if(c->numItens == 0){
                printf("\nNao existe nenhum jogador na colecao!");
                break;
            }

            int pegaMatricula;

            printf("\nInforme a matricula do jogador a ser removido: ");
            scanf("%i", &pegaMatricula);

            Jogador *removePlayer;
            removePlayer = (Jogador*)malloc(sizeof(Jogador)); //Alocando de forma dinamica para buscar
            if(removePlayer == NULL){
                printf("\nErro!");
                break;
            }

            removePlayer = (Jogador*)colRemove(c, (void*)pegaMatricula); // Buscando jogador pela matricula para remove-lo
            if(removePlayer != NULL){
                printf("\nO jogador foi removido");
                printf("\n-=-=-=-=-Dados do Jogador Removido-=-=-=-=-");
                printf("\nNome: %s", removePlayer->nome);
                printf("\nMatricula: %i", removePlayer->matricula);
                printf("\nMedia de Pontos por partida: %.2f", removePlayer->mediaPontos);

            }else{
                printf("\nNao foi possivel encontrar o jogador");
            }
            break;
        case 5: // Destruir colecaoo
            if(c == NULL){
                printf("\nAinda nao existe uma colecao. Crie uma antes de tentar destrui-la.");
                break;
            }

            if(colDestruir(c) == 1){
                printf("\nColecao destruida!");
            }else{
                printf("\nOcorreu um erro!");
            }
            break;
        case 6:
            if(c == NULL){
                printf("\nAinda nao existe uma colecao. Crie uma e insira jogadores antes de tentar listar.");
                break;
            }else if(c->numItens == 0){
                printf("\nErro! A colecao esta vazia");
                break;
            };
             printf("\n-=-=-=-=-Jogadores Matriculados-=-=-=-=-");
            for(int i = 0; i < c->numItens; i++){
                printf("\n\n-=-=-=-=-Dados do Jogador-=-=-=-=-");
                mostraPlayer(c->itens[i]);
            }
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
