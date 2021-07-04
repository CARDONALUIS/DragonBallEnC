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
 Objetivo:Me pinta el ecenario con sus respectivos colores
 Parametro de Entrada:Un auxiliar de tipo malla, y un contador de avanze de fondo
 Parametro de salida:
*/
void fondo(MALLA auxFon,int contFon)
{
    float arr[1380], xPr = 0.001, yPr = 0.001;
    int iren, icol;

    auxFon->archivo = fopen("fondo.dat","rb");

    while(!feof(auxFon->archivo))
    {
        fread(&arr,sizeof(float)*1380,1,auxFon->archivo);
        if(!feof(auxFon->archivo))

            for(iren = 0; iren<46; iren++)
            {
                for(icol = 0; icol < 7;icol++)
                {
                    if(arr[contFon] == -1)
                        {
                            contFon ++;
                            xPr += 78;
                        }
                    else
                        {
                            setfillstyle(SOLID_FILL, arr[contFon]);
                            bar(xPr, yPr, xPr +78, yPr +119.6);
                            xPr += 78;
                            contFon ++;
                        }

                }
                xPr = 0.00;
                yPr += 119.6;
            }
    }

    fclose(auxFon->archivo);
}


