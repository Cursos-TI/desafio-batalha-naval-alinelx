#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int naviov[3] = {3,3,3};
    int navioh[3] = {3,3,3};
    int naviod1[3] = {3,3,3};
    int naviod2[3] = {3,3,3}; // tamanho dos navios vertical, horizontal e diagonais
    int habcone[3][5] = {
        {5,5,1,5,5},
        {5,1,1,1,5},
        {1,1,1,1,1}
    };
    int habcruz[3][5] = {
        {5,5,1,5,5},
        {1,1,1,1,1},
        {5,5,1,5,5}
    };
    int haboctaedro[3][3] = {
        {5,1,5},
        {1,1,1},
        {5,1,5}
    };
    int pivlinha, pivcol, pihlinha, pihcol, pid1linha, pid1col, pid2linha, pid2col; // posições iniciais navios
    int pihconelinha, pihconecol, pihcruzlinha, pihcruzcol, pihoctaedrolinha, pihoctaedrocol; //posições iniciais habilidades
    int i,j,k,l; // auxiliares

    for (i=0;i<10;i++){ // Iniciar todas as posições como água "0", vertical
        for (j=0;j<10;j++){ // Iniciar todas as posições como água "0", horizontal
            tabuleiro[i][j]=0;
        }
    }

    pivlinha = 1; // começa na segunda linha, não pode ser maior que 7
    pivcol = 9;
    pihlinha = 9;
    pihcol = 7; // começa na oitava coluna, não pode ser maior que 7
    pid1linha = 5;
    pid1col = 5;
    pid2linha = 9;
    pid2col = 0;
    pihconelinha = 3;
    pihconecol = 2;
    pihcruzlinha = 1;
    pihcruzcol = 4;
    pihoctaedrolinha = 8;
    pihoctaedrocol = 4;


    if (pivlinha > 7 || pihcol > 7 || pid1col > 7 || pid1linha > 7 || pid2col > 7 || pid2linha<2){
        printf("Posição inicial de navio ultrapassa tabuleiro");
        return 0;
    }

    if (pihconelinha < 1 || pihconelinha > 7 || pihconecol < 2 || pihconecol > 7 || pihcruzlinha < 1 || pihcruzlinha > 8 || pihcruzcol < 2  || pihcruzcol > 7  || pihoctaedrolinha < 1 || pihoctaedrolinha > 8 || pihoctaedrocol < 1 || pihoctaedrocol > 8){
        printf("Posição inicial de habilidade ultrapassa tabuleiro");
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
                }else{
                    if(tabuleiro[pid1col+j][pid1linha+j]!=0){
                        printf("Posição sobreposta no navio diagonal 1");
                        return 0;
                    }else{
                        if(tabuleiro[pid2col+j][pid2linha+j]!=0){
                            printf("Posição sobreposta no navio diagonal 2");
                            return 0;
                        }else{
                            if(tabuleiro[pihconecol+j][pihconelinha+j]!=0){
                                printf("Posiçãao sobreposta na habilidade cone");
                                return 0;
                            }else{
                                if(tabuleiro[pihcruzcol+j][pihcruzlinha+j]!=0){
                                printf("Posiçãao sobreposta na habilidade cruz");
                                return 0;
                                }
                            }
                        }
                    }
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
            if(i==pid1linha && j==pid1col){
                tabuleiro[i][j]=naviod1[0];
                tabuleiro[i+1][j+1]=naviod1[1];
                tabuleiro[i+2][j+2]=naviod1[2];
            }
            if(i==pid2linha && j==pid2col){
                tabuleiro[i][j]=naviod2[0];
                tabuleiro[i-1][j+1]=naviod2[1];
                tabuleiro[i-2][j+2]=naviod2[2];
            }
            if(i==pihconelinha && j==pihconecol){
                for(k=0;k<3;k++){
                    for(l=0;l<5;l++){
                        tabuleiro[i][j-2]=habcone[k][l];
                        j++;
                    }
                    j=pihconecol;
                    i++;
                }
                i=pihconelinha;
                j=pihconecol+1;
            }
            if(i==pihcruzlinha && j==pihcruzcol){
                for(k=0;k<3;k++){
                    for(l=0;l<5;l++){
                        tabuleiro[i-1][j-2]=habcruz[k][l];
                        j++;
                    }
                    j=pihcruzcol;
                    i++;
                }
                i=pihcruzlinha;
                j=pihcruzcol+1;
            }
            if(i==pihoctaedrolinha && j==pihoctaedrocol){
                for(k=0;k<3;k++){
                    for(l=0;l<3;l++){
                        tabuleiro[i-1][j-1]=haboctaedro[k][l];
                        j++;
                    }
                    j=pihoctaedrocol;
                    i++;
                }
                i=pihoctaedrolinha;
                j=pihoctaedrocol+1;
            }
        }
    }

    for (i=0;i<10;i++){
        for (j=0;j<10;j++){
            printf("%d ",tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
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