/*
 * Nome: Rodrigo Nogueira de Oliveira
 * RA: 2040482522005
 * Disciplina: Programacao Estruturada e Modular
 * Professor: Carlos Verissimo
 * Data: 29/05/2026
 * Exercício: 04 - Validador de Triangulo e Classificacao
 */

#include <stdio.h>

int main(void) {
    double a, b, c, x, y, z, aux, x2, y2, z2;

    printf("Digite os tres lados do triangulo: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 0;

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Erro: lados devem ser positivos.\n");
        return 0;
    }

    x = a; y = b; z = c;
    if (x > y) { aux = x; x = y; y = aux; }
    if (x > z) { aux = x; x = z; z = aux; }
    if (y > z) { aux = y; y = z; z = aux; }

    if (x + y <= z) {
        printf("Nao forma um triangulo valido.\n");
        return 0;
    }

    printf("Triangulo valido.\n");

    if (a == b && b == c)           printf("Lados: Equilatero\n");
    else if (a == b || a == c || b == c) printf("Lados: Isosceles\n");
    else                            printf("Lados: Escaleno\n");

    x2 = x * x; y2 = y * y; z2 = z * z;

    if (z2 == x2 + y2)      printf("Angulos: Retangulo\n");
    else if (z2 > x2 + y2)  printf("Angulos: Obtusangulo\n");
    else                    printf("Angulos: Acutangulo\n");

    return 0;
}
