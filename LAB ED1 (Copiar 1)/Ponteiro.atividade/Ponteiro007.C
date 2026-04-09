#include <stdio.h>

int somavetor(int *vetor,int tamanhovetor){
    int soma=0;
    for(int contador=0; contador < tamanhovetor ;contador++){
     
    soma+= *(vetor+contador);
    }
    return soma;
}


int main(){

    int tamanho_vetor=0;
    int soma_dos_elementos=0;

    printf("Informe o tamanho do vetor:");
    scanf(" %d",&tamanho_vetor);

    int vetor[tamanho_vetor];
    int *pointer_vetor=vetor;
    printf("Informe os valores de cada posiçao do vetor\n");
    for(int contador=0; contador < tamanho_vetor ;contador++){
        scanf("%d",pointer_vetor+contador);
    }

    soma_dos_elementos=somavetor(pointer_vetor,tamanho_vetor);

    printf("Soma dos elementos do vertor igual a: %d\n",soma_dos_elementos);

    return 0;
}