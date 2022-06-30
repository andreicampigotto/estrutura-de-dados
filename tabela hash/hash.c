#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

// funcao de dispersao. Calcula um ındice na tabela, a partir da chave k. No caso deste exercıcio, k e o numero
// de matrıcula de um aluno. A funcao deve ser declarada estatica para que seu escopo seja local (restrito ao modulo hash.c);
static int hash(int k)
{
    return k;
}

// operacao para buscar e retornar a refefencia para um Aluno com numero de matrıcula mat. Se o aluno nao for encontrado na tabela tab,
// retorna null.
Aluno *hsh_get(Hash tab, int mat)
{
    int h = hash(mat);
    while (tab[h] != NULL)
    {
        if (tab[h]->matricula == mat)
        {
            return tab[h];
        }
        h = (h + 1) % sizeof tab;
    }
    return NULL;
}

// insere os dados de um novo aluno na tabela tab. Se ja existir o cadastro do aluno na tabela, altere os dados inserindo os valores passados
// para a funcao. A funcao deve retornar o ponteiro para o novo aluno inserido, ou para o aluno com dados modificados;
Aluno *hsh_set(Hash tab, int mat, char *n, char *e, char t)
{
}

// remove da tabela tab o registro do aluno com matrıcula mat. Caso este aluno nao seja encontrado, a fun ̧cao nao faz qualquer alteracao na tabela;
void hsh_remove(Hash tab, int mat)
{
    int achou;
    int end = hsh_get(tab, mat);
    if (achou)
    {
        // remove marcando flag para liberado
        free(tab[end]);
    }
    else
    {
        printf("Matricula nao encontrada");
    }
}

// imprime o conteu ́do de toda a tabelahash.
void hsh_imprime(Hash tab)
{
}
