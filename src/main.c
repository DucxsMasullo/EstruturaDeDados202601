#include <stdio.h>
#include <stdlib.h>
#include "lse.h"


int main (void){
    printf("hello world");
    Nolse *head = NULL;

    for(int i=0;i<5;i++){
        addList(&head);
    }

    deleteList(&head);

    printlist(&head);
    scanf("%d", &head);
    
    
    

}    