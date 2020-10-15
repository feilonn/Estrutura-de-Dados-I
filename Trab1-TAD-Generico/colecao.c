#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"
//Funções da coleção

Colecao *colCriar(int maxItens){    
    Colecao *c;
    if(maxItens > 0){
        c = (Colecao*)malloc(sizeof(Colecao));
        if(c != NULL){
            c-> itens = (void**)malloc(sizeof(void*)*maxItens);
            if(c->itens != NULL){
                c->numItens = 0;
                c->maxItens = maxItens;
                return c;
            };
            free(c);
        };
    };
    return NULL;
};

int colDestruir(Colecao *c){
    if(c != NULL){
        if(c->itens != NULL){
            if(c->numItens == 0){
                free(c->itens);
                free(c);
                return 1;
            };
        };
    };
    return 0;
};

int colInserir(Colecao *c, void *item){
    if(c!= NULL){
        if(c->itens != NULL){
            if(c->maxItens <  c->maxItens - 1){
                c->itens[c->numItens] = item;
                c->numItens++;
                return 1;
            };
        };
    };
    return 0;
};


int cmp(void *elm, void *key){
    int *pelm = (int*)elm;
    int *pkey = (int *)key;

    if(*pelm == *pkey){
        return 1;
    }else{
        return 0;
    };  
};

void *colBusca(Colecao *c, void *key, int (*cmp)(void *, void *)){ 
    
    int i = 0;
    if(c!= NULL){
        if(c->itens != NULL){
            if(c->numItens > 0){
                while(cmp(c->itens[i], key) != 1){
                    i++;
                };
                if(cmp(c->itens[i], key) == 1){
                    return c->itens[i];
                };
            };
        };
    };
    return NULL;
};

void *colRemove(Colecao *c, void *key, int (*cmp)(void *, void *)){ 
    
    int i = 0;
    void* aux;
    if(c!= NULL){
        if(c->itens != NULL){
            if(c->numItens > 0){
                while(cmp(c->itens[i], key) != 1){
                    i++;
                };
                if(cmp(c->itens[i], key) == 1){
                    aux = c->itens[i];
                    while(i < c->numItens){
                        c-> itens[i] = c-> itens[i+1];
                        i++;
                    };
                    c->numItens--;
                    return aux; 
                };
            };
        };
    };
    return NULL;
};