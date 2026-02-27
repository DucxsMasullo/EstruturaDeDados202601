#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"



int main (void){
    printf("hello world");
    Pilha *pilha = NULL;


    for(int i=0;i<4;i++){
        push_pilha(&pilha);
    }
    for(int i=0;i<5;i++){
        pop_item(&pilha);
    }

    scanf("%d", pilha);

    return 0;

}    