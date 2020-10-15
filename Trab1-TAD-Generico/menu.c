#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"

int escolha(){
    
    int escolha;
    printf("Bem-vindo. Para a utilizacao do programa, siga o menu abaixo:");
    printf("1 - Criar uma colecao.\n");
    printf("2 - Inserir um ??? na colecao.\n");
    printf("3 - Verificar se um ??? esta na colecao.\n");
    printf("4 -  Remover um ??? especifico da colecao.\n");
    printf("5 -  Detruir a colecao.\n");

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("Informe sua escolha:  ");

    scanf("%i", &escolha);

    return escolha;

};