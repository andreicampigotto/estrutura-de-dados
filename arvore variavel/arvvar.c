#include "arvvar.h"
#include <stdio.h>
#include <stdlib.h>

// esta função cria um nó folha e retorna seu endereço de memória. Sendo um nó folha, seus ponteiros para prim e prox devem ser
// inicializadas como NULL
ArvVar *arvv_cria(char c)
{
}

// insere uma sub-árvore sa como filha de um dado nó a
void arvv_insere(ArvVar *a, ArvVar *sa)
{
}

// deve imprimir a árvore em pré-ordem (primeiro o nó raiz, e depois cada uma das sub-árvores)
void arvv_imprime(ArvVar *a)
{
}

// retorna 1 caso o caracter c estiver contido na árvore, e retorna 0 caso contrário
int arvv_pertence(ArvVar *a, char c)
{
}

// libera a memória alocada pela árvore
void arvv_libera(ArvVar *a)
{
}

// retorna a quantidade de nós folha da árvore
int arvv_folhas(ArvVar *a)
{
}

// retorna a altura da árvore (0 para árvore vazia)
int arvv_altura(ArvVar *a)
{
}

// retorna 1 se as árvores a1 e a2 são iguais. Retorna 0 caso contrário.
// As duas árvores são iguais se seus nós armazenarem informações iguais nas mesmas posições
int arvv_igual(ArvVar *a1, ArvVar *a2)
{
}

// retorna uma cópia da árvore a. A nova árvore deve ter novos nós instanciados
ArvVar *arvv_copia(ArvVar *a)
{
}
