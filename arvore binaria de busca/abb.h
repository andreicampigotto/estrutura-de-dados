struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
};
typedef struct arv Arv;

Arv *abb_cria(void);
void abb_imprime(Arv *a);
Arv *abb_busca(Arv *r, int v);
Arv *abb_insere(Arv *a, int v);
Arv *abb_retira(Arv *r, int v);
void abb_imprimeDecrescente(Arv *a);
