void trocar_valores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n) {
    int *i, *j, *min_idx;

    for (i = arr; i < arr + n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < arr + n; j++) {
            if (*j < *min_idx) {
                min_idx = j;
            }
        }
        // Troca se necessário
        if (min_idx != i) {
            trocar_valores(i, min_idx);
        }
    }
}

void exercicio_12() {
    printf("--- Exercício 12: Selection Sort com Ponteiros ---\n");
    int arr[8] = {64, 25, 12, 22, 11, 99, 5, 30};
    int n = 8;

    printf("Antes: ");
    for(int k=0; k<n; k++) printf("%d ", arr[k]);
    
    selectionSort(arr, n);
    
    printf("\nDepois: ");
    for(int k=0; k<n; k++) printf("%d ", arr[k]);
    printf("\n");
}

// Função Main para rodar tudo
int main() {
    exercicio_01();
    exercicio_02();
    exercicio_03();
    exercicio_04();
    exercicio_05();
    exercicio_06();
    exercicio_07();
    exercicio_08();
    exercicio_09();
    exercicio_10();
    exercicio_11();
    exercicio_12();
    return 0;
}