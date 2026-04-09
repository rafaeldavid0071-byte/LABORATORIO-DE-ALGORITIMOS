#include <stdio.h>


void inverter(int *vetor,int tamanhovetor){
    int vetor_invertido[tamanhovetor];

    for(int contador=0; contador < tamanhovetor ;contador++){
    
    int contador1= tamanhovetor - 1 -contador;
        
    *(vetor_invertido + contador1)= *(vetor+contador);
    }
    for(int contador=0; contador < tamanhovetor ;contador++){
        printf("%d\n",vetor_invertido[contador]);
    }
    //funçao feita com juda do chatgpt :(
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
    printf("\n");
    inverter(pointer_vetor,tamanho_vetor);
    

    return 0;
}