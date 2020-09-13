#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>
#include "funcoes.c"

#define LINHAS 31
#define COLUNAS 81
#define VELOCIDADE 80000


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