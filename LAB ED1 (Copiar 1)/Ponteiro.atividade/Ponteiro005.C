#include <stdio.h>


int maior(int *a,int *b){
    if(*a>*b){
        return *a;
    }
    else{
        return *b;
    }
}

int main(){

    int a=0,b=0,resultado=0;

    int * pointer_a=&a;
    int * pointer_b=&b;

    printf("Digite os valores de A e B\n");
    scanf("%d%d",pointer_a,pointer_b);
    resultado=maior(pointer_a,pointer_b);
    printf("Maior numero: %d\n",resultado);





    return 0;
}