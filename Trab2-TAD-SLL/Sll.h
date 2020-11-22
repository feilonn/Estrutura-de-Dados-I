#include <stdio.h>
#include <stdlib.h>


typedef struct _sllist_ Sllist;
typedef struct _slnode_ SlNode;

Sllist *sllCreate();
int sllInsert(Sllist *l, void *item);
void *sllQuery(Sllist *l, void *key, int(*cmp)(void*, void*));
void *sllRemove(Sllist *l);
void *sllRemoveSpec(Sllist *l, void *key, int(*cmp)(void*, void*));
int sllDestroy(Sllist *c);
void *sllGetNumElms(Sllist *l);
void *mostraPlayer(Sllist *c, void (*mostraTodos)(void* elm));
