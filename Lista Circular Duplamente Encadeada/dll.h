/*
**       dll.h:   Definicoes para listas circulares duplamente encadeadas.
**
**       Criacao:	13-Mai-93		Luiz Fernando Martha
**
*/

#ifndef _dll_h
#define _dll_h

typedef struct _dllrec{
  struct _dllrec *next;
  struct _dllrec *prev;
} * Dll, DllRec;

/* prototipo das funcoes */

Dll DllAddEnd(Dll *head, unsigned int size);
Dll DllAddAft(Dll *head, Dll elem, unsigned int size);
void DllDelOne(Dll *head, Dll elem);
void DllDelAll(Dll *head);

#endif
