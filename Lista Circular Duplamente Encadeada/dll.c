/*
**	Dll - Pacote de software para gerenciamento de listas 
**            circulares duplamente encadeadas. 
**
**	comentarios:
**	---------------------------------------------------------------
**
**	Funcionalidade:
**      Este eh um pacote para gerenciamento generico de listas circulares
**      duplamente encadeadas. Eh generico no sentido de que realiza as 
**      operacoes basicas em listas duplamente encadeadas.
**      Para que isto seja possivel, eh necessario que os dois primeiros
**      campos de qualquer elemento da lista cliente sejam ponteiros para
**      os elementos anterior (previus) e posterior (next) na lista.
**      A alocacao de memoria para um elemento da lista eh feito neste 
**      pacote. Para tal, os operadores de insercao necessitam que o 
**      tamanho do elemento da lista cliente seja passado como argumento 
**      (incluindo o tamanho dos campos next e previus).
**      Abaixo eh mostrada a estrutura da lista dupla generica:
**
**		typedef struct _dllrec {
**			struct _dllrec	*next;
**			struct _dllrec	*prev;
**		   } *Dll, DllRec;
**
**      Cabeca da lista:
**      Embora a lista circular nao possua cabeca, neste pacote a cabeca
**      significa, por convencao, o primeiro elemento na lista. A cabeca
**      (head) funciona como uma referencia para a lista, e eh usada
**      para que se tenha acesso a lista.
**      Nos operadores deste pacote, o argumento head sempre eh passado
**      por referencia, porque sempre ha a possibilidade de que a cabeca 
**      da lista possa ser alterada em cada operacao.
**
**
**	---------------------------------------------------------------
**
**	Funcoes:
**	---------------------------------------------------------------
**
** 	DllRec	*DllAddEnd( Dll *head, unsigned int size )
**
**		    head	- cabeca da lista		(in/out)
**		    size	- tamanho do elemento da lista	(in)
**
**              Esta funcao insere um elemento no final de uma lista,
**              ie, antes da cabeca (head). A funcao retorna um ponteiro
**              para o novo elemento.
**              O argumento size eh usado para alocacao dinamica de 
**              memoria para o elemento da lista a ser criado.
**              Se *head for null, assume-se que a lista esta vazia e que
**              o novo elemento tera ambos os ponteiros next e previus
**              apontando para si proprio.
**              Se nao for possivel alocar memoria para o elemento da 
**              lista, a funcao deve retornar um ponteiro nulo (null).
**
**	---------------------------------------------------------------
**
** 	DllRec	*DllAddAft( Dll *head, Dll elem, unsigned int size )
**
**		    head	- cabeca da lista		(in/out)
**		    elem	- elemento de referencia	(in)
**		    size	- tamanho do elemento da lista	(in)
**
**              Esta funcao insere um elemento depois de um dado elemento
**              da lista (elemento de referencia). A funcao retorna um
**              ponteiro para o novo elemento.
**              O argumento size eh usado para alocacao dinamica de 
**              memoria para o elemento da lista a ser criado.
**              Se *head for null, assume-se que a lista esta vazia e que
**              o novo elemento tera ambos os ponteiros next e previus
**              apontando para si proprio. Caso contrario, assume-se que
**              o elemento de referencia realmente pertence a lista.
**              Se nao for possivel alocar memoria para o elemento da 
**              lista, a funcao deve retornar um ponteiro nulo (null).
**
**	---------------------------------------------------------------
**
**	void	DllDelOne( Dll *head, Dll elem )
**
**		    head	- cabeca da lista		(in/out)
**		    elem	- elemento a ser removido	(in)
**
**              Esta funcao remove um elemento da lista.
**              Assume-se que o elemento fornecido realmente pertence
**              a lista.
**              Aqui, remover um elemento implica em liberar a memoria
**              utilizada pelo elemento.
**              Se o elemento a ser removido eh a cabeca da lista, a nova
**              cabeca da lista (depois da remocao) sera o seu elemento
**              sucessor na lista, que retornara' no argumento "head".
**              Se o elemento a ser removiso eh o ultimo elemento 
**              remanescente na lista, a funcao retorna um ponteiro 
**              nulo (null) no argumento head.
**              Se a lista esta vazia, (head eh igual a null), entao nenhuma
**              acao sera tomada.
**
**	---------------------------------------------------------------
**
**	void	DllDelAll( Dll *head )
**
**		    head	- cabeca da lista		(in/out)
**
**              Esta funcao remove todos os elementos de uma lista.
**              O valor de retorno da cabeca da lista eh null.
**
**	---------------------------------------------------------------
**
**	versao:	0-001
**
**	historico:	Data	        Autor
**  Criacao:	maio-1993	    Luiz Fernando Martha
**		
*/

/*
**	---------------------------------------------------------------
**	Definicoes e variaveis globais:
*/
#include <stdlib.h>	/* calloc, free */
#include "dll.h"

/*
**	---------------------------------------------------------------
**	Definicoes e variaveis locais: (nenhum)
*/


/*
**	---------------------------------------------------------------
**	Funcoes privadas: (nenhuma)
*/


/*
**	---------------------------------------------------------------
**	Implementacao das funcoes comeca aqui:
*/

/*=========================  DllAddEnd  =========================*/
Dll DllAddEnd(Dll *head, unsigned int size){
    
    Dll novo =(Dll) calloc(1,size);
    
    if(novo !=NULL){
        if(*head){
            Dll ultimo = *head->prev;
            ultimo->next = novo;
            novo->prev = ultimo;
            novo->next = *head;
            *head->prev = novo;
    
        }
  
        else{
            *head = novo;
            *head->prev = *head;
            *head->next = *head;
   
        }
        return novo
    }
    
    return NULL
}


/*=========================  DllAddAft  =========================*/
Dll DllAddAft(Dll *head, Dll elem, unsigned int size){
    
    Dll novo =(Dll) calloc(1,size);
    
   if(novo !=NULL){
       if(*head){
           Dll proximo;
           proximo = elem->next;
           elem->next = novo;
           novo->next = proximo;
           novo->prev = elem;
           proximo->prev = novo;
       }
 
       else{
           *head = novo;
           *head->prev = *head;
           *head->next = *head;
  
       }
       return novo
   }
    return NULL
    
}

/*=========================  DllDelOne  =========================*/
void DllDelOne(Dll *head, Dll elem){
    
    if(elem !=NULL){;
        if(*head){
            Dll proximo;
            Dll anterior;
            proximo = elem->next;
            anterior = elem->prev;
            anterior->prev = proximo;
            proximo->next = anterior;
            free(elem);
        }
        else
            printf( "\n\n Elemento a ser removido nao foi encontrado !!! \n\n" );
    }

}


/*=========================  DllDelAll  =========================*/
void DllDelAll(Dll *head){
    if(*head != NULL){
        free(lista);
    }
}


