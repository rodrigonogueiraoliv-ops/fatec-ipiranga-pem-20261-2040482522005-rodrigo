/******************************************************************************
 * Arquivo    : ex16.c
 * Aluno      : Rodrigo Nogueira de Oliveira
 * RA         : 2040482522005
 * Professor  : Carlos Veríssimo
 * Disciplina : Programação Estruturada e Modular (PEM-2026-01)
 * Semana     : 14 - Atividade de Consolidação
 * Data       : 29/05/2026
 * Tema       : T11 - Programa Modular Final
 * Descrição  :
 *   Sistema completo com menu que integra várias funcionalidades
 *   desenvolvidas ao longo da semana (media, IMC, tabuada, etc).
 * Compilação : gcc -Wall ex16.c -o ex16
 ******************************************************************************/
#include <stdio.h>

void menu(void);
void calcularMedia(void);
void calcularIMC(void);
void mostrarTabuada(void);

int main(void) {
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: calcularMedia(); break;
            case 2: calcularIMC(); break;
            case 3: mostrarTabuada(); break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void menu(void) {
    printf("\n=== SISTEMA INTEGRADO PEM-2026 ===\n");
    printf("1. Calcular Media Ponderada\n");
    printf("2. Calcular IMC\n");
    printf("3. Mostrar Tabuada\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void calcularMedia(void) {
    double n1, n2, n3;
    int p1, p2, p3;
    printf("Digite nota1 peso1: "); scanf("%lf %d", &n1, &p1);
    printf("Digite nota2 peso2: "); scanf("%lf %d", &n2, &p2);
    printf("Digite nota3 peso3: "); scanf("%lf %d", &n3, &p3);
    double media = (n1*p1 + n2*p2 + n3*p3) / (p1+p2+p3);
    printf("Media = %.2f\n", media);
}

void calcularIMC(void) {
    double peso, altura;
    printf("Peso (kg): "); scanf("%lf", &peso);
    printf("Altura (m): "); scanf("%lf", &altura);
    if (peso > 0 && altura > 0) {
        double imc = peso / (altura * altura);
        printf("IMC = %.2f\n", imc);
    } else {
        printf("Valores invalidos!\n");
    }
}

void mostrarTabuada(void) {
    for (int i = 1; i <= 5; i++) {
        printf("\nTabuada do %d:\n", i);
        for (int j = 1; j <= 10; j++) {
            printf("%d x %d = %d\n", i, j, i*j);
        }
    }
}
