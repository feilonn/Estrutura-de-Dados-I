#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"

typedef struct _colecao_{
    int numItens;
    int maxItens;
    void **itens;
}Colecao;

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
            }
            free(c);
        }
    }
    return NULL;
}

int colDestruir(Colecao *c){
    if(c != NULL){
        if(c->itens != NULL){
            if(c->numItens == 0){ // Verifica se a cole��o esta vazia para poder destruir
                free(c->itens); // Libera vetor da colecao
                free(c);        // Libera colecao
                return 1;
            }
        }
    }
    return 0;
}

int colInserir(Colecao *c, void *item){
    if(c!= NULL){
        if(c->itens != NULL){
          //  if(c->maxItens <  c->maxItens - 1){ //Verifica se ainda � possivel inserir um item
            if(c->numItens <  c->maxItens){ //Verifica se ainda � possivel inserir um item
                c->itens[c->numItens] = item;
                c->numItens++; // Um iten foi inserido, numItens incrementa
                return 1;
            }
        }
    }
    return 0;
}

void *colBusca(Colecao *c, void *key, int(*cmp)(void* elm, void* key)){
       
    if(c!= NULL){
        if(c->itens != NULL){
            if(c->numItens > 0){
                for(int i = 0; i < c->numItens; i++){
                    if(cmp(c->itens[i], key) == 1){
                        return key;
                    }
                }
            }
        }
    }
    return NULL;
}

void *colRemove(Colecao *c, void *key, int(*cmp)(void* elm, void* key)){

    void* aux;

    if(c!= NULL){
        if(c->itens != NULL){
            if(c->numItens > 0){
                for(int i = 0; i < c->numItens; i++){
                    if(cmp(c->itens[i], key) == 1){
                        aux = c->itens[i];
                        while(i < c->numItens){
                            c->itens[i] = c->itens[i+1];
                            i++;
                        }
                        c->numItens--;
                        return aux;
                    }
                }
            }
        }
    }
    return NULL;
}

void *mostraPlayer(Colecao *c, void (*mostraTodos)(void* elm)){
    if(c != NULL){
        if(c->itens != NULL){
            if(c->numItens > 0){
                 for(int i = 0; i < c->numItens; i++){
                    mostraTodos(c->itens[i]);
                }
            }
        }
    }
    return NULL; 
} 





/*
int cmpNome(void *elm, void *key){ // Funcao compara baseada no nome(char)
    char *pkey = (char*)key;
    Jogador *pelm = (Jogador*)elm;

    if(*pkey == pelm->nome){
        return 1;
    }else{
        return 0;
    };
};
int cmpMedia(void *elm, void *key){ // Funcao compara baseada na media de pontos por partida(float)
    float *pkey = (float*)key;
    Jogador *pelm = (Jogador*)elm;

    if(*pkey == pelm->mediaPontos){
        return 1;
    }else{
        return 0;
    };
};
*/