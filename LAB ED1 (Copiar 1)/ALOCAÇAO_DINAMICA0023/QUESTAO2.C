#include <stdio.h>
#include <stdlib.h>





int main() {
   
   
   
    int linhas=0, colunas=0;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro de alocaçao!\n");
        return 1;
    }

    for (int contador1 = 0; contador1 < linhas; contador1++) {
        matriz[contador1] = (int *) malloc(colunas * sizeof(int));
        if (matriz[contador1] == NULL) {
            printf("Erro de alocaçao!\n");
            return 1;
        }
    }

    printf("\nDigite os elementos da matriz:\n");
    
    for (int contador1=0; contador1 < linhas ;contador1++){
        for (int contador2 = 0; contador2 < colunas ;contador2++){
            printf("Elemento [%d][%d]: ", contador1, contador2);
            scanf("%d", &matriz[contador1][contador2]);
        }
    }

    printf("\nMatriz original:\n");
    for (int contador1 = 0; contador1 < linhas; contador1++){
        for (int contador2 = 0; contador2 < colunas; contador2++){
            printf("%d ", matriz[contador1][contador2]);
        }
        printf("\n");
    }

    printf("\nMatriz transposta:\n");
    for (int contador1 = 0; contador1 < colunas; contador1++){
        for (int contador2 = 0; contador2 < linhas; contador2++){
            printf("%d ", matriz[contador2][contador1]);
        }
        printf("\n");
    }

    for (int contador1 = 0; contador1 < linhas; contador1++){
        free(matriz[contador1]);
    }
    free(matriz);

    return 0;
}