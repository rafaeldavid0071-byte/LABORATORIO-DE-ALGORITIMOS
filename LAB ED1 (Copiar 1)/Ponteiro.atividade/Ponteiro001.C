#include <stdio.h>





int main(){

    int x=10;
    int *px=&x;

    printf("Valor de x: %d\n",x);
    printf("Endereço da memoria de x: %p\n",&x);
    printf("Valor armazenado em p: %d\n",*px);
    printf("Valor apontado por p: %p\n",px);

    return 0;
}