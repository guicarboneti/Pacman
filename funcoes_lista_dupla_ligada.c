#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct nodo *criaNodo(struct fantasma *fant)
{
    struct nodo *aux;
    aux = malloc(sizeof(struct nodo));
    aux->fantasma = fant;
    aux->prox = NULL;
    aux->ant = NULL;
    return aux;
}

struct lista_dupla_ligada *inicializaLista() 
{
    struct lista_dupla_ligada *Laux;
    Laux = malloc(sizeof(struct lista_dupla_ligada));
    Laux->ini = NULL;
    Laux->fim = NULL;
    return Laux;
}

/*void mostraLista (struct lista_dupla_ligada *L)
{
    struct nodo *aux = L->ini;
    while (aux != NULL)
    {
        printf("%d ", aux->fantasma);
        aux = aux->prox;
    }
}*/


void insereLista (struct lista_dupla_ligada *L, struct fantasma *fant)
{
    struct nodo *aux = criaNodo(fant);
    if (L->ini == NULL)
    {
        L->ini = aux;
        L->fim = aux;
    }
    else
    {
        aux->ant = L->fim;
        L->fim->prox = aux;
        L->fim = aux;
    }
}

void removeNodo (struct lista_dupla_ligada *L, struct fantasma *fant)
{
    struct nodo *aux = L->ini;
    
    if (aux != NULL && aux->fantasma->id == fant->id)
    {
        L->ini = aux->prox;
        free(aux);
        return;
    }
    
    while (aux != NULL && aux->fantasma->id != fant->id)
    {
        aux = aux->prox;
    }
    
    if (aux == NULL)
        return;
    
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
}

struct fantasma *achaFantasma(struct lista_dupla_ligada *L, int x)
{
    struct nodo *aux = L->ini;
    while (aux->fantasma->id != x && aux != NULL)
    {
        aux = aux->prox;
    }
    if (aux->fantasma->id == x)
        return aux->fantasma;
    return aux->fantasma;
}