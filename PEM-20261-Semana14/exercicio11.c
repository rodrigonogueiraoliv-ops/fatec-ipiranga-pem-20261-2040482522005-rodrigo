/******************************************************************************
 * Arquivo    : ex11.c
 * Aluno      : Rodrigo Nogueira de Oliveira
 * RA         : 2040482522005
 * Professor  : Carlos Veríssimo
 * Disciplina : Programação Estruturada e Modular (PEM-2026-01)
 * Semana     : 14 - Atividade de Consolidação
 * Data       : 29/05/2026
 * Tema       : T6 - Funções e Modularização
 * Descrição  :
 *   Refatora o cálculo de estatísticas de um vetor usando funções.
 *   Demonstra passagem de parâmetros, retorno de valores e modularização.
 * Compilação : gcc -Wall ex11.c -o ex11
 ******************************************************************************/
#include <stdio.h>
#define TAM 10

void lerVetor(float v[], int tamanho);
float calcularMedia(float v[], int tamanho);
void encontrarMaiorMenor(float v[], int tamanho, float *maior, float *menor);
float somaAcimaDaMedia(float v[], int tamanho, float media);

int main(void) {
    float vetor[TAM];
    float media, maior, menor, somaAcima;

    printf("Digite %d valores:\n", TAM);
    lerVetor(vetor, TAM);

    media = calcularMedia(vetor, TAM);
    encontrarMaiorMenor(vetor, TAM, &maior, &menor);
    somaAcima = somaAcimaDaMedia(vetor, TAM, media);

    printf("\n=== RESULTADOS ===\n");
    printf("Media aritmetica: %.2f\n", media);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);
    printf("Soma acima da media: %.2f\n", somaAcima);

    return 0;
}

void lerVetor(float v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        scanf("%f", &v[i]);
    }
}

float calcularMedia(float v[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += v[i];
    }
    return soma / tamanho;
}

void encontrarMaiorMenor(float v[], int tamanho, float *maior, float *menor) {
    *maior = *menor = v[0];
    for (int i = 1; i < tamanho; i++) {
        if (v[i] > *maior) *maior = v[i];
        if (v[i] < *menor) *menor = v[i];
    }
}

float somaAcimaDaMedia(float v[], int tamanho, float media) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        if (v[i] > media) soma += v[i];
    }
    return soma;
}
