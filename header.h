#define LINHAS 31
#define COLUNAS 81

struct pac
{
    int x;
    int y;
    int direcao;
    int energizado;
};

struct fantasma
{
    int id;
    int x;
    int y;
    int direcao;
    int morreu;
};

struct moeda
{
    int x;
    int y;
    int aparece;
    int especial;
};

struct nodo
{
    struct fantasma *fantasma;
    struct nodo *prox;
    struct nodo *ant;
};

struct lista_dupla_ligada
{
    struct nodo *ini;
    struct nodo *fim;
};

struct sistema
{
    int pontos;
};

void desenha_jogo(unsigned char tabuleiro[LINHAS][COLUNAS]);

void desenha_moeda(unsigned char tabuleiro[LINHAS][COLUNAS], struct moeda m);

void imprime_moedas(unsigned char tabuleiro[LINHAS][COLUNAS], struct moeda moedas[152]);

void apaga_moeda(unsigned char tabuleiro[LINHAS][COLUNAS], struct moeda moedas[152], int x, int y, int direcao);

void inicializa_moedas(struct moeda moedas[152]);

void imprime_tabuleiro (unsigned char tabuleiro[LINHAS][COLUNAS]);

int encerrou(unsigned char tabuleiro[LINHAS][COLUNAS]);

void posiciona_pacman(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac);

void posiciona_fantasma(unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma, int energia);

void inicia_fantasmas (unsigned char tabuleiro[LINHAS][COLUNAS], struct lista_dupla_ligada *L, int energia);

void reinicia_fantasma (unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac, struct lista_dupla_ligada *L, int *colide);

void limpa_estrutura(unsigned char tabuleiro[LINHAS][COLUNAS], int x, int y);

int parede (unsigned char tabuleiro[LINHAS][COLUNAS], int x, int y, int direcao);

int aplica_direcao(int tecla);

void delay(int fase);

int colisao(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pacman);

int bateu_fantasma(unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma);

void movimentacao_fantasma(unsigned char tabuleiro[LINHAS][COLUNAS], struct fantasma *ptr_fantasma, struct pac *ptr_pacman);

int especial(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac);

int achou_moeda(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac, struct sistema *ptr_sistema);

void movimentacao(unsigned char tabuleiro[LINHAS][COLUNAS], struct pac *ptr_pac, int fase, int *ptr_tecla, struct lista_dupla_ligada *L, struct moeda moedas[152], struct sistema *ptr_sistema, int cont, int *colide);

struct nodo *criaNodo(struct fantasma *fant);

struct lista_dupla_ligada *inicializaLista();

void mostraLista (struct lista_dupla_ligada *L);

void insereLista (struct lista_dupla_ligada *L, struct fantasma *fant);

void removeNodo (struct lista_dupla_ligada *L, struct fantasma *fant);

struct fantasma *achaFantasma(struct lista_dupla_ligada *L, int x);