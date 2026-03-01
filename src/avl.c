#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

static Noavl* createnewnode(int dado){
    Noavl *newnode = (Noavl*)malloc(sizeof(Noavl));
    if(newnode == NULL){
        printf("\n falha ao alocar memoria \n ");
        return NULL;
    }
    else{
        newnode->altura = 1;
        newnode->fb = 0;
        newnode->dado = dado;
        newnode->esquerda = NULL;
        newnode->direita = NULL;
        return newnode;
    }
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static void attdados(Noavl *root){
int leftHeight  = root->esquerda ? root->esquerda->altura : 0;
int rightHeight = root->direita  ? root->direita->altura  : 0;

root->altura = max(leftHeight, rightHeight) + 1;
root->fb = leftHeight - rightHeight;

}

static void rr(Noavl **root){
    Noavl *newroot = (*root)->direita;
            (*root)->direita = newroot->esquerda;
            newroot->esquerda = *root;

            attdados(*root);
            attdados(newroot);

            *root = newroot;
}

static void ll(Noavl **root) {
    Noavl *newRoot = (*root)->esquerda;
    (*root)->esquerda = newRoot->direita;
    newRoot->direita = *root;

    attdados(*root);
    attdados(newRoot);

    *root = newRoot;
}

static void rl(Noavl **root){
    ll(&(*root)->direita);
    rr(root);
}

static void lr(Noavl **root){
    rr(&(*root)->esquerda);
    ll(root);
}

static void balanceroot(Noavl **root){
    if((*root)->fb == -2){
        if((*root)->direita->fb <= 0){
            rr(root);
        }
        else if((*root)->direita->fb > 0){
            rl(root);
        }
    }
    else if ((*root)->fb == 2){
        if((*root)->esquerda->fb >= 0){
            ll(root);
        }
        else if((*root)->esquerda->fb <0){
            lr(root);
        }
    }
}

static void insert(Noavl **root, Noavl *newnode){
    if(newnode->dado == (*root)->dado){
        free(newnode);
        printf("\n dado ja existe\n");
        return;
    }

    if(newnode->dado < (*root)->dado){
        if((*root)->esquerda != NULL){
            insert(&(*root)->esquerda, newnode);
            attdados(*root);
        }
        else{
            (*root)->esquerda = newnode;
            attdados(*root);
        }
    }
    else if(newnode->dado > (*root)->dado){
        if((*root)->direita != NULL){
            insert(&(*root)->direita, newnode);
            attdados(*root);
        }
        else{
            (*root)->direita = newnode;
            attdados(*root);
        }
    }

    if((*root)->fb <-1 || (*root)->fb >1){
        balanceroot(root);
    } 
}

void add_on_tree(Noavl **root){
    int dado;
    printf("\n insira dado :");
    scanf("%d", &dado);
    Noavl *newnode = createnewnode(dado);


    if(*root == NULL){
        *root = newnode;
        return;
    }
    else{
        insert(root, newnode);
        return;
    }
}

void print_all_tree(Noavl **root){
    if((*root)->esquerda == NULL){
        printf("dado : %d\naltura do node:%d\nfb do node:%d\n", (*root)->dado, (*root)->altura, (*root)->fb);
        printf("==========\n");
    }
    else{
        print_all_tree(&(*root)->esquerda);
        printf("dado : %d\naltura do node:%d\nfb do node:%d\n", (*root)->dado, (*root)->altura, (*root)->fb);
        printf("==========\n");
    }
    if((*root)->direita !=NULL){
        print_all_tree(&(*root)->direita);
    }
}