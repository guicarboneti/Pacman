#define LINHAS 31
#define COLUNAS 81


void desenha_jogo(unsigned char tabuleiro[LINHAS][COLUNAS]);

struct moeda
{
    int x;
    int y;
    int aparece;
    int especial;
};

void desenha_moeda(unsigned char tabuleiro[LINHAS][COLUNAS], struct moeda m);

void imprime_moedas(unsigned char tabuleiro[LINHAS][COLUNAS], struct moeda moedas[152]);

void apaga_moeda(unsigned char tabuleiro[LINHAS][COLUNAS], struct moeda moedas[152], int x, int y);

void inicializa_moedas(struct moeda moedas[152]);

void imprime_tabuleiro (unsigned char tabuleiro[LINHAS][COLUNAS]);

int checa_pontos(unsigned char tabuleiro[LINHAS][COLUNAS], int fase);

int encerrou(unsigned char tabuleiro[LINHAS][COLUNAS]);

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

void posiciona_pacman(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac);

void posiciona_fantasma(unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma);

void inicia_fantasmas (unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma1, struct fantasma *ptr_fantasma2, struct fantasma *ptr_fantasma3, struct fantasma *ptr_fantasma4);

void limpa_estrutura(unsigned char tabuleiro[LINHAS][COLUNAS], int x, int y);

int parede (unsigned char tabuleiro[LINHAS][COLUNAS], int x, int y, int direcao);

int aplica_direcao(int tecla);

void delay(int fase);

int colisao(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pacman);

int bateu_fantasma(unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma);

void movimentacao_fantasma(unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma);

int achou_moeda(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac);

void movimentacao(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac, int fase, int *ptr_tecla, struct fantasma *ptr_fantasma1, struct fantasma *ptr_fantasma2, struct fantasma *ptr_fantasma3, struct fantasma *ptr_fantasma4, struct moeda moedas[152]);