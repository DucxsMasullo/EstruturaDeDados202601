#include <stdio.h>
#include <stdlib.h>
#include "bst.h"



int main (void){
    printf("hello world\n");
    int cntrl;
    Nobst *root = NULL;

    for(int i=0;i<4;i++){
        add_node_tree_user_entry(&root);
    }

    print_bsl(&root);
    delete_bsl(&root);
    print_bsl(&root);

    

    scanf("%d", &cntrl);

    return 0;

}    