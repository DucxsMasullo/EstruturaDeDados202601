#include <stdio.h>
#include <stdlib.h>
#include  "lse.h"

void addList(Nolse **head){
    //cria novo no
    Nolse *newnode = (Nolse*)malloc(sizeof(Nolse));
    int dado = 0;

    //verifica se alocou
    if(newnode == NULL){
        printf("\nerro ao alocar memoria\n");
        return ;
    }

    //preenche no
    else{
        printf("\n insira o dado:\n");
        scanf("%d",&dado);
        newnode->proximo = NULL;
        newnode->dado = dado;
    }

    //avalia onde inserir
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

    //trashcode pra garantir que usuario n tente excluir item de lista vazia
    if(current == NULL){
        printf("\n a lista nao tem itens\n");
        return ;
    }

    //busca até setar o no correto como current
    Nolse *previous = NULL;
    while(current->dado != dado && current->proximo != NULL){
        previous = current;
        current = current->proximo;
    }

    //avalia se precisa ajustar o head ou nao
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
    //é uma lista...sem comentarios
    while(temp != NULL){

        printf("\n item numero:%d dado:%d", indice, temp->dado);
        indice++;
        temp = temp->proximo;
    }
}

void deleteList(Nolse **head){
    Nolse *current = *head;
    //exclui usando uma variavel auxiliar para nao perder a lista
    while(current != NULL){
        Nolse *previous = current;
        current = current->proximo;
        free(previous);
    }
    *head = NULL;
    printf("\nlista deletada\n");
}