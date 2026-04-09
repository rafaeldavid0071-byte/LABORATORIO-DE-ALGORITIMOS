#include <stdio.h>
#include <stdlib.h>




int main(){


    int tamanho_vetor=0;
    float soma=0;
    float media=0;
    
    printf("Informe o tamaho do vetor\n");
    scanf("%d",&tamanho_vetor);
   
    int *vetor= (int *) malloc(tamanho_vetor * sizeof(int));

    if (vetor== NULL){
        printf("erro\n");

    }
    else{

        printf("Informe os valores de cada elemento do vetor\n");
        for(int contador=0; contador < tamanho_vetor ;contador++){
            scanf("%d",vetor+contador);
            soma += *(vetor+contador);
        }
    }
   
    media= soma / tamanho_vetor;

    printf("Media: %.4f",media);

    free(vetor);

    
    return 0;
}