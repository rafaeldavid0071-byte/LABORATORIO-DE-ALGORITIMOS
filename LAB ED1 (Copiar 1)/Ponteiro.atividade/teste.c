#include <stdio.h>


int main(){


    int numero_1=0,numero_2=0;
    int resultado=0;


    printf("\n\nDigite o primeiro numero:\n");
    scanf("%d",&numero_1);

    printf("Digite o segundo numero:\n");
    scanf("%d",&numero_2);


    resultado = numero_1 + numero_2;


    printf("\nResultado: %d\n\n",resultado);
   
    return 0;
}