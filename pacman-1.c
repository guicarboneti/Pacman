#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>

#define LINHAS 31
#define COLUNAS 81
#define VELOCIDADE 120000


void desenha_jogo(char tabuleiro[LINHAS][COLUNAS])
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

    /* preenche com pastilhas */
    for (j=2; j<COLUNAS-2; j+=3)
        tabuleiro[2][j] = 79;
    for (i=4; i<9; i+=2)
        tabuleiro[i][2] = 79;
    for (i=4; i<9; i+=2)
        tabuleiro[i][COLUNAS-3] = 79;
    for (j=5; j<14; j+=3)
        tabuleiro[8][j] = 79;
    for (j=COLUNAS-6; j>67; j-=3)
        tabuleiro[8][j] = 79;
    for (i=4; i<13; i+=2)
        tabuleiro[i][14] = 79;
    for (i=10; i<23; i+=2)
        tabuleiro[i][11] = 79;
    for (i=10; i<23; i+=2)
        tabuleiro[i][COLUNAS-12] = 79;
    for (i=4; i<13; i+=2)
        tabuleiro[i][COLUNAS-15] = 79;
    for (j=24; j<39; j+=3)
        tabuleiro[7][j] = 79;
    for (j=43; j<56; j+=3)
        tabuleiro[7][j] = 79;
    tabuleiro[5][32] = 79;
    tabuleiro[5][48] = 79;
    for (i=9; i<24; i+=2)
        tabuleiro[i][24] = 79;
    for (i=9; i<24; i+=2)
        tabuleiro[i][56] = 79;
    for (j=18; j<23; j+=3)
        tabuleiro[12][j] = 79;
    for (j=COLUNAS-18; j>COLUNAS-24; j-=4)
        tabuleiro[12][j] = 79;
    for (j=18; j<23; j+=3)
        tabuleiro[18][j] = 79;
    tabuleiro[18][14] = 79;
    for (j=COLUNAS-18; j>COLUNAS-24; j-=4)
        tabuleiro[18][j] = 79;
    tabuleiro[18][COLUNAS-15] = 79;
    for (j=27; j<39; j+=3)
        tabuleiro[23][j] = 79;
    for (j=44; j<55; j+=3)
        tabuleiro[23][j] = 79;
    tabuleiro[LINHAS-6][32] = 79;
    tabuleiro[LINHAS-6][48] = 79;
    for (i=20; i<23; i+=2)
        tabuleiro[i][16] = 79;
    for (i=20; i<23; i+=2)
        tabuleiro[i][COLUNAS-17] = 79;
    for (j=6; j<14; j+=3)
        tabuleiro[LINHAS-7][j] = 79;
    for (j=COLUNAS-7; j>COLUNAS-15; j-=3)
        tabuleiro[LINHAS-7][j] = 79;
    tabuleiro[LINHAS-7][16] = 79;
    tabuleiro[LINHAS-5][5] = 79;
    tabuleiro[LINHAS-5][16] = 79;
    tabuleiro[LINHAS-7][COLUNAS-17] = 79;
    tabuleiro[LINHAS-5][COLUNAS-6] = 79;    
    tabuleiro[LINHAS-5][COLUNAS-17] = 79;
    for (j=2; j<(COLUNAS/2)-2; j+=3)
        tabuleiro[LINHAS-3][j] = 79;
    for (j=(COLUNAS/2)+5; j<COLUNAS; j+=3)
        tabuleiro[LINHAS-3][j] = 79;
    
    /* pastilhas especiais */
    tabuleiro[8][1] = '@';
    tabuleiro[8][2] = '@';
    tabuleiro[9][1] = '@';
    tabuleiro[9][2] = '@';

    tabuleiro[8][COLUNAS-3] = '@';
    tabuleiro[8][COLUNAS-2] = '@';
    tabuleiro[9][COLUNAS-3] = '@';
    tabuleiro[9][COLUNAS-2] = '@';

    tabuleiro[LINHAS-6][1] = '@';
    tabuleiro[LINHAS-6][2] = '@';
    tabuleiro[LINHAS-7][1] = '@';
    tabuleiro[LINHAS-7][2] = '@';

    tabuleiro[LINHAS-6][COLUNAS-3] = '@';
    tabuleiro[LINHAS-6][COLUNAS-2] = '@';
    tabuleiro[LINHAS-7][COLUNAS-3] = '@';
    tabuleiro[LINHAS-7][COLUNAS-2] = '@';


}

void imprime_tabuleiro (char tabuleiro[LINHAS][COLUNAS])
{
    int i, j;

    for (i=0;i<LINHAS;i++)
        for (j=0; j<COLUNAS; j++)
            mvprintw(i+6, j+4, "%c", tabuleiro[i][j]);

    /* textos */
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

    mvprintw(40, 35, "DIGITE 'Q' PARA SAIR");
    refresh();
}

int checa_pontos(char tabuleiro[LINHAS][COLUNAS])
{
    int i, j, soma = 0, soma_especiais = 0, total;
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
    total = (10*(148 - soma)) + (100*((16 - soma_especiais)/4));
    return total;
}

int encerrou(char tabuleiro[LINHAS][COLUNAS])
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

void posiciona_pacman(char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac)
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

void limpa_caminho(char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac)
{
    switch (ptr_pac->direcao)
    {
    case 1: /* esquerda */
        if (tabuleiro[ptr_pac->x][(ptr_pac->y)+2] != 186)
        {
            tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)+2] = ' ';
            tabuleiro[ptr_pac->x][(ptr_pac->y)+2] = ' ';
            tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)+2] = ' ';
        }
        break;
    
    case 2: /* direita */
        if (tabuleiro[ptr_pac->x][(ptr_pac->y)-2] != 186)
        {
            tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)-2] = ' ';
            tabuleiro[ptr_pac->x][(ptr_pac->y)-2] = ' ';
            tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)-2] = ' ';
        }
        break;

    case 3: /* cima */
        if (tabuleiro[ptr_pac->x][(ptr_pac->y)+2] != 205)
        {
            tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)-1] = ' ';
            tabuleiro[(ptr_pac->x)+2][ptr_pac->y] = ' ';
            tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)+1] = ' ';
        }
        break;
    
    case 4: /* baixo */
        if (tabuleiro[ptr_pac->x][(ptr_pac->y)-2] != 186)
        {
            tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)-1] = ' ';
            tabuleiro[(ptr_pac->x)-2][ptr_pac->y] = ' ';
            tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)+1] = ' ';
        }
        break;
    }
}

void limpa_pacman(char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac)
{
    tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)+1] = ' ';
    tabuleiro[ptr_pac->x][(ptr_pac->y)+1] = ' ';
    tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)+1] = ' ';
    tabuleiro[(ptr_pac->x)-1][ptr_pac->y] = ' ';
    tabuleiro[ptr_pac->x][ptr_pac->y] = ' ';
    tabuleiro[(ptr_pac->x)+1][ptr_pac->y] = ' ';
    tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)-1] = ' ';
    tabuleiro[ptr_pac->x][(ptr_pac->y)-1] = ' ';
    tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)-1] = ' ';
}


int parede (char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac, int direcao)
{
    if (direcao == 1) /* esquerda */
    {
        if ((tabuleiro[ptr_pac->x][(ptr_pac->y)-2] == ' ' || tabuleiro[ptr_pac->x][(ptr_pac->y)-2] == 79 || tabuleiro[ptr_pac->x][(ptr_pac->y)-2] == '@') && (tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)-2] == ' ' || tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)-2] == 79 || tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)-2] == '@') && (tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)-2] == ' ' || tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)-2] == 79 || tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)-2] == '@'))
            return 0;
    }

    else if (direcao == 2) /* direita */
    {
        if ((tabuleiro[ptr_pac->x][(ptr_pac->y)+2] == ' ' || tabuleiro[ptr_pac->x][(ptr_pac->y)+2] == 79 || tabuleiro[ptr_pac->x][(ptr_pac->y)+2] == '@') && (tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)+2] == ' ' || tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)+2] == 79 || tabuleiro[(ptr_pac->x)-1][(ptr_pac->y)+2] == '@') && (tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)+2] == ' ' || tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)+2] == 79 || tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)+2] == '@'))
            return 0;
    }

    else if (direcao == 3) /* cima */
    {
        if ((tabuleiro[(ptr_pac->x)-2][ptr_pac->y] == ' ' || tabuleiro[(ptr_pac->x)-2][ptr_pac->y] == 79 || tabuleiro[(ptr_pac->x)-2][ptr_pac->y] == '@') && (tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)-1] == ' ' || tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)-1] == 79 || tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)-1] == '@') && (tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)+1] == ' ' || tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)+1] == 79 || tabuleiro[(ptr_pac->x)-2][(ptr_pac->y)+1] == '@'))
            return 0;
    }

    else if (direcao == 4) /* baixo */
    {
        if ((tabuleiro[(ptr_pac->x)+2][ptr_pac->y] == ' ' || tabuleiro[(ptr_pac->x)+2][ptr_pac->y] == 79 || tabuleiro[(ptr_pac->x)+2][ptr_pac->y] == '@') && (tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)-1] == ' ' || tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)-1] == 79 || tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)-1] == '@') && (tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)+1] == ' ' || tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)+1] == 79 || tabuleiro[(ptr_pac->x)+2][(ptr_pac->y)+1] == '@'))
            return 0;
    }

    return 1;
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
        usleep(VELOCIDADE - (0.1*(VELOCIDADE - (VELOCIDADE*0.1))));
}

void movimentacao(char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac, int fase, int *ptr_tecla)
{
    int direcao, espera = 0;
    switch (*ptr_tecla)
    {
        case 'a':
        case KEY_LEFT:      /* seta pra esquerda */
            ptr_pac->direcao = 1;
            while (!parede(tabuleiro, ptr_pac, ptr_pac->direcao)) /* verifica se a próxima posição é a parede */
            {
                if (((ptr_pac->y)-2) == 0)
                {
                    limpa_pacman(tabuleiro, ptr_pac);
                    ptr_pac->y = COLUNAS-2;
                    posiciona_pacman(tabuleiro, ptr_pac);
                    imprime_tabuleiro(tabuleiro);
                    delay(fase);
                }
                else
                {
                    if (tabuleiro[ptr_pac->x][(ptr_pac->y)-2] == '@')   /* checa se é moeda especial, para apagar a moeda inteira */
                    {
                        tabuleiro[ptr_pac->x][(ptr_pac->y)-3] = ' ';
                        tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)-3] = ' ';
                    }
                    ptr_pac->y = ptr_pac->y - 1;
                    posiciona_pacman(tabuleiro, ptr_pac);
                    limpa_caminho(tabuleiro, ptr_pac);
                    mvprintw(37, 77, "%d PTS", checa_pontos(tabuleiro));
                    imprime_tabuleiro(tabuleiro);
                    delay(fase);
                    if (espera == 0)
                    {
                        *ptr_tecla = wgetch(stdscr);
                        if (*ptr_tecla == 'd' || *ptr_tecla == KEY_RIGHT || *ptr_tecla == 'w' || *ptr_tecla == KEY_UP || *ptr_tecla == 's' || *ptr_tecla == KEY_DOWN)
                        {
                            direcao = aplica_direcao(*ptr_tecla);
                            if (!parede(tabuleiro, ptr_pac, direcao))
                                movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla);
                            else
                                espera = 1; 
                        }
                    }
                    else
                        if (!parede(tabuleiro, ptr_pac, direcao))
                            movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla);
                    if (*ptr_tecla == 'q' || *ptr_tecla =='Q')
                        break;
                }
            }
            break;

        case 'd':
        case KEY_RIGHT:	    /* seta pra direita */
            ptr_pac->direcao = 2;
            while (!parede(tabuleiro, ptr_pac, ptr_pac->direcao)) /* verifica se a próxima posição é a parede */
            {
                if (((ptr_pac->y)+2) == COLUNAS-1)
                {
                    limpa_pacman(tabuleiro, ptr_pac);
                    ptr_pac->y = 1;
                    posiciona_pacman(tabuleiro, ptr_pac);
                    imprime_tabuleiro(tabuleiro);
                    delay(fase);
                }
                else
                {
                    if (tabuleiro[ptr_pac->x][(ptr_pac->y)+2] == '@')    /* checa se é moeda especial, para apagar a moeda inteira */
                    {
                        tabuleiro[ptr_pac->x][(ptr_pac->y)+3] = ' ';
                        tabuleiro[(ptr_pac->x)+1][(ptr_pac->y)+3] = ' ';
                    }
                    ptr_pac->y = ptr_pac->y + 1;
                    posiciona_pacman(tabuleiro, ptr_pac);
                    limpa_caminho(tabuleiro, ptr_pac);
                    mvprintw(37, 77, "%d PTS", checa_pontos(tabuleiro));
                    imprime_tabuleiro(tabuleiro);
                    delay(fase);
                    if (espera == 0)
                    {
                        *ptr_tecla = wgetch(stdscr);
                        if (*ptr_tecla == 'e' || *ptr_tecla == KEY_LEFT || *ptr_tecla == 'w' || *ptr_tecla == KEY_UP || *ptr_tecla == 's' || *ptr_tecla == KEY_DOWN)
                        {
                            direcao = aplica_direcao(*ptr_tecla);
                            if (!parede(tabuleiro, ptr_pac, direcao))
                                movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla);
                            else
                                espera = 1; 
                        }
                    }
                    else
                        if (!parede(tabuleiro, ptr_pac, direcao))
                            movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla);
                    if (*ptr_tecla == 'q' || *ptr_tecla =='Q')
                        break;
                }
            }
            break;

        case 'w':
        case KEY_UP:	/* seta pra cima */
            ptr_pac->direcao = 3;
            while (!parede(tabuleiro, ptr_pac, ptr_pac->direcao)) /* verifica se a próxima posição é a parede */
            {
                ptr_pac->x = ptr_pac->x - 1;
                posiciona_pacman(tabuleiro, ptr_pac);
                limpa_caminho(tabuleiro, ptr_pac);
                mvprintw(37, 77, "%d PTS", checa_pontos(tabuleiro));
                imprime_tabuleiro(tabuleiro);
                delay(fase);
                if (espera == 0)
                {
                    *ptr_tecla = wgetch(stdscr);
                    if (*ptr_tecla == 'd' || *ptr_tecla == KEY_RIGHT || *ptr_tecla == 'e' || *ptr_tecla == KEY_LEFT || *ptr_tecla == 's' || *ptr_tecla == KEY_DOWN)
                    {
                        direcao = aplica_direcao(*ptr_tecla);
                        if (!parede(tabuleiro, ptr_pac, direcao))
                            movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla);
                        else
                            espera = 1; 
                    }
                }
                else
                    if (!parede(tabuleiro, ptr_pac, direcao))
                        movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla);
                if (*ptr_tecla == 'q' || *ptr_tecla =='Q')
                    break;
            }
            break;

        case 's':
        case KEY_DOWN:	    /* seta pra baixo */
            ptr_pac->direcao = 4;
            while (!parede(tabuleiro, ptr_pac, ptr_pac->direcao)) /* verifica se a próxima posição é a parede */
            {
                if (tabuleiro[(ptr_pac->x)+2][ptr_pac->y] == '@')    /* checa se é moeda especial, para apagar a moeda inteira */
                {
                    tabuleiro[(ptr_pac->x)+3][ptr_pac->y] = ' ';
                    tabuleiro[(ptr_pac->x)+3][(ptr_pac->y)+1] = ' ';
                    tabuleiro[(ptr_pac->x)+3][(ptr_pac->y)-1] = ' ';
                }
                ptr_pac->x = ptr_pac->x + 1;
                posiciona_pacman(tabuleiro, ptr_pac);
                limpa_caminho(tabuleiro, ptr_pac);
                mvprintw(37, 77, "%d PTS", checa_pontos(tabuleiro));
                imprime_tabuleiro(tabuleiro);
                delay(fase);
                if (espera == 0)
                {
                    *ptr_tecla = wgetch(stdscr);
                    if (*ptr_tecla == 'd' || *ptr_tecla == KEY_RIGHT || *ptr_tecla == 'w' || *ptr_tecla == KEY_UP || *ptr_tecla == 'e' || *ptr_tecla == KEY_LEFT)
                    {
                        direcao = aplica_direcao(*ptr_tecla);
                        if (!parede(tabuleiro, ptr_pac, direcao))
                            movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla);
                        else
                            espera = 1; 
                    }
                }
                else
                    if (!parede(tabuleiro, ptr_pac, direcao))
                        movimentacao(tabuleiro, ptr_pac, fase, ptr_tecla);
                if (*ptr_tecla == 'q' || *ptr_tecla =='Q')
                    break;
            }
            break;

        default: 
            break;
    }
}

int main()
{
    char tabuleiro[LINHAS][COLUNAS];
    int fase, sair = 0, tecla = 0;

    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
    keypad(stdscr, true);

    struct pac pacman;
    pacman.x = LINHAS-3;
    pacman.y = COLUNAS/2;
    pacman.direcao = 1;

    desenha_jogo(tabuleiro);
    posiciona_pacman(tabuleiro, &pacman);
    imprime_tabuleiro(tabuleiro);
    
    for (fase = 1; (fase < 4); fase++)
    {
        if (fase == 1)
        {
            pacman.x = LINHAS-3;
            pacman.y = COLUNAS/2;
            while (tecla!= 'q' && tecla != 'Q' && !encerrou(tabuleiro))
            {
                tecla = wgetch(stdscr);
                movimentacao(tabuleiro, &pacman, fase, &tecla);
            }
            if (tecla == 'q' || tecla == 'Q')
                endwin();
        }
        if (fase == 2)
        {
            mvprintw(38, 23, "PARABENS, VOCE PASSOU PARA O SEGUNDO NIVEL!");
            mvprintw(37, 77, "         ");
            pacman.x = LINHAS-3;
            pacman.y = COLUNAS/2;
            desenha_jogo(tabuleiro);
            posiciona_pacman(tabuleiro, &pacman);
            imprime_tabuleiro(tabuleiro);
            while (tecla!= 'q' && tecla != 'Q' && !encerrou(tabuleiro))
            {
                tecla = wgetch(stdscr);
                movimentacao(tabuleiro, &pacman, fase, &tecla);
            }
            if (tecla == 'q' || tecla == 'Q')
                endwin();
        }
        if (fase == 3)
        {
            mvprintw(38, 23, "PARABENS, VOCE PASSOU PARA O TERCEIRO NIVEL!");
            mvprintw(37, 77, "         ");
            pacman.x = LINHAS-3;
            pacman.y = COLUNAS/2;
            desenha_jogo(tabuleiro);
            posiciona_pacman(tabuleiro, &pacman);
            imprime_tabuleiro(tabuleiro);
            while (tecla!= 'q' && tecla != 'Q' && !encerrou(tabuleiro))
            {
                tecla = wgetch(stdscr);
                movimentacao(tabuleiro, &pacman, fase, &tecla);
            }
            if (tecla == 'q' || tecla == 'Q')
                endwin();
        }
    }


    mvprintw(38, 23, "        PARABENS, VOCE GANHOU O JOGO!       ");
    imprime_tabuleiro(tabuleiro);
    scanf("%c",&tecla);
    if (tecla == 'q' || tecla == 'Q')
        endwin();
    
    return 1;
}