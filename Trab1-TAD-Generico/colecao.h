#include <stdio.h>
#include <stdlib.h>

//Colecao generica
typedef struct _colecao_{
    int numItens;
    int maxItens;
    void **itens;
}Colecao;

//Defini��o da cole��o de qualquer cosia
typedef struct _jogador_{
    char nome[100];
    int matricula;
    float mediaPontos;
}Jogador;

//Chamda de Fun��es da Colecao
Colecao *colCriar(int maxItens);
int colInserir(Colecao *c, void *item);
void* colBusca(Colecao *c, void *key);
void* colRemove(Colecao *c, void *key);
int colDestruir(Colecao *c);
int cmp(void *elm, void *key);

/*
typedef struct _Colecao_{
    int numQqcoisa;
    int maxQqcoisa;
    Qqcoisa *vetor;
}Colecao;
*/

/*
void mostraElm(Qqcoisa *elm){
    printf("\nNome: %s", elm->nome);
    printf("\nMatricula: %s", elm->num);
    printf("\nAltura: %s", elm->real);
};
*/
