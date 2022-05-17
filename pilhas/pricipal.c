#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void main ( void )
{
struct calc {
    charf[21]; /* formato para impressão, por exemplo “%.2f\n” */
    Pilha *p; /* pilha de operandos */
    };
    typedef struct calc Calc;

    Calc calc_cria(char* f);

    void calc_operando(Calc* c, float v);
    void calc_operador(Calc* c, char op);
    void calc_libera(Calc *c);
    
}

Calc *calc_cria(char *f){
    Calc *c = (Calc *)malloc(1, sizeof(Calc));
    c->p = pilha_cria();
    strcpy(c->f, f);
    return c;
}

void calc_operando(Calc *c, float v){
    pilha_push(c->p, v);
}

void calc_operador(Calc *c, char op)
{
    float op2 = (pilha_vazia(c->p)) ? 0.0 : pilha_pop(c->p);
    float op1 = (pilha_vazia(c->p)) ? 0.0 : pilha_pop(c->p);

    switch (op)
    {
    case '+':
        pilha_push(c->p, op1 + op2);
        break;
    case '-':
        pilha_push(c->p, op1 - op2);
        break;
    case '*':
        pilha_push(c->p, op1 * op2);
        break;
    case '/':
        pilha_push(c->p, op1 / op2);
        break;
    default:
        printf("Erro! Operação com operador inválido!\n");
        break;
    }
}

// libera a memória usada pela calculadora (incluindo a Pilha).
void calc_libera(Calc *c)
{
    pilha_libera(c->p);
    free(c);
    // c->f = NULL;
}

