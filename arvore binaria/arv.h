#ifndef _arv_h
#define _arv_h

struct arv
{
    char info;
    struct arv *esq;
    struct arv *dir;
};
typedef struct arv Arv;

Arv *arv_criavazia(void);
Arv *arv_cria(char c, Arv *e, Arv *d);
Arv *arv_libera(Arv *a);
int arv_vazia(Arv *a);
int arv_pertence(Arv *a, char c);
void arv_imprime(Arv *a);
void arv_imprime_pre(Arv *a);
void arv_imprime_sim(Arv *a);
void arv_imprime_pos(Arv *a);
int arv_folhas(Arv *a);
int arv_altura(Arv *a);
int arv_igual(Arv *a1, Arv *a2);
Arv *arv_copia(Arv *a);

#endif