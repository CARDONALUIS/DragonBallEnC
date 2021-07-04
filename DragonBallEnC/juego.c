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
  int info;
  //FILE *archivo;
  struct nodo *sig;
  struct nodo *ant;
  struct nodo *arr;
  struct nodo *aba;
}*MALLA;

void inilista(MALLA *cab);
int creaMalla(MALLA *cab,int dato, float coox, float cooy);
void eliminaMalla(MALLA *cab);
void grafico(MALLA cab);

int main()
{
    MALLA m_cab;
    int m_dato;
    float m_coox = 0, m_cooy = 0;
    m_dato = 0;


    inilista(&m_cab);


    creaMalla(&m_cab,m_dato, m_coox, m_cooy);
    grafico(m_cab);
    eliminaMalla(&m_cab);

}


/*
 Objetivo:inicializar la malla
 Parametro de Entrada: Malla
 Parametro de salida:-
*/
void inilista(MALLA *cab)
{
    *cab = NULL;
}

/*
 Objetivo:crear un bloque que poseera informacion junto con cuatro enlaces inicializados
 Parametro de Entrada:Recibo la cab, un dato, y coordenadas
 Parametro de salida:Regresa un entero para confirmar crecion del bloque
*/
int creaNodo(MALLA *cab,int dato, float coox, float cooy)
{
  int res;

  *cab = (MALLA)malloc(sizeof(struct nodo));
  if(*cab != NULL)
  {
      res = 1;
      (*cab)->info = dato;
      (*cab)->aba = NULL;
      (*cab)->arr = NULL;
      (*cab)->sig = NULL;
      (*cab)->ant = NULL;
      (*cab)->x1 = coox;
      (*cab)->y1 = cooy;
  }
  return(res);
}

/*
 Objetivo: Crear la malla osea los enlaces de todos los nodos
 Parametro de Entrada: La cabezera con el enlace a los nodos de la malla,  junto con la informacion que contendra cada nodo
 Parametro de salida: Regresara  un entero de confirmacion de creacion
*/
int creaMalla(MALLA *cab, int dato, float coox, float cooy)
{
    int res, nRen, nCol, i = 1;
    float cx = 0.001, cy = 0.001;
    MALLA aux, antAux , nuevo;



    for(nRen=0 ; nRen< REN; nRen++)
    {
        for(nCol = 0; nCol < COL; nCol++)
        {
            dato = i;
            coox = cx;
            cooy = cy;



            res = creaNodo(&nuevo, 0, coox, cooy);
             if(res != 0)
             {
                 res = 1;
                if(nRen == 0)
                   {
                    if(nCol == 0)
                    {
                      nuevo->sig = *cab;

                        antAux = nuevo;
                        aux = nuevo;

                       *cab = nuevo;
                     }
                     else
                      {
                        nuevo->sig = *cab;
                        (*cab)->ant = nuevo;

                        *cab = nuevo;
                      }
                    }
                    else
                      {
                       if(nCol == 0)
                         {
                          nuevo->arr = antAux;
                          antAux->aba = nuevo;

                          antAux = antAux->ant;
                          *cab = nuevo;
                         }
                        else
                         {
                          (*cab)->ant = nuevo;
                          nuevo->sig = *cab;

                          nuevo->arr = antAux;
                          antAux->aba = nuevo;


                          *cab = nuevo;
                            if(antAux->ant == NULL)
                            {
                                aux = aux->aba;
                                antAux = aux;
                            }
                            else
                             antAux = antAux->ant;
                          }
                        }

             }

             i++;
             cx += 78;

        }
        cy += 119.6;
        cx = 0.001;

     }
    return(res);


}

/*
 Objetivo:Borrar todos los bloques de la malla
 Parametro de Entrada:cabezera de malla
 Parametro de salida:
*/
void eliminaMalla(MALLA *cab)
{
    int nRen, nCol;
    MALLA aux, auxCol, auxEli;


    if(*cab)
    {
    aux = *cab;
    auxCol = aux;


    for(nRen =  0; nRen < REN; nRen++)
    {
        for(nCol = 0;nCol < COL ; nCol++)
        {
                   if(nCol == COL-1)
                   {
                       auxEli = aux;
                       auxCol = auxCol->arr;
                       aux = auxCol;


                   }
                   else
                   {
                       auxEli = aux;
                       aux = aux->sig;
                   }

            free(auxEli);

        }

    }
    }


}




