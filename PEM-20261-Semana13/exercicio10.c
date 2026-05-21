void inverter(int *arr, int n) {
    int *inicio = arr;
    int *fim = arr + n - 1;

    while (inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        
        inicio++;
        fim--;
    }
}

void exercicio_09() {
    printf("--- Exercício 09: Inversão de Array ---\n");
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;

    printf("Antes: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    
    inverter(arr, n);
    
    printf("\nDepois: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n\n");
}