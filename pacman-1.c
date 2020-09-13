#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>

#define LINHAS 31
#define COLUNAS 81
#define VELOCIDADE 80000


void desenha_jogo(unsigned char tabuleiro[LINHAS][COLUNAS])
{
    int i, j;

    /* inicializa tabuleiro */
    for (i=0; i<LINHAS;i++)
        for (j=0;j<COLUNAS;j++)
            tabuleiro[i][j] = ' ';

    /* desenha bordas */
    for (i=1; i<(LINHAS/2)-5; i++)
        tabuleiro[i][0] = 186;          /* ║ */
    for (i=(LINHAS/2)+7; i<LINHAS; i++)
        tabuleiro[i][0] = 186;
    for (i=1; i<(LINHAS/2)-5; i++)
        tabuleiro[i][COLUNAS-1] = 186;
    for (i=(LINHAS/2)+7; i<LINHAS; i++)
        tabuleiro[i][COLUNAS-1] = 186;
    for (j=1; j<COLUNAS; j++)
        tabuleiro[0][j] = 205;         /* ═ */
    for (j=0; j<COLUNAS-1; j++)
        tabuleiro[LINHAS-1][j] = 205;
    tabuleiro[0][0] = 201;            /* ╔ */
    tabuleiro[LINHAS-1][0] = 200;        /* ╚ */
    tabuleiro[0][COLUNAS-1] = 187;          /* ╗ */
    tabuleiro[LINHAS-1][COLUNAS-1] = 188;      /* ╝ */

    
    tabuleiro[(LINHAS/2)-2][0] = 205;
    tabuleiro[(LINHAS/2)-2][1] = 205;
    tabuleiro[(LINHAS/2)-2][2] = 205;
    tabuleiro[(LINHAS/2)-2][3] = 205;
    tabuleiro[(LINHAS/2)-2][4] = 205;
    tabuleiro[(LINHAS/2)-2][5] = 205;
    tabuleiro[(LINHAS/2)-2][6] = 205;
    tabuleiro[(LINHAS/2)-2][7] = 205;
    tabuleiro[(LINHAS/2)-2][8] = 205;
    tabuleiro[(LINHAS/2)-2][9] = 188;

    tabuleiro[(LINHAS/2)+2][0] = 205;
    tabuleiro[(LINHAS/2)+2][1] = 205;
    tabuleiro[(LINHAS/2)+2][2] = 205;
    tabuleiro[(LINHAS/2)+2][3] = 205;
    tabuleiro[(LINHAS/2)+2][4] = 205;
    tabuleiro[(LINHAS/2)+2][5] = 205;
    tabuleiro[(LINHAS/2)+2][6] = 205;
    tabuleiro[(LINHAS/2)+2][7] = 205;
    tabuleiro[(LINHAS/2)+2][8] = 205;
    tabuleiro[(LINHAS/2)+2][9] = 187;

    tabuleiro[(LINHAS/2)-2][COLUNAS-1] = 205;
    tabuleiro[(LINHAS/2)-2][COLUNAS-2] = 205;
    tabuleiro[(LINHAS/2)-2][COLUNAS-3] = 205;
    tabuleiro[(LINHAS/2)-2][COLUNAS-4] = 205;
    tabuleiro[(LINHAS/2)-2][COLUNAS-5] = 205;
    tabuleiro[(LINHAS/2)-2][COLUNAS-6] = 205;
    tabuleiro[(LINHAS/2)-2][COLUNAS-7] = 205;
    tabuleiro[(LINHAS/2)-2][COLUNAS-8] = 205;
    tabuleiro[(LINHAS/2)-2][COLUNAS-9] = 205;
    tabuleiro[(LINHAS/2)-2][COLUNAS-10] = 200;

    tabuleiro[(LINHAS/2)+2][COLUNAS-1] = 205;
    tabuleiro[(LINHAS/2)+2][COLUNAS-2] = 205;
    tabuleiro[(LINHAS/2)+2][COLUNAS-3] = 205;
    tabuleiro[(LINHAS/2)+2][COLUNAS-4] = 205;
    tabuleiro[(LINHAS/2)+2][COLUNAS-5] = 205;
    tabuleiro[(LINHAS/2)+2][COLUNAS-6] = 205;
    tabuleiro[(LINHAS/2)+2][COLUNAS-7] = 205;
    tabuleiro[(LINHAS/2)+2][COLUNAS-8] = 205;
    tabuleiro[(LINHAS/2)+2][COLUNAS-9] = 205;
    tabuleiro[(LINHAS/2)+2][COLUNAS-10] = 201;

    tabuleiro[(LINHAS/2)-3][9] = 186;
    tabuleiro[(LINHAS/2)-4][9] = 186;
    tabuleiro[(LINHAS/2)-5][9] = 186;
    tabuleiro[(LINHAS/2)+3][9] = 186;
    tabuleiro[(LINHAS/2)+4][9] = 186;
    tabuleiro[(LINHAS/2)+5][9] = 186;
    tabuleiro[(LINHAS/2)+6][9] = 186;

    tabuleiro[(LINHAS/2)-5][9] = 187;
    tabuleiro[(LINHAS/2)-5][8] = 205;
    tabuleiro[(LINHAS/2)-5][7] = 205;
    tabuleiro[(LINHAS/2)-5][6] = 205;
    tabuleiro[(LINHAS/2)-5][5] = 205;
    tabuleiro[(LINHAS/2)-5][4] = 205;
    tabuleiro[(LINHAS/2)-5][3] = 205;
    tabuleiro[(LINHAS/2)-5][2] = 205;
    tabuleiro[(LINHAS/2)-5][1] = 205;
    tabuleiro[(LINHAS/2)-5][0] = 200;

    tabuleiro[(LINHAS/2)+7][9] = 188;
    tabuleiro[(LINHAS/2)+7][8] = 205;
    tabuleiro[(LINHAS/2)+7][7] = 205;
    tabuleiro[(LINHAS/2)+7][6] = 205;
    tabuleiro[(LINHAS/2)+7][5] = 205;
    tabuleiro[(LINHAS/2)+7][4] = 205;
    tabuleiro[(LINHAS/2)+7][3] = 205;
    tabuleiro[(LINHAS/2)+7][2] = 205;
    tabuleiro[(LINHAS/2)+7][1] = 205;
    tabuleiro[(LINHAS/2)+7][0] = 201;

    tabuleiro[(LINHAS/2)-3][COLUNAS-10] = 186;
    tabuleiro[(LINHAS/2)-4][COLUNAS-10] = 186;
    tabuleiro[(LINHAS/2)-5][COLUNAS-10] = 186;
    tabuleiro[(LINHAS/2)+3][COLUNAS-10] = 186;
    tabuleiro[(LINHAS/2)+4][COLUNAS-10] = 186;
    tabuleiro[(LINHAS/2)+5][COLUNAS-10] = 186;
    tabuleiro[(LINHAS/2)+6][COLUNAS-10] = 186;

    tabuleiro[(LINHAS/2)-5][COLUNAS-10] = 201;
    tabuleiro[(LINHAS/2)-5][COLUNAS-9] = 205;
    tabuleiro[(LINHAS/2)-5][COLUNAS-8] = 205;
    tabuleiro[(LINHAS/2)-5][COLUNAS-7] = 205;
    tabuleiro[(LINHAS/2)-5][COLUNAS-6] = 205;
    tabuleiro[(LINHAS/2)-5][COLUNAS-5] = 205;
    tabuleiro[(LINHAS/2)-5][COLUNAS-4] = 205;
    tabuleiro[(LINHAS/2)-5][COLUNAS-3] = 205;
    tabuleiro[(LINHAS/2)-5][COLUNAS-2] = 205;
    tabuleiro[(LINHAS/2)-5][COLUNAS-1] = 188;

    tabuleiro[(LINHAS/2)+7][COLUNAS-10] = 200;
    tabuleiro[(LINHAS/2)+7][COLUNAS-9] = 205;
    tabuleiro[(LINHAS/2)+7][COLUNAS-8] = 205;
    tabuleiro[(LINHAS/2)+7][COLUNAS-7] = 205;
    tabuleiro[(LINHAS/2)+7][COLUNAS-6] = 205;
    tabuleiro[(LINHAS/2)+7][COLUNAS-5] = 205;
    tabuleiro[(LINHAS/2)+7][COLUNAS-4] = 205;
    tabuleiro[(LINHAS/2)+7][COLUNAS-3] = 205;
    tabuleiro[(LINHAS/2)+7][COLUNAS-2] = 205;
    tabuleiro[(LINHAS/2)+7][COLUNAS-1] = 187;


    /* Caixa do MEIO */
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)+2] = 205;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)+2] = 205;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)+3] = 205;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)+4] = 205;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)+5] = 187;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)-2] = 205;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)-3] = 205;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)-4] = 205;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)-5] = 201;

    tabuleiro[(LINHAS/2)+2][COLUNAS/2] = 205;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)+1] = 205;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)+2] = 205;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)+2] = 205;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)+3] = 205;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)+4] = 205;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)+5] = 188;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)-1] = 205;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)-2] = 205;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)-3] = 205;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)-4] = 205;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)-5] = 200;

    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)-5] = 186;
    tabuleiro[(LINHAS/2)][(COLUNAS/2)-5] = 186;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)-5] = 186;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)+5] = 186;
    tabuleiro[(LINHAS/2)][(COLUNAS/2)+5] = 186;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)+5] = 186;

    /* PAREDES INTERNAS */
    tabuleiro[LINHAS-5][0] = 204;    /* ╠ */    
    tabuleiro[LINHAS-5][1] = 205;
    tabuleiro[LINHAS-5][2] = 205;
    tabuleiro[LINHAS-5][3] = 205;
    tabuleiro[LINHAS-5][COLUNAS-1] = 185;   /* ╣ */
    tabuleiro[LINHAS-5][COLUNAS-2] = 205;
    tabuleiro[LINHAS-5][COLUNAS-3] = 205;
    tabuleiro[LINHAS-5][COLUNAS-4] = 205;

    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)-5] = 205;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)-6] = 205;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)-7] = 205;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)-8] = 205;

    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)+5] = 205;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)+6] = 205;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)+7] = 205;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)+8] = 205;

    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)-5] = 205;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)-6] = 205;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)-7] = 205;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)-8] = 205;

    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)+5] = 205;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)+6] = 205;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)+7] = 205;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)+8] = 205;

    tabuleiro[(LINHAS/2)-6][COLUNAS/2] = 205;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)-1] = 200;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)+1] = 188;
    tabuleiro[(LINHAS/2)-7][(COLUNAS/2)+1] = 186;
    tabuleiro[(LINHAS/2)-8][(COLUNAS/2)+1] = 186;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)+1] = 201;
    tabuleiro[(LINHAS/2)-9][(COLUNAS/2)+1] = 186;
    tabuleiro[(LINHAS/2)-7][(COLUNAS/2)-1] = 186;
    tabuleiro[(LINHAS/2)-8][(COLUNAS/2)-1] = 186;
    tabuleiro[(LINHAS/2)-9][(COLUNAS/2)-1] = 186;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)-1] = 187;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)+2] = 205;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)-2] = 205;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)+3] = 205;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)-3] = 205;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)+4] = 205;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)-4] = 205;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)+5] = 205;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)-5] = 205;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)+6] = 188;
    tabuleiro[(LINHAS/2)-10][(COLUNAS/2)-6] = 200;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)+6] = 187;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)-6] = 201;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)+5] = 205;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)-5] = 205;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)+4] = 205;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)-4] = 205;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)+3] = 205;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)-3] = 205;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)+2] = 205;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)-2] = 205;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)+1] = 205;
    tabuleiro[(LINHAS/2)-11][(COLUNAS/2)-1] = 205;
    tabuleiro[(LINHAS/2)-11][COLUNAS/2] = 205;
    tabuleiro[(LINHAS/2)-11][COLUNAS/2] = 205;

    tabuleiro[(LINHAS/2)+6][COLUNAS/2] = 205;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)-1] = 201;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)+1] = 187;
    tabuleiro[(LINHAS/2)+7][(COLUNAS/2)+1] = 186;
    tabuleiro[(LINHAS/2)+8][(COLUNAS/2)+1] = 186;
    tabuleiro[(LINHAS/2)+9][(COLUNAS/2)+1] = 186;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+1] = 200;
    tabuleiro[(LINHAS/2)+7][(COLUNAS/2)-1] = 186;
    tabuleiro[(LINHAS/2)+8][(COLUNAS/2)-1] = 186;
    tabuleiro[(LINHAS/2)+9][(COLUNAS/2)-1] = 186;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)-1] = 188;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+2] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)-2] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+3] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)-3] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+4] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)-4] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+5] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)-5] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+6] = 187;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)-6] = 201;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+6] = 188;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)-6] = 200;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+5] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)-5] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+4] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)-4] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+3] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)-3] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+2] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)-2] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+1] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)-1] = 205;
    tabuleiro[(LINHAS/2)+11][COLUNAS/2] = 205;
    tabuleiro[(LINHAS/2)+11][COLUNAS/2] = 205;

    tabuleiro[LINHAS/2][(COLUNAS/2)-9] = 186;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)-9] = 187;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)-9] = 188;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)-10] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)-10] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)-11] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)-11] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)-12] = 201;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)-12] = 200;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)-12] = 186;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)-12] = 186;
    tabuleiro[(LINHAS/2)+3][(COLUNAS/2)-12] = 186;
    tabuleiro[(LINHAS/2)-3][(COLUNAS/2)-12] = 186;
    tabuleiro[(LINHAS/2)+4][(COLUNAS/2)-12] = 186;
    tabuleiro[(LINHAS/2)-4][(COLUNAS/2)-12] = 186;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/2)-12] = 186;
    tabuleiro[(LINHAS/2)-5][(COLUNAS/2)-12] = 186;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)-12] = 188;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)-12] = 187;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)-13] = 205;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)-13] = 205;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)-14] = 200;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)-14] = 201;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/2)-14] = 186;
    tabuleiro[(LINHAS/2)-5][(COLUNAS/2)-14] = 186;
    tabuleiro[(LINHAS/2)+4][(COLUNAS/2)-14] = 186;
    tabuleiro[(LINHAS/2)-4][(COLUNAS/2)-14] = 186;
    tabuleiro[(LINHAS/2)+3][(COLUNAS/2)-14] = 186;
    tabuleiro[(LINHAS/2)-3][(COLUNAS/2)-14] = 186;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)-14] = 186;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)-14] = 186;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)-14] = 186;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)-14] = 186;
    tabuleiro[LINHAS/2][(COLUNAS/2)-14] = 186;
    tabuleiro[LINHAS/2][(COLUNAS/2)-14] = 186;

    tabuleiro[LINHAS/2][(COLUNAS/2)+9] = 186;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)+9] = 201;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)+9] = 200;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)+10] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)+10] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)+11] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)+11] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)+12] = 187;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)+12] = 188;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)+12] = 186;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)+12] = 186;
    tabuleiro[(LINHAS/2)+3][(COLUNAS/2)+12] = 186;
    tabuleiro[(LINHAS/2)-3][(COLUNAS/2)+12] = 186;
    tabuleiro[(LINHAS/2)+4][(COLUNAS/2)+12] = 186;
    tabuleiro[(LINHAS/2)-4][(COLUNAS/2)+12] = 186;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/2)+12] = 186;
    tabuleiro[(LINHAS/2)-5][(COLUNAS/2)+12] = 186;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)+12] = 200;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)+12] = 201;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)+13] = 205;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)+13] = 205;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)+14] = 188;
    tabuleiro[(LINHAS/2)-6][(COLUNAS/2)+14] = 187;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/2)+14] = 186;
    tabuleiro[(LINHAS/2)-5][(COLUNAS/2)+14] = 186;
    tabuleiro[(LINHAS/2)+4][(COLUNAS/2)+14] = 186;
    tabuleiro[(LINHAS/2)-4][(COLUNAS/2)+14] = 186;
    tabuleiro[(LINHAS/2)+3][(COLUNAS/2)+14] = 186;
    tabuleiro[(LINHAS/2)-3][(COLUNAS/2)+14] = 186;
    tabuleiro[(LINHAS/2)+2][(COLUNAS/2)+14] = 186;
    tabuleiro[(LINHAS/2)-2][(COLUNAS/2)+14] = 186;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/2)+14] = 186;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/2)+14] = 186;
    tabuleiro[LINHAS/2][(COLUNAS/2)+14] = 186;
    tabuleiro[LINHAS/2][(COLUNAS/2)+14] = 186;

    tabuleiro[LINHAS/2][(COLUNAS/4)+2] = 186;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)+2] = 187;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/4)+2] = 188;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)+2] = 187;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)+1] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/4)+1] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)+1] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/4)+1] = 205;
    tabuleiro[(LINHAS/2)-1][COLUNAS/4] = 205;
    tabuleiro[(LINHAS/2)+1][COLUNAS/4] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)-1] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/4)-1] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)-2] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/4)-2] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)-3] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/4)-3] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)-4] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/4)-4] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)-5] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/4)-5] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)-6] = 205;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/4)-6] = 205;
    tabuleiro[(LINHAS/2)-1][(COLUNAS/4)-7] = 201;
    tabuleiro[(LINHAS/2)+1][(COLUNAS/4)-7] = 200;
    tabuleiro[LINHAS/2][(COLUNAS/4)-7] = 186;

    tabuleiro[LINHAS/2][((COLUNAS/4)*3)+7] = 186;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)+7] = 187;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)+7] = 188;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)+7] = 187;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)+6] = 205;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)+6] = 205;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)+6] = 205;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)+6] = 205;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)+5] = 205;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)+5] = 205;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)+4] = 205;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)+4] = 205;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)+3] = 205;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)+3] = 205;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)+2] = 205;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)+2] = 205;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)+1] = 205;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)+1] = 205;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)] = 205;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)] = 205;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)-1] = 205;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)-1] = 205;
    tabuleiro[(LINHAS/2)-1][((COLUNAS/4)*3)-2] = 201;
    tabuleiro[(LINHAS/2)+1][((COLUNAS/4)*3)-2] = 200;
    tabuleiro[LINHAS/2][((COLUNAS/4)*3)-2] = 186;


    tabuleiro[4][4] = 201;
    tabuleiro[5][4] = 186;
    tabuleiro[6][4] = 200;
    tabuleiro[4][5] = 205;
    tabuleiro[6][5] = 205;
    tabuleiro[4][6] = 205;
    tabuleiro[6][6] = 205;
    tabuleiro[4][7] = 205;
    tabuleiro[6][7] = 205;
    tabuleiro[4][8] = 205;
    tabuleiro[6][8] = 205;
    tabuleiro[4][9] = 205;
    tabuleiro[6][9] = 205;
    tabuleiro[4][10] = 205;
    tabuleiro[6][10] = 205;
    tabuleiro[4][11] = 205;
    tabuleiro[6][11] = 205;
    tabuleiro[4][12] = 187;
    tabuleiro[5][12] = 186;
    tabuleiro[6][12] = 188;

    tabuleiro[4][COLUNAS-5] = 187;
    tabuleiro[5][COLUNAS-5] = 186;
    tabuleiro[6][COLUNAS-5] = 188;
    tabuleiro[4][COLUNAS-6] = 205;
    tabuleiro[6][COLUNAS-6] = 205;
    tabuleiro[4][COLUNAS-7] = 205;
    tabuleiro[6][COLUNAS-7] = 205;
    tabuleiro[4][COLUNAS-8] = 205;
    tabuleiro[6][COLUNAS-8] = 205;
    tabuleiro[4][COLUNAS-9] = 205;
    tabuleiro[6][COLUNAS-9] = 205;
    tabuleiro[4][COLUNAS-10] = 205;
    tabuleiro[6][COLUNAS-10] = 205;
    tabuleiro[4][COLUNAS-11] = 205;
    tabuleiro[6][COLUNAS-11] = 205;
    tabuleiro[4][COLUNAS-12] = 205;
    tabuleiro[6][COLUNAS-12] = 205;
    tabuleiro[4][COLUNAS-13] = 201;
    tabuleiro[5][COLUNAS-13] = 186;
    tabuleiro[6][COLUNAS-13] = 200;

    tabuleiro[4][16] = 201;
    tabuleiro[4][17] = 205;
    tabuleiro[4][18] = 205;
    tabuleiro[4][19] = 205;
    tabuleiro[4][20] = 205;
    tabuleiro[4][21] = 205;
    tabuleiro[4][22] = 205;
    tabuleiro[4][23] = 205;
    tabuleiro[4][24] = 205;
    tabuleiro[4][25] = 205;
    tabuleiro[4][26] = 205;
    tabuleiro[4][27] = 205;
    tabuleiro[4][28] = 205;
    tabuleiro[4][29] = 205;
    tabuleiro[4][30] = 187;
    tabuleiro[4][16] = 201;
    tabuleiro[5][16] = 186;
    tabuleiro[6][16] = 186;
    tabuleiro[7][16] = 186;
    tabuleiro[8][16] = 186;
    tabuleiro[9][16] = 186;
    tabuleiro[10][16] = 200;
    tabuleiro[10][17] = 205;
    tabuleiro[10][17] = 205;
    tabuleiro[10][18] = 205;
    tabuleiro[10][19] = 205;
    tabuleiro[10][20] = 205;
    tabuleiro[10][21] = 205;
    tabuleiro[10][22] = 188;
    tabuleiro[9][22] = 186;
    tabuleiro[8][22] = 186;
    tabuleiro[7][22] = 186;
    tabuleiro[6][22] = 186;
    tabuleiro[5][22] = 201;
    tabuleiro[5][23] = 205;
    tabuleiro[5][24] = 205;
    tabuleiro[5][25] = 205;
    tabuleiro[5][26] = 205;
    tabuleiro[5][27] = 205;
    tabuleiro[5][28] = 205;
    tabuleiro[5][29] = 205;
    tabuleiro[5][30] = 188;

    tabuleiro[4][(COLUNAS/2)+10] = 201;
    tabuleiro[4][(COLUNAS/2)+11] = 205;
    tabuleiro[4][(COLUNAS/2)+12] = 205;
    tabuleiro[4][(COLUNAS/2)+13] = 205;
    tabuleiro[4][(COLUNAS/2)+14] = 205;
    tabuleiro[4][(COLUNAS/2)+15] = 205;
    tabuleiro[4][(COLUNAS/2)+16] = 205;
    tabuleiro[4][(COLUNAS/2)+17] = 205;
    tabuleiro[4][(COLUNAS/2)+18] = 205;
    tabuleiro[4][(COLUNAS/2)+19] = 205;
    tabuleiro[4][(COLUNAS/2)+20] = 205;
    tabuleiro[4][(COLUNAS/2)+21] = 205;
    tabuleiro[4][(COLUNAS/2)+22] = 205;
    tabuleiro[4][(COLUNAS/2)+23] = 205;
    tabuleiro[4][(COLUNAS/2)+24] = 187;
    tabuleiro[5][(COLUNAS/2)+24] = 186;
    tabuleiro[6][(COLUNAS/2)+24] = 186;
    tabuleiro[7][(COLUNAS/2)+24] = 186;
    tabuleiro[8][(COLUNAS/2)+24] = 186;
    tabuleiro[9][(COLUNAS/2)+24] = 186;
    tabuleiro[10][(COLUNAS/2)+24] = 188;
    tabuleiro[10][(COLUNAS/2)+23] = 205;
    tabuleiro[10][(COLUNAS/2)+22] = 205;
    tabuleiro[10][(COLUNAS/2)+21] = 205;
    tabuleiro[10][(COLUNAS/2)+20] = 205;
    tabuleiro[10][(COLUNAS/2)+19] = 205;
    tabuleiro[10][(COLUNAS/2)+18] = 200;
    tabuleiro[9][(COLUNAS/2)+18] = 186;
    tabuleiro[8][(COLUNAS/2)+18] = 186;
    tabuleiro[7][(COLUNAS/2)+18] = 186;
    tabuleiro[6][(COLUNAS/2)+18] = 186;
    tabuleiro[5][(COLUNAS/2)+18] = 187;
    tabuleiro[5][(COLUNAS/2)+17] = 205;
    tabuleiro[5][(COLUNAS/2)+16] = 205;
    tabuleiro[5][(COLUNAS/2)+15] = 205;
    tabuleiro[5][(COLUNAS/2)+14] = 205;
    tabuleiro[5][(COLUNAS/2)+13] = 205;
    tabuleiro[5][(COLUNAS/2)+12] = 205;
    tabuleiro[5][(COLUNAS/2)+11] = 205;
    tabuleiro[5][(COLUNAS/2)+10] = 200;

    tabuleiro[(LINHAS/2)+5][(COLUNAS/4)+2] = 187;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/4)+1] = 205;    
    tabuleiro[(LINHAS/2)+5][COLUNAS/4] = 205;    
    tabuleiro[(LINHAS/2)+5][(COLUNAS/4)-1] = 205;    
    tabuleiro[(LINHAS/2)+5][(COLUNAS/4)-2] = 201;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/4)-2] = 186;
    tabuleiro[(LINHAS/2)+7][(COLUNAS/4)-2] = 186;
    tabuleiro[(LINHAS/2)+8][(COLUNAS/4)-2] = 186;
    tabuleiro[(LINHAS/2)+9][(COLUNAS/4)-2] = 186;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/4)-2] = 186;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)-2] = 200;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)-1] = 205;
    tabuleiro[(LINHAS/2)+11][COLUNAS/4] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)+1] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)+2] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)+3] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)+4] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)+5] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)+6] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)+7] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)+8] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)+9] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)+10] = 188;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/4)+10] = 187;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/4)+9] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/4)+8] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/4)+7] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/4)+6] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/4)+5] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/4)+4] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/4)+3] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/4)+2] = 200;
    tabuleiro[(LINHAS/2)+9][(COLUNAS/4)+2] = 186;
    tabuleiro[(LINHAS/2)+8][(COLUNAS/4)+2] = 186;
    tabuleiro[(LINHAS/2)+7][(COLUNAS/4)+2] = 186;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/4)+2] = 186;

    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+10] = 201;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+10] = 200;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+11] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+12] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+13] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+14] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+15] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+16] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+17] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+18] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+19] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+20] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+21] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/2)+22] = 188;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+22] = 186;
    tabuleiro[(LINHAS/2)+9][(COLUNAS/2)+22] = 186;
    tabuleiro[(LINHAS/2)+8][(COLUNAS/2)+22] = 186;
    tabuleiro[(LINHAS/2)+7][(COLUNAS/2)+22] = 186;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)+22] = 186;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/2)+22] = 187;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/2)+21] = 205;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/2)+20] = 205;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/2)+19] = 205;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/2)+18] = 201;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/2)+18] = 186;
    tabuleiro[(LINHAS/2)+7][(COLUNAS/2)+18] = 186;
    tabuleiro[(LINHAS/2)+8][(COLUNAS/2)+18] = 186;
    tabuleiro[(LINHAS/2)+9][(COLUNAS/2)+18] = 186;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+18] = 188;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+17] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+16] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+15] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+14] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+13] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+12] = 205;
    tabuleiro[(LINHAS/2)+10][(COLUNAS/2)+11] = 205;

    tabuleiro[(LINHAS/2)+5][(COLUNAS/4)-6] = 187;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/4)-6] = 186;
    tabuleiro[(LINHAS/2)+7][(COLUNAS/4)-6] = 188;
    tabuleiro[(LINHAS/2)+5][(COLUNAS/4)-7] = 201;
    tabuleiro[(LINHAS/2)+6][(COLUNAS/4)-7] = 186;
    tabuleiro[(LINHAS/2)+7][(COLUNAS/4)-7] = 200;

    tabuleiro[(LINHAS/2)+5][((COLUNAS/4)*3)+6] = 201;
    tabuleiro[(LINHAS/2)+6][((COLUNAS/4)*3)+6] = 186;
    tabuleiro[(LINHAS/2)+7][((COLUNAS/4)*3)+6] = 200;
    tabuleiro[(LINHAS/2)+5][((COLUNAS/4)*3)+7] = 187;
    tabuleiro[(LINHAS/2)+6][((COLUNAS/4)*3)+7] = 186;
    tabuleiro[(LINHAS/2)+7][((COLUNAS/4)*3)+7] = 188;

    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)-6] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)-7] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)-8] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)-9] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)-10] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)-11] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)-12] = 205;
    tabuleiro[(LINHAS/2)+11][(COLUNAS/4)-13] = 205;

    tabuleiro[(LINHAS/2)+11][((COLUNAS/4)*3)+6] = 205;
    tabuleiro[(LINHAS/2)+11][((COLUNAS/4)*3)+7] = 205;
    tabuleiro[(LINHAS/2)+11][((COLUNAS/4)*3)+8] = 205;
    tabuleiro[(LINHAS/2)+11][((COLUNAS/4)*3)+9] = 205;
    tabuleiro[(LINHAS/2)+11][((COLUNAS/4)*3)+10] = 205;
    tabuleiro[(LINHAS/2)+11][((COLUNAS/4)*3)+11] = 205;
    tabuleiro[(LINHAS/2)+11][((COLUNAS/4)*3)+12] = 205;
    tabuleiro[(LINHAS/2)+11][((COLUNAS/4)*3)+13] = 205;
}

struct moeda
{
    int x;
    int y;
    int aparece;
    int especial;
};


void desenha_moeda(unsigned char tabuleiro[LINHAS][COLUNAS], struct moeda m)
{
    if (m.aparece == 1)
    {
        if (m.especial == 0)
            tabuleiro[m.x][m.y] = 79;
        else
        {
            tabuleiro[m.x][m.y] = '@';
            tabuleiro[m.x][m.y+1] = '@';
            tabuleiro[m.x+1][m.y] = '@';
            tabuleiro[m.x+1][m.y+1] = '@';
        }
    }
    else
    {
        if (m.especial == 0)
        {
            tabuleiro[m.x][m.y-1] = ' ';
            tabuleiro[m.x][m.y] = ' ';
            tabuleiro[m.x][m.y+1] = ' ';
        }
        else
        {
            tabuleiro[m.x][m.y] = ' ';
            tabuleiro[m.x][m.y+1] = ' ';
            tabuleiro[m.x+1][m.y] = ' ';
            tabuleiro[m.x+1][m.y+1] = ' ';
        }
    }
}

void imprime_moedas(unsigned char tabuleiro[LINHAS][COLUNAS], struct moeda moedas[152])
{
    int i;
    for (i=0; i<152; i++)
        desenha_moeda(tabuleiro, moedas[i]);
}

void apaga_moeda(unsigned char tabuleiro[LINHAS][COLUNAS], struct moeda moedas[152], int x, int y)
{
    int i;
    for (i=0; i<152; i++)
    {
        if ((moedas[i].x == x && moedas[i].y == y) || (moedas[i].x == x && moedas[i].y-1 == y) || (moedas[i].x == x && moedas[i].y+1 == y))
        {
            moedas[i].aparece = 0;
            desenha_moeda(tabuleiro, moedas[i]);
        }
    }
}

void inicializa_moedas(struct moeda moedas[152])
{
    int i, j;
    for (i=0, j=2; i<=25 && j<COLUNAS-2; i++, j+=3)
    {
        moedas[i].x = 2;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=26, j=4; i<=27 && j<7; i++, j+=2)
    {
        moedas[i].x = j;
        moedas[i].y = 2;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=28, j=4; i<=29 && j<7; i++, j+=2)
    {
        moedas[i].x = j;
        moedas[i].y = COLUNAS-3;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=30, j=5; i<=32 && j<12; i++, j+=3)
    {
        moedas[i].x = 8;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=33, j=COLUNAS-6; i<=34 && j>COLUNAS-12; i++, j-=3)
    {
        moedas[i].x = 8;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=35, j=4; i<=39 && j<13; i++, j+=2)
    {
        moedas[i].x = j;
        moedas[i].y = 14;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=40, j=10; i<=46 && j<23; i++, j+=2)
    {
        moedas[i].x = j;
        moedas[i].y = 11;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=47, j=8; i<=54 && j<23; i++, j+=2)
    {
        moedas[i].x = j;
        moedas[i].y = COLUNAS-12;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=55, j=4; i<=59 && j<13; i++, j+=2)
    {
        moedas[i].x = j;
        moedas[i].y = COLUNAS-15;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=60, j=24; i<=64 && j<37; i++, j+=3)
    {
        moedas[i].x = 7;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=65, j=43; i<=69 && j<56; i++, j+=3)
    {
        moedas[i].x = 7;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    moedas[70].x = 5;
    moedas[70].y = 32;
    moedas[70].aparece = 1;
    moedas[70].especial = 0;
    moedas[71].x = 5;
    moedas[71].y = 48;
    moedas[71].aparece = 1;
    moedas[71].especial = 0;
    for (i=72, j=9; i<=79 && j<24; i++, j+=2)
    {
        moedas[i].x = j;
        moedas[i].y = 24;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=80, j=9; i<=87 && j<24; i++, j+=2)
    {
        moedas[i].x = j;
        moedas[i].y = 56;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=88, j=18; i<=89 && j<22; i++, j+=3)
    {
        moedas[i].x = 12;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    moedas[90].x = 12;
    moedas[90].y = COLUNAS-19;
    moedas[90].aparece = 1;
    moedas[90].especial = 0;
    moedas[91].x = 12;
    moedas[91].y = COLUNAS-22;
    moedas[91].aparece = 1;
    moedas[91].especial = 0;
    for (i=92, j=18; i<=93 && j<23; i++, j+=3)
    {
        moedas[i].x = 18;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    moedas[94].x = 18;
    moedas[94].y = 14;
    moedas[94].aparece = 1;
    moedas[94].especial = 0;
    for (i=95, j=COLUNAS-18; i<=96 && j>COLUNAS-24; i++, j-=4)
    {
        moedas[i].x = 18;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    moedas[97].x = 18;
    moedas[97].y = COLUNAS-15;
    moedas[97].aparece = 1;
    moedas[97].especial = 0;
    for (i=98, j=27; i<=101 && j<37; i++, j+=3)
    {
        moedas[i].x = 23;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=102, j=44; i<=105 && j<54; i++, j+=3)
    {
        moedas[i].x = 23;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    moedas[106].x = LINHAS-6;
    moedas[106].y = 32;
    moedas[106].aparece = 1;
    moedas[106].especial = 0;
    moedas[107].x = LINHAS-6;
    moedas[107].y = 48;
    moedas[107].aparece = 1;
    moedas[107].especial = 0;
    for (i=108, j=20; i<=109 && j<23; i++, j+=2)
    {
        moedas[i].x = j;
        moedas[i].y = 16;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=110, j=20; i<=111 && j<23; i++, j+=2)
    {
        moedas[i].x = j;
        moedas[i].y = COLUNAS-17;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=112, j=6; i<=114 && j<13; i++, j+=3)
    {
        moedas[i].x = LINHAS-7;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=115, j=COLUNAS-7; i<=117 && j>COLUNAS-14; i++, j-=3)
    {
        moedas[i].x = LINHAS-7;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    moedas[118].x = LINHAS-7;
    moedas[118].y = 16;
    moedas[118].aparece = 1;
    moedas[118].especial = 0;
    moedas[119].x = LINHAS-5;
    moedas[119].y = 16;
    moedas[119].aparece = 1;
    moedas[119].especial = 0;
    moedas[120].x = LINHAS-7;
    moedas[120].y = COLUNAS-17;
    moedas[120].aparece = 1;
    moedas[120].especial = 0;
    moedas[121].x = LINHAS-5;
    moedas[121].y = COLUNAS-6;
    moedas[121].aparece = 1;
    moedas[121].especial = 0;
    moedas[122].x = LINHAS-5;
    moedas[122].y = COLUNAS-17;
    moedas[122].aparece = 1;
    moedas[122].especial = 0;
    moedas[123].x = LINHAS-5;
    moedas[123].y = 5;
    moedas[123].aparece = 1;
    moedas[123].especial = 0;
    for (i=124, j=2; i<=135 && j<(COLUNAS/2)-2; i++, j+=3)
    {
        moedas[i].x = LINHAS-3;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    for (i=136, j=(COLUNAS/2)+5; i<=146 && j<COLUNAS-4; i++, j+=3)
    {
        moedas[i].x = LINHAS-3;
        moedas[i].y = j;
        moedas[i].aparece = 1;
        moedas[i].especial = 0;
    }
    moedas[147].x = LINHAS-3;
    moedas[147].y = COLUNAS-3;
    moedas[147].aparece = 1;
    moedas[147].especial = 0;
    
    /* pastilhas especiais */
    moedas[148].x = 8;
    moedas[148].y = 1;
    moedas[148].aparece = 1;
    moedas[148].especial = 1;
    moedas[149].x = 8;
    moedas[149].y = COLUNAS-3;
    moedas[149].aparece = 1;
    moedas[149].especial = 1;
    moedas[150].x = LINHAS-7;
    moedas[150].y = 1;
    moedas[150].aparece = 1;
    moedas[150].especial = 1;
    moedas[151].x = LINHAS-7;
    moedas[151].y = COLUNAS-3;
    moedas[151].aparece = 1;
    moedas[151].especial = 1;
}

void imprime_tabuleiro (unsigned char tabuleiro[LINHAS][COLUNAS])
{
    int i, j;

    for (i=0;i<LINHAS;i++)
    {
        for (j=0; j<COLUNAS; j++)
        {   if (tabuleiro[i][j] == '@')
            {
                attron(COLOR_PAIR(2));
                mvprintw(i+6, j+4, "%c", tabuleiro[i][j]);
                attroff(COLOR_PAIR(2));
            }
            else
                mvprintw(i+6, j+4, "%c", tabuleiro[i][j]);
        }
    }

    /* textos */
	attron(COLOR_PAIR(1));
    mvprintw(1, 30, "/");
    mvprintw(2, 30, "/");
    mvprintw(3, 30, "/");
    mvprintw(4, 30, "/");
    mvprintw(1, 31, "/");
    mvprintw(1, 32, "/");
    mvprintw(1, 33, "/");
    mvprintw(3, 33, "/");
    mvprintw(3, 32, "/");
    mvprintw(3, 31, "/");
    mvprintw(2, 33, "/");
    mvprintw(1, 35, "/");
    mvprintw(2, 35, "/");
    mvprintw(3, 35, "/");
    mvprintw(4, 35, "/");
    mvprintw(1, 36, "/");
    mvprintw(1, 37, "/");
    mvprintw(1, 38, "/");
    mvprintw(3, 37, "/");
    mvprintw(3, 36, "/");
    mvprintw(2, 38, "/");
    mvprintw(3, 38, "/");
    mvprintw(4, 38, "/");
    mvprintw(1, 40, "/");
    mvprintw(1, 41, "/");
    mvprintw(1, 42, "/");
    mvprintw(1, 43, "/");
    mvprintw(2, 40, "/");
    mvprintw(3, 40, "/");
    mvprintw(4, 40, "/");
    mvprintw(4, 41, "/");
    mvprintw(4, 42, "/");
    mvprintw(4, 43, "/");
    mvprintw(1, 45, "/");
    mvprintw(1, 46, "/");
    mvprintw(2, 47, "/");
    mvprintw(1, 48, "/");
    mvprintw(1, 49, "/");
    mvprintw(2, 49, "/");
    mvprintw(3, 49, "/");
    mvprintw(4, 49, "/");
    mvprintw(2, 45, "/");
    mvprintw(3, 45, "/");
    mvprintw(4, 45, "/");
    mvprintw(1, 51, "/");
    mvprintw(1, 52, "/");
    mvprintw(1, 53, "/");
    mvprintw(1, 54, "/");
    mvprintw(2, 51, "/");
    mvprintw(3, 51, "/");
    mvprintw(4, 51, "/");
    mvprintw(2, 54, "/");
    mvprintw(3, 54, "/");
    mvprintw(4, 54, "/");
    mvprintw(3, 52, "/");
    mvprintw(3, 53, "/");
    mvprintw(1, 56, "/");
    mvprintw(2, 56, "/");
    mvprintw(3, 56, "/");
    mvprintw(4, 56, "/");
    mvprintw(2, 59, "/");
    mvprintw(2, 57, "/");
    mvprintw(3, 58, "/");
    mvprintw(4, 59, "/");
    mvprintw(3, 59, "/");
    mvprintw(2, 59, "/");
    mvprintw(1, 59, "/");
	attroff(COLOR_PAIR(1));

    mvprintw(40, 35, "DIGITE 'Q' PARA SAIR");
    refresh();
}

int checa_pontos(unsigned char tabuleiro[LINHAS][COLUNAS], int fase)
{
    int i, j, soma = 0, soma_especiais = 0, total, pts_fase;
    for (i=0; i<LINHAS; i++)
    {
        for (j=0; j<COLUNAS; j++)
        {
            if (tabuleiro[i][j] == 79)
                soma = soma + 1;
            else if (tabuleiro[i][j] == '@')
                soma_especiais = soma_especiais + 1;
        }
    }
    if (fase == 1)
        pts_fase = 0;
    else if (fase == 2)
        pts_fase = 1870;
    else if (fase == 3)
        pts_fase = 1870*2;

    total = pts_fase + (10*(147 - soma)) + (100*((16 - soma_especiais)/4));
    return total;
}

int encerrou(unsigned char tabuleiro[LINHAS][COLUNAS])
{
    int i, j;
    for (i=0; i<LINHAS; i++)
        for (j=0; j<COLUNAS; j++)
            switch (tabuleiro[i][j])
            {
            case 79:
            case '@':
                return 0;
                break;
            
            default:
                break;
            }
    return 1;
}

struct pac
{
    int x;
    int y;
    int direcao;
};

struct fantasma
{
    int x;
    int y;
    int direcao;
};

void posiciona_pacman(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac)
{
    switch (ptr_pac->direcao)
    {
    case 1: /* esquerda */
        tabuleiro[ptr_pac->x-1][ptr_pac->y-1] = 220;
        tabuleiro[ptr_pac->x][ptr_pac->y-1] = ' ';
        tabuleiro[ptr_pac->x-1][ptr_pac->y] = 220;
        tabuleiro[ptr_pac->x-1][ptr_pac->y+1] = 220;
        tabuleiro[ptr_pac->x][ptr_pac->y] = ' ';
        tabuleiro[ptr_pac->x][ptr_pac->y+1] = 222;
        tabuleiro[ptr_pac->x+1][ptr_pac->y] = 223;
        tabuleiro[ptr_pac->x+1][ptr_pac->y-1] = 223;
        tabuleiro[ptr_pac->x+1][ptr_pac->y+1] = 223;
        break;

    case 2: /* direita */
        tabuleiro[ptr_pac->x-1][ptr_pac->y-1] = 220;
        tabuleiro[ptr_pac->x][ptr_pac->y-1] = 221;
        tabuleiro[ptr_pac->x-1][ptr_pac->y] = 220;
        tabuleiro[ptr_pac->x-1][ptr_pac->y+1] = 220;
        tabuleiro[ptr_pac->x][ptr_pac->y] = ' ';
        tabuleiro[ptr_pac->x][ptr_pac->y+1] = ' ';
        tabuleiro[ptr_pac->x+1][ptr_pac->y] = 223;
        tabuleiro[ptr_pac->x+1][ptr_pac->y-1] = 223;
        tabuleiro[ptr_pac->x+1][ptr_pac->y+1] = 223;
        break;

    case 3: /* cima */
        tabuleiro[ptr_pac->x-1][ptr_pac->y-1] = 221;
        tabuleiro[ptr_pac->x][ptr_pac->y-1] = 221;
        tabuleiro[ptr_pac->x-1][ptr_pac->y] = ' ';
        tabuleiro[ptr_pac->x-1][ptr_pac->y+1] = 222;
        tabuleiro[ptr_pac->x][ptr_pac->y] = ' ';
        tabuleiro[ptr_pac->x][ptr_pac->y+1] = 222;
        tabuleiro[ptr_pac->x+1][ptr_pac->y] = 223;
        tabuleiro[ptr_pac->x+1][ptr_pac->y-1] = 223;
        tabuleiro[ptr_pac->x+1][ptr_pac->y+1] = 223;
        break;

    case 4: /* baixo */
        tabuleiro[ptr_pac->x-1][ptr_pac->y-1] = 220;
        tabuleiro[ptr_pac->x][ptr_pac->y-1] = 221;
        tabuleiro[ptr_pac->x-1][ptr_pac->y] = 220;
        tabuleiro[ptr_pac->x-1][ptr_pac->y+1] = 220;
        tabuleiro[ptr_pac->x][ptr_pac->y] = ' ';
        tabuleiro[ptr_pac->x][ptr_pac->y+1] = 222;
        tabuleiro[ptr_pac->x+1][ptr_pac->y] = ' ';
        tabuleiro[ptr_pac->x+1][ptr_pac->y-1] = 221;
        tabuleiro[ptr_pac->x+1][ptr_pac->y+1] = 222;
        break;
    }
}

void posiciona_fantasma(unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma)
{
    switch (ptr_fantasma->direcao)
    {
    case 1: /* esquerda */
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y-1] = 220;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y-1] = 250;
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y] = 220;
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y+1] = 220;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y] = 250;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y+1] = 222;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y] = 221;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y-1] = 221;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y+1] = 221;
        break;

    case 2: /* direita */
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y-1] = 220;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y-1] = 221;
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y] = 220;
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y+1] = 220;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y] = 250;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y+1] = 250;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y] = 222;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y-1] = 222;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y+1] = 222;
        break;

    case 3: /* cima */
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y-1] = 221;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y-1] = 223;
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y] = 250;
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y+1] = 250;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y] = 223;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y+1] = 223;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y] = 222;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y-1] = 222;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y+1] = 222;
        break;

    case 4: /* baixo */
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y-1] = 221;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y-1] = 220;
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y] = 221;
        tabuleiro[ptr_fantasma->x-1][ptr_fantasma->y+1] = 221;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y] = 220;
        tabuleiro[ptr_fantasma->x][ptr_fantasma->y+1] = 220;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y] = 250;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y-1] = 250;
        tabuleiro[ptr_fantasma->x+1][ptr_fantasma->y+1] = 222;
        break;
    }
}

void inicia_fantasmas (unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma1, struct fantasma *ptr_fantasma2, struct fantasma *ptr_fantasma3, struct fantasma *ptr_fantasma4)
{
    ptr_fantasma1->x = (LINHAS/2)-4;
    ptr_fantasma1->y = COLUNAS/2;
    ptr_fantasma1->direcao = 1;
    posiciona_fantasma(tabuleiro, ptr_fantasma1);

    ptr_fantasma2->x = LINHAS/2;
    ptr_fantasma2->y = (COLUNAS/2)-3;
    ptr_fantasma2->direcao = 3;
    posiciona_fantasma(tabuleiro, ptr_fantasma2);

    ptr_fantasma3->x = LINHAS/2;
    ptr_fantasma3->y = COLUNAS/2;
    ptr_fantasma3->direcao = 4;
    posiciona_fantasma(tabuleiro, ptr_fantasma3);

    ptr_fantasma4->x = LINHAS/2;
    ptr_fantasma4->y = (COLUNAS/2)+3;
    ptr_fantasma4->direcao = 3;
    posiciona_fantasma(tabuleiro, ptr_fantasma4);
}

void limpa_estrutura(unsigned char tabuleiro[LINHAS][COLUNAS], int x, int y)
{
    tabuleiro[x-1][y+1] = ' ';
    tabuleiro[x][y+1] = ' ';
    tabuleiro[x+1][y+1] = ' ';
    tabuleiro[x-1][y] = ' ';
    tabuleiro[x][y] = ' ';
    tabuleiro[x+1][y] = ' ';
    tabuleiro[x-1][y-1] = ' ';
    tabuleiro[x][y-1] = ' ';
    tabuleiro[x+1][y-1] = ' ';
}


int parede (unsigned char tabuleiro[LINHAS][COLUNAS], int x, int y, int direcao)
{
    if (direcao == 1)    /* checa parede na esquerda */
    {
        if (tabuleiro[x][y-2] == 186 || tabuleiro[x][y-2] == 205 || tabuleiro[x][y-2] == 187 || tabuleiro[x][y-2] == 188 || tabuleiro[x][y-2] == 200 || tabuleiro[x][y-2] == 201)
        {
            return 1;
        }
        if (tabuleiro[x-1][y-2] == 186 || tabuleiro[x-1][y-2] == 205 || tabuleiro[x-1][y-2] == 187 || tabuleiro[x-1][y-2] == 188 || tabuleiro[x-1][y-2] == 200 || tabuleiro[x-1][y-2] == 201)
        {
            return 1;
        }
        if (tabuleiro[x+1][y-2] == 186 || tabuleiro[x+1][y-2] == 205 || tabuleiro[x+1][y-2] == 187 || tabuleiro[x+1][y-2] == 188 || tabuleiro[x+1][y-2] == 200 || tabuleiro[x+1][y-2] == 201)
        {
            return 1;
        }
    }

    if (direcao == 2)    /* checa parede na direita */
    {
        if (tabuleiro[x][y+2] == 186 || tabuleiro[x][y+2] == 205 || tabuleiro[x][y+2] == 187 || tabuleiro[x][y+2] == 188 || tabuleiro[x][y+2] == 200 || tabuleiro[x][y+2] == 201)
        {
            return 1;
        }
        if (tabuleiro[x-1][y+2] == 186 || tabuleiro[x-1][y+2] == 205 || tabuleiro[x-1][y+2] == 187 || tabuleiro[x-1][y+2] == 188 || tabuleiro[x-1][y+2] == 200 || tabuleiro[x-1][y+2] == 201)
        {
            return 1;
        }
        if (tabuleiro[x+1][y+2] == 186 || tabuleiro[x+1][y+2] == 205 || tabuleiro[x+1][y+2] == 187 || tabuleiro[x+1][y+2] == 188 || tabuleiro[x+1][y+2] == 200 || tabuleiro[x+1][y+2] == 201)
        {
            return 1;
        }
    }

    if (direcao == 3)    /* checa parede em cima */
    {
        if (tabuleiro[x-2][y] == 186 || tabuleiro[x-2][y] == 205 || tabuleiro[x-2][y] == 187 || tabuleiro[x-2][y] == 188 || tabuleiro[x-2][y] == 200 || tabuleiro[x-2][y] == 201)
        {
            return 1;
        }
        if (tabuleiro[x-2][y-1] == 186 || tabuleiro[x-2][y-1] == 205 || tabuleiro[x-2][y-1] == 187 || tabuleiro[x-2][y-1] == 188 || tabuleiro[x-2][y-1] == 200 || tabuleiro[x-2][y-1] == 201)
        {
            return 1;
        }
        if (tabuleiro[x-2][y+1] == 186 || tabuleiro[x-2][y+1] == 205 || tabuleiro[x-2][y+1] == 187 || tabuleiro[x-2][y+1] == 188 || tabuleiro[x-2][y+1] == 200 || tabuleiro[x-2][y+1] == 201)
        {
            return 1;
        }
    }

    if (direcao == 4)    /* checa parede em baixo */
    {
        if (tabuleiro[x+2][y] == 186 || tabuleiro[x+2][y] == 205 || tabuleiro[x+2][y] == 187 || tabuleiro[x+2][y] == 188 || tabuleiro[x+2][y] == 200 || tabuleiro[x+2][y] == 201)
        {
            return 1;
        }
        if (tabuleiro[x+2][y-1] == 186 || tabuleiro[x+2][y-1] == 205 || tabuleiro[x+2][y-1] == 187 || tabuleiro[x+2][y-1] == 188 || tabuleiro[x+2][y-1] == 200 || tabuleiro[x+2][y-1] == 201)
        {
            return 1;
        }
        if (tabuleiro[x+2][y+1] == 186 || tabuleiro[x+2][y+1] == 205 || tabuleiro[x+2][y+1] == 187 || tabuleiro[x+2][y+1] == 188 || tabuleiro[x+2][y+1] == 200 || tabuleiro[x+2][y+1] == 201)
        {
            return 1;
        }
    }

    return 0;
}

int aplica_direcao(int tecla)
{
    switch (tecla)
    {
    case 'a':
    case KEY_LEFT:
        return 1;
    
    case 'd':
    case KEY_RIGHT:
        return 2;
    
    case 'w':
    case KEY_UP:
        return 3;

    case 's':
    case KEY_DOWN:
        return 4;
    }
}

void delay(int fase)
{
    if (fase == 1)
        usleep(VELOCIDADE);
    else if (fase == 2)
        usleep(VELOCIDADE - (VELOCIDADE*0.1));
    else if (fase == 3)
        usleep((VELOCIDADE - (VELOCIDADE*0.1)) - (0.1*(VELOCIDADE - (VELOCIDADE*0.1))));
}

int colisao(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pacman)
{
    /* checa colisao na esquerda */
    if (tabuleiro[ptr_pacman->x][(ptr_pacman->y)-2] != ' ' && tabuleiro[ptr_pacman->x][(ptr_pacman->y)-2] != 79 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)-2] != '@' && tabuleiro[ptr_pacman->x][(ptr_pacman->y)-2] != 186 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)-2] != 205 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)-2] != 187 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)-2] != 188 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)-2] != 200 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)-2] != 201)
    {
        return 1;
    }
    if (tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)-2] != ' ' && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)-2] != 79 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)-2] != '@' && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)-2] != 186 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)-2] != 205 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)-2] != 187 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)-2] != 188 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)-2] != 200 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)-2] != 201)
    {
        return 1;
    }
    if (tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)-2] != ' ' && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)-2] != 79 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)-2] != '@' && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)-2] != 186 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)-2] != 205 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)-2] != 187 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)-2] != 188 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)-2] != 200 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)-2] != 201)
    {
        return 1;
    }

    /* checa colisao na direita */
    if (tabuleiro[ptr_pacman->x][(ptr_pacman->y)+2] != ' ' && tabuleiro[ptr_pacman->x][(ptr_pacman->y)+2] != 79 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)+2] != '@' && tabuleiro[ptr_pacman->x][(ptr_pacman->y)+2] != 186 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)+2] != 205 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)+2] != 187 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)+2] != 188 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)+2] != 200 && tabuleiro[ptr_pacman->x][(ptr_pacman->y)+2] != 201)
    {
        return 1;
    }
    if (tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)+2] != ' ' && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)+2] != 79 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)+2] != '@' && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)+2] != 186 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)+2] != 205 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)+2] != 187 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)+2] != 188 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)+2] != 200 && tabuleiro[(ptr_pacman->x)-1][(ptr_pacman->y)+2] != 201)
    {
        return 1;
    }
    if (tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)+2] != ' ' && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)+2] != 79 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)+2] != '@' && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)+2] != 186 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)+2] != 205 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)+2] != 187 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)+2] != 188 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)+2] != 200 && tabuleiro[(ptr_pacman->x)+1][(ptr_pacman->y)+2] != 201)
    {
        return 1;
    }

    /* checa colisao em cima */
    if (tabuleiro[(ptr_pacman->x)-2][ptr_pacman->y] != ' ' && tabuleiro[(ptr_pacman->x)-2][ptr_pacman->y] != 79 && tabuleiro[(ptr_pacman->x)-2][ptr_pacman->y] != '@' && tabuleiro[(ptr_pacman->x)-2][ptr_pacman->y] != 186 && tabuleiro[(ptr_pacman->x)-2][ptr_pacman->y] != 205 && tabuleiro[(ptr_pacman->x)-2][ptr_pacman->y] != 187 && tabuleiro[(ptr_pacman->x)-2][ptr_pacman->y] != 188 && tabuleiro[(ptr_pacman->x)-2][ptr_pacman->y] != 200 && tabuleiro[(ptr_pacman->x)-2][ptr_pacman->y] != 201)
    {
        return 1;
    }
    if (tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)-1] != ' ' && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)-1] != 79 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)-1] != '@' && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)-1] != 186 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)-1] != 205 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)-1] != 187 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)-1] != 188 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)-1] != 200 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)-1] != 201)
    {
        return 1;
    }
    if (tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)+1] != ' ' && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)+1] != 79 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)+1] != '@' && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)+1] != 186 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)+1] != 205 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)+1] != 187 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)+1] != 188 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)+1] != 200 && tabuleiro[(ptr_pacman->x)-2][(ptr_pacman->y)+1] != 201)
    {
        return 1;
    }

    /* checa colisao em baixo */
    if (tabuleiro[(ptr_pacman->x)+2][ptr_pacman->y] != ' ' && tabuleiro[(ptr_pacman->x)+2][ptr_pacman->y] != 79 && tabuleiro[(ptr_pacman->x)+2][ptr_pacman->y] != '@' && tabuleiro[(ptr_pacman->x)+2][ptr_pacman->y] != 186 && tabuleiro[(ptr_pacman->x)+2][ptr_pacman->y] != 205 && tabuleiro[(ptr_pacman->x)+2][ptr_pacman->y] != 187 && tabuleiro[(ptr_pacman->x)+2][ptr_pacman->y] != 188 && tabuleiro[(ptr_pacman->x)+2][ptr_pacman->y] != 200 && tabuleiro[(ptr_pacman->x)+2][ptr_pacman->y] != 201)
    {
        return 1;
    }
    if (tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)-1] != ' ' && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)-1] != 79 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)-1] != '@' && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)-1] != 186 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)-1] != 205 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)-1] != 187 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)-1] != 188 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)-1] != 200 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)-1] != 201)
    {
        return 1;
    }
    if (tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)+1] != ' ' && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)+1] != 79 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)+1] != '@' && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)+1] != 186 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)+1] != 205 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)+1] != 187 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)+1] != 188 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)+1] != 200 && tabuleiro[(ptr_pacman->x)+2][(ptr_pacman->y)+1] != 201)
    {
        return 1;
    }

    return 0;
}

int bateu_fantasma(unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma)
{
    if (ptr_fantasma->direcao == 1)    /* checa fantasma na esquerda */
    {
        if (tabuleiro[ptr_fantasma->x][(ptr_fantasma->y)-2] == 220 || tabuleiro[ptr_fantasma->x][(ptr_fantasma->y)-2] == 221 || tabuleiro[ptr_fantasma->x][(ptr_fantasma->y)-2] == 222 || tabuleiro[ptr_fantasma->x][(ptr_fantasma->y)-2] == 223 || tabuleiro[ptr_fantasma->x][(ptr_fantasma->y)-2] == 250)
        {
            return 1;
        }
        if (tabuleiro[(ptr_fantasma->x)-1][(ptr_fantasma->y)-2] == 220 || tabuleiro[(ptr_fantasma->x)-1][(ptr_fantasma->y)-2] == 221 || tabuleiro[(ptr_fantasma->x)-1][(ptr_fantasma->y)-2] == 222 || tabuleiro[(ptr_fantasma->x)-1][(ptr_fantasma->y)-2] == 223 || tabuleiro[(ptr_fantasma->x)-1][(ptr_fantasma->y)-2] == 250)
        {
            return 1;
        }
        if (tabuleiro[(ptr_fantasma->x)+1][(ptr_fantasma->y)-2] == 220 || tabuleiro[(ptr_fantasma->x)+1][(ptr_fantasma->y)-2] == 221 || tabuleiro[(ptr_fantasma->x)+1][(ptr_fantasma->y)-2] == 222 || tabuleiro[(ptr_fantasma->x)+1][(ptr_fantasma->y)-2] == 223 || tabuleiro[(ptr_fantasma->x)+1][(ptr_fantasma->y)-2] == 250)
        {
            return 1;
        }
    }

    if (ptr_fantasma->direcao == 2)    /* checa fantasma na direita */
    {
        if (tabuleiro[ptr_fantasma->x][(ptr_fantasma->y)+2] == 220 || tabuleiro[ptr_fantasma->x][(ptr_fantasma->y)+2] == 221 || tabuleiro[ptr_fantasma->x][(ptr_fantasma->y)+2] == 222 || tabuleiro[ptr_fantasma->x][(ptr_fantasma->y)+2] == 223 || tabuleiro[ptr_fantasma->x][(ptr_fantasma->y)+2] == 250)
        {
            return 1;
        }
        if (tabuleiro[(ptr_fantasma->x)-1][(ptr_fantasma->y)+2] == 220 || tabuleiro[(ptr_fantasma->x)-1][(ptr_fantasma->y)+2] == 221 || tabuleiro[(ptr_fantasma->x)-1][(ptr_fantasma->y)+2] == 222 || tabuleiro[(ptr_fantasma->x)-1][(ptr_fantasma->y)+2] == 223 || tabuleiro[(ptr_fantasma->x)-1][(ptr_fantasma->y)+2] == 250)
        {
            return 1;
        }
        if (tabuleiro[(ptr_fantasma->x)+1][(ptr_fantasma->y)+2] == 220 || tabuleiro[(ptr_fantasma->x)+1][(ptr_fantasma->y)+2] == 221 || tabuleiro[(ptr_fantasma->x)+1][(ptr_fantasma->y)+2] == 222 || tabuleiro[(ptr_fantasma->x)+1][(ptr_fantasma->y)+2] == 223 || tabuleiro[(ptr_fantasma->x)+1][(ptr_fantasma->y)+2] == 250)
        {
            return 1;
        }
    }

    if (ptr_fantasma->direcao == 3)    /* checa fantasma em cima */
    {
        if (tabuleiro[(ptr_fantasma->x)-2][ptr_fantasma->y] == 220 || tabuleiro[(ptr_fantasma->x)-2][ptr_fantasma->y] == 221 || tabuleiro[(ptr_fantasma->x)-2][ptr_fantasma->y] == 222 || tabuleiro[(ptr_fantasma->x)-2][ptr_fantasma->y] == 223 || tabuleiro[(ptr_fantasma->x)-2][ptr_fantasma->y] == 250)
        {
            return 1;
        }
        if (tabuleiro[(ptr_fantasma->x)-2][(ptr_fantasma->y)-1] == 220 || tabuleiro[(ptr_fantasma->x)-2][(ptr_fantasma->y)-1] == 221 || tabuleiro[(ptr_fantasma->x)-2][(ptr_fantasma->y)-1] == 222 || tabuleiro[(ptr_fantasma->x)-2][(ptr_fantasma->y)-1] == 223 || tabuleiro[(ptr_fantasma->x)-2][(ptr_fantasma->y)-1] == 250)
        {
            return 1;
        }
        if (tabuleiro[(ptr_fantasma->x)-2][(ptr_fantasma->y)+1] == 220 || tabuleiro[(ptr_fantasma->x)-2][(ptr_fantasma->y)+1] == 221 || tabuleiro[(ptr_fantasma->x)-2][(ptr_fantasma->y)+1] == 222 || tabuleiro[(ptr_fantasma->x)-2][(ptr_fantasma->y)+1] == 223 || tabuleiro[(ptr_fantasma->x)-2][(ptr_fantasma->y)+1] == 250)
        {
            return 1;
        }
    }

    if (ptr_fantasma->direcao == 4)    /* checa fanstasma em baixo */
    {
        if (tabuleiro[(ptr_fantasma->x)+2][ptr_fantasma->y] == 220 || tabuleiro[(ptr_fantasma->x)+2][ptr_fantasma->y] == 221 || tabuleiro[(ptr_fantasma->x)+2][ptr_fantasma->y] == 222 || tabuleiro[(ptr_fantasma->x)+2][ptr_fantasma->y] == 223 || tabuleiro[(ptr_fantasma->x)+2][ptr_fantasma->y] == 250)
        {
            return 1;
        }
        if (tabuleiro[(ptr_fantasma->x)+2][(ptr_fantasma->y)-1] == 220 || tabuleiro[(ptr_fantasma->x)+2][(ptr_fantasma->y)-1] == 221 || tabuleiro[(ptr_fantasma->x)+2][(ptr_fantasma->y)-1] == 222 || tabuleiro[(ptr_fantasma->x)+2][(ptr_fantasma->y)-1] == 223 || tabuleiro[(ptr_fantasma->x)+2][(ptr_fantasma->y)-1] == 250)
        {
            return 1;
        }
        if (tabuleiro[(ptr_fantasma->x)+2][(ptr_fantasma->y)+1] == 220 || tabuleiro[(ptr_fantasma->x)+2][(ptr_fantasma->y)+1] == 221 || tabuleiro[(ptr_fantasma->x)+2][(ptr_fantasma->y)+1] == 222 || tabuleiro[(ptr_fantasma->x)+2][(ptr_fantasma->y)+1] == 223 || tabuleiro[(ptr_fantasma->x)+2][(ptr_fantasma->y)+1] == 250)
        {
            return 1;
        }
    }

    return 0;
}

void movimentacao_fantasma(unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma)
{
    int i, j, direcao_passada;
    i = rand()%2;
    j = rand()%2;
    if ((i || j) == 0)
    {
        direcao_passada = ptr_fantasma->direcao;
        ptr_fantasma->direcao = 1 + (rand() % 4);
    }
    if (parede(tabuleiro, ptr_fantasma->x, ptr_fantasma->y, ptr_fantasma->direcao))
        ptr_fantasma->direcao = direcao_passada;
    for (i=0; i<4 && (parede(tabuleiro, ptr_fantasma->x, ptr_fantasma->y, ptr_fantasma->direcao) || bateu_fantasma(tabuleiro, ptr_fantasma)); i++)
    {
        ptr_fantasma->direcao = 1 + (rand() % 4);
    }
    if (!bateu_fantasma(tabuleiro, ptr_fantasma) && !parede(tabuleiro, ptr_fantasma->x, ptr_fantasma->y, ptr_fantasma->direcao))
    {
        switch (ptr_fantasma->direcao)
        {
            case 1:
                if (((ptr_fantasma->y)-2) == 0)
                {
                    limpa_estrutura(tabuleiro, ptr_fantasma->x, ptr_fantasma->y);
                    ptr_fantasma->y = COLUNAS-2;
                    posiciona_fantasma(tabuleiro, ptr_fantasma);
                }
                else
                {
                    limpa_estrutura(tabuleiro, ptr_fantasma->x, ptr_fantasma->y);
                    ptr_fantasma->y = ptr_fantasma->y - 1;
                    posiciona_fantasma(tabuleiro, ptr_fantasma);
                }
                break;

            case 2:
                if (((ptr_fantasma->y)+2) == COLUNAS-1)
                {
                    limpa_estrutura(tabuleiro, ptr_fantasma->x, ptr_fantasma->y);
                    ptr_fantasma->y = 1;
                    posiciona_fantasma(tabuleiro, ptr_fantasma);
                }
                else
                {
                    limpa_estrutura(tabuleiro, ptr_fantasma->x, ptr_fantasma->y);
                    ptr_fantasma->y = ptr_fantasma->y + 1;
                    posiciona_fantasma(tabuleiro, ptr_fantasma);
                }
                break;

            case 3:
                limpa_estrutura(tabuleiro, ptr_fantasma->x, ptr_fantasma->y);
                ptr_fantasma->x = ptr_fantasma->x - 1;
                posiciona_fantasma(tabuleiro, ptr_fantasma);
                break;

            case 4:
                limpa_estrutura(tabuleiro, ptr_fantasma->x, ptr_fantasma->y);
                ptr_fantasma->x = ptr_fantasma->x + 1;
                posiciona_fantasma(tabuleiro, ptr_fantasma);
                break;
        }
    }
}

int achou_moeda(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac)
{
    switch (ptr_pac->direcao)
    {
    case 1:
        if (tabuleiro[ptr_pac->x][(ptr_pac->y)-2] == 79 || tabuleiro[ptr_pac->x][(ptr_pac->y)-2] == '@' || tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)-2] == 79 || tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)-2] == '@' || tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)-2] == 79 || tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)-2] == '@')
            return 1;
        else
            return 0;
        break;
    
    case 2:
        if (tabuleiro[ptr_pac->x][(ptr_pac->y)+2] == 79 || tabuleiro[ptr_pac->x][(ptr_pac->y)+2] == '@' || tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)+2] == 79 || tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)+2] == '@' || tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)+2] == 79 || tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)+2] == '@')
            return 1;
        else
            return 0;
        break;

    case 3:
        if (tabuleiro[(ptr_pac->x)-2][ptr_pac->y] == 79 || tabuleiro[(ptr_pac->x)-2][ptr_pac->y] == '@' || tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)-1] == 79 || tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)-1] == '@' || tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)+1] == 79 || tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)+1] == '@')
            return 1;
        else
            return 0;
        break;
    
    case 4:
        if (tabuleiro[(ptr_pac->x)+2][ptr_pac->y] == 79 || tabuleiro[(ptr_pac->x)+2][ptr_pac->y] == '@' || tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)-1] == 79 || tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)-1] == '@' || tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)+1] == 79 || tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)+1] == '@')
            return 1;
        else
            return 0;
        break;
    }
}

void movimentacao(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac, int fase, int *ptr_tecla, struct fantasma *ptr_fantasma1, struct fantasma *ptr_fantasma2, struct fantasma *ptr_fantasma3, struct fantasma *ptr_fantasma4, struct moeda moedas[152])
{
    int direcao, espera = 0;
    switch (*ptr_tecla)
    {
        case 'a':
        case KEY_LEFT:      /* seta pra esquerda */
            ptr_pac->direcao = 1;
            while (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, ptr_pac->direcao) && !encerrou(tabuleiro) && !colisao(tabuleiro, ptr_pac)) /* verifica se a próxima posição é a parede */
            {
                if (((ptr_pac->y)-2) == 0)     /* passagem para o outro lado do tabuleiro */
                {
                    limpa_estrutura(tabuleiro, ptr_pac->x, ptr_pac->y);
                    ptr_pac->y = COLUNAS-2;
                    imprime_moedas(tabuleiro, moedas);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma1);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma2);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma3);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma4);
                    posiciona_pacman(tabuleiro, ptr_pac);
                    imprime_tabuleiro(tabuleiro);
                    delay(fase);
                }
                else
                {
                    if (achou_moeda(tabuleiro, ptr_pac))
                        apaga_moeda(tabuleiro, moedas, ptr_pac->x, (ptr_pac->y)-2);
                    limpa_estrutura(tabuleiro, ptr_pac->x, ptr_pac->y);
                    ptr_pac->y = ptr_pac->y - 1;
                    imprime_moedas(tabuleiro, moedas);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma1);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma2);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma3);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma4);
                    posiciona_pacman(tabuleiro, ptr_pac);
                    mvprintw(37, 77, "%d PTS", checa_pontos(tabuleiro, fase));
                    imprime_tabuleiro(tabuleiro);
                    delay(fase);
                    if (espera == 0)   /* guarda ultima instrução para executar quando o caminho estiver livre */
                    {
                        *ptr_tecla = wgetch(stdscr);
                        if (*ptr_tecla == 'd' || *ptr_tecla == KEY_RIGHT || *ptr_tecla == 'w' || *ptr_tecla == KEY_UP || *ptr_tecla == 's' || *ptr_tecla == KEY_DOWN)
                        {
                            direcao = aplica_direcao(*ptr_tecla);
                            if (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, direcao))
                                movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                            else
                                espera = 1; 
                        }
                    }
                    else
                        if (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, direcao))
                            movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                    if (*ptr_tecla == 'q' || *ptr_tecla =='Q')
                        break;
                }
            }
            while(parede(tabuleiro, ptr_pac->x, ptr_pac->y, ptr_pac->direcao) && !encerrou(tabuleiro) && !colisao(tabuleiro, ptr_pac) && *ptr_tecla != 'q' && *ptr_tecla !='Q')
            {
                imprime_moedas(tabuleiro, moedas);
                movimentacao_fantasma(tabuleiro, ptr_fantasma1);
                movimentacao_fantasma(tabuleiro, ptr_fantasma2);
                movimentacao_fantasma(tabuleiro, ptr_fantasma3);
                movimentacao_fantasma(tabuleiro, ptr_fantasma4);
                imprime_tabuleiro(tabuleiro);
                *ptr_tecla = wgetch(stdscr);
                movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                delay(fase);
            }
            break;

        case 'd':
        case KEY_RIGHT:	    /* seta pra direita */
            ptr_pac->direcao = 2;
            while (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, ptr_pac->direcao) && !encerrou(tabuleiro) && !colisao(tabuleiro, ptr_pac)) /* verifica se a próxima posição é a parede */
            {
                if (((ptr_pac->y)+2) == COLUNAS-1)    /* passagem para o outro lado do tabuleiro */
                {
                    limpa_estrutura(tabuleiro, ptr_pac->x, ptr_pac->y);
                    ptr_pac->y = 1;
                    imprime_moedas(tabuleiro, moedas);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma1);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma2);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma3);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma4);
                    posiciona_pacman(tabuleiro, ptr_pac);
                    imprime_tabuleiro(tabuleiro);
                    delay(fase);
                }
                else
                {
                    if (achou_moeda(tabuleiro, ptr_pac))
                        apaga_moeda(tabuleiro, moedas, ptr_pac->x, (ptr_pac->y)+2);
                    limpa_estrutura(tabuleiro, ptr_pac->x, ptr_pac->y);
                    ptr_pac->y = ptr_pac->y + 1;
                    imprime_moedas(tabuleiro, moedas);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma1);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma2);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma3);
                    movimentacao_fantasma(tabuleiro, ptr_fantasma4);
                    posiciona_pacman(tabuleiro, ptr_pac);
                    mvprintw(37, 77, "%d PTS", checa_pontos(tabuleiro, fase));
                    imprime_tabuleiro(tabuleiro);
                    delay(fase);
                    if (espera == 0)   /* guarda ultima instrução para executar quando o caminho estiver livre */
                    {
                        *ptr_tecla = wgetch(stdscr);
                        if (*ptr_tecla == 'e' || *ptr_tecla == KEY_LEFT || *ptr_tecla == 'w' || *ptr_tecla == KEY_UP || *ptr_tecla == 's' || *ptr_tecla == KEY_DOWN)
                        {
                            direcao = aplica_direcao(*ptr_tecla);
                            if (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, direcao))
                                movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                            else
                                espera = 1; 
                        }
                    }
                    else
                        if (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, direcao))
                            movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                    if (*ptr_tecla == 'q' || *ptr_tecla =='Q')
                        break;
                }
            }
            while(parede(tabuleiro, ptr_pac->x, ptr_pac->y, ptr_pac->direcao) && !encerrou(tabuleiro) && !colisao(tabuleiro, ptr_pac) && *ptr_tecla != 'q' && *ptr_tecla !='Q')
            {
                imprime_moedas(tabuleiro, moedas);
                movimentacao_fantasma(tabuleiro, ptr_fantasma1);
                movimentacao_fantasma(tabuleiro, ptr_fantasma2);
                movimentacao_fantasma(tabuleiro, ptr_fantasma3);
                movimentacao_fantasma(tabuleiro, ptr_fantasma4);
                imprime_tabuleiro(tabuleiro);
                *ptr_tecla = wgetch(stdscr);
                movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                delay(fase);
            }
            break;

        case 'w':
        case KEY_UP:	/* seta pra cima */
            ptr_pac->direcao = 3;
            while (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, ptr_pac->direcao) && !encerrou(tabuleiro) && !colisao(tabuleiro, ptr_pac)) /* verifica se a próxima posição é a parede */
            {
                if (achou_moeda(tabuleiro, ptr_pac))
                    apaga_moeda(tabuleiro, moedas, (ptr_pac->x)-2, ptr_pac->y);
                limpa_estrutura(tabuleiro, ptr_pac->x, ptr_pac->y);
                ptr_pac->x = ptr_pac->x - 1;
                imprime_moedas(tabuleiro, moedas);
                movimentacao_fantasma(tabuleiro, ptr_fantasma1);
                movimentacao_fantasma(tabuleiro, ptr_fantasma2);
                movimentacao_fantasma(tabuleiro, ptr_fantasma3);
                movimentacao_fantasma(tabuleiro, ptr_fantasma4);
                posiciona_pacman(tabuleiro, ptr_pac);
                mvprintw(37, 77, "%d PTS", checa_pontos(tabuleiro, fase));
                imprime_tabuleiro(tabuleiro);
                delay(fase);
                if (espera == 0)   /* guarda ultima instrução para executar quando o caminho estiver livre */
                {
                    *ptr_tecla = wgetch(stdscr);
                    if (*ptr_tecla == 'd' || *ptr_tecla == KEY_RIGHT || *ptr_tecla == 'e' || *ptr_tecla == KEY_LEFT || *ptr_tecla == 's' || *ptr_tecla == KEY_DOWN)
                    {
                        direcao = aplica_direcao(*ptr_tecla);
                        if (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, direcao))
                            movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                        else
                            espera = 1; 
                    }
                }
                else
                    if (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, direcao))
                        movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                if (*ptr_tecla == 'q' || *ptr_tecla =='Q')
                    break;
            }
            while(parede(tabuleiro, ptr_pac->x, ptr_pac->y, ptr_pac->direcao) && !encerrou(tabuleiro) && !colisao(tabuleiro, ptr_pac) && *ptr_tecla != 'q' && *ptr_tecla !='Q')
            {
                imprime_moedas(tabuleiro, moedas);
                movimentacao_fantasma(tabuleiro, ptr_fantasma1);
                movimentacao_fantasma(tabuleiro, ptr_fantasma2);
                movimentacao_fantasma(tabuleiro, ptr_fantasma3);
                movimentacao_fantasma(tabuleiro, ptr_fantasma4);
                imprime_tabuleiro(tabuleiro);
                *ptr_tecla = wgetch(stdscr);
                movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                delay(fase);
            }
            break;

        case 's':
        case KEY_DOWN:	    /* seta pra baixo */
            ptr_pac->direcao = 4;
            while (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, ptr_pac->direcao) && !encerrou(tabuleiro) && !colisao(tabuleiro, ptr_pac)) /* verifica se a próxima posição é a parede */
            {
                if (achou_moeda(tabuleiro, ptr_pac))
                    apaga_moeda(tabuleiro, moedas, (ptr_pac->x)+2, ptr_pac->y);
                limpa_estrutura(tabuleiro, ptr_pac->x, ptr_pac->y);
                ptr_pac->x = ptr_pac->x + 1;
                imprime_moedas(tabuleiro, moedas);
                movimentacao_fantasma(tabuleiro, ptr_fantasma1);
                movimentacao_fantasma(tabuleiro, ptr_fantasma2);
                movimentacao_fantasma(tabuleiro, ptr_fantasma3);
                movimentacao_fantasma(tabuleiro, ptr_fantasma4);
                posiciona_pacman(tabuleiro, ptr_pac);
                mvprintw(37, 77, "%d PTS", checa_pontos(tabuleiro, fase));
                imprime_tabuleiro(tabuleiro);
                delay(fase);
                if (espera == 0)   /* guarda ultima instrução para executar quando o caminho estiver livre */
                {
                    *ptr_tecla = wgetch(stdscr);
                    if (*ptr_tecla == 'd' || *ptr_tecla == KEY_RIGHT || *ptr_tecla == 'w' || *ptr_tecla == KEY_UP || *ptr_tecla == 'e' || *ptr_tecla == KEY_LEFT)
                    {
                        direcao = aplica_direcao(*ptr_tecla);
                        if (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, direcao))
                            movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                        else
                            espera = 1; 
                    }
                }
                else
                    if (!parede(tabuleiro, ptr_pac->x, ptr_pac->y, direcao))
                        movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                if (*ptr_tecla == 'q' || *ptr_tecla =='Q')
                    break;
            }
            while(parede(tabuleiro, ptr_pac->x, ptr_pac->y, ptr_pac->direcao) && !encerrou(tabuleiro) && !colisao(tabuleiro, ptr_pac) && *ptr_tecla != 'q' && *ptr_tecla !='Q')
            {
                imprime_moedas(tabuleiro, moedas);
                movimentacao_fantasma(tabuleiro, ptr_fantasma1);
                movimentacao_fantasma(tabuleiro, ptr_fantasma2);
                movimentacao_fantasma(tabuleiro, ptr_fantasma3);
                movimentacao_fantasma(tabuleiro, ptr_fantasma4);
                imprime_tabuleiro(tabuleiro);
                *ptr_tecla = wgetch(stdscr);
                movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla, ptr_fantasma1, ptr_fantasma2, ptr_fantasma3, ptr_fantasma4, moedas);
                delay(fase);
            }
            break;

        default: 
            break;
    }
}

int main()
{
    unsigned char tabuleiro[LINHAS][COLUNAS];
    int fase, sair = 0, tecla = 0, vidas = 3;

    srand(time(NULL));

    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
    keypad(stdscr, true);

    struct pac pacman;
    struct fantasma fantasma1, fantasma2, fantasma3, fantasma4;
    struct moeda moedas[152];
    

    if(has_colors() == FALSE)
	{	endwin();
		printf("Seu terminal não suporta cores\n");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);


    for (fase = 1; (fase < 4); fase++)
    {
        if (fase == 1)
        {
            mvprintw(38, 77, "FASE %d", fase);
            mvprintw(38, 5, "%d VIDAS", vidas);
            pacman.x = LINHAS-3;
            pacman.y = COLUNAS/2;
            pacman.direcao = 1;
            desenha_jogo(tabuleiro);
            if (fase == 1 && vidas == 3)
                inicializa_moedas(moedas);
            inicia_fantasmas(tabuleiro, &fantasma1, &fantasma2, &fantasma3, &fantasma4);
            imprime_moedas(tabuleiro, moedas);
            posiciona_pacman(tabuleiro, &pacman);
            imprime_tabuleiro(tabuleiro);
            if (vidas == 3)
                vidas--;
            while (tecla!= 'q' && tecla != 'Q' && !encerrou(tabuleiro) && !colisao(tabuleiro, &pacman) && vidas>=0)
            {
                tecla = wgetch(stdscr);
                if (tecla == 'a' || tecla == 'd' || tecla == 'w' || tecla == 's' || tecla == KEY_LEFT || tecla == KEY_RIGHT || tecla == KEY_UP || tecla == KEY_DOWN)
                    mvprintw(38, 5, "%d VIDAS", vidas);
                movimentacao(tabuleiro, &pacman, fase, &tecla, &fantasma1, &fantasma2, &fantasma3, &fantasma4, moedas);
            }
            if (tecla == 'q' || tecla == 'Q')
            {
                endwin();
                return 1;
            }
            if (colisao(tabuleiro, &pacman))
            {
                fase--;
                vidas--;
            }
        }
        if (fase == 2)
        {
            mvprintw(38, 23, "PARABENS, VOCE PASSOU PARA A SEGUNDA FASE!");
            mvprintw(37, 77, "         ");
            mvprintw(38, 77, "FASE %d", fase);
            pacman.x = LINHAS-3;
            pacman.y = COLUNAS/2;
            pacman.direcao = 1;
            desenha_jogo(tabuleiro);
            inicializa_moedas(moedas);
            inicia_fantasmas(tabuleiro, &fantasma1, &fantasma2, &fantasma3, &fantasma4);
            imprime_moedas(tabuleiro, moedas);
            posiciona_pacman(tabuleiro, &pacman);
            imprime_tabuleiro(tabuleiro);
            while (tecla!= 'q' && tecla != 'Q' && !encerrou(tabuleiro) && !colisao(tabuleiro, &pacman) && vidas>=0)
            {
                tecla = wgetch(stdscr);
                if (tecla == 'a' || tecla == 'w' || tecla == 's' || tecla == 'd' || tecla == KEY_DOWN || tecla == KEY_UP || tecla == KEY_LEFT || tecla == KEY_RIGHT)
                {
                    mvprintw(38, 5, "%d VIDAS", vidas);
                    mvprintw(38, 23, "                                           ");
                }
                movimentacao(tabuleiro, &pacman, fase, &tecla, &fantasma1, &fantasma2, &fantasma3, &fantasma4, moedas);
            }
            if (tecla == 'q' || tecla == 'Q')
            {
                endwin();
                return 1;
            }
            if (colisao(tabuleiro, &pacman))
            {
                fase--;
                vidas--;
            }
        }
        if (fase == 3)
        {
            mvprintw(38, 23, "PARABENS, VOCE PASSOU PARA A TERCEIRA FASE!");
            mvprintw(37, 77, "         ");
            mvprintw(38, 77, "FASE %d", fase);
            pacman.x = LINHAS-3;
            pacman.y = COLUNAS/2;
            pacman.direcao = 1;
            desenha_jogo(tabuleiro);
            inicializa_moedas(moedas);
            inicia_fantasmas(tabuleiro, &fantasma1, &fantasma2, &fantasma3, &fantasma4);
            imprime_moedas(tabuleiro, moedas);
            posiciona_pacman(tabuleiro, &pacman);
            imprime_tabuleiro(tabuleiro);
            while (tecla!= 'q' && tecla != 'Q' && !encerrou(tabuleiro) && !colisao(tabuleiro, &pacman) && vidas>=0)
            {
                tecla = wgetch(stdscr);
                if (tecla == 'a' || tecla == 'w' || tecla == 's' || tecla == 'd' || tecla == KEY_DOWN || tecla == KEY_UP || tecla == KEY_LEFT || tecla == KEY_RIGHT)
                {
                    mvprintw(38, 5, "%d VIDAS", vidas);
                    mvprintw(38, 23, "                                            ");
                }
                movimentacao(tabuleiro, &pacman, fase, &tecla, &fantasma1, &fantasma2, &fantasma3, &fantasma4, moedas);
            }
            if (tecla == 'q' || tecla == 'Q')
            {
                endwin();
                return 1;
            }
            if (colisao(tabuleiro, &pacman))
            {
                fase--;
                vidas--;
            }
        }
    }


    if (fase == 4 && encerrou(tabuleiro))
    {
        mvprintw(38, 23, "       PARABENS, VOCE GANHOU O JOGO!       ");
        mvprintw(38, 77, "         ");
    }
    if (vidas<0)
    {
        mvprintw(38, 5, "        ");
        mvprintw(38, 23, "              VOCE PERDEU :/               ");
        mvprintw(38, 77, "         ");
    }
    imprime_moedas(tabuleiro, moedas);
    imprime_tabuleiro(tabuleiro);
    
    while (1)
    {
        tecla = wgetch(stdscr);
        if (tecla == 'q' || tecla == 'Q')
        {
            endwin();
            return 1;
        }
    }
    
}