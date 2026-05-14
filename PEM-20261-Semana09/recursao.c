#include <stdio.h>
#include "recursao.h"

void decToBin(int n) {
  if (n < 0) {
    putchar('-');
    decToBin(-n);
    return;
  }

  if (n < 2) {
    printf("%d", n);
    return;
  }

  decToBin(n / 2);
  printf("%d", n % 2);
}

int potencia(int base, int exp) {
  if (exp < 0) {
    return 0;
  }

  if (exp == 0) {
    return 1;
  }

  return base * potencia(base, exp - 1);
}

int somaDigitos(int n) {
  if (n < 0) {
    return somaDigitos(-n);
  }

  if (n < 10) {
    return n;
  }

  return (n % 10) + somaDigitos(n / 10);
}