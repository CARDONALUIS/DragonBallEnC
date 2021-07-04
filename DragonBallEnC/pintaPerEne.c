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

void moviMur(MALLA aux);
void pintaExplo(MALLA explo);


/*
 Objetivo: Pinta a los murcielagos que son los enemigos del juego
 Parametro de Entrada:Auxiliar de tipo malla que contiene un apuntador a un archivo
 Parametro de salida:
*/
void pintaPerEne(MALLA aux)
{
    float arr[1380], xPr , yPr ;
    int cont = 0, iren, icol;
    xPr = aux->x1;
    yPr = aux->y1;


    aux->archivo = fopen("mursielago.dat","rb");

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

/*
 Objetivo: Pinta al personaje enemigo (mursielago) pero con las alas hacia arriba para dar un efecto de movimiento
 Parametro de Entrada:Auxiliar de tipo malla que contiene un apuntador a un archivo
 Parametro de salida:
*/
void moviMur(MALLA aux)
{
   float arr[1380], xPr , yPr ;
    int cont = 0, iren, icol;
    xPr = aux->x1;
    yPr = aux->y1;


    aux->archivo = fopen("mursielagovolando.dat","rb");

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

/*
 Objetivo: Pinta una explocion para cuando intersecta con el personaje principal
 Parametro de Entrada:Auxilir de tipo malla que contiene un apuntador a un archivo
 Parametro de salida:
*/
void pintaExplo(MALLA explo)
{
   float arr[1380], xPr , yPr ;
    int cont = 0, iren, icol;
    xPr = explo->x1;
    yPr = explo->y1;


    explo->archivo = fopen("explosion.dat","rb");

    while(!feof(explo->archivo))
        {
            fread(&arr,sizeof(float)*1380,1,explo->archivo);
            if(!feof(explo->archivo))

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
                    xPr = explo->x1;
                    yPr += 2.6;
                }



        }

        fclose(explo->archivo);
}
