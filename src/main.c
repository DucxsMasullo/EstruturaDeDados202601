#include <stdio.h>
#include <stdlib.h>
#include "fila.h"



int main (void){
    printf("hello world");
    int cntrl;
    Fila *fila = NULL;
    
    for(int i=0;i<4;i++){
        enqueu(&fila);
    }

    dequeu(&fila);

    print_queu(&fila);

    scanf("%d", &cntrl);

    return 0;

}    