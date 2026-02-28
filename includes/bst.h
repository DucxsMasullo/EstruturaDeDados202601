#ifndef BST_H
#define BST_H

typedef struct no {
    int dado;
    struct no *esquerda;
    struct no *direita;
} Nobst;

void add_node_tree_user_entry(Nobst **root);
void print_bsl(Nobst **root);
void delete_bsl(Nobst **root);


#endif