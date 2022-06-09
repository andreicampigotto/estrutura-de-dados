#include "arvvar.h"
#include <stdio.h>
#include <stdlib.h>

// esta função cria um nó folha e retorna seu endereço de memória. Sendo um nó folha, seus ponteiros para prim e prox devem ser
// inicializadas como NULL
ArvVar *arvv_cria(char c)
{
    ArvVar *a = (ArvVar *)(1, sizeof(ArvVar));
    a->info = c;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

// insere uma sub-árvore sa como filha de um dado nó a
void arvv_insere(ArvVar *a, ArvVar *sa)
{
    sa->prox = a->prim;
    a->prim = sa;
}

// deve imprimir a árvore em pré-ordem (primeiro o nó raiz, e depois cada uma das sub-árvores)
void arvv_imprime(ArvVar *a)
{
    ArvVar *p;
    printf("<%c\n", a->info);
    for (p = a->prim; p != NULL; p = p->prox)
        arvv_imprime(p);
    printf(">");
}

// retorna 1 caso o caracter c estiver contido na árvore, e retorna 0 caso contrário
int arvv_pertence(ArvVar *a, char c)
{
    ArvVar *p;
    if (a->info == c)
        return 1;
    else
    {
        for (p = a->prim; p != NULL; p = p->prox)
        {
            if (arvv_pertence(p, c))
                return 1;
        }
    }
    return 0;
}

// libera a memória alocada pela árvore
void arvv_libera(ArvVar *a)
{
    ArvVar *p = a->prim;
    while (p != NULL)
    {
        ArvVar *t = p->prox;
        arvv_libera(p);
        p = t;
    }
    return free(a);
}

// retorna a quantidade de nós folha da árvore
int arvv_folhas(ArvVar *a)
{
    return printf("\nfolhas da árvore 'a': %d\n", arvv_folhas(a));
}

// retorna a altura da árvore (0 para árvore vazia)
int arvv_altura(ArvVar *a)
{
    int max = -1;
    ArvVar *p;
    for (p = a->prim; p != NULL; p = p->prox)
    {
        int h = arvv_altura(p);
        if (h > max)
        {
            max = h;
        }
    }
    return max + 1;
}

// retorna 1 se as árvores a1 e a2 são iguais. Retorna 0 caso contrário.
// As duas árvores são iguais se seus nós armazenarem informações iguais nas mesmas posições
int arvv_igual(ArvVar *a1, ArvVar *a2)
{
    if (a1 == NULL && a2 == NULL)
    {
        return 1;
    }
    if (a1 == NULL || a2 == NULL)
    {
        return 0;
    }

    return a1->info == a2->info && arvv_igual(a1->prim, a2->prim) && arvv_igual(a1->prox, a2->prox);
}

// retorna uma cópia da árvore a. A nova árvore deve ter novos nós instanciados
ArvVar *arvv_copia(ArvVar *a)
{
    return arvv_cria(a);
}
