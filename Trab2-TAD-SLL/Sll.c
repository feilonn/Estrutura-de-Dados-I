#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sll.h"

typedef struct _slnode_{
    struct _slnode_ *next;
    void *data;
}SlNode;

typedef struct _sllist_{
    SlNode *first;
    SlNode *cur;
}Sllist;

Sllist *sllCreate(){
    Sllist *l;
    l = (Sllist*)malloc(sizeof(Sllist));
    if(l != NULL){
        l->first = NULL;
        return l;
    }
    return NULL;
}

int sllInsert(Sllist *l, void *elm){
    SlNode *newnode;
    if(l!= NULL){
        newnode = (SlNode*)malloc(sizeof(SlNode));
        if(newnode != NULL){
            newnode->data = elm;
            if(l->first == NULL){
                newnode->next = NULL;
            }else{
                newnode->next = l->first;
            }
            l->first = newnode;
            return 1;
        }
    }
    return 0;
}

void *sllRemove(Sllist *l){
    SlNode *aux;
    void *data;
    if(l != NULL){
        if(l->first != NULL){
            aux = l->first;
            data = aux->data;
            l->first = aux->next;
            free(aux);
            return data;
        }
    }
    return NULL;
}

int sllDestroy(Sllist *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return 1;
        }
    }
    return 0;
}


void *sllRemoveSpec(Sllist *l, void *key, int(*cmp)(void*, void*)){
    SlNode *spec, *prev;
    void *data;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            prev = NULL;
            while(spec->next != NULL && cmp(spec->data, key) != 1){
                prev = spec;
                spec = spec->next;
            }
            if(cmp(spec->data, key) == 1){
                data = spec->data;
                if(spec == l->first){
                    l->first = spec->next;
                }else{
                    prev->next = spec->next;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}

void *sllQuery(Sllist *l, void *key, int(*cmp)(void*, void*)){
    SlNode *cur;
    if(l != NULL){
        if(l->first != NULL){
            cur = l->first;
            while(cur->next != NULL && cmp(cur->data, key) != 1){
                cur = cur->next;
            }
            if(cmp(cur->data, key) == 1){
                return cur->data;
            }
        }
    }
    return NULL;
}

void *mostraPlayer(Sllist *l, void (*mostraTodos)(void* elm)){
    SlNode *cur;
    void *view;
    if(l != NULL){
        if(l->first != NULL){
            cur = l->first;
            mostraTodos(cur->data);
            while(cur->next != NULL){
                cur = cur->next;
                mostraTodos(cur->data);
            }
            
        }
    }
    return NULL; 
}

/*
void *sllGetNumElms(Sllist *l){
    SlNode *cur;
    int n = 0;
    if(l != NULL){
        if(l->first != NULL){
            cur = l->first;
            while(cur->next != NULL){
                n++;
                cur = cur->next;
            }
            n++;
            return n;
        }
        return 0;
    }
    return -1;
}
*/