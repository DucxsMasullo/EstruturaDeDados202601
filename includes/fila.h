#ifndef FILA_H
#define FILA_H

typedef struct no {
    int dado;
    struct no *proximo;
} Fila;

void enqueu(Fila **head);
void dequeu(Fila **head);
void print_queu(Fila **head);


#endif