#include <stdio.h>
#include <stdlib.h>
//#include "colecao.h"

void mostraPlayer (Jogador *player){
    printf("\nNome:  %s", player->nome);
    printf("\nMatricula:  %i", player->matricula);
    printf("\nMedia de pontos por partida:  %.2f", player->mediaPontos);
}


int escolha(){

    int escolha;
    printf("Bem-vindo. Para a utilizacao do programa, siga o menu abaixo:\n");
    printf("1 - Criar reserva de jogadores.\n");
    printf("2 - Inserir um jogador na colecao.\n");
    printf("3 - Verificar se um jogador esta na colecao.\n");
    printf("4 -  Remover um jogador especifico da colecao.\n");
    printf("5 -  Detruir a colecao.\n");
    printf("6 -  Mostrar todos os jogadores.\n");

    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\nInforme sua escolha:  ");

    scanf("%i", &escolha);
    return escolha;
}
