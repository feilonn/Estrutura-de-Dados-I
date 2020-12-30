#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

typedef struct _tnode_{
    struct _tnode_ *left;
    struct _tnode_ *right;
    void *item;
}TNode;

void preOrdem(TNode *t, void(*visit)(void*)){
    if(t != NULL){
        visit(t->item);
        preOrdem(t->left, visit);
        preOrdem(t->right, visit);
    }
}

void simetrico(TNode *t, void(*visit)(void*)){
    if(t != NULL){
        simetrico(t->left, visit);
        visit(t->item);
        simetrico(t->right, visit);
    }
}

void *abpQuery(TNode *t, void *key, int(*cmp)(void*, void*)){
    int stat;
    if(t != NULL){
        stat = cmp(key, t->item);
        if(stat == 0){
            return t->item;
        }else if(stat < 0){
            return abpQuery(t->left, key, cmp);
        }else{
            return abpQuery(t->right, key, cmp);
        }
    }

    return NULL;
}

TNode *abpInsert(TNode *t, void *data, int(*cmp)(void*, void*)){
    TNode *newnode;
    int stat;
    if(t != NULL){
        stat = cmp(data, t->item);
        if(stat <= 0){
            t->left = abpInsert(t, data, cmp);
        }else{
            t->right = abpInsert(t, data, cmp);
        }
        return t;
    }else{
        newnode = (TNode*)malloc(sizeof(TNode));
        if(newnode != NULL){
            newnode->item = data;
            newnode->left = newnode->right = NULL;
            return newnode;
        }else{
            return NULL;
        }
    }
}

TNode *abpCreate(){
    TNode *t;
    t = (TNode*)malloc(sizeof(TNode));
    if(t != NULL){
        t->item = NULL;
        t->right = NULL;
        t->left = NULL;
        return t;
    }
    return NULL;
}

/*
TNode *abpRemoveMenor(TNode *t, void *key, int(*cmp)(void*, void*), void **data){
    void *data2;
    if(t->left == NULL){
        data2 = t->item;
        free(t);
        return NULL;
    }else{
        return abpMenor(t->right, key, cmp, &data2);
    }
}
*/

TNode *abpRemove(TNode *t, void *key, int(*cmp)(void*, void*)){
    int stat;
    void *data2;
    void *aux;
    if(t != NULL){
        stat = cmp(key, t->item);
        if(stat < 0){
            t->left = abpRemove(t->left, key, cmp);
            return t;
        }else if(stat > 0){
            t->right = abpRemove(t->right, key, cmp);
        }else{
            if(t->left == NULL){
                aux = t->right;
                data2 = t->item;
                free(t);
                return aux;
            }else if(t->right == NULL){
                aux = t->left;
                data2 = t->item;
                free(t);
                return aux;
            }
           /* else{
                *data = t->item;
                t->right = abpRemoveMenor(t->right, key, cmp, &data2);
                return t;
            }
            */
        }
    }
    data2 = NULL;
    return NULL;
}

/*
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
*/