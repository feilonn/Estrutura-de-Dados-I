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
            if(c->numItens == 0){ // Verifica se a coleção esta vazia para poder destruir
                free(c->itens); // Libera vetor da colecao
                free(c);        // Libera colecao
                return 1;
            };
        };
    };
    return 0;
};

int colInserir(Colecao *c, void *item){
    if(c!= NULL){
        if(c->itens != NULL){
            if(c->maxItens <  c->maxItens - 1){ //Verifica se ainda é possivel inserir um item
                c->itens[c->numItens] = item;
                c->numItens++; // Um iten foi inserido, numItens incrementa
                return 1;
            };
        };
    };
    return 0;
};


int cmp(void *elm, void *key){ // Funcao compara baseada na matricula(int)
    int *pkey = (int *)key;
    Jogador *pelm = (Jogador*)elm;

    if(*pkey == pelm->matricula){
        return 1;
    }else{
        return 0;
    };  
};

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
void *colBusca(Colecao *c, void *key){ 
    
    void* aux;
    int buscaMatricula;

    if(c!= NULL){
        if(c->itens != NULL){
            if(c->numItens > 0){
                for(int i = 0; i < c->numItens; i++){
                    buscaMatricula = cmp(c->itens[i], key); // chamada da função cmp para matricula(int)
                    if(buscaMatricula == 1){
                        aux = c->itens[i];
                        return aux;
                    };
                };
            };
        };
    };
    return NULL;
};

void *colRemove(Colecao *c, void *key){ 
    
    void* aux;
    int removeComMatricula;

    if(c!= NULL){
        if(c->itens != NULL){
            if(c->numItens > 0){
                for(int i = 0; i < c->numItens; i++){ // busca o item para remover
                    removeComMatricula = cmp(c->itens[i], key);
                    if(removeComMatricula == 1){ 
                        aux = c->itens[i];
                        for(int j = i; j < c->numItens; j++){  // Um item saiu, os outros tambem atualizam a posicao
                            c->itens[j] = c->itens[j+1];
                        };
                        c->numItens--; // Um item sai, numItens decrementa
                        return aux;
                    };
                };
            };
        };
    };
    return NULL;
};
