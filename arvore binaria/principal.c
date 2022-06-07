#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main(int argc, char const *argv[])
{

    // criando árvore vazia
    Arv *a = arv_criavazia();

    // criando árvore com filhos
    Arv *a = arv_cria('1',
                      arv_cria('2', NULL,
                               arv_cria('4', NULL, NULL)),
                      arv_cria('3', arv_cria('5', NULL, NULL),
                               arv_cria('6', NULL, NULL)));

    arv_imprime_pre(a);
    arv_libera(a);
    arv_vazia(a);
    arv_pertence(a, 1);
    arv_imprime_sim(a);
    arv_imprime_pos(a);
    arv_folhas(a);
    arv_altura(a);
    arv_copia(a);
    arv_igual(a, a);

    return 0;
}