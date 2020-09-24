/* TRABALHO DE PROGRAMAÇÃO 1 - GUILHERME C. BONETI - 13/09/20 - UFPR */
/* PARA COMPILAR: gcc funcoes.c pacman.c -o pacman -lncurses */
/* FAVOR MUDAR CODIFICAÇÃO DO TERMINAL PARA CP866, PARA SUPORTAR CARACTERES ESPECIAIS */
/* (clique na aba "Terminal" e depois em "Definir codificação de caractere" e escolha CP866) */

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>
#include "header.h"

#define LINHAS 31
#define COLUNAS 81
#define COLOR_MOEDAS 8
#define COLOR_FANTASMAS_ENERGIA 9


int main()
{
    unsigned char tabuleiro[LINHAS][COLUNAS];
    int fase, tecla = 0, vidas = 3;

    srand(time(NULL));

    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
    keypad(stdscr, true);

    struct pac pacman;

    struct lista_dupla_ligada *ListaFantasmas = inicializaLista();
    struct fantasma fantasma1, fantasma2, fantasma3, fantasma4;
    fantasma1.id = 1;   /*  fantasma vermelho Blinky  */
    fantasma2.id = 2;   /*  fantasma rosa Pinky  */
    fantasma3.id = 3;   /*  fantasma azul Inky   */
    fantasma4.id = 4;   /*  fantasma amarelo Clyde  */
    insereLista(ListaFantasmas, &fantasma1);
    insereLista(ListaFantasmas, &fantasma2);
    insereLista(ListaFantasmas, &fantasma3);
    insereLista(ListaFantasmas, &fantasma4);

    struct moeda moedas[152];
    struct sistema sistema;
    sistema.pontos = 0;

    if(has_colors() == FALSE)
	{	
        endwin();
		printf("Seu terminal não suporta cores\n");
		exit(1);
	}
	start_color();
    init_color(COLOR_MOEDAS, 999, 599, 999);
    init_color(COLOR_FANTASMAS_ENERGIA, 0, 0, 999);
    init_color(COLOR_CYAN, 930, 403, 805);
    init_color(COLOR_RED, 999, 200, 200);
    init_color(COLOR_BLUE, 0, 800, 999);
    init_color(COLOR_MAGENTA, 999, 999, 400);
    init_color(COLOR_YELLOW, 999, 900, 0);
    init_color(COLOR_GREEN, 999, 100, 500);
	init_color(COLOR_WHITE, 0, 799, 999);
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_MOEDAS, COLOR_BLACK);
    init_pair(8, COLOR_FANTASMAS_ENERGIA, COLOR_BLACK);


    for (fase = 1; (fase < 4); fase++)
    {
        if (fase == 1)
        {
            mvprintw(38, 77, "FASE %d", fase);
            mvprintw(38, 5, "%d VIDAS", vidas);
            pacman.x = LINHAS-3;
            pacman.y = COLUNAS/2;
            pacman.direcao = 1;
            pacman.energizado = 0;
            desenha_jogo(tabuleiro);
            if (fase == 1 && vidas == 3)
                inicializa_moedas(moedas);
            inicia_fantasmas(tabuleiro, ListaFantasmas, pacman.energizado);
            imprime_moedas(tabuleiro, moedas);
            posiciona_pacman(tabuleiro, &pacman);
            imprime_tabuleiro(tabuleiro);
            if (vidas == 3)
                vidas--;
            while (tecla!= 'q' && tecla != 'Q' && !encerrou(tabuleiro) && !(colisao(tabuleiro, &pacman) && pacman.energizado == 0) && vidas>=0)
            {
                tecla = wgetch(stdscr);
                if (tecla == 'a' || tecla == 'd' || tecla == 'w' || tecla == 's' || tecla == KEY_LEFT || tecla == KEY_RIGHT || tecla == KEY_UP || tecla == KEY_DOWN)
                    mvprintw(38, 5, "%d VIDAS", vidas);
                movimentacao(tabuleiro, &pacman, fase, &tecla, ListaFantasmas, moedas, &sistema, 0);
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
            inicia_fantasmas(tabuleiro, ListaFantasmas, pacman.energizado);
            imprime_moedas(tabuleiro, moedas);
            posiciona_pacman(tabuleiro, &pacman);
            imprime_tabuleiro(tabuleiro);
            while (tecla!= 'q' && tecla != 'Q' && !encerrou(tabuleiro) && !(colisao(tabuleiro, &pacman) && pacman.energizado == 0) && vidas>=0)
            {
                tecla = wgetch(stdscr);
                if (tecla == 'a' || tecla == 'w' || tecla == 's' || tecla == 'd' || tecla == KEY_DOWN || tecla == KEY_UP || tecla == KEY_LEFT || tecla == KEY_RIGHT)
                {
                    mvprintw(38, 5, "%d VIDAS", vidas);
                    mvprintw(38, 23, "                                           ");
                }
                movimentacao(tabuleiro, &pacman, fase, &tecla, ListaFantasmas, moedas, &sistema, 0);
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
            inicia_fantasmas(tabuleiro, ListaFantasmas, pacman.energizado);
            imprime_moedas(tabuleiro, moedas);
            posiciona_pacman(tabuleiro, &pacman);
            imprime_tabuleiro(tabuleiro);
            while (tecla!= 'q' && tecla != 'Q' && !encerrou(tabuleiro) && !(colisao(tabuleiro, &pacman) && pacman.energizado == 0) && vidas>=0)
            {
                tecla = wgetch(stdscr);
                if (tecla == 'a' || tecla == 'w' || tecla == 's' || tecla == 'd' || tecla == KEY_DOWN || tecla == KEY_UP || tecla == KEY_LEFT || tecla == KEY_RIGHT)
                {
                    mvprintw(38, 5, "%d VIDAS", vidas);
                    mvprintw(38, 23, "                                            ");
                }
                movimentacao(tabuleiro, &pacman, fase, &tecla, ListaFantasmas, moedas, &sistema, 0);
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