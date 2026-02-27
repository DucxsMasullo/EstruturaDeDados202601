#include <stdio.h>
#include <stdlib.h>
#include "lde.h"



int main (void){
    printf("hello world");
    Nolde *head = NULL;

    for(int i=0;i<7;i++){
        int dado = 0;
        printf("insira dado\n");
        scanf("%d", &dado);
        add_not_ordened_lde(&head, dado);
    }
    

    delete_list_lde(&head);

    print_list_lde(head);
    scanf("%d", head);
    return 0;

}    