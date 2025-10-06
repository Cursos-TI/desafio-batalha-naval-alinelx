#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[10][10];
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    int naviov[3] = {1,1,1};
    int navioh[3] = {2,2,2}; // tamanho dos navios vertical e horizontal
    int pivlinha, pivcol, pihlinha, pihcol; // posições iniciais
    int i,j; // auxiliares

    for (i=0;i<10;i++){ // Iniciar todas as posições como água "0", vertical
        for (j=0;j<10;j++){ // Iniciar todas as posições como água "0", horizontal
            tabuleiro[i][j]=0;
        }
    }

    pivlinha = 1; // começa na segunda linha, não pode ser maior que 7
    pivcol = 9;
    pihlinha = 9;
    pihcol = 7; // começa na oitava coluna, não pode ser maior que 7

    if (pivlinha>7 || pihcol>7){
        printf("Posição inicial ultrapassa tabuleiro");
        return 0;
    }

    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            if(tabuleiro[pivcol][pivlinha+j]!=0){
                printf("Posição sobreposta no navio vertical\nTabuleiro[%d][%d]",i,j);
                return 0;
             }else{
                if(tabuleiro[pihcol+j][pihlinha]!=0){
                printf("Posição sobreposta no navio horizontal");
                return 0;
                }
             }
        }
    }

    for (i=0;i<10;i++){
        for (j=0;j<10;j++){
            if(i==pivlinha && j==pivcol){
                tabuleiro[i][j]=naviov[0];
                tabuleiro[i+1][j]=naviov[1];
                tabuleiro[i+2][j]=naviov[2];
            }
            if(i==pihlinha && j==pihcol){
                tabuleiro[i][j]=navioh[0];
                tabuleiro[i][j+1]=navioh[1];
                tabuleiro[i][j+2]=navioh[2];
            }
        }
    }

    for (i=0;i<10;i++){
        for (j=0;j<10;j++){
            printf("%d",tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
