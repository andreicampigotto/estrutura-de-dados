#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main(int argc, char const *argv[])
{
    int v = 7;
    Arv *a = abb_cria();
    abb_insere(a, 4);
    abb_insere(a, 1);
    abb_insere(a, 2);
    abb_insere(a, 3);
    abb_insere(a, 5);
    abb_insere(a, 6);
    abb_insere(a, 7);

    abb_imprime(a);
    abb_imprimeDecrescente(a);
    abb_busca(a, v);

    abb_retira(a, 5);

    free(a);
    return 0;
}