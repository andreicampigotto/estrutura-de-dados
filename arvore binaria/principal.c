#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main(int argc, char const *argv[])
{
    // criando árvore com filhos
    Arv *a = arv_cria('1',
                      arv_cria('2', NULL,
                               arv_cria('4', NULL, NULL)),
                      arv_cria('3', arv_cria('5', NULL, NULL),
                               arv_cria('6', NULL, NULL)));

    Arv *b = arv_copia(a);

    arv_imprime_pre(a);
    arv_imprime_sim(a);
    arv_imprime_pos(a);

    arv_vazia(a) ? printf("árvore vazia") : printf("árvore não vazia");

    arv_pertence(a, 1) ? printf("pertence a árvore") : printf("não pertence a árvore");
    arv_folhas(a);

    printf("%d\n", arv_altura(a));

    arv_igual(a, b) ? printf("árvore igual") : printf("árvore não igual");

    arv_libera(a);

    return 0;
}