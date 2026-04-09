#include <stdio.h>

int maior_elemento(int *vetor,int tamanhovetor){
   
    int maior_numero=*vetor+0; 
   
    for(int contador=0; contador < tamanhovetor ;contador++){
   
        if(*(vetor+contador)> maior_numero){
            maior_numero= *(vetor+contador);
        }
    }
   
    return maior_numero;
}

int main(){

    int tamanho_vetor=0;
    int maior_valor=0;


    printf("Informe o tamanho do vetor:");
    scanf(" %d",&tamanho_vetor);

    int vetor[tamanho_vetor];
    int *pointer_vetor=&vetor[0];
    printf("Informe os valores de cada posiçao do vetor\n");
    for(int contador=0; contador < tamanho_vetor ;contador++){
        scanf("%d",pointer_vetor+contador);
    }


    maior_valor=maior_elemento(pointer_vetor,tamanho_vetor);

    printf("O maior elemento e: %d\n",maior_valor);





    return 0;
}