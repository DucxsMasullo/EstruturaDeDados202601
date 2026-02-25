#include <stdio.h>
#include <stdlib.h>
#include  "lse.h"

void addList(Nolse **head){
    Nolse *newnode = (Nolse*)malloc(sizeof(Nolse));
    int dado = 0;
    if(newnode == NULL){
        printf("\nerro ao alocar memoria\n");
        return ;
    }
    else{
        printf("\n insira o dado:\n");
        scanf("%d",&dado);
        newnode->proximo = NULL;
        newnode->dado = dado;
    }
    if(*head == NULL){
        *head = newnode;
    }
    else{
        Nolse *current = *head;
        while(current->proximo != NULL){
            current = current->proximo;
        }
        current->proximo = newnode;

    }
}

void removeItem(Nolse **head,int dado){
    Nolse *current = *head;
    Nolse *previous = NULL;
    while(current->dado != dado && current->proximo != NULL){
        previous = current;
        current = current->proximo;
    }
    if(current->dado != dado){
        printf("\ndado nao existe na lista\n");
    }
    else{
        if(current == *head){
            *head = current->proximo;
            free(current);
        }
        else{
            previous->proximo = current->proximo;
            free(current);
        }
    }

}

void printlist(Nolse **head){
    Nolse *temp = *head;
    int indice = 1;
    while(temp != NULL){

        printf("\n item numero:%d dado:%d", indice, temp->dado);
        indice++;
        temp = temp->proximo;
    }
}

void deleteList(Nolse **head){
    Nolse *current = *head;
    while(current != NULL){
        Nolse *previous = current;
        current = current->proximo;
        free(previous);
    }
    *head = NULL;
    printf("\nlista deletada\n");
}