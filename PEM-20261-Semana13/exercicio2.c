void exercicio_02() {
    printf("--- Exercício 02: Tamanho de um Ponteiro ---\n");
    
    int *p_int;
    float *p_float;
    double *p_double;
    char *p_char;

    printf("Tamanho ponteiro int: %zu bytes\n", sizeof(p_int));
    printf("Tamanho ponteiro float: %zu bytes\n", sizeof(p_float));
    printf("Tamanho ponteiro double: %zu bytes\n", sizeof(p_double));
    printf("Tamanho ponteiro char: %zu bytes\n", sizeof(p_char));

    /* 
       COMENTÁRIO EXPLICATIVO:
       O tamanho NÃO varia com o tipo apontado. Todos terão o mesmo tamanho 
       (geralmente 4 bytes em sistemas 32bits ou 8 bytes em 64bits). 
       Isso ocorre porque um ponteiro apenas armazena um endereço de memória, 
       e o tamanho de um endereço depende da arquitetura do processador, 
       não do dado que está lá guardado.
    */
    printf("\n");
}