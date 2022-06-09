#include <stdio.h>
#include <stdlib.h>
#include "arvvar.h"

int main(int argc, char const *argv[])
{
    // cria árvore
    ArvVar *a = arvv_cria('1');

    arvv_insere(a, '2');
    arvv_insere(a, '3');
    arvv_insere(a, '4');
    arvv_insere(a, '5');

    arvv_imprime(a);

    arvv_pertence(a, '7') == 1 ? printf("pertence a árvore") : printf("não pertence a árvore");

    arvv_folhas(a);

    printf("%d\n", arvv_altura(a));

    ArvVar *b = arvv_copia(a);

    arvv_igual(a, b) == 1 ? printf("árvore igual") : printf("árvore não igual");

    arvv_libera(a);

    return 0;
}