#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *criaVetorEmbaralhado(int n);
int buscaLinear(int vet[], int elem);
int buscaBinaria(int vet[], int elem);
void bubbleSort(int n, int *v);

int *criaVetorEmbaralhado(int n)
{
    int *arr = malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int j = (rand() % n);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return arr;
}

void bubbleSort(int n, int *v)
{
    int j, troca = 0;

    for (j = 0; j < n - 1; j++)
    {
        if (v[j] > v[j + 1])
        {
            int aux = v[j];
            v[j] = v[j + 1];
            v[j + 1] = aux;
            troca = 1;
        }
    }
    if (troca == 1)
    {
        bubbleSort(n - 1, v);
    }
}

int buscaLinear(int vet[], int elem)
{
    int n = sizeof vet;
    for (int i = 0; i < n; i++)
    {
        if (elem == vet[i])
            return i;
    }
    return -1;
}

int buscaBinaria(int vet[], int elem)
{
    int n = sizeof vet;
    int ini = 0;
    int fim = n - 1;
    int meio;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (elem < vet[meio])
        {
            fim = meio - 1;
        }
        else
        {
            if (elem > vet[meio])
            {
                ini = meio + 1;
            }
            else
                return meio;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    // 10
    long n = 10, elem = 7;
    int *v = criaVetorEmbaralhado(n);
    printf(" Busca linear com 10:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    bubbleSort(n, v);
    printf("\nposição: %d ", buscaLinear(v, elem));
    printf("\n\n");
    free(v);

    // 100
    n = n * 10;
    v = criaVetorEmbaralhado(n);
    printf("\n");
    printf("Busca linear com 100\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    bubbleSort(n, v);
    printf("\nposição: %d ", buscaLinear(v, elem));
    printf("\n\n");
    free(v);

    // 1000
    n = n * 10;
    v = criaVetorEmbaralhado(n);
    printf("\n");
    printf("Busca linear com 1000\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    bubbleSort(n, v);
    printf("\nposição: %d ", buscaLinear(v, elem));
    printf("\n\n");
    free(v);

    // 10000
    n = n * 10;
    v = criaVetorEmbaralhado(n);
    printf("\n");
    printf("Busca linear com 10000\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    bubbleSort(n, v);
    printf("\nposição: %d ", buscaLinear(v, elem));
    printf("\n\n");
    free(v);

    // 100000
    n = n * 10;
    v = criaVetorEmbaralhado(n);
    printf("\n");
    printf("Busca linear com 100000\n");
    for (int i = 0; i < n; i++)
    {
        printf("%ld ", v[i]);
    }
    printf("\n");
    bubbleSort(n, v);
    printf("\nposição: %d ", buscaLinear(v, elem));
    printf("\n\n");
    free(v);
    free(n);

    // 10
    n = 10;
    v = criaVetorEmbaralhado(n);
    printf("\n");
    printf("Busca binaria com 10:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\nposição: %d ", buscaBinaria(v, elem));
    printf("\n\n");
    free(v);

    // 100
    n = n * 10;
    v = criaVetorEmbaralhado(n);
    printf("\n");
    printf("Busca binaria com 100:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\nposição: %d ", buscaBinaria(v, elem));
    printf("\n\n");
    free(v);

    // 1000
    n = n * 10;
    v = criaVetorEmbaralhado(n);
    printf("\n");
    printf("Busca binaria com 1000\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\nposição: %d ", buscaBinaria(v, elem));
    printf("\n\n");
    free(v);

    // 10000
    n = n * 10;
    v = criaVetorEmbaralhado(n);
    printf("\n");
    printf("Busca binaria com 10000\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\nposição: %d ", buscaBinaria(v, elem));
    printf("\n\n");
    free(v);

    // 100000
    n = n * 10;
    v = criaVetorEmbaralhado(n);
    printf("\n");
    printf("Busca binaria com 100000\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\nposição: %d ", buscaBinaria(v, elem));
    printf("\n\n");
    free(v);
    free(n);

    return 0;
}
