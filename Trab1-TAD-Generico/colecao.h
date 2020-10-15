#include <stdio.h>
#include <stdlib.h>

//Colecao generica
typedef struct _colecao_{
    int numItens;
    int maxItens;
    void **itens;
}Colecao;

//Definição da coleção de qualquer cosia
typedef struct _qqcoisa_{
    char nome[100];
    int num;
    float real;
}Qqcoisa;

//Chamda de Funções da Colecao
Colecao *colCriar(int tam);
int colInserir(Colecao *bau, void *item);
void* colBusca(Colecao *bau, void *key, int (*cmp)(void *, void *));
void* colRemove(Colecao *bau, void *key, int (*cmp)(void *, void *));
int colDestroi(Colecao *bau);

/*
typedef struct _Colecao_{
    int numQqcoisa;
    int maxQqcoisa;
    Qqcoisa *vetor;
}Colecao;
*/

