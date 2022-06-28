#include <stdio.h>
#include <stdlib.h>

int *criaVetorEmbaralhado(int n);

void bubbleSort(int n, int *v);
void quickSort(int n, int *v);
void mergeSort(int n, int *v);

int *criaVetorEmbaralhado(int n)
{
    n = 10;
    for (int i = 0; i < n; i++)
    {
        return rand() % (n * 10);
    }
}

void bubbleSort(int n, int *v)
{
    int aux;

    for (int i = 1; i < n; i++)
    {
        printf("\n[%d] ", i);

        for (int j = 0; j < n - 1; j++)
        {
            printf("%d, ", j);

            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void troca(int v[], int a, int b)
{
    int tmp;
    tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

void quickSort(int n, int *v)
{

    int pivo = v[0];

    if (v[n] > v[0])
    {
        int i, f;
        i = v[0];
        f = v[n];

        while (v[1] <= v[n])
        {
            if (v[i] <= pivo)
                i++;
            else if (v[f] > pivo)
                f--;
            else
            {
                troca(v, i, f);
                i++;
                f--;
            }
        }

        i--;
        troca(v, v[0], i);
    }

    for (int i = 0; i < (int)sizeof(v); i++)
    {
        printf(" %d ", v[i]);
    }
    printf("\n");
}

void intercala(int v1[], int i1, int f1,
               int v2[], int i2, int f2,
               int v3[])
{
    int n1, n2, n3, k1, k2;

    n1 = f1 - i1 + 1;
    n2 = f2 - i2 + 1;
    n3 = n1 + n2;

    k1 = i1;
    k2 = i2;
    for (int i = 0; i < n3; i++)
    {
        if (k1 <= f1 && k2 <= f2)
        {
            if (v1[k1] <= v2[k2])
            {
                v3[i] = v1[k1];
                k1++;
            }
            else
            {
                v3[i] = v2[k2];
                k2++;
            }
        }
        else if (k1 <= f1)
        {
            v3[i] = v1[k1];
            k1++;
        }
        else
        {
            v3[i] = v2[k2];
            k2++;
        }
    }
}

void mergeSort(int n, int *v)
{

    int *aux;
    int m = (v[0] + (int)sizeof(v)) / 2;
    if (v[0] < (int)sizeof(v))
    {
        mergesort(v, v[0], m);
        mergesort(v, m + 1, (int)sizeof(v));

        aux = (int *)malloc(sizeof(int) * ((int)sizeof(v) - v[0] + 1));

        intercala(v, v[0], m,
                  v, m + 1, (int)sizeof(v),
                  aux);
        for (int i = 0; i < (int)sizeof(v) - v[0] + 1; i++)
        {
            v[v[0] + i] = aux[i];
        }
        free(aux);
    }

    for (int i = 0; i < (int)sizeof(v); i++)
        printf(" %d ", v[i]);
    printf("\n");

    return 0;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    int *v;
    v = (int *)malloc(n * sizeof(int));

    v = criaVetorEmbaralhado(n);

    bubbleSort(n, v);
    quickSort(n, v);
    mergeSort(n, v);

    free(v);
    return 0;
}