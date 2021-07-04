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

void pintaFonEsfe(MALLA auxEsfe);
void pintaCasa(MALLA casa);
void pintaArbol(MALLA arbol);


/*
 Objetivo: Inicializa los esferas de tipo malla y manda llamar a otra funcion
 Parametro de Entrada:Auxilir de tipo malla que contiene un apuntador a un archivo
 Parametro de salida:
*/
void pintaEsfera(MALLA auxEsfe)
{
   MALLA esfe2, esfe3,esfe4,esfe5,esfe6,esfe7;
   esfe2 = esfe3 = esfe4 = esfe5 = esfe6 = esfe7 = auxEsfe;


       pintaFonEsfe(auxEsfe);


}

/*
 Objetivo: Pintar las esferas dentro del juego
 Parametro de Entrada:AuxilirEsfe de tipo malla que contiene un apuntador a un archivo
 Parametro de salida:
*/
void pintaFonEsfe(MALLA auxEsfe)
{
    float arr[1380], xPr , yPr;
    int cont = 0, iren, icol;

    xPr = auxEsfe->x1;
    yPr = auxEsfe->y1;




    auxEsfe->archivo = fopen("esfera.dat","rb");

    while(!feof(auxEsfe->archivo))
    {
        fread(&arr,sizeof(float)*1380,1,auxEsfe->archivo);
        if(!feof(auxEsfe->archivo))

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
                xPr = auxEsfe->x1;
                yPr += 2.6;
            }



    }

    fclose(auxEsfe->archivo);
}

/*
 Objetivo: Pinta las casas que estan dentro del juego
 Parametro de Entrada:casa de tipo malla que contiene un apuntador a un archivo
 Parametro de salida:
*/
void pintaCasa(MALLA casa)
{
    float arr[1380], xPr , yPr;
    int cont = 0, iren, icol;

    xPr = casa->x1;
    yPr = casa->y1;




    casa->archivo = fopen("casa1.dat","rb");

    while(!feof(casa->archivo))
    {
        fread(&arr,sizeof(float)*1380,1,casa->archivo);
        if(!feof(casa->archivo))

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
                xPr = casa->x1;
                yPr += 2.6;
            }



    }

    fclose(casa->archivo);
}


/*
 Objetivo: Pintar los arboles que estan contenidos en el juego
 Parametro de Entrada:arbol de tipo malla que contiene un apuntador a un archivo
 Parametro de salida:
*/
void pintaArbol(MALLA arbol)
{
    float arr[1380], xPr , yPr;
    int cont = 0, iren, icol;

    xPr = arbol->x1;
    yPr = arbol->y1;




    arbol->archivo = fopen("arbol.dat","rb");

    while(!feof(arbol->archivo))
    {
        fread(&arr,sizeof(float)*1380,1,arbol->archivo);
        if(!feof(arbol->archivo))

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
                xPr = arbol->x1;
                yPr += 2.6;
            }



    }

    fclose(arbol->archivo);
}

