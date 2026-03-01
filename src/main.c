#include <stdio.h>
#include <stdlib.h>
#include "avl.h"



int main (void){
    printf("hello world\n");
    int cntrl;
    Noavl *root = NULL;

    for(int i=0;i<10;i++){
        add_on_tree(&root);
    }

    print_all_tree(&root);

    scanf("%d", &cntrl);

    return 0;

}    