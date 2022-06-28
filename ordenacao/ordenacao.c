#include <stdio.h>
#include <stdlib.h>

int *criaVetorEmbaralhado(int n);

void bubbleSort(int n, int *v);
void quickSort(int n, int *v);
void mergeSort(v, primeiro, ultimo);

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

    for (int i = 0; i < v[n]; i++)
    {
        printf(" %d ", v[i]);
    }
    printf("\n");
}

void Merge(v, primeiro, q, ultimo)
{
    int n1 = q - primeiro + 1;
    int n2 = ultimo - q;

    int : L[0..n1];
    int : R[0..n1];

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
        MergeSort(v, primeiro, ultimo);
        MergeSort(v, primeiro + 1, ultimo);
        Merge(v, primeiro, q, ultimo);
    }
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