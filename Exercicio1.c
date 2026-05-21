#include <stdio.h>

void exercicio_01() {
    printf("--- Exercício 01: Endereço na Memória ---\n");

    // 1. Declaração de variáveis
    int var_int = 10;
    float var_float = 3.14;
    char var_char = 'A';

    // 2. Criação de ponteiros para cada uma
    int *ptr_int = &var_int;
    float *ptr_float = &var_float;
    char *ptr_char = &var_char;

    // 3. Impressão dos dados
    // Para int
    printf("INT -> Valor: %d | Endereço da Var: %p | Endereço no Ponteiro: %p | Valor via Ponteiro: %d\n",
           var_int, (void*)&var_int, (void*)ptr_int, *ptr_int);

    // Para float
    printf("FLOAT -> Valor: %.2f | Endereço da Var: %p | Endereço no Ponteiro: %p | Valor via Ponteiro: %.2f\n",
           var_float, (void*)&var_float, (void*)ptr_float, *ptr_float);

    // Para char
    printf("CHAR -> Valor: %c | Endereço da Var: %p | Endereço no Ponteiro: %p | Valor via Ponteiro: %c\n",
           var_char, (void*)&var_char, (void*)ptr_char, *ptr_char);
    printf("\n");
}