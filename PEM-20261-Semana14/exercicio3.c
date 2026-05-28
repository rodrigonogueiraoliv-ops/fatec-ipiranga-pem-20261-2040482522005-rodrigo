/*
 * Nome: Rodrigo Nogueira de Oliveira
 * RA: 2040482522005
 * Disciplina: Programacao Estruturada e Modular
 * Professor: Carlos Verissimo
 * Data: 29/05/2026
 * Exercício: 03 - Classificador de IMC
 */

#include <stdio.h>

int main(void) {
    double peso, altura, imc;

    printf("Digite o peso (kg): ");
    if (scanf("%lf", &peso) != 1) return 0;

    printf("Digite a altura (m): ");
    if (scanf("%lf", &altura) != 1) return 0;

    if (peso <= 0 || altura <= 0) {
        printf("Erro: valores invalidos.\n");
        return 0;
    }

    imc = peso / (altura * altura);
    printf("\nIMC: %.2f\n", imc);

    if (imc < 18.5)        printf("Classificacao: Abaixo do peso\n");
    else if (imc < 25.0)   printf("Classificacao: Peso normal\n");
    else if (imc < 30.0)   printf("Classificacao: Sobrepeso\n");
    else                   printf("Classificacao: Obesidade\n");

    return 0;
}
