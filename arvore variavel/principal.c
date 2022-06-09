#include <stdio.h>
#include <stdlib.h>
#include "arvvar.h"

int main(int argc, char const *argv[])
{
    // cria árvore
    /* Cria nós como folhas */
    ArvVar *a = arvv_cria('a');
    ArvVar *b = arvv_cria('b');
    ArvVar *c = arvv_cria('c');
    ArvVar *d = arvv_cria('d');
    ArvVar *e = arvv_cria('e');
    ArvVar *f = arvv_cria('f');
    ArvVar *g = arvv_cria('g');
    ArvVar *h = arvv_cria('h');
    ArvVar *i = arvv_cria('i');
    ArvVar *j = arvv_cria('j');
    /* monta a hierarquia */
    arvv_insere(c, d);
    arvv_insere(b, e);
    arvv_insere(b, c);
    arvv_insere(i, j);
    arvv_insere(g, i);
    arvv_insere(g, h);
    arvv_insere(a, g);
    arvv_insere(a, f);
    arvv_insere(a, b);

    arvv_imprime(a);

    arvv_pertence(a, '7') == 1 ? printf("pertence a árvore\n") : printf("não pertence a árvore\n");

    arvv_folhas(a);

    printf("%d\n", arvv_altura(a));

    ArvVar *b = arvv_copia(a);

    arvv_igual(a, b) == 1 ? printf("árvore igual\n") : printf("árvore não igual\n");

    arvv_libera(a);

    return 0;
}