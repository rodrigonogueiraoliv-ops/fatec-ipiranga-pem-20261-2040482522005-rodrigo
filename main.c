#ifndef TABULEIRO_H
#define TABULEIRO_H

#define LINHAS 8
#define COLUNAS 8

// Peças (letras maiúsculas = brancas, minúsculas = pretas)
#define VAZIO '.'
#define PB 'P'  // Peão Branco
#define TB 'T'  // Torre Branca
#define CB 'C'  // Cavalo Branco
#define BB 'B'  // Bispo Branco
#define DB 'D'  // Dama Branca
#define RB 'R'  // Rei Branco

void inicializarTabuleiro(char tabuleiro[LINHAS][COLUNAS]);
void imprimirTabuleiro(char tabuleiro[LINHAS][COLUNAS]);
void moverPeca(char tabuleiro[LINHAS][COLUNAS], int origemL, int origemC, int destinoL, int destinoC);

#endif