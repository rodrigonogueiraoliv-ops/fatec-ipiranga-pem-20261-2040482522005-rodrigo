/*
 * Nome: Rodrigo Nogueira de Oliveira
 * RA: 2040482522005
 * Disciplina: Programacao Estruturada e Modular
 * Professor: Carlos Verissimo
 * Data: 29/05/2026
 * Exercício: 10 - Jogo da Memoria - Analise de Tabuleiro
 */

#include <stdio.h>
#define TAM 4

int main(void) {
    int tab[TAM][TAM] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    int i, j, somaP = 0, somaS = 0;

    printf("Tabuleiro:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) printf("%3d", tab[i][j]);
        printf("\n");
    }

    printf("\nDiagonal Principal: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", tab[i][i]);
        somaP += tab[i][i];
    }

    printf("\nDiagonal Secundaria: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", tab[i][TAM - 1 - i]);
        somaS += tab[i][TAM - 1 - i];
    }

    printf("\n\nSoma Diagonal Principal: %d\n", somaP);
    printf("Soma Diagonal Secundaria: %d\n", somaS);

    return 0;
}
