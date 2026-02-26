#include <stdio.h>
#include <stdlib.h>
#include "lde.h"



int main (void){
    printf("hello world");
    Nolde *head = NULL;

    for(int i=0;i<6;i++){
        int dado = 0;
        printf("insira dado\n");
        scanf("%d", &dado);
        addordenedlde(&head,dado);
    }

    devprint(&head);
    scanf("%d", head);
    return 0;

}    