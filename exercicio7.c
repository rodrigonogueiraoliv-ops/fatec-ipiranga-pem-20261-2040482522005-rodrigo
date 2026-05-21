void exercicio_07() {
    printf("--- Exercício 07: Percurso com Incremento ---\n");
    int arr[8] = {10, 20, 5, 40, 15, 30, 25, 35};
    int *ptr = arr;
    int *fim = arr + 8; // Ponteiro para logo após o último elemento

    int soma = 0;
    int maior = *ptr;
    int menor = *ptr;

    printf("Elementos e Endereços:\n");
    while (ptr < fim) {
        printf("Valor: %d | Endereço: %p\n", *ptr, (void*)ptr);
        
        soma += *ptr;
        if (*ptr > maior) maior = *ptr;
        if (*ptr < menor) menor = *ptr;
        
        ptr++; // Avança para o próximo int
    }

    float media = (float)soma / 8;
    printf("Soma: %d, Media: %.2f, Maior: %d, Menor: %d\n", soma, media, maior, menor);
    printf("\n");
}