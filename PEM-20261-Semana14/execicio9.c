/*
 * Nome: Rodrigo Nogueira de Oliveira
 * RA: 2040482522005
 * Disciplina: Programacao Estruturada e Modular
 * Professor: Carlos Verissimo
 * Data: 29/05/2026
 * Exercício: 09 - Multiplicacao de Matrizes
 */

#include <stdio.h>
#define TAM 3

int main(void) {
    int a[TAM][TAM], b[TAM][TAM], c[TAM][TAM];
    int i, j, k;

    printf("Digite a matriz A:\n");
    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            scanf("%d", &a[i][j]);

    printf("Digite a matriz B:\n");
    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++) {
            c[i][j] = 0;
            for (k = 0; k < TAM; k++)
                c[i][j] += a[i][k] * b[k][j];
        }

    printf("\nMatriz A:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) printf("%6d", a[i][j]);
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) printf("%6d", b[i][j]);
        printf("\n");
    }

    printf("\nMatriz C (A x B):\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) printf("%6d", c[i][j]);
        printf("\n");
    }

    return 0;
}
