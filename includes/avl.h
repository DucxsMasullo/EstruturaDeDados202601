#ifndef AVL_H
#define AVL_H

typedef struct no {
    int dado;
    int altura;
    int fb;
    struct no *esquerda;
    struct no *direita;
} Noavl;

void add_on_tree(Noavl **root);
void print_all_tree(Noavl **root);



#endif