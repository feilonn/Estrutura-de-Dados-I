#include <stdio.h>
#include <stdlib.h>
//#include "colecao.h"

int escolha(){

    int escolha;
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\nBem-vindo. Para a utilizacao do programa, siga o menu abaixo:\n");
    printf("1 - Criar reserva de jogadores.\n");
    printf("2 - Inserir um jogador na reserva.\n");
    printf("3 - Verificar se um jogador esta na reserva.\n");
    printf("4 -  Remover um jogador especifico da reserva.\n");
    printf("5 -  Aposentar a reserva.\n");
    printf("6 -  Mostrar todos os jogadores.\n");

    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\nInforme sua escolha:  ");

    scanf("%i", &escolha);
    return escolha;
}
