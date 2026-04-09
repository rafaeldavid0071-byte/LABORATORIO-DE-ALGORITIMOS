#include <stdio.h>
#include <stdlib.h>




int main(){


    int tamanho_vetor=0;

    printf("Informe o tamanho do vetor\n");
    scanf("%d",&tamanho_vetor);

    int *vetor=(int *)malloc(tamanho_vetor * sizeof(int));

        if (vetor==NULL){
            printf("erro de alocaçao");
            return 1;
        }else{
    printf("Informe os valores de cada posiçao do vetor\n");

    for(int contador=0; contador < tamanho_vetor ;contador++){
    
         scanf("%d",vetor+contador);

    }
    printf("\n");

    for(int contador=0; contador < tamanho_vetor ;contador++){
    
        int contador1;
        contador1 = tamanho_vetor -1 - contador;
        printf("%d\n",*(vetor+contador1));
         
    }
        }

    free(vetor);
    return 0;

}