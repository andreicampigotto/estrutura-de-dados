#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int listaVazia (plista l) {

    return (l->dimensao == 0);
}

void criarLista (pplista l) {
    *l = (struct lista*)malloc(sizeof(struct lista)); // mudei a forma de declaracao do malloc e resolveu o segmentation fault
    (*l)->inicio = NULL;
    (*l)->final = NULL;
    (*l)->dimensao = 0;
}

void inserirInicio (pplista l, int d) {

    pbloco b = (bloco *) malloc (sizeof(bloco));
    b->dado = d;

    if ((*l)->dimensao != 0) {
        b->prox = (*l)->inicio;
        (*l)->inicio = b;
        (*l)->final->prox = b;   
    }
    else {
        b->prox = b;
        (*l)->inicio = b;
        (*l)->final = b;
    }
    
    (*l)->dimensao+= 1;
}

void inserirFinal (pplista l, int d) {

    bloco *b = (bloco *)malloc(sizeof(bloco));
    b->dado = d;

    if ((*l)->dimensao != 0) {
        b->prox = (*l)->inicio;
        (*l)->final->prox = b;
        (*l)->final = b;
    }
    else {
        b->prox = b;
        (*l)->inicio = (*l)->final = b;
    }

    (*l)->dimensao++;
}

void inserirPosK (pplista l, int p, int d) {

    if ((*l)->dimensao > 0) {
        if (p == 1)
           inserirInicio(l, d);
        else {
            if (p > (*l)->dimensao)
               inserirFinal(l, d);
            else {
               int pos = 1;
               bloco *tmp = (*l)->inicio;
               bloco *ant = NULL;
               bloco *b = (bloco *)malloc(sizeof(bloco));

               b->dado = d;
               b->prox = NULL;

               while (pos < p) {
                 ant = tmp;
                 tmp = tmp->prox;
                 pos++;
               }
    
               ant->prox = b;
               b->prox = tmp;
               (*l)->dimensao++;
            }
        }
    }
    else
       inserirInicio(l, d);
}

int removerInicio (pplista l) {
    if ((*l)->dimensao > 0) {
        int dado = (*l)->inicio->dado;
        bloco *tmp = (*l)->inicio;

        if ((*l)->inicio != (*l)->final) {
           (*l)->inicio = (*l)->inicio->prox;
           (*l)->final->prox = (*l)->inicio;
        }
        else
            (*l)->inicio = (*l)->final = NULL;

        free(tmp);
        (*l)->dimensao--;
        return dado;
    }
}

int removerFinal (pplista l) {
    if ((*l)->dimensao > 0) {
        int dado;
    
        if ((*l)->dimensao == 1)
           dado = removerInicio(l);
        else {
            bloco *tmp = (*l)->inicio;
            bloco *ant = NULL;

            while (tmp->prox != (*l)->inicio) {
                ant = tmp;
                tmp = tmp->prox;
            }

            ant->prox = (*l)->inicio;
            dado = tmp->dado;
            free(tmp);
            (*l)->dimensao--;
        }

        return dado;
    }
}

int removerPosK (pplista l, int p) {

    if ((*l)->dimensao > 0) {
        int dado;
        if (p == 1)
           dado = removerInicio(l);
        else {
            if (p > (*l)->dimensao)
               dado = removerFinal(l);
            else {
                int pos = 1;
                bloco *tmp = (*l)->inicio;
                bloco *ant = NULL;

                while (pos < p) {
                    ant = tmp;
                    tmp = tmp->prox;
                    pos++;
                }

                dado = tmp->dado;
                ant->prox = tmp->prox;
                (*l)->dimensao--;
                free(tmp);
            }
        }

        return dado;
    }
}

void imprimirLista (plista l) {

    if (l->dimensao > 0) {
        int i = 1;
        bloco *tmp = l->inicio;

        while (i <= l->dimensao) {
            printf ("\nElemento: %d", tmp->dado);
            tmp = tmp->prox;
            i++;
        }
    }
}