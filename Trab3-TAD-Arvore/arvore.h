#include <stdio.h>
#include <stdlib.h>


typedef struct _sllist_ Sllist;
typedef struct _slnode_ SlNode;

typedef struct _tnode_ TNode;


int sllInsert(Sllist *l, void *item);
void *sllQuery(Sllist *l, void *key, int(*cmp)(void*, void*));
void *sllRemove(Sllist *l);
void *sllRemoveSpec(Sllist *l, void *key, int(*cmp)(void*, void*));
int sllDestroy(Sllist *c);
void *sllGetNumElms(Sllist *l);
void *mostraPlayer(Sllist *c, void (*mostraTodos)(void* elm));


TNode *abpCreate();
void preOrdem(TNode *t, void(*visit)(void*));
void simetrico(TNode *t, void(*visit)(void*));
void *abpQuery(TNode *t, void *key, int(*cmp)(void*, void*));
TNode *abpInsert(TNode *t, void *data, int(*cmp)(void*, void*));
TNode *abpRemove(TNode *t, void *key, int(*cmp)(void*, void*));
TNode *abpRemoveMenor(TNode *t, void *key, int(*cmp)(void*, void*), void **data);