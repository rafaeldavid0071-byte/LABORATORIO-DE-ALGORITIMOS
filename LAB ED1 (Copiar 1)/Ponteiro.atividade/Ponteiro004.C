#include <stdio.h>

void troca(int *a,int *b){
    int var=0;
    var=*a;
    *a=*b;
    *b=var; 
    printf("Valor A: %d\n",*a);
    printf("Valor B: %d\n",*b);

}


int main(){


    int a=50;
    int b=100;
    int *pointer_a=&a;
    int *pointer_b=&b;

    troca(pointer_a,pointer_b);


    return 0;    
}