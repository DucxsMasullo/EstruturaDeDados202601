#include <stdio.h>
#include <stdlib.h>
#include "lde.h"

static Nolde* createnewnode(int dado){
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

static void createlde(Nolde **head, Nolde *newnode){
    *head = newnode;
    return;
}

static void addheadlde(Nolde **head, Nolde *newnode){
    newnode->proximo = *head;
    (*head)->anterior = newnode;
    *head = newnode;
}

static void addtaillde(Nolde **head, Nolde *newnode){
    Nolde *current = *head;
    while(current->proximo != NULL){
        current = current->proximo;
    }
    current->proximo = newnode;
    newnode->anterior = current;
}

static void addonleft(Nolde *current, Nolde *newnode){
    current->anterior->proximo = newnode;
    newnode->anterior = current->anterior;
    newnode->proximo = current;
    current->anterior = newnode;
}

static void addonright(Nolde *current, Nolde *newnode){
    current->proximo->anterior = newnode;
    newnode->proximo = current->proximo;
    newnode->anterior = current;
    current->proximo = newnode;
}

static void deletefirstnode(Nolde **head){
    if((*head)->proximo == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    else{
        *head = (*head)->proximo;
        free((*head)->anterior);
        (*head)->anterior=NULL;
        return;
    }
}

static void deletelastnode(Nolde **head){
    Nolde *current = *head;
    while (current->proximo != NULL){
        current = current->proximo;
    }
    current->anterior->proximo = NULL;
    free(current);
    return;
}

static void deletethisitem(Nolde *node){
    node->anterior->proximo = node->proximo;
    node->proximo->anterior = node->anterior;
    free(node);
    return;
}

void add_ordened_lde(Nolde **head,int dado){
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

void add_not_ordened_lde(Nolde **head, int dado){
    Nolde *newnode = createnewnode(dado);
    if(*head == NULL){
        createlde(head, newnode);
        return;
    }
    else{
        Nolde *current = *head;
        while(current->proximo != NULL){
            current = current->proximo;
        }
        current->proximo = newnode;
        newnode->anterior = current;
    }
}

void delete_item_lde(Nolde **head, int dado){
    if(*head == NULL){
        printf("\nlista vazia");
        return;
    }
    Nolde *current = *head;
    while(current->dado != dado && current->proximo != NULL){
        current = current->proximo;
    }
    if(current->dado != dado && current->proximo == NULL){
        printf("\ndado nao esta na lista\n");
    }
    else if(current->anterior == NULL){
        deletefirstnode(head);
    }
    else if(current->proximo == NULL){
        deletelastnode(head);
    }
    else if(current->dado == dado){
        deletethisitem(current);
    }
    return;
}

void print_list_lde(Nolde *head){
    if(head == NULL){
        printf("\nlista nao existe\n");
        return;
    }
    Nolde *current = head;
    int indice = 1;
    while(current != NULL){
        printf("Item %d  valor do item: \n", indice, current->dado);
        indice++;
        current = current->proximo;
    }
    return;
}
void delete_list_lde(Nolde **head){
    if (*head == NULL){
        return;
    }
    delete_list_lde(&(*head)->proximo);
    free(*head);
    *head = NULL;
}
