#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *criaVetorEmbaralhado(int n);

void bubbleSort(int n, int *v);
void quickSort(int v[], int a, int b);
void mergeSort(int v[], int primeiro, int ultimo);
int particiona(int *v, int a, int b);
void troca(int v[], int a, int b);
void Merge(int v[], int primeiro, int q, int ultimo);

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

void Merge(int v[], int primeiro, int q, int ultimo)
{
    int n1 = q - primeiro + 1;
    int n2 = ultimo - q;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    int i = 0, j = 0;
    for (i = 0; i < n1 - 1; i++)
    {
        L[i] = v[primeiro + i];
    }

    for (j = 0; j < n2 - 1; j++)
    {
        R[j] = v[q + j + 1];
    }

    L[n1] = INT8_MAX;
    R[n2] = INT8_MAX;
    i = 0;
    j = 0;

    for (int p = primeiro; p < ultimo; p++)
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

void mergeSort(int v[], int primeiro, int ultimo)
{
    if (primeiro < ultimo)
    {
        int q;
        q = ((primeiro + ultimo) / 2);

        mergeSort(v, primeiro, q);
        mergeSort(v, q + 1, ultimo);
        Merge(v, primeiro, q, ultimo);
    }
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int *v = criaVetorEmbaralhado(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    bubbleSort(n, v);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);

    v = criaVetorEmbaralhado(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    quickSort(v, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);

    v = criaVetorEmbaralhado(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    mergeSort(v, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    free(v);

    n = 10 * n;
    v = criaVetorEmbaralhado(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    bubbleSort(n, v);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);

    v = criaVetorEmbaralhado(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    quickSort(v, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);

    v = criaVetorEmbaralhado(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    mergeSort(v, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    free(v);

    n = 10 * n;
    v = criaVetorEmbaralhado(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    bubbleSort(n, v);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);

    v = criaVetorEmbaralhado(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    quickSort(v, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);

    v = criaVetorEmbaralhado(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    mergeSort(v, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }

    free(v);
    return 0;
}