#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define TAMANHO_NAVIO 3

// Onde pode colocar o Navio

int podeColocarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;
        if (novaLinha < 0 || novaLinha >= TAM || novaColuna < 0 || novaColuna >= TAM)
            return 0;
        if (tabuleiro[novaLinha][novaColuna] != 0)
            return 0;
    }
    return 1;
}

// COLOCAR NAVIO

void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i * dLinha][coluna + i * dColuna] = NAVIO;
    }
}

// Tabuleiro

void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int c = 0; c < TAM; c++) {
        printf("%d ", c);
    }
    printf("\n");

    for (int l = 0; l < TAM; l++) {
        printf("%d: ", l);
        for (int c = 0; c < TAM; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // NAVIO 1 HORIZONTAL
    if (podeColocarNavio(tabuleiro, 0, 0, 0, 1))
        posicionarNavio(tabuleiro, 0, 0, 0, 1);
    // NAVIO 2 VERTICAL
    if (podeColocarNavio(tabuleiro, 2, 5, 1, 0))
        posicionarNavio(tabuleiro, 2, 5, 1, 0);
    // NAVIO 3 DIAGONAL
    if (podeColocarNavio(tabuleiro, 4, 4, 1, 1))
        posicionarNavio(tabuleiro, 4, 4, 1, 1);
    // NAVIO 4 DIAGONAL
    if (podeColocarNavio(tabuleiro, 2, 7, 1, -1))
        posicionarNavio(tabuleiro, 2, 7, 1, -1);
    // EXIBIR O TABULEIRO
    imprimirTabuleiro(tabuleiro);

    return 0;
}
