#include <stdio.h>

int main(){

    int x=10;
    int *pointer_x= &x;
    int **pointer_pointerx = &pointer_x;


    printf("Valor de x: %d\n",**pointer_pointerx);


    
    return 0;
}