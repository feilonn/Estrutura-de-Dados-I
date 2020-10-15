#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include "menu.c"


int main(void){

    int ativo = 9;
    int usuario, tamCol, matricula;
    float peso;
    char nome;

    Colecao *c;

    while(ativo != 0){

        usuario = escolha();

        while(usuario < 1 || usuario > 5){
            printf("Operacao invalida! Insira uma opcao correspondente ao menu");
            usuario = escolha();
        };

        switch (usuario)
        {
        case 1:
            printf("Informe o tamanho da colecao: ");
            scanf("%i", &tamCol);

            c = colCriar(tamCol);
            
            if(c != NULL){
                printf("A colecao foi criada!");
            }else{
                printf("Ocorreu um erro ao criar a colecao!");
            };

            break;
        case 2:
            if(c == NULL){
                printf("\nAinda nao existe uma colecao. Crie uma antes de tentar inserir");
                break;
            }else if(c->numItens < c->maxItens - 1){
                Qqcoisa *coisa;
                coisa = (Qqcoisa*)malloc(sizeof(Qqcoisa));
                if(coisa != NULL){
                    printf("\n-=-=-=-=-Cadastro de ???-=-=-=-=-");
                    
                    printf("\nNome do ???: ");
                    scanf("%s", &coisa->nome);

                    printf("\nMatricula(inteiro) do ???: ");
                    scanf("%i", &coisa->num);

                    printf("\nPeso/Altura do ???: ");
                    scanf("%f", &coisa->real);

                    if(colInserir(c, (void*)coisa) != 0){
                        printf("Parabens. ??? foi inserido!");
                        break;
                    };
                };
            }else{
                printf("Erro! A colecao esta cheia");
            };
            break;
        case 3:
            if(c == NULL){
                printf("\nAinda nao existe uma colecao. Crie uma antes de tentar buscar por um ???");
                break;
            };

            printf("\nInforme a matricula do ??? a ser procurado");
            scanf("%i", &matricula);

            Qqcoisa *buscaCoisa;
            buscaCoisa = (Qqcoisa*)malloc(sizeof(Qqcoisa));
            if(buscaCoisa == NULL){
                printf("Erro! nao foi possivel executar a busca");
                break;
            };

            //buscaCoisa = (Qqcoisa*)colBusca(c, (void*)&matricula, cmp);

        default:
            break;
        }

        printf("Para sair do sistema digite 0(Zero). Para continuar pressione qualquer tecla: ");
        scanf("%i", &ativo);
    };

   return 0; 
}