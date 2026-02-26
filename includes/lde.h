#ifndef LDE_H
#define LDE_H

typedef struct no {
    int dado;
    struct no *proximo;
    struct no *anterior;
} Nolde;

Nolde* createnewnode(int dado);
void addheadlde(Nolde **head, Nolde *newnode);
void addtaillde(Nolde **head, Nolde *newnode);
void addonleft(Nolde *current, Nolde *newnode);
void addonright(Nolde *current, Nolde *newnode);
void addordenedlde(Nolde **head,int dado);
void devprint(Nolde **head);


#endif