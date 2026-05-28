/*
 * Nome: Rodrigo Nogueira de Oliveira
 * RA: 2040482522005
 * Disciplina: Programacao Estruturada e Modular
 * Professor: Carlos Verissimo
 * Data: 29/05/2026
 * Exercício: 07 - Estatisticas de um Conjunto de Dados
 */

#include <stdio.h>
#define TAM 10

int main(void) {
    float v[TAM], soma = 0, media, somaAcima = 0;
    float maior, menor;
    int i;

    for (i = 0; i < TAM; i++) {
        printf("Digite o valor %d: ", i + 1);
        if (scanf("%f", &v[i]) != 1) return 0;
        soma += v[i];
        if (i == 0) maior = menor = v[i];
        else {
            if (v[i] > maior) maior = v[i];
            if (v[i] < menor) menor = v[i];
        }
    }

    media = soma / TAM;
    for (i = 0; i < TAM; i++)
        if (v[i] > media) somaAcima += v[i];

    printf("\nMedia: %.2f\n", media);
    printf("Maior: %.2f\nMenor: %.2f\n", maior, menor);
    printf("Soma acima da media: %.2f\n", somaAcima);

    return 0;
}
