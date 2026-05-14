#include <stdio.h>
#include "interface.h"
#include "recursao.h"

int main(void) {
  int opcao;

  do {
    int numero;
    int base;
    int expoente;

    exibirMenu();
    opcao = lerInteiro("Escolha uma opcao: ");

    switch (opcao) {
      case 1:
        numero = lerInteiro("Digite um numero decimal: ");
        printf("Binario: ");
        decToBin(numero);
        putchar('\n');
        break;

      case 2:
        base = lerInteiro("Digite a base: ");
        expoente = lerInteiro("Digite o expoente (>= 0): ");

        if (expoente < 0) {
          puts("Expoente negativo nao e suportado em int.");
        } else {
          printf("Resultado: %d\n", potencia(base, expoente));
        }
        break;

      case 3:
        numero = lerInteiro("Digite um numero inteiro: ");
        printf("Soma dos digitos: %d\n", somaDigitos(numero));
        break;

      case 0:
        puts("Encerrando o sistema.");
        break;

      default:
        puts("Opcao invalida.");
    }
  } while (opcao != 0);

  return 0;
}