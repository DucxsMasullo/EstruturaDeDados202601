#ifndef LSE_H
#define LSE_H

typedef struct no {
    int dado;
    struct no *proximo;
} Nolse;

void addList(Nolse **head);
void removeItem(Nolse **head,int dado);
void printlist(Nolse **head);
void deleteList(Nolse **head);



#endif