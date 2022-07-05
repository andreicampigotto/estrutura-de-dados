#include <stdio.h>
#include <stdlib.h>

int Soma_elementos(int V[], int n);
void Exibe_invertido(char mensagem[], int tamanho);
int Potencia(int x, int y);
long Euclides(long m, long n);

// Implementar um método recursivo para calcular
// o produto de dois números inteiros arbitrários usando apenas o operador de soma
int Soma_elementos(int V[], int n)
{
    if (n == 0)
        return 0;
    else
        return (V[n] + Soma_elementos(V, n - 1));
}

// Implementar um método para imprimir uma String de maneira invertida
void Exibe_invertido(char mensagem[], int tamanho)
{
    if (tamanho >= 0)
    {
        printf("%c ", mensagem[tamanho]);
        Exibe_invertido(mensagem, tamanho - 1);
    }
}

// Implementar um método para calcular uma operação de potência de modo recursiva (fornecer base e expoente)
int Potencia(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
        return x * Potencia(x, n - 1);
}

// Implementar um método recursivo para calcular o MDC de 2 números pelo algoritmo de Euclides
long Euclides(long m, long n)
{
    if (n == 0)
        return m;
    return Euclides(n, m % n);
}

int main(int argc, char const *argv[])
{
    int tamanho = 10;
    char mensagem[10] = "teste";

    Exibe_invertido(mensagem, tamanho);

    int N = 5;
    int V[5];
    V[0] = 3;
    V[1] = 4;
    printf("resultado=%d", Soma_elementos(V, N - 1));
    return 0;

    int x = 2, y = 2;
    printf("resultado=%d", Potencia(x, y));

    long e1 = 4000, e2 = 32320;
    printf("resultado=%ld", Euclides(e1, e2));
}