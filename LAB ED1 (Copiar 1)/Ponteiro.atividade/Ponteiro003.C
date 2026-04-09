#include <stdio.h>

void soma_valores(int *a,int *b,int *resultado){

    *resultado=*a + *b;
    printf("Resultado: %d\n",*resultado);
}


int main(){

    int a=10,b=35,resultado;
    int *pointer_a=&a;
    int* pointer_b=&b;
    int *pointer_resultado=&resultado;


    soma_valores(pointer_a,pointer_b,pointer_resultado);

    return 0;
}