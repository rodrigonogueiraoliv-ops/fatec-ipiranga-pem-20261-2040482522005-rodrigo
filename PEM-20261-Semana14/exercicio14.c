/******************************************************************************
 * Arquivo    : ex14.c
 * Aluno      : Rodrigo Nogueira de Oliveira
 * RA         : 2040482522005
 * Professor  : Carlos Veríssimo
 * Disciplina : Programação Estruturada e Modular (PEM-2026-01)
 * Semana     : 14 - Atividade de Consolidação
 * Data       : 29/05/2026
 * Tema       : T9 - Algoritmos de Ordenação
 * Descrição  :
 *   Implementa Selection Sort e Bubble Sort. Exibe o vetor antes e depois
 *   da ordenação e conta o número de trocas em cada algoritmo.
 * Compilação : gcc -Wall ex14.c -o ex14
 ******************************************************************************/
#include <stdio.h>
#define TAM 8

void selectionSort(int v[], int n, int *trocas);
void bubbleSort(int v[], int n, int *trocas);
void imprimirVetor(int v[], int n);

int main(void) {
    int vetor[TAM] = {64, 34, 25, 12, 22, 11, 90, 88};
    int trocasSel = 0, trocasBub = 0;
    int copia[TAM];

    printf("Vetor original: ");
    imprimirVetor(vetor, TAM);

    // Selection Sort
    for (int i = 0; i < TAM; i++) copia[i] = vetor[i];
    selectionSort(copia, TAM, &trocasSel);
    printf("\nSelection Sort: ");
    imprimirVetor(copia, TAM);
    printf("Trocas: %d\n", trocasSel);

    // Bubble Sort
    for (int i = 0; i < TAM; i++) copia[i] = vetor[i];
    bubbleSort(copia, TAM, &trocasBub);
    printf("Bubble Sort   : ");
    imprimirVetor(copia, TAM);
    printf("Trocas: %d\n", trocasBub);

    return 0;
}

void selectionSort(int v[], int n, int *trocas) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            int temp = v[i];
            v[i] = v[min_idx];
            v[min_idx] = temp;
            (*trocas)++;
        }
    }
}

void bubbleSort(int v[], int n, int *trocas) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
