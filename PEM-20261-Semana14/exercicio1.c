#include <stdio.h>

int main(void) {
    double n1, n2, n3;   // notas
    int p1, p2, p3;      // pesos (inteiros)

    printf("Digite a nota 1 e seu peso: ");
    scanf("%lf %d", &n1, &p1);
    printf("Digite a nota 2 e seu peso: ");
    scanf("%lf %d", &n2, &p2);
    printf("Digite a nota 3 e seu peso: ");
    scanf("%lf %d", &n3, &p3);

    double media = (n1 * p1 + n2 * p2 + n3 * p3) / (p1 + p2 + p3);

    printf("\nMedia ponderada: %.2f\n", media);
    printf("Tamanho de double: %zu bytes\n", sizeof(double));
    printf("Tamanho de int: %zu bytes\n", sizeof(int));

    return 0;
}
