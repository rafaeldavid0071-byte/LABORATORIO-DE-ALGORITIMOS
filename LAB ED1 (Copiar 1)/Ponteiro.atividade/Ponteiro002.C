#include <stdio.h>





int main(){

    int n=5;
    int *ponteiro_n=&n;
    *ponteiro_n=20;

    printf("valor de n=%d\n",n);
    return 0;
}