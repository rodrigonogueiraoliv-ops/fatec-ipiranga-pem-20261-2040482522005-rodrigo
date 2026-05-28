/******************************************************************************
 * Arquivo    : ex15.c
 * Aluno      : Rodrigo Nogueira de Oliveira
 * RA         : 2040482522005
 * Professor  : Carlos Veríssimo
 * Disciplina : Programação Estruturada e Modular (PEM-2026-01)
 * Semana     : 14 - Atividade de Consolidação
 * Data       : 29/05/2026
 * Tema       : T10 - Arquivos
 * Descrição  :
 *   Lê dados de um vetor, grava em arquivo binário e texto,
 *   depois lê novamente e exibe os dados salvos.
 * Compilação : gcc -Wall ex15.c -o ex15
 ******************************************************************************/
#include <stdio.h>
#define TAM 5

int main(void) {
    int numeros[TAM] = {10, 20, 30, 40, 50};
    int lidos[TAM];

    // Gravar em arquivo texto
    FILE *arqTxt = fopen("dados.txt", "w");
    for (int i = 0; i < TAM; i++) {
        fprintf(arqTxt, "%d\n", numeros[i]);
    }
    fclose(arqTxt);

    // Gravar em arquivo binário
    FILE *arqBin = fopen("dados.bin", "wb");
    fwrite(numeros, sizeof(int), TAM, arqBin);
    fclose(arqBin);

    // Ler do arquivo texto
    printf("Dados lidos do arquivo texto:\n");
    arqTxt = fopen("dados.txt", "r");
    for (int i = 0; i < TAM; i++) {
        fscanf(arqTxt, "%d", &lidos[i]);
        printf("%d ", lidos[i]);
    }
    fclose(arqTxt);
    printf("\n");

    printf("Arquivo 'dados.txt' e 'dados.bin' foram gerados com sucesso!\n");
    return 0;
}
