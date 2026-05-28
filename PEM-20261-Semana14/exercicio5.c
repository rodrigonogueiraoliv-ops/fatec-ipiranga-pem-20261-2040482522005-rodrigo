/*
 * Nome: Rodrigo Nogueira de Oliveira
 * RA: 2040482522005
 * Disciplina: Programacao Estruturada e Modular
 * Professor: Carlos Verissimo
 * Data: 29/05/2026
 * Exercício: 05 - Tabuada Interativa com Controle de Fluxo
 */

#include <stdio.h>

int main(void) {
    char resposta = 'S';
    int n, i;

    do {
        for (n = 1; n <= 10 && resposta != 'N'; n++) {
            printf("\n=== TABUADA DO %d ===\n", n);
            i = 1;
            while (i <= 10) {
                printf("%2d x %2d = %3d\n", n, i, n * i);
                i++;
            }

            do {
                printf("Deseja continuar? (S/N): ");
                if (scanf(" %c", &resposta) != 1) return 0;
                if (resposta >= 'a' && resposta <= 'z')
                    resposta -= ('a' - 'A');
            } while (resposta != 'S' && resposta != 'N');
        }
    } while (resposta != 'N');

    printf("Programa encerrado.\n");
    return 0;
}
