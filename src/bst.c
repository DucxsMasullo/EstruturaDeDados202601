#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

static Nobst* createnewnode(int dado){
    Nobst *newnode = (Nobst*)malloc(sizeof(Nobst));
    if(newnode == NULL){
        printf("\n erro ao alocar memoria\n");
        return NULL;
    }
    else{
        newnode->dado = dado;
        newnode->direita = NULL;
        newnode->esquerda = NULL;
        return newnode;
    }
}

static void putonright(Nobst *root, Nobst *newnode){
    root->direita = newnode;
    return;
}

static void putonleft(Nobst *root, Nobst *newnode){
    root->esquerda = newnode;
    return;
}

static void createtree(Nobst **root, Nobst *newnode){
    *root = newnode;
    return;
}

static void searchandput(Nobst **root, Nobst *newnode){
    if(newnode->dado == (*root)->dado){
        free(newnode);
        return;
    }
    if(newnode->dado < (*root)->dado){
        if((*root)->esquerda != NULL){
            searchandput(&(*root)->esquerda, newnode);
            return;
        }
        putonleft(*root, newnode);
        return;
    }
    if(newnode->dado > (*root)->dado){
        if((*root)->direita != NULL){
            searchandput(&(*root)->direita, newnode);
            return;
        }
        putonright(*root, newnode);
        return;
    }
}

void add_node_tree_user_entry(Nobst **root){
    int dado;
    Nobst *newnode = NULL;
    printf("\ninsira Valor do dado:");
    scanf("%d",&dado);
    newnode = createnewnode(dado);

    if(*root == NULL){
        createtree(root, newnode);
        return;
    }
    searchandput(root, newnode);
}

void print_bsl(Nobst **root){
    if(*root == NULL){
        printf("\nlista vazia");
        return;
    }
    if((*root)->esquerda == NULL){
        printf("\n dado:%d", (*root)->dado);
    }
    else{
        print_bsl(&(*root)->esquerda);
        printf("\n dado:%d", (*root)->dado);
    }
    if((*root)->direita != NULL){
        print_bsl(&(*root)->direita);
    }
} 

void delete_bsl(Nobst **root){
    if (*root == NULL){
        return;
    }

    delete_bsl(&(*root)->esquerda);
    delete_bsl(&(*root)->direita);

    free(*root);
    *root = NULL;
}