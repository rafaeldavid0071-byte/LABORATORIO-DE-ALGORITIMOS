#include <stdio.h>
#include <string.h>

// Definição da estrutura
struct pessoa {
    char nome[81];
    int documento;
    int idade;
};
typedef struct pessoa Pessoa;

// a) Função para preencher os dados
void preenche_pessoa(Pessoa *p) {
    printf("\n--- Cadastro ---\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]s", p->nome);
    printf("Digite o documento: ");
    scanf("%d", &p->documento);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
}

// b) Função para imprimir uma única pessoa
void imprime_pessoa(Pessoa *p) {
    printf("\nNome: %-20s | Doc: %-8d | Idade: %d", p->nome, p->documento, p->idade);
}

// c) Função para atualizar as idades de todos
void atualiza_todas_idades(Pessoa *vetor, int tamanho) {
    printf("\n\n>>> ATUALIZANDO IDADES DE TODOS <<<");
    for (int contador = 0; contador < tamanho; contador++) {
        Pessoa *pointer_atual = &vetor[contador]; // Seu estilo: ponteiro explícito
        printf("\nDigite a nova idade para %s: ", pointer_atual->nome);
        scanf("%d", &pointer_atual->idade);
    }
}

// d) NOVA FUNÇÃO: Encontra e imprime a pessoa mais velha e a mais nova
void imprime_mais_velha_e_nova(Pessoa *vetor, int tamanho) {
    // Começamos apontando para a primeira pessoa como sendo a mais velha e a mais nova
    Pessoa *p_velha = &vetor[0];
    Pessoa *p_nova = &vetor[0];

    for (int contador = 1; contador < tamanho; contador++) {
        Pessoa *p_atual = &vetor[contador]; // Ponteiro para a pessoa da iteração atual

        // Comparação de idades usando os ponteiros
        if (p_atual->idade > p_velha->idade) {
            p_velha = p_atual;
        }
        if (p_atual->idade < p_nova->idade) {
            p_nova = p_atual;
        }
    }

   
    printf("\nA pessoa mais VELHA e: %s com %d anos.", p_velha->nome, p_velha->idade);
    printf("\nA pessoa mais NOVA e: %s com %d anos.", p_nova->nome, p_nova->idade);
   
}

int main() {
    int n = 3; 
    Pessoa grupo[n];
    
    
    for (int contador = 0; contador < n; contador++) {
        preenche_pessoa(&grupo[contador]);
    }

    
    printf("\n--- Lista Original ---");
    for (int contador = 0; contador < n; contador++) {
        imprime_pessoa(&grupo[contador]);
    }

    atualiza_todas_idades(grupo, n);

    // 4. Lista atualizada
    printf("\n--- Lista Atualizada ---");
    for (int contador = 0; contador < n; contador++) {
        imprime_pessoa(&grupo[contador]);
    }

    
    imprime_mais_velha_e_nova(grupo, n);

    return 0;
}