void exercicio_05() {
    printf("--- Exercício 05: Modificação Indireta ---\n");
    int vetor[5] = {1, 2, 3, 4, 5};
    int *ptr = vetor; // Ponteiro aponta para o início do vetor

    printf("Antes: ");
    for(int i=0; i<5; i++) printf("%d ", *(ptr + i)); // Leitura com *
    printf("\n");

    // Modificação usando apenas * e aritmética
    for(int i=0; i<5; i++) {
        *(ptr + i) = *(ptr + i) * 2; 
    }

    printf("Depois: ");
    for(int i=0; i<5; i++) printf("%d ", *(ptr + i));
    printf("\n\n");
}