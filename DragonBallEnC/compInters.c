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
void pintaExplo(MALLA explo);

/*
 Objetivo: Esta funcion de encarga de comprobar si hubo interseccion entre el personaje principal y los demas objetos
 Parametro de Entrada: bandera para saber si acaban sus vidas, auxiliares de los objetos, y banderas de recoleccion de esferas
 Parametro de salida:
*/
void compInter(int *bandTer ,MALLA aux, MALLA esfe, int *bE1,MALLA esfe2, int *bE2, MALLA esfe3, int *bE3, MALLA esfe4, int *bE4, MALLA esfe5, int *bE5, MALLA esfe6, int *bE6, MALLA esfe7, int *bE7, MALLA casa2, MALLA mur, MALLA mur2, int *vid,int *totEsf)
{
    char numVid[5];




       if(aux == esfe)
                {
                    if(*bE1 == 0)
                    pintaEsfera(esfe);
                    outtextxy(650,150,"1");
                    (*bE1)++;
                    if(*bE1 == 1)
                        (*totEsf)++;

                }
        if(aux == esfe2)
                {
                    setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                    bar(esfe2->x1,esfe2->y1,esfe2->x1+78, esfe2->y1+119.6);
                    outtextxy(650,170,"2");
                    (*bE2)++;
                    if(*bE2 == 1)
                        (*totEsf)++;
                }

        if(aux == esfe3)
                {
                    setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                    bar(esfe3->x1,esfe3->y1,esfe3->x1+78, esfe3->y1+119.6);
                    outtextxy(650,190,"3");
                    (*bE3)++;
                    if(*bE3 == 1)
                        (*totEsf)++;
                }
            if(aux == esfe4)
                {
                    setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                    bar(esfe4->x1,esfe4->y1,esfe4->x1+78, esfe4->y1+119.6);
                    outtextxy(650,210,"4");
                    (*bE4)++;
                    if(*bE4 == 1)
                    (*totEsf) ++;
                }
            if(aux == esfe5)
                {
                    setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                    bar(esfe5->x1,esfe5->y1,esfe5->x1+78, esfe5->y1+119.6);
                    outtextxy(650,230,"5");
                    (*bE5)++;
                    if(*bE5 == 1)
                      (*totEsf) ++;
                }
            if(aux == esfe6)
                {
                    setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                    bar(esfe6->x1,esfe6->y1,esfe6->x1+78, esfe6->y1+119.6);
                    outtextxy(650,250,"6");
                    (*bE6)++;
                    if(*bE6 == 1)
                    (*totEsf) ++;
                }
            if(aux == esfe7)
                {
                    setfillstyle(SOLID_FILL,COLOR(175, 88, 11 ));//COLOR(175, 88, 11 )
                    bar(esfe7->x1,esfe7->y1,esfe7->x1+78, esfe7->y1+119.6);
                    outtextxy(650,270,"7");
                    (*bE7)++;
                    if(*bE7 == 1)
                     (*totEsf) ++;
                }

            if(aux == casa2)
            {

                outtextxy(600,570,"TRAMPA -1 VIDA");
                pintaExplo(casa2);
                (*vid) --;
                sprintf(numVid,"%d",*vid);
                outtextxy(600,540,numVid);
                delay(500);
                setfillstyle(SOLID_FILL,BLACK);
                bar(600,570,785,590);
            }

            if(aux == mur || mur2 == aux)
            {
                 outtextxy(600,570,"PELIGRO -1 VIDA");
                (*vid) --;
                sprintf(numVid,"%d",*vid);
                outtextxy(600,540,numVid);
                delay(500);
                setfillstyle(SOLID_FILL,BLACK);
                bar(600,570,785,590);
            }

            if(mur->ant)
            if(mur->ant==aux)
            {
                 outtextxy(600,570,"PELIGRO -1 VIDA");
                (*vid) --;
                sprintf(numVid,"%d",*vid);
                outtextxy(600,540,numVid);
                delay(500);
                setfillstyle(SOLID_FILL,BLACK);
                bar(600,570,785,590);
            }

            if(mur->sig)
            if(mur->sig == aux)
            {
                 outtextxy(600,570,"PELIGRO -1 VIDA");
                (*vid) --;
                sprintf(numVid,"%d",*vid);
                outtextxy(600,540,numVid);
                delay(500);
                setfillstyle(SOLID_FILL,BLACK);
                bar(600,570,785,590);
            }

         if(*vid == 0)
             *bandTer = 1;





}



