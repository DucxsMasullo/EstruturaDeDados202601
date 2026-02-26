#include <stdio.h>
#include <stdlib.h>
#include "lde.h"

Nolde* createnewnode(int dado){
    Nolde *newnode = (Nolde*)malloc(sizeof(Nolde));
    if(newnode == NULL){
        printf("\nfalha ao criar novo node \n");
        return NULL;
    }
    else{
        newnode->anterior=NULL;
        newnode->proximo=NULL;

        newnode->dado = dado;

        return newnode;

    }
}

void createlde(Nolde **head, Nolde *newnode){
    *head = newnode;
    return;
}

void addheadlde(Nolde **head, Nolde *newnode){
    newnode->proximo = *head;
    (*head)->anterior = newnode;
    *head = newnode;
}

void addtaillde(Nolde **head, Nolde *newnode){
    Nolde *current = *head;
    while(current->proximo != NULL){
        current = current->proximo;
    }
    current->proximo = newnode;
    newnode->anterior = current;
}

void addonleft(Nolde *current, Nolde *newnode){
    current->anterior->proximo = newnode;
    newnode->anterior = current->anterior;
    newnode->proximo = current;
    current->anterior = newnode;
}

void addonright(Nolde *current, Nolde *newnode){
    current->proximo->anterior = newnode;
    newnode->proximo = current->proximo;
    newnode->anterior = current;
    current->proximo = newnode;
}


void devprint(Nolde **head){
    Nolde *current = *head;
    int item = 1;
    while(current !=NULL){
        printf("\nitem %d, valor do dado:%d", item, current->dado);
        item++;
        current = current->proximo;
    }
}

void addordenedlde(Nolde **head,int dado){
    Nolde *newnode = createnewnode(dado);
    if(*head == NULL){
        createlde(head,newnode);
        return;
    }
    else if(newnode->dado <= (*head)->dado){
        addheadlde(head,newnode);
        return;
    }
    else if((*head)->proximo == NULL){
        addtaillde(head, newnode);
        return;
    }
    else{
        Nolde *current = *head;
        while(current != NULL){
            if(newnode->dado <= current->dado){
                addonleft(current, newnode);
                return;
            }
            else{
                current = current->proximo;
            }
        }
        addtaillde(head, newnode);
        return;
    }

}