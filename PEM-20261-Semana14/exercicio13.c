/******************************************************************************
 * Arquivo    : ex13.c
 * Aluno      : Rodrigo Nogueira de Oliveira
 * RA         : 2040482522005
 * Professor  : Carlos Veríssimo
 * Disciplina : Programação Estruturada e Modular (PEM-2026-01)
 * Semana     : 14 - Atividade de Consolidação
 * Data       : 29/05/2026
 * Tema       : T8 - Recursão
 * Descrição  :
 *   Implementa fatorial e Fibonacci de forma recursiva.
 *   Inclui versão iterativa para comparação de eficiência.
 * Compilação : gcc -Wall ex13.c -o ex13
 ******************************************************************************/
#include <stdio.h>

long long fatorialRecursivo(int n);
long long fatorialIterativo(int n);
int fibonacciRecursivo(int n);

int main(void) {
    int num;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Erro: numero deve ser positivo.\n");
    } else {
        printf("Fatorial (recursivo) de %d = %lld\n", num, fatorialRecursivo(num));
        printf("Fatorial (iterativo) de %d = %lld\n", num, fatorialIterativo(num));
        printf("Fibonacci(%d) = %d\n", num, fibonacciRecursivo(num));
    }

    return 0;
}

long long fatorialRecursivo(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fatorialRecursivo(n - 1);
}

long long fatorialIterativo(int n) {
    long long fat = 1;
    for (int i = 2; i <= n; i++) fat *= i;
    return fat;
}

int fibonacciRecursivo(int n) {
    if (n <= 1) return n;
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}
