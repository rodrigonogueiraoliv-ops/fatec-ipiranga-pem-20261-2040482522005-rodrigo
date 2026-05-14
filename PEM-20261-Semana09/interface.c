#include <stdio.h>
#include "interface.h"

void exibirMenu(void) {
  puts("\n=== CUCC - Conversor e Calculadora Cientifica ===");
  puts("1. Converter decimal para binario");
  puts("2. Calcular potencia (base^expoente)");
  puts("3. Somar digitos de um inteiro");
  puts("0. Sair");
}

int lerInteiro(const char *mensagem) {
  int valor;
  int lidos;

  while (1) {
    printf("%s", mensagem);
    lidos = scanf("%d", &valor);

    if (lidos == 1) {
      return valor;
    }

    puts("Entrada invalida. Tente novamente com um numero inteiro.");
    while (getchar() != '\n') {
    }
  }
}