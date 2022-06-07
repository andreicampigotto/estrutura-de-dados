#include pilha.h 
#include lista.h

Pilha *pilha_cria(void){
    Pilha *p = (Pilha *)calloc(1, sizeof(Pilha));
        p->topo = NULL;
        return p;
}


void pilha_push(Pilha *p, float v){
    NoLista *no = (NoLista *)malloc(sizeof(NoLista));
    no->valor = v;
    no->prox = p->topo;
    p->topo = no;
}



float pilha_pop(Pilha *p){
    NoLista *no = Null;
    if(p->topo){
        no= p->topo;
        p->topo = no->prox;
    }
    return no;

}

int pilha_vazia(Pilha *p){
    return p->topo ==Null;
}

void pilha_libera(Pilha *p){
    while (!pilha_vazia(p))
        {
            NoLista *tmp = p->topo;
            p->topo = p->topo->prox;
            free(tmp);
        }
}
