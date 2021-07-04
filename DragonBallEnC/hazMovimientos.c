#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define REN 46
#define COL 7


typedef struct nodo
{
  float x1;
  float y1;
  FILE *archivo;
  struct nodo *sig;
  struct nodo *ant;
  struct nodo *arr;
  struct nodo *aba;
}*MALLA;

void pintaEsfera(MALLA esfeFun);
void pintaCasa(MALLA casa);
void pintaArbol(MALLA arbol);

/*
 Objetivo: Esta funcion realiza los movimientos de los diferentes objetos cuando el personaje principal se desplaza hacia abajo
 Parametro de Entrada: Los auxiliares de objetos del tipo malla.
 Parametro de salida:
*/
void hazMovi(MALLA *esfe, MALLA *casa, MALLA *casa2, MALLA *casa3, MALLA *casa4, MALLA *casa5, MALLA *casa6, MALLA *casa7, MALLA *casa8, MALLA *casa9, MALLA *casa10, int *bE1, MALLA *esfe2, int *bE2, MALLA *esfe3, int *bE3, MALLA *esfe4, int *bE4, MALLA *esfe5, int *bE5, MALLA *esfe6, int *bE6, MALLA *esfe7, int *bE7, MALLA *arbol, MALLA *arbol2, MALLA *arbol3, MALLA *arbol4, MALLA *arbol5, MALLA *arbol6)
{

    if((*esfe)->arr)
            {
             (*esfe) = (*esfe)->arr;
             (*casa) = (*casa)->arr;

              if(*bE1 == 0)
                {
                  pintaEsfera(*esfe);
                  pintaCasa(*casa);
                }
              else
                {
                  pintaCasa(*casa);
                }
             }
    else
        (*esfe)->arr = NULL;

    if((*esfe2)->arr)
            {
                (*esfe2) = (*esfe2)->arr;

                    if(*bE2 == 0)
                        pintaEsfera(*esfe2);
                            else
                            {
                              setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                              bar((*esfe2)->x1,(*esfe2)->y1,(*esfe2)->x1+78, (*esfe2)->y1+119.6);
                            }
            }
    else
                (*esfe2)->arr = NULL;


    if((*esfe3)->arr)
                {
                  (*esfe3) = (*esfe3)->arr;

                            if(*bE3 == 0)
                                pintaEsfera(*esfe3);
                            else
                                {
                                    setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                                    bar((*esfe3)->x1,(*esfe3)->y1,(*esfe3)->x1+78, (*esfe3)->y1+119.6);

                                }
                }
    else
        (*esfe3)->arr = NULL;


        if((*esfe4)->arr)
                {
                 (*esfe4) = (*esfe4)->arr;
                 (*casa4) = (*casa4)->arr;

              if(*bE4 == 0)
                {
                  pintaEsfera(*esfe4);
                  pintaCasa(*casa4);
                }
              else
                {
                  pintaCasa(*casa4);
                }
             }
    else
        (*esfe4)->arr = NULL;


        if((*esfe5)->arr)
                {
                  (*esfe5) = (*esfe5)->arr;

                            if(*bE5 == 0)
                                pintaEsfera(*esfe5);
                            else
                                {
                                    setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                                    bar((*esfe5)->x1,(*esfe5)->y1,(*esfe5)->x1+78, (*esfe5)->y1+119.6);

                                }
                }
    else
        (*esfe5)->arr = NULL;


        if((*esfe6)->arr)
                {
                  (*esfe6) = (*esfe6)->arr;

                            if(*bE6 == 0)
                                pintaEsfera(*esfe6);
                            else
                                {
                                    setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                                    bar((*esfe6)->x1,(*esfe6)->y1,(*esfe6)->x1+78, (*esfe6)->y1+119.6);

                                }
                }
    else
        (*esfe6)->arr = NULL;


        if((*esfe7)->arr)
                {
                  (*esfe7) = (*esfe7)->arr;

                            if(*bE7 == 0)
                                pintaEsfera(*esfe7);
                            else
                                {
                                    setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                                    bar((*esfe7)->x1,(*esfe7)->y1,(*esfe7)->x1+78, (*esfe7)->y1+119.6);

                                }
                }
    else
        (*esfe7)->arr = NULL;





        if((*arbol)->arr)
                                {
                                    (*arbol)= (*arbol)->arr;
                                    pintaArbol((*arbol));
                                }
                                else
                                    (*arbol)->arr = NULL;

        if((*arbol2)->arr)
                                {
                                    (*arbol2)= (*arbol2) ->arr;
                                    pintaArbol((*arbol2));
                                }
                                else
                                    (*arbol2)->arr = NULL;

       if((*arbol3)->arr)
                                {
                                    (*arbol3)= (*arbol3) ->arr;
                                    pintaArbol((*arbol3));
                                }
                                else
                                    (*arbol3)->arr = NULL;

      if((*arbol4)->arr)
                                {
                                    (*arbol4)= (*arbol4) ->arr;
                                    pintaArbol((*arbol4));
                                }
                                else
                                    (*arbol4)->arr = NULL;

      if((*arbol5)->arr)
                                {
                                    (*arbol5)= (*arbol5) ->arr;
                                    pintaArbol((*arbol5));
                                }
                                else
                                    (*arbol5)->arr = NULL;

        if((*arbol6)->arr)
                                {
                                    (*arbol6)= (*arbol6) ->arr;
                                    pintaArbol((*arbol6));
                                }
                                else
                                    (*arbol6)->arr = NULL;

        if((*casa2)->arr)
                                {
                                    (*casa2)= (*casa2) ->arr;
                                    pintaCasa(*casa2);
                                }
                                else
                                    (*casa2)->arr = NULL;

        if((*casa3)->arr)
                                {
                                    (*casa3)= (*casa3) ->arr;
                                    pintaCasa(*casa3);
                                }
                                else
                                    (*casa3)->arr = NULL;


        if((*casa5)->arr)
                                {
                                    (*casa5)= (*casa5) ->arr;
                                    pintaCasa(*casa5);
                                }
                                else
                                    (*casa5)->arr = NULL;


        if((*casa6)->arr)
                                {
                                    (*casa6)= (*casa6) ->arr;
                                    pintaCasa(*casa6);
                                }
                                else
                                    (*casa6)->arr = NULL;


        if((*casa7)->arr)
                                {
                                    (*casa7)= (*casa7) ->arr;
                                    pintaCasa(*casa7);
                                }
                                else
                                    (*casa7)->arr = NULL;

        if((*casa8)->arr)
                                {
                                    (*casa8)= (*casa8) ->arr;
                                    pintaCasa(*casa8);
                                }
                                else
                                    (*casa8)->arr = NULL;

        if((*casa9)->arr)
                                {
                                    (*casa9)= (*casa9) ->arr;
                                    pintaCasa(*casa9);
                                }
                                else
                                    (*casa9)->arr = NULL;

        if((*casa10)->arr)
                                {
                                    (*casa10)= (*casa10) ->arr;
                                    pintaCasa(*casa10);
                                }
                                else
                                    (*casa10)->arr = NULL;

}

