/*
** -------------------------------------------------------------------------
**
** dlldrv.c - Modulo exemplo para utilizacao do pacote dll.
**
** -------------------------------------------------------------------------
**
** Created: 13-Apr-95	Paulo C. Rodacki Gomes
**
** -------------------------------------------------------------------------
*/

#include <stdio.h>	/* printf, scanf */
#include <stdlib.h>	/* exit */
#include "dll.h"

typedef enum {
 NONE,
 ADDEND,
 ADDAFT,
 DELETE,
 DELALL,
 FINISH
 } Option;

typedef struct _list {
 struct _list *next;
 struct _list *prev;
 char         c;
 } List;

List *list_head = NULL;

List *FindElem( char );
void DspList  ( void );
void DspMenu  ( void );
void DspUpdate( void );

void main ( void )
{
  *l;
 char s[128];
 int  option;

 while( 1 )
 {
  DspUpdate( );

  scanf( "%s", s );
  option = s[0] - '0';
  switch( option )
  {
   case ADDEND:
    printf( " Entre o nome do novo elemento: " );
    scanf( "%s", s );
    l = (List *)DllAddEnd( (Dll *)&list_head, sizeof(List) );
    l->c = s[0];
    break;

   case ADDAFT:
    printf( " Entre o nome do elemento de referencia: " );
    scanf( "%s", s );
    l = FindElem( s[0] );
    if( l != NULL )
    {
     printf( " Entre o nome do novo elemento: " );
     scanf( "%s", s );
     l = (List *)DllAddAft( (Dll *)&list_head, (Dll)l, sizeof(List) );
     l->c = s[0];
    }
    else
     printf( "\n\n O elemento de referencia nao foi encontrado !!! \n\n" );
    break;

   case DELETE:
    if( list_head == NULL ) break;
    printf( " Entre o nome do elemento a ser removido: " );
    scanf( "%s", s );
    l = FindElem( s[0] );
    if( l != NULL )
     DllDelOne( (Dll *)&list_head, (Dll)l );
    else
     printf( "\n\n Elemento a ser removido nao foi encontrado !!! \n\n" );
    break;

   case DELALL:
    if( list_head == NULL ) break;
    DllDelAll( (Dll *)&list_head );
    break;

   case FINISH:
    exit( 1 );

   default:
    break;
  }
 }
}


List *FindElem( char c )
{
 List *l = list_head;

 if( l != NULL )
 {
  do
  {
   if( l->c == c ) return( l );
   l = l->next;
  } while( l != list_head );
 }
 return( NULL );
}


void DspMenu( void )
{
 printf( " Opcoes  \n" );
 printf( " 1 - Adicionar elemento no final \n" );
 printf( " 2 - Adicionar elemento apos outro elemento \n" );
 printf( " 3 - Remover elemento \n" );
 printf( " 4 - Remover todos \n");
 printf( " 5 - Sair \n\n" );
 printf( " Entre sua opcao ? ");
}


void DspList( void )
{
 List *l = list_head;

 if( l == NULL )
 {
  printf( "\n\n Lista vazia \n\n" );
 }
 else
 {
  printf( "\n\n Lista atual: " );
  do
  {
   printf( "  %c  ", l->c );
   l = l->next;
  } while( l != list_head );
  printf( "\n\n" );
 }
}

void DspUpdate( void )
{
 DspList( );
 DspMenu( );
}

