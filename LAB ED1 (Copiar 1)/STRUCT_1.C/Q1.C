#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[50];
    float salario;
    int identificador;
    char cargo[30];
} Funcionario;


void preencherFuncionario(Funcionario *f) {
    printf("Nome: ");
    scanf(" %[^\n]", f->nome);
    printf("Salario: ");
    scanf("%f", &f->salario);
    printf("Identificador (ID): ");
    scanf("%d", &f->identificador);
    printf("Cargo: ");
    scanf(" %[^\n]", f->cargo);
}


void mostrarfuncionario(Funcionario *f) {
    printf("\nID: %d | Nome: %s | Cargo: %s | Salario: R$ %.2f",f->identificador, f->nome, f->cargo, f->salario);

}


void alterarSalario(Funcionario *f, float novoSalario) {
    
    f->salario = novoSalario;
}


void maiorMenorSalario(Funcionario vetor[], int numero_funcionarios) {
    int maior_salario = 0, menor_salario = 0;
    for(int contador = 1; contador < numero_funcionarios; contador++) {
        if(vetor[contador].salario > vetor[maior_salario].salario){
        
            maior_salario = contador;
     }
        if(vetor[contador].salario < vetor[menor_salario].salario){ 
        
            menor_salario = contador;
        }
    }
   
    printf("\n\n--- RELATORIO DE SALARIOS ---");

    printf("\nMAIOR SALARIO -> Cargo: %s | Valor: R$ %.2f", vetor[maior_salario].cargo, vetor[maior_salario].salario);
    printf("\nMENOR SALARIO -> Cargo: %s | Valor: R$ %.2f\n", vetor[menor_salario].cargo, vetor[menor_salario].salario);

}


int main() {
   
    int numero_funcionarios = 2; 
    Funcionario equipe[numero_funcionarios];
    float novosalario;
    
    //entendi
    for(int contador = 0; contador < numero_funcionarios ;contador++) {
        printf("\n--- Cadastro do Funcionario %d --- \n", contador + 1);
        preencherFuncionario(&equipe[contador]);
    }//
    
    //entendi
    printf("\n\n>>> Dados Originais:");
    for(int contador = 0; contador < numero_funcionarios ;contador++) {
        mostrarfuncionario(&equipe[contador]);
    }//

    //entendi
    printf("\n\n--- ATUALIZACAO DE SALARIOS ---");
    for(int contador = 0; contador < numero_funcionarios ;contador++) {
        printf("\nDigite o novo salario para %s (ID: %d): ", equipe[contador].nome, equipe[contador].identificador);
        scanf("%f", &novosalario);
        
       
        alterarSalario(&equipe[contador], novosalario);
    }//

    //entendi
    printf("\n\n>>> Dados Apos Atualizacao:");
    for(int contador = 0; contador < numero_funcionarios ;contador++) {
        mostrarfuncionario(&equipe[contador]);
    }//

 
    maiorMenorSalario(equipe, numero_funcionarios);

    return 0;
}