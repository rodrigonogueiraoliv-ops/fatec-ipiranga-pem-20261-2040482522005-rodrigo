/*
 * Nome: Rodrigo Nogueira de Oliveira
 * RA: 2040482522005
 * Disciplina: Programacao Estruturada e Modular
 * Professor: Carlos Verissimo
 * Data: 29/05/2026
 * Exercício: 06 - Sequencia de Collatz
 */

#include <stdio.h>

int main(void) {
    long long n;
    int passos = 0;

    printf("Digite um inteiro positivo: ");
    if (scanf("%lld", &n) != 1 || n <= 0) {
        printf("Erro: valor invalido.\n");
        return 0;
    }

    printf("Sequencia: %lld", n);
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        printf(" -> %lld", n);
        passos++;
    }
    printf("\nPassos necessarios: %d\n", passos);

    return 0;
}
