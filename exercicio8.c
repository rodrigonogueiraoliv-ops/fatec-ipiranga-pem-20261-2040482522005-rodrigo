void exercicio_08() {
    printf("--- Exercício 08: Distância entre Ponteiros ---\n");
    double arr[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    
    double *p1 = &arr[2]; // Aponta para o 3º elemento (índice 2)
    double *p2 = &arr[7]; // Aponta para o 8º elemento (índice 7)

    long distancia = p2 - p1;
    
    /* 
       COMENTÁRIO EXPLICATIVO:
       O compilador calcula a diferença em bytes entre os endereços e divide 
       pelo tamanho do tipo (sizeof(double)). 
       Ex: (EnderecoP2 - EnderecoP1) / 8 bytes.
       O resultado é o número de ELEMENTOS entre eles, não bytes.
       Aqui, 7 - 2 = 5 elementos de distância.
    */
    printf("Distancia (numero de elementos): %ld\n", distancia);

    printf("Percorrendo o intervalo:\n");
    for (double *p = p1; p < p2; p++) {
        printf("%.1f ", *p);
    }
    printf("\n\n");
}