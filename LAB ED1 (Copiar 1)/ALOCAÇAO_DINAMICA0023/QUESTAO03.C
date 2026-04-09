#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main() {
  
    int n;

    printf("Digite a ordem da matriz (n): ");
    scanf("%d", &n);

    int **matriz = (int **) malloc(n * sizeof(int *));
    
    for (int contador = 0; contador < n; contador++) {
        matriz[contador] = (int *) malloc(n * sizeof(int));
    }

 
    srand(time(NULL));

  
    for (int contador = 0; contador < n; contador++) {
        for (int contador1 = 0; contador1 < n; contador1++) {
            matriz[contador][contador1] = rand() % 100 + 1;
        }
    }

    printf("\nMatriz gerada:\n\n");
    for (int contador = 0; contador < n; contador++) {
        for (int contador1 = 0; contador1 < n; contador1++) {
            printf("%d\t ", matriz[contador][contador1]);
        }
        printf("\n");
    }

    for (int contador = 0; contador < n; contador++) {
        free(matriz[contador]);
    }
    
    free(matriz);

    return 0;
}