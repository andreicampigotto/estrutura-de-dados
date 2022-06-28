#include <stdio.h>
#include <stdlib.h>

int *criaVetorEmbaralhado(int n);
int buscaLinear(int n, int *vet, int elem);
int buscaBinaria(int n, int *vet, int elem);

int *criaVetorEmbaralhado(int n)
{
}

int buscaLinear(int n, int *vet, int elem)
{
    for (int i = 0; i < n; i++)
    {
        if (elem == vet[i])
            return i;
    }
    return -1;
}

int buscaBinaria(int n, int *vet, int elem)
{
    for (int i = 0; i < n; i++)
    {
        if (elem == vet[i])
        {
            return i;
        }

        else if (elem < vet[i])
        {
            return -1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    return 0;
}
