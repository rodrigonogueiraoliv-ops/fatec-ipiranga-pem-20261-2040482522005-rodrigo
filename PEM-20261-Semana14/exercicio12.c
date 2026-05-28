/******************************************************************************
 * Arquivo    : ex12.c
 * Aluno      : Rodrigo Nogueira de Oliveira
 * RA         : 2040482522005
 * Professor  : Carlos Veríssimo
 * Disciplina : Programação Estruturada e Modular (PEM-2026-01)
 * Semana     : 14 - Atividade de Consolidação
 * Data       : 29/05/2026
 * Tema       : T7 - Strings e Processamento de Texto
 * Descrição  :
 *   Lê uma string e realiza várias operações: contar vogais, inverter,
 *   verificar se é palíndromo e converter para maiúsculo.
 * Compilação : gcc -Wall ex12.c -o ex12
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contarVogais(char str[]);
void inverterString(char str[], char invertida[]);
int ehPalindromo(char str[]);
void converterMaiusculo(char str[]);

int main(void) {
    char texto[100], invertida[100];

    printf("Digite uma frase (max 99 caracteres): ");
    fgets(texto, 100, stdin);
    texto[strcspn(texto, "\n")] = '\0';  // remove o \n

    printf("\n=== ANALISE DA STRING ===\n");
    printf("Original: %s\n", texto);
    printf("Tamanho: %zu caracteres\n", strlen(texto));
    printf("Vogais: %d\n", contarVogais(texto));

    inverterString(texto, invertida);
    printf("Invertida: %s\n", invertida);

    if (ehPalindromo(texto))
        printf("A string EH um palindromo!\n");
    else
        printf("A string NAO eh um palindromo.\n");

    converterMaiusculo(texto);
    printf("Em maiusculo: %s\n", texto);

    return 0;
}

int contarVogais(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}

void inverterString(char str[], char invertida[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        invertida[i] = str[len - 1 - i];
    }
    invertida[len] = '\0';
}

int ehPalindromo(char str[]) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        while (!isalnum(str[i])) i++;
        while (!isalnum(str[j])) j--;
        if (tolower(str[i]) != tolower(str[j])) return 0;
        i++; j--;
    }
    return 1;
}

void converterMaiusculo(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}
