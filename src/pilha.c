#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

static Pilha* createnewnode(int dado){
    Pilha *newnode = (Pilha*)malloc(sizeof(Pilha));
    if(newnode == NULL){
        printf("\nerro ao alocar memoria");
        return NULL;
    }
    else{
        newnode->dado = dado;
        newnode->anterior = NULL;
        return newnode;
    }
}

void push_pilha(Pilha **pilha){
    int dado;
    printf("\n insira dado : ");
    scanf("%d", &dado);
    Pilha *newnode = createnewnode(dado);
    newnode->anterior = *pilha;
    *pilha = newnode;
}

void pop_item(Pilha **pilha){
    if(*pilha != NULL){
        Pilha *current = *pilha;
        printf("\n dado removido foi : %d", current->dado);
        *pilha = current->anterior;
        free(current);
    }
    else{
        printf("\nnao ha nada na pilha\n");
    }
}

void seek_pilha(Pilha *pilha){
    printf("valor do item: %d", pilha->dado);
}
