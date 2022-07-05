public
void insereOrdenado(int v)
{

    NoLista ant = NULL;
    NoLista novo;
    NoLista p = prim;

    while (p != NULL && p->info < v)
    {
        ant = p;
        p = p->prox;
    }
    novo = *NoList();
    novo->info = v;

    if (ant == NULL)
    {
        novo->prox = prim;
        prim = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
}