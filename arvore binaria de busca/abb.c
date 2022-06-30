#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <abb.h>

// cria uma arvore binaria vazia (i.e., simplesmente retorna NULL);
Arv *abb_cria(void)
{
    return NULL;
}

// percorre a arvore em ordem simetrica para imprimir seu conteu ́do (nu ́meros) em ordem crescente;
void abb_imprime(Arv *a)
{
    printf("<");
    if (!abb_cria())
    {
        abb_imprime(a->esq);
        printf("%c", a->info);
        abb_imprime(a->dir);
    }
    printf(">");
}

// esta e a operacao para buscar umelemento na arvore, com desempenho computacional proporcional a
// sua altura (O(log n)), portanto, a funcao deve se valer do fato de a arvore estar ordenada. Caso o valor v seja encontrado, a funcao
// retorna o endereco do no que armazena v. Caso contrario, a funcao deve retornar NULL;
Arv *abb_busca(Arv *r, int v)
{
    if (r == NULL)
    {
        return NULL;
    }
    else
    {
        if (v < r->info)
        {
            abb_busca(r->esq, v);
        }
        else
        {
            if (v > r->info)
            {
                abb_busca(r->esq, v);
            }
            else
            {
                return r;
            }
        }
    }
}

// adiciona um novo elemento na arvore na posicao correta para que a propriedade fundamental de ordenacao seja mantida. Importante notar a necessidade de atualizar os
// ponteiros para sub arvores a esquerda ou a direita quando da chamada recursiva da funcao, pois a insercao pode alterar o valor do ponteiro
// para a raiz da (sub)arvore;
Arv *abb_insere(Arv *a, int v)
{
    if (a == NULL)
    {
        a = (Arv *)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else
    {
        if (v < a->info)
        {
            a->esq = abb_insere(a->esq, v);
        }
        else
        {
            a->dir = abb_insere(a->dir, v);
        }
    }
    return a;
}

// operacao para retirar um elemento com valor v da arvore. A funcao tem como valor de retorno a eventual nova raiz da (sub)arvore.
Arv *abb_retira(Arv *r, int v)
{
    if (r == NULL)
    {
        return NULL;
    }
    else
    {
        if (v < r->info)
        {
            r->esq = abb_retira(r->esq, v);
        }
        else
        {
            if (v > r->info)
            {
                r->dir = abb_retira(r->dir, v);
            }
            else
            {
                if (r->esq == NULL && no.dir == NULL)
                {
                    r = NULL;
                }
                else
                {
                    if (r->esq == NULL)
                    {
                        r = r->dir;
                    }
                    else
                    {
                        if (r->dir == NULL)
                        {
                            r = r->esq;
                        }
                        else
                        {
                            // cria p
                            while (p.dir != NULL)
                            {
                                p = p.dir;
                                r->info = p->info;
                                p->info = v;
                                r->esq = retiraAux(r->esq, valor);
                            }
                        }
                    }
                }
            }
        }
    }
    return r;
}

// implementacao semelhantea funcao abb_imprime, porem deve imprimir o elementos da arvore em ordem decrescente.
void abb_imprimeDecrescente(Arv *a)
{
    printf("<");
    if (!abb_cria())
    {
        abb_imprimeDecrescente(a->esq);
        abb_imprimeDecrescente(a->dir);
        printf("%c", a->info);
    }
    printf(">");
}
