#include <stdio.h>
#include <stdlib.h>


typedef struct _colecao_ Colecao;

Colecao *colCriar(int maxItens);
int colInserir(Colecao *c, void *item);
void* colBusca(Colecao *c, void *key, int(*cmp)(void*, void*));
void* colRemove(Colecao *c, void *key, int(*cmp)(void*, void*));
int colDestruir(Colecao *c);
void *mostraPlayer(Colecao *c, void (*mostraTodos)(void* elm));

