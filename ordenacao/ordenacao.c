#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *criaVetorEmbaralhado(int n);

void bubbleSort(int n, int *v);
void quickSort(int v[], int a, int b);
void mergeSort(int v[], int primeiro, int ultimo);
int particiona(int *v, int a, int b);
void troca(int v[], int a, int b);

int *criaVetorEmbaralhado(int n)
{
    int *arr = malloc(n * sizeof(int));
    int *aux = malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i; i < n; i++)
    {
        aux[i] = i;
    }

    for (int i; i < n; i++)
    {
        j = (rand() % n);
        int temp = aux[i];
        aux[i] = aux[j];
        aux[j] = temp
    }
}

void bubbleSort(int n, int *v)
{
    int j, troca = 0;

    for (j = 0; j < n; j++)
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

void quickSort(int v[], int a, int b)
{
    if (a < b)
    {
        int pivo = particiona(v, a, b);
        quickSort(v, a, pivo - 1);
        quickSort(v, pivo + 1, b);
    }
}

int particiona(int v[], int a, int b)
{
    int x = v[a];
    while (a < b)
    {
        while (v[a] < x)
        {
            a++;
        }
        while (v[b] > x)
        {
            b--;
        }
        troca(v, a, b);
    }
    return a;
}

void troca(int v[], int a, int b)
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void Merge(v, primeiro, q, ultimo)
{
    int n1 = q - primeiro + 1;
    int n2 = ultimo - q;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    memcpy(L, v, n1 * sizeof(int));
    memcpy(R, v, n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        L[i] = v[primeiro + i];
        for (int j = 0; j < n2; j++)
        {
            R[j] = v[q + j + 1];
        }
        for (p = primeiro; p < ultimo; p++)
        {
            if (L[i] <= R[j])
            {
                v[p] = L[i];
                i++;
            }
            else
            {
                v[p] = R[j];
                j++;
            }
        }
    }
}

void mergeSort(v, primeiro, ultimo)
{
    if (primeiro < ultimo)
    {
        int q = (primeiro + ultimo) / 2;
        mergeSort(v, primeiro, ultimo);
        mergeSort(v, primeiro + 1, ultimo);
        Merge(v, primeiro, q, ultimo);
    }
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int *v = malloc(n * sizeof(int));

    v = criaVetorEmbaralhado(n);

    bubbleSort(n, v);
    quickSort(v, 0, n);
    mergeSort(v, 0, n);

    free(v);
    return 0;
}