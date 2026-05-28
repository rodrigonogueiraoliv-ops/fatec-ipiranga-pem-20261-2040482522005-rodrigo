/*
 * Nome: Rodrigo Nogueira de Oliveira
 * RA: 2040482522005
 * Disciplina: Programacao Estruturada e Modular
 * Professor: Carlos Verissimo
 * Data: 29/05/2026
 * Exercício: 02 - Conversor de Unidades com Overflow Controlado
 */

#include <stdio.h>

int main(void) {
    long long entrada;
    int cm;
    float metros;
    double km, milhas;

    printf("Digite a distancia em centimetros: ");
    if (scanf("%lld", &entrada) != 1) return 0;

    if (entrada <= 0 || entrada > 2147483647LL) {
        printf("Erro: valor invalido.\n");
        return 0;
    }

    cm = (int)entrada;
    metros = cm / 100.0f;
    km = cm / 100000.0;
    milhas = km / 1.60934;

    printf("\nMetros: %.2f\n", metros);
    printf("Quilometros: %.6f\n", km);
    printf("Milhas: %.6f\n", milhas);

    return 0;
}
