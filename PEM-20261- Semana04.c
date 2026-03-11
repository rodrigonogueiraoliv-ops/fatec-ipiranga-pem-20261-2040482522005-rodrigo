#include <stdio.h>
#include <stdbool.h>

/* Definição de constantes conforme solicitado */
const char VAZIO = ' ';

// Protótipos das funções
void inicializarTabuleiro(char tabuleiro[3][3]);
void exibirTabuleiro(char tabuleiro[3][3]);
bool verificarVencedor(char tabuleiro[3][3], char jogador);
bool tabuleiroCheio(char tabuleiro[3][3]);

int main() {
    char tabuleiro[3][3];
    char jogador_atual = 'X';
    bool vencedor = false;
    int linha, coluna;

    // 1. Inicialização: Preencher com espaços vazios
    inicializarTabuleiro(tabuleiro);

    printf("--- JOGO DA VELHA ---\n");

    // 2. Laço Principal
    while (!vencedor && !tabuleiroCheio(tabuleiro)) {
        exibirTabuleiro(tabuleiro);
        
        printf("Turno do jogador [%c]\n", jogador_atual);
        printf("Digite a linha e coluna (0-2) separadas por espaco: ");
        
        // Solicitar coordenadas
        if (scanf("%d %d", &linha, &coluna) != 2) {
            printf("Entrada invalida! Use números.\n");
            while(getchar() != '\n'); // Limpa o buffer
            continue;
        }

        // Validação: Verificar limites e se a posição está vazia
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != VAZIO) {
            printf("\n!!! JOGADA INVALIDA !!! Posicao ocupada ou fora dos limites.\n");
            continue;
        }

        // Atualização: Insere o símbolo
        tabuleiro[linha][coluna] = jogador_atual;

        // 3. Verificação de Vitória
        vencedor = verificarVencedor(tabuleiro, jogador_atual);

        if (vencedor) {
            exibirTabuleiro(tabuleiro);
            printf("PARABENS! O jogador [%c] venceu!\n", jogador_atual);
        } else if (tabuleiroCheio(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("O jogo terminou em empate (VELHA)!\n");
        } else {
            // Alternar jogador
            jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

void inicializarTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\n  0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d %c | %c | %c \n", i, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2) printf("  --+---+--\n"); // Divisórias sugeridas
    }
    printf("\n");
}

bool verificarVencedor(char tabuleiro[3][3], char j) {
    // Verificar Linhas e Colunas usando laços Para (for)
    for (int i = 0; i < 3; i++) {
        if ((tabuleiro[i][0] == j && tabuleiro[i][1] == j && tabuleiro[i][2] == j) || // Linha
            (tabuleiro[0][i] == j && tabuleiro[1][i] == j && tabuleiro[2][i] == j))   // Coluna
            return true;
    }

    // Verificar Diagonal Principal ([0][0], [1][1], [2][2])
    if (tabuleiro[0][0] == j && tabuleiro[1][1] == j && tabuleiro[2][2] == j)
        return true;

    // Verificar Diagonal Secundária ([0][2], [1][1], [2][0])
    if (tabuleiro[0][2] == j && tabuleiro[1][1] == j && tabuleiro[2][0] == j)
        return true;

    return false;
}

bool tabuleiroCheio(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == VAZIO) return false;
        }
    }
    return true;
}
