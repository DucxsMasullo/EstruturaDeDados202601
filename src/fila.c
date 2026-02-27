#include <stdio.h>
#include<stdlib.h>
#include "fila.h"

static Fila* createnewnode(int dado){
    Fila *newnode = (Fila*)malloc(sizeof(Fila));
    if(newnode == NULL){
        printf("\n erro ao alocar memoria\n");
        return NULL;
    }
    else{
        newnode->dado = dado;
        newnode->proximo = NULL;
        return newnode;
    }
}

void enqueu(Fila **head){
    int dado;
    printf("\n insira dado : ");
    scanf("%d", &dado);
    Fila *newnode = createnewnode(dado);
    if(*head == NULL){
        *head = newnode;
    }
    else{
        Fila *current = *head;
        while(current->proximo != NULL){
            current = current->proximo;
        }
        current->proximo = newnode;
    }
    return;
}

void dequeu(Fila **head){
    if(*head == NULL){
        return;
    }
    Fila *current = *head;
    if(current->proximo != NULL){
        *head = current->proximo;
        free(current);
    }
    else{
        free(*head);
        *head = NULL;
    }
}

void print_queu(Fila **head){
    Fila *current = *head;
    while(current != NULL){
        printf("dado : %d\n", current->dado);
        current = current->proximo;
    }
}
