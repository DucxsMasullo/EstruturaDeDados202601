#ifndef PILHA_H
#define PILHA_H

typedef struct no {
    int dado;
    struct no *anterior;
} Pilha;

void push_pilha(Pilha **pilha);
void pop_item(Pilha **pilha);
void seek_pilha(Pilha *pilha);

#endif