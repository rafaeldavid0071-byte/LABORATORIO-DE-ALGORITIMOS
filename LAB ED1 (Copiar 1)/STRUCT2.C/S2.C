#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 3
#define MAX_TURMAS 2

// Definição das Estruturas (conforme o PDF)
struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma {
    char id;
    int vagas;
    Aluno* alunos[MAX_VAGAS]; // Vetor de ponteiros para alunos
};
typedef struct turma Turma;

// --- FUNÇÕES (Seguindo o seu estilo de lógica clara) ---

// a) Cria uma turma e limpa os ponteiros de alunos
Turma* cria_turma(char id) {
    Turma* nova_turma = (Turma*) malloc(sizeof(Turma));
    if (nova_turma != NULL) {
        nova_turma->id = id;
        nova_turma->vagas = MAX_VAGAS;
        // Seu estilo: inicializando cada ponteiro com NULL para segurança
        for (int i = 0; i < MAX_VAGAS; i++) {
            nova_turma->alunos[i] = NULL;
        }
    }
    return nova_turma;
}

// b) Matricula um aluno em uma vaga disponível
void matricula_aluno(Turma* turma, int mat, char* nome) {
    if (turma->vagas <= 0) {
        printf("Nao ha vagas disponiveis na turma %c!\n", turma->id);
        return;
    }

    // Alocando memória para o novo aluno
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    novo_aluno->mat = mat;
    strcpy(novo_aluno->nome, nome);
    novo_aluno->notas[0] = 0;
    novo_aluno->notas[1] = 0;
    novo_aluno->notas[2] = 0;
    novo_aluno->media = 0;

    // Colocando o aluno na primeira vaga (NULL) encontrada
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] == NULL) {
            turma->alunos[i] = novo_aluno;
            turma->vagas--; // Diminui o contador de vagas
            printf("Aluno matriculado com sucesso!\n");
            break;
        }
    }
}

// c) Lança notas e calcula média
void lanca_notas(Turma* turma) {
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            Aluno* p_aluno = turma->alunos[i]; // Ponteiro auxiliar no seu estilo
            printf("Matricula: %d Aluno: %s\n", p_aluno->mat, p_aluno->nome);
            
            float soma = 0;
            for (int j = 0; j < 3; j++) {
                printf("Digite a nota %d: ", j + 1);
                scanf("%f", &p_aluno->notas[j]);
                soma += p_aluno->notas[j];
            }
            p_aluno->media = soma / 3.0;
        }
    }
}

// d) Imprime alunos de uma turma específica
void imprime_alunos(Turma* turma) {
    printf("Listando alunos...\n");
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("Matricula: %d\nNome: %s\nMedia: %.1f\n", 
                   turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
        }
    }
}

// e) Imprime todas as turmas existentes
void imprime_turmas(Turma** turmas, int n) {
    printf("Listando turmas...\n");
    for (int i = 0; i < n; i++) {
        if (turmas[i] != NULL) {
            printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas);
        }
    }
}

// f) Procura uma turma pelo ID
Turma* procura_turma(Turma** turmas, int n, char id) {
    for (int i = 0; i < n; i++) {
        if (turmas[i] != NULL && turmas[i]->id == id) {
            return turmas[i];
        }
    }
    return NULL;
}

// --- MAIN COM MENU DE INTERAÇÃO ---

int main() {
    Turma* lista_turmas[MAX_TURMAS];
    for(int i=0; i<MAX_TURMAS; i++) lista_turmas[i] = NULL;
    
    int num_turmas_criadas = 0;
    int opcao = 0;

    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Autor: Seu Nome Versao: 1.0\n");

    while (opcao != 6) {
        printf("\nMENU:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (num_turmas_criadas < MAX_TURMAS) {
                char id;
                printf("Criando nova turma...\nDigite um id: ");
                scanf(" %c", &id);
                lista_turmas[num_turmas_criadas] = cria_turma(id);
                printf("Turma %c criada com sucesso!\n", id);
                num_turmas_criadas++;
            } else {
                printf("Limite de turmas atingido!\n");
            }
        } 
        else if (opcao == 2) {
            imprime_turmas(lista_turmas, num_turmas_criadas);
        }
        else if (opcao == 3) {
            char id;
            int mat;
            char nome[81];
            printf("Matriculando aluno...\nDigite o id da turma: ");
            scanf(" %c", &id);
            Turma* t = procura_turma(lista_turmas, num_turmas_criadas, id);
            if (t) {
                printf("Digite a matricula: \n");
                scanf("%d", &mat);
                printf("Digite o nome: \n");
                scanf(" %[^\n]s", nome); // Lê nome com espaços
                matricula_aluno(t, mat, nome);
            } else {
                printf("Turma inexistente!\n");
            }
        }
        else if (opcao == 4) {
            char id;
            printf("Lancando notas...\nDigite o id da turma: ");
            scanf(" %c", &id);
            Turma* t = procura_turma(lista_turmas, num_turmas_criadas, id);
            if (t) lanca_notas(t);
            else printf("Turma inexistente!\n");
        }
        else if (opcao == 5) {
            char id;
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            Turma* t = procura_turma(lista_turmas, num_turmas_criadas, id);
            if (t) imprime_alunos(t);
            else printf("Turma inexistente!\n");
        }
    }

    printf("Obrigado por usar este programa!\n");
    return 0;
}