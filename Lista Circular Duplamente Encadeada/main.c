#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main (void) {
    plista lst;

    criarLista(&lst);

    inserirInicio(&lst, 10);
    inserirInicio(&lst, 20);
    inserirFinal(&lst, 30);
    inserirPosK(&lst, 2, 40);

    removerPosK(&lst, 3);

    imprimirLista(lst);
}