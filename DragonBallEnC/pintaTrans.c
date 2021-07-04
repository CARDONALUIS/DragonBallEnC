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


/*
 Objetivo: Esta funcion se encarga de obtener los pixele del lugar al que se va mover el personaje principal
 Parametro de Entrada:Auxiliar de tipo malla, el arreglo de qu contendra los colores de los pixeles
 Parametro de salida:
*/
void pintaTrans(MALLA aux,float arr[1380])//Obtiene los pixeles
{
    float xPr = aux->x1 , yPr = aux->y1;
    int iren, jcol, cont = 0 ;


   for(iren = 0;iren<46;iren++)
   {
       for(jcol = 0;jcol<30;jcol++)
       {
         arr[cont] = getpixel(xPr + 1.3, yPr+1.3);
         xPr += 2.6;

         cont ++;
       }

       xPr = aux->x1;
       yPr += 2.6;
   }

}


/*
 Objetivo: Esta funcion rellena de los pixeles previamente guardados para que al momento de moverse el personaje principal vuleva al estado de pixeles que en el que estaba
 Parametro de Entrada: auxiliar de tipo malla, junto con el arreglo que contiene los colores de los pixeles.
 Parametro de salida:
*/
void rellena(MALLA aux, float arr[1380])//pinta los pixeles
{
    float xPr = aux->x1 , yPr = aux->y1;
    int iren, jcol, cont = 0 ;

    for(iren = 0;iren<46;iren++)
    {
       for(jcol = 0;jcol<30;jcol++)
       {
           if(arr[cont] == -1)
           {
                cont ++;
                xPr += 2.6;
           }
           else
           {
               setfillstyle(SOLID_FILL, arr[cont]);
               bar(xPr,yPr,xPr+2.6,yPr+2.6);
               xPr += 2.6;
               cont ++;
           }

       }
       xPr = aux->x1;
       yPr += 2.6;
    }


}


/*
 Objetivo: Esta funcion se encarga de obtener los pixele del lugar al que se va mover el personaje enemigo
 Parametro de Entrada:Auxiliar de tipo malla, el arreglo de qu contendra los colores de los pixeles
 Parametro de salida:
*/
void pintaTransEne(MALLA aux,float arr[1380])//Obtiene los pixeles
{
    float xPr = aux->x1 , yPr = aux->y1;
    int iren, jcol, cont = 0 ;


   for(iren = 0;iren<46;iren++)
   {
       for(jcol = 0;jcol<30;jcol++)
       {
         arr[cont] = getpixel(xPr + 1.3, yPr+1.3);
         xPr += 2.6;
         cont ++;
       }
       xPr = aux->x1;
       yPr += 2.6;
   }

}


/*
 Objetivo: Esta funcion rellena de los pixeles previamente guardados para que al momento de moverse el personaje enemigo vuleva al estado de pixeles que en el que estaba
 Parametro de Entrada: auxiliar de tipo malla, junto con el arreglo que contiene los colores de los pixeles.
 Parametro de salida:
*/
void rellenaEne(MALLA aux, float arr[1380])//pinta los pixeles
{
    float xPr = aux->x1 , yPr = aux->y1;
    int iren, jcol, cont = 0 ;

    for(iren = 0;iren<46;iren++)
    {
       for(jcol = 0;jcol<30;jcol++)
       {
           if(arr[cont] == -1)
           {
                cont ++;
                xPr += 2.6;
           }
           else
           {
               setfillstyle(SOLID_FILL, arr[cont]);
               bar(xPr,yPr,xPr+2.6,yPr+2.6);
               xPr += 2.6;
               cont ++;
           }

       }
       xPr = aux->x1;
       yPr += 2.6;
    }


}


