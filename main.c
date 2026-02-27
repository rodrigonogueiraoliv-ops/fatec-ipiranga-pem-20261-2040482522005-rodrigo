#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];
    int tamanho, i, contadorPalavras = 1;

    printf("Digite a frase completa: ");
    fgets(frase, sizeof(frase), stdin);

    tamanho = strlen(frase);

    if (frase[tamanho - 1] == '\n') {
        frase[tamanho - 1] = '\0';
        tamanho--;
    }

    if (tamanho == 0) {
        contadorPalavras = 0;
    } else {
        for (i = 0; i < tamanho; i++) {
            if (frase[i] == ' ') {
                if (frase[i + 1] != ' ' && frase[i + 1] != '\0') {
                    contadorPalavras++;
                }
            }
        }
    }

    printf("A frase tem %d palavras.\n", contadorPalavras);

    return 0;
}