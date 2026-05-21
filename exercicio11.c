void estatisticas(int *v, int n, int *soma, float *media, int *maior, int *menor) {
    *soma = 0;
    *maior = v[0];
    *menor = v[0];

    for (int i = 0; i < n; i++) {
        *soma += v[i];
        if (v[i] > *maior) *maior = v[i];
        if (v[i] < *menor) *menor = v[i];
    }
    *media = (float)(*soma) / n;
}

void exercicio_11() {
    printf("--- Exercício 11: Múltiplos Retornos ---\n");
    int dados[6] = {10, 20, 30, 40, 50, 60};
    int s, mai, men;
    float med;

    estatisticas(dados, 6, &s, &med, &mai, &men);

    printf("Soma: %d\n", s);
    printf("Media: %.2f\n", med);
    printf("Maior: %d\n", mai);
    printf("Menor: %d\n", men);
    printf("\n");
}