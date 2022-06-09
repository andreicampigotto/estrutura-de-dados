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
}