#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 100
#define TAM_LINHA 256

void exibirMenu() {
    printf("\n=== Editor de Texto ===\n");
    printf("1. Adicionar Linha de Texto\n");
    printf("2. Exibir Texto Atual\n");
    printf("3. Salvar em Arquivo\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

void adicionarLinha(char texto[MAX_LINHAS][TAM_LINHA], int *numLinhas) {
    if (*numLinhas >= MAX_LINHAS) {
        printf("Limite de linhas atingido! Nao e possivel adicionar mais texto.\n");
        return;
    }

    printf("Digite a linha de texto: ");
    getchar(); // Limpa o buffer do teclado
    fgets(texto[*numLinhas], TAM_LINHA, stdin);
    texto[*numLinhas][strcspn(texto[*numLinhas], "\n")] = '\0'; // Remove o '\n'

    (*numLinhas)++;
    printf("Linha adicionada com sucesso!\n");
}

void exibirTexto(char texto[MAX_LINHAS][TAM_LINHA], int numLinhas) {
    if (numLinhas == 0) {
        printf("Nenhum texto foi digitado ainda.\n");
        return;
    }

    printf("\n=== Texto Atual ===\n");
    for (int i = 0; i < numLinhas; i++) {
        printf("%s\n", texto[i]);
    }
}

void salvarEmArquivo(char texto[MAX_LINHAS][TAM_LINHA], int numLinhas) {
    if (numLinhas == 0) {
        printf("Nao ha texto para salvar.\n");
        return;
    }

    char nomeArquivo[TAM_LINHA];
    printf("Digite o nome do arquivo para salvar (ex: texto.txt): ");
    scanf("%s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numLinhas; i++) {
        fprintf(arquivo, "%s\n", texto[i]);
    }

    fclose(arquivo);
    printf("Texto salvo com sucesso em '%s'!\n", nomeArquivo);
}

int main() {
    char texto[MAX_LINHAS][TAM_LINHA];
    int numLinhas = 0;
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLinha(texto, &numLinhas);
                break;
            case 2:
                exibirTexto(texto, numLinhas);
                break;
            case 3:
                salvarEmArquivo(texto, numLinhas);
                break;
            case 4:
                printf("Saindo do editor de texto...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
