#include <stdio.h>
#include <stdlib.h>




int main() {
  
  
  
    int n;

    printf("Digite o numero de pessoas (max 100): ");
    scanf("%d", &n);

    if (n > 100 || n <= 0) {
        printf("Numero invalido!\n");
        return 1;
    }

    int *idades = (int *) malloc(n * sizeof(int));
    char **nomes = (char **) malloc(n * sizeof(char *));
    
    getchar();

    for (int contador = 0; contador < n; contador++) {
        nomes[contador] = (char *) malloc(100 * sizeof(char)); 

        printf("\nDigite o nome da pessoa %d: ", contador + 1);
        fgets(nomes[contador], 100, stdin);

        printf("Digite a idade: ");
        scanf("%d", &idades[contador]);
        getchar(); 
    }

    
    printf("\nNomes armazenados:\n\n");
    for (int contador = 0; contador < n; contador++) {
        printf("%s", nomes[contador]);
    }

    for (int contador = 0; contador < n; contador++) {
        free(nomes[contador]);
    }
    
    
    
    free(nomes);
    free(idades);



    return 0;
}