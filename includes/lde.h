#ifndef LDE_H
#define LDE_H

typedef struct no {
    int dado;
    struct no *proximo;
    struct no *anterior;
} Nolde;

void add_ordened_lde(Nolde **head,int dado);
void add_not_ordened_lde(Nolde **head, int dado);
void delete_item_lde(Nolde **head, int dado);
void print_list_lde(Nolde *head);
void delete_list_lde(Nolde **head);


#endif