#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char const *argv[])
{
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    int mat = 3;
    char n[81] = 'tata';
    char e[41] = 'tata@tatamail.com';
    char t = 1;

    hsh_set(novo, mat, n, e, t);

    hsh_get(novo, mat);

    hsh_imprime(novo);

    hsh_remove(novo, mat);
}