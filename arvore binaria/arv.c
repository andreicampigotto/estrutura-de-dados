#include "arv.h"
#include <stdio.h>
#include <stdlib.h>

// instancia uma nova árvore binária vazia. Esta
// função simplesmente deve retornar NULL
Arv *arv_criavazia(void)
{
    return NULL;
}

// instancia uma nova árvore. A função recebe ponteiros para as suas duas sub-árvores e a
// informação (char) a ser armazenada no nó raiz. A função deve retornar o endereço do nov nó raiz
Arv *arv_cria(char c, Arv *e, Arv *d)
{
    Arv *a = (Arv *)calloc(1, sizeof(Arv));
    a->info = c;
    a->esq = e;
    a->dir = d;
    return a;
}

// libera toda a memória ocupada pela árvore (em outras palavras, “apaga” a árvore
Arv *arv_libera(Arv *a)
{
    if (!arv_vazia(a))
    {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return ((void *)0);
}

// retorna 1 ou 0 caso a árvore esteja vazia ou não, respectivamente.
int arv_vazia(Arv *a)
{
    return a == ((void *)0);
}

// retorna 1 caso o caracter c estiver contido na árvore, e retorna 0 caso contrário
int arv_pertence(Arv *a, char c)
{
    if (arv_vazia(a))
    {
        return 0;
    }
    else
    {

        return a->info == c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c);
    }
}

// imprime a árvore em saída de texto em pré-ordem
void arv_imprime_pre(Arv *a)
{
    printf("<");
    if (!arv_vazia(a))
    {
        printf("%c", a->info);
        arv_imprime_pre(a->esq);
        arv_imprime_pre(a->dir);
    }
    printf(">");
}

// imprime a árvore em saída de texto em ordem simétrica
void arv_imprime_sim(Arv *a)
{
    printf("<");
    if (!arv_vazia(a))
    {
        arv_imprime_pre(a->esq);
        printf("%c", a->info);
        arv_imprime_pre(a->dir);
    }
    printf(">");
}

// imprime a árvore em saída de texto em pós-ordem
void arv_imprime_pos(Arv *a)
{
    printf("<");
    if (!arv_vazia(a))
    {
        arv_imprime_pre(a->esq);
        arv_imprime_pre(a->dir);
        printf("%c", a->info);
    }
    printf(">");
}

// retorna a quantidade de nós folha da árvore
int arv_folhas(Arv *a)
{
    printf("folhas da árvore 'a': %d\n", arv_folhas(a));
}

// retorna a altura da árvore (0 para árvore vazia)
int arv_altura(Arv *a)
{
    int max = 0;
    int alturaEsq = arv_altura(a->esq);
    int alturaDir = arv_altura(a->esq);

    if (arv_vazia(a))
    {
        return -1;
    }

    if (alturaEsq > alturaDir)
    {
        max = alturaEsq;
    }
    else
    {
        max = alturaDir;
    }
    return 1 + max;
}

// retorna 1 se as árvores a1 e a2 são iguais. Retorna 0 caso contrário. As duas árvores são iguais se seus
// nós armazenarem informações iguais nas mesmas posições
int arv_igual(Arv *a1, Arv *a2)
{
    if (a1 == NULL && a2 == NULL)
    {
        return 1;
    }
    if (a1 == NULL || a2 == NULL)
    {
        return 0;
    }

    return a1->info == a2->info && arv_igual(a1->esq, a2->esq) && arv_igual(a1->dir, a2->dir);
}

// retorna uma cópia da árvore a. A nova árvore deve ter novos nós instanciados
Arv *arv_copia(Arv *a)
{
    if (arv_vazia(a))
    {
        return arv_criavazia();
    }

    return arv_cria(a->info, arv_copia(a->esq), arv_copia(a->dir));
}