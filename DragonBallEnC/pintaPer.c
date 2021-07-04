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
 Objetivo:Me pinta el personaje principal en base a un archivo del campo File de la estructura malla
 Parametro de Entrada: auxiliar de tipo malla, y la cadena contenedora del nombre del archivo del personaje elegido
 Parametro de salida:
*/
void pintaPer(MALLA aux,char cad[])
{
    float arr[1380], xPr , yPr ;
    int cont = 0, iren, icol;

    xPr = aux->x1;
    yPr = aux->y1;



    aux->archivo = fopen(cad,"rb");

    while(!feof(aux->archivo))
    {
        fread(&arr,sizeof(float)*1380,1,aux->archivo);
        if(!feof(aux->archivo))

            for(iren = 0; iren<46; iren++)
            {
                for(icol = 0; icol < 30;icol++)
                {
                    if(arr[cont] == -1)
                        {
                            cont ++;
                            xPr += 2.6;
                        }
                    else
                        {
                            setfillstyle(SOLID_FILL, arr[cont]);
                            bar(xPr, yPr, xPr +2.6, yPr +2.6);
                            xPr += 2.6;
                            cont ++;
                        }
                }
                xPr = aux->x1;
                yPr += 2.6;
            }

    }

    fclose(aux->archivo);
}


