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

typedef struct
{
    char nom[25];
    int numEsfe;
}JUG;


void grafico(MALLA cab);
void fondo(MALLA auxFon,int contFon);
void pintaPer(MALLA aux, char cad[]);
void pintaPerEne(MALLA mur);
void moviMur(MALLA murMo);
void pintaEsfera(MALLA esfeFun);
void pintaCasa(MALLA casa);


void rellena(MALLA aux, float arr[1380]);
void pintaTrans(MALLA aux, float arr[1380]);

void rellenaEne(MALLA aux, float arrEne[1380]);
void pintaTransEne(MALLA aux, float arrEne[1380]);



void colocaObjeMur(MALLA aux, MALLA *mur);//Coloca el murcielago
void colocaObjeMur2(MALLA mur, MALLA *mur2);

void colocaObjeCasa(MALLA esfe, MALLA *casa);//aqui esta esfera
void colocaObjeCasa2(MALLA esfe, MALLA *casa2);//aqui es trampa
void colocaObjeCasa3(MALLA casa2, MALLA *casa3);
void colocaObjeCasa4(MALLA esfe4, MALLA *casa4);//aqui esta esfera
void colocaObjeCasa5(MALLA casa3, MALLA *casa5);
void colocaObjeCasa6(MALLA casa5, MALLA *casa6);//aqui es trampa
void colocaObjeCasa7(MALLA casa6, MALLA *casa7);
void colocaObjeCasa8(MALLA esfe6, MALLA *casa8);//aqui es esfera
void colocaObjeCasa9(MALLA casa7, MALLA *casa9);//aqui es trampa
void colocaObjeCasa10(MALLA casa9, MALLA *casa10);



void colocaObjeEsf1(MALLA aux, MALLA *esfe);
void colocaObjeEsf2(MALLA aux, MALLA *esfe2);
void colocaObjeEsf3(MALLA esfe2, MALLA *esfe3);
void colocaObjeEsf4(MALLA esfe3, MALLA *esfe4);
void colocaObjeEsf5(MALLA esfe4, MALLA *esfe5);
void colocaObjeEsf6(MALLA esfe5, MALLA *esfe6);
void colocaObjeEsf7(MALLA esfe6, MALLA *esfe7);

void colocaObjeArbol(MALLA aux, MALLA *arbol);
void colocaObjeArbol2(MALLA arbol, MALLA *arbol2);
void colocaObjeArbol3(MALLA arbol2, MALLA *arbol3);
void colocaObjeArbol4(MALLA arbol3, MALLA *arbol4);
void colocaObjeArbol5(MALLA arbol4, MALLA *arbol5);
void colocaObjeArbol6(MALLA arbol5, MALLA *arbol6);
void colocaObjeArbol7(MALLA arbol6, MALLA *arbol7);

void regisEsfe(int acumEsf, char cadNom[], JUG datos);


void compInter(int *bandTer, MALLA aux, MALLA esfe, int *bE1, MALLA esfe2, int *bE2, MALLA esfe3, int *bE3, MALLA esfe4, int *bE4, MALLA esfe5, int *bE5, MALLA esfe6, int *bE6, MALLA esfe7, int *bE7, MALLA casa2, MALLA mur, MALLA mur2,int *vid, int *totEsf);

void hazMovi(MALLA *esfe, MALLA *casa, MALLA *casa2, MALLA *casa3, MALLA *casa4, MALLA *casa5, MALLA *casa6, MALLA *casa7, MALLA *casa8, MALLA *casa9, MALLA *casa10, int *bE1, MALLA *esfe2, int *bE2, MALLA *esfe3, int *bE3, MALLA *esfe4, int *bE4, MALLA *esfe5, int *bE5, MALLA *esfe6, int *bE6, MALLA *esfe7, int *bE7, MALLA *arbol, MALLA *arbol2, MALLA *arbol3, MALLA *arbol4, MALLA *arbol5, MALLA *arbol6);

void pintaArbol(MALLA arbol);


/*
 Objetivo: Esta funcion hase el movimiento del personaje principal junto con todas las interacciones que tiene el con el contorno y sus respectivos movimientos que dependen de el
 Parametro de Entrada:cabezera de tipo malla, el nombre del arhcivo del personaje principal, el nombre del usuario y una estructura jugador
 Parametro de salida:
*/

void moviPerPri(MALLA cab, char cad[], char cadNom[], JUG datos)
{
    time_t t1, t2;
    float arr[1380], lim = 717.6, arrEne[1380], arrEne2[1380];
    int  contFon = 0, contObj = 0, bE2 = 0,
    bE3 = 0, bE4 = 0, bE5 = 0, bE6 = 0,
    bE7 = 0, bE1 = 0, contAvan = 0, conMur = 1;
    char tecla = 0, numVid[5];
    int band = 0, borra = 0, totEsf = 0;
    int vid = 8, bandTer;



    bandTer = 0;

    t1 = clock();

    MALLA aux, casa, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9, casa10 , mur, mur2, arbol, arbol2, arbol3, arbol4, arbol5, arbol6, esfe, esfe2, esfe3, esfe4, esfe5, esfe6, esfe7;

    outtextxy(600,500,"VIDAS");
    sprintf(numVid,"%d",vid);
    outtextxy(600,540,numVid);


    aux = cab;

    colocaObjeMur(aux, &mur);
    colocaObjeMur2(mur, &mur2);

    colocaObjeEsf1(aux, &esfe);
    colocaObjeEsf2(aux, &esfe2);
    colocaObjeEsf3(esfe2, &esfe3);
    colocaObjeEsf4(esfe3, &esfe4);
    colocaObjeEsf5(esfe4, &esfe5);
    colocaObjeEsf6(esfe5, &esfe6);
    colocaObjeEsf7(esfe6, &esfe7);

    colocaObjeArbol(aux, &arbol);
    colocaObjeArbol2(arbol, &arbol2);
    colocaObjeArbol3(arbol2, &arbol3);
    colocaObjeArbol4(arbol3, &arbol4);
    colocaObjeArbol5(arbol4, &arbol5);
    colocaObjeArbol6(arbol5, &arbol6);

    colocaObjeCasa(esfe,&casa);
    colocaObjeCasa2(esfe,&casa2);
    colocaObjeCasa3(casa2,&casa3);
    colocaObjeCasa4(esfe4,&casa4);
    colocaObjeCasa5(casa4,&casa5);
    colocaObjeCasa6(casa5,&casa6);
    colocaObjeCasa7(casa6,&casa7);
    colocaObjeCasa8(esfe6,&casa8);
    colocaObjeCasa9(casa8,&casa9);
    colocaObjeCasa10(casa9,&casa10);



    outtextxy(545,100,"Haz tomado la esfera No. ");
    pintaEsfera(esfe);
    pintaCasa(casa);
    pintaCasa(casa2);


    pintaArbol(arbol);
    pintaArbol(arbol2);
    pintaArbol(arbol3);
    pintaArbol(arbol4);
    pintaArbol(arbol5);
    pintaArbol(arbol6);


    pintaEsfera(esfe2);
    pintaEsfera(esfe3);
    pintaEsfera(esfe4);
    pintaEsfera(esfe5);
    pintaEsfera(esfe6);
    pintaEsfera(esfe7);

    pintaTrans(aux, arr);
    pintaPer(aux, cad);

    pintaTransEne(mur,arrEne);
    pintaPerEne(mur);
    pintaTransEne(mur2,arrEne2);
    pintaPerEne(mur2);



   while(tecla != 27 && bandTer == 0)
   {


       if(kbhit())
       {

           tecla = getch();
           rellena(aux, arr);
           rellenaEne(mur,arrEne);
           rellenaEne(mur2,arrEne2);


           switch(tecla)
            {
                case 87:
                case 119:
                case 72:
                    if(aux->arr )
                     aux = aux->arr;
                break;

                case 83:
                case 115:
                case 80:
                    if(aux->aba)
                    {
                      aux = aux->aba;

                      if(aux->aba->y1 > lim )
                      {

                          contAvan = 1;


                          if(contAvan == 1)
                          {

                             aux = aux->arr;
                          }

                          if(contFon < 276)
                          {
                             contObj ++;
                             contFon += 7;
                             fondo(aux, contFon);

                             hazMovi(&esfe,&casa,&casa2,&casa3,&casa4,&casa5,&casa6,&casa7,&casa8,&casa9,&casa10, &bE1, &esfe2, &bE2, &esfe3, &bE3, &esfe4, &bE4, &esfe5, &bE5, &esfe6, &bE6, &esfe7, &bE7, &arbol, &arbol2, &arbol3, &arbol4, &arbol5, &arbol6);

                          }
                          else
                          {

                             outtextxy(200,200,"GRACIAS POR JUGAR");

                             regisEsfe(totEsf, cadNom, datos);

                             delay(1000);
                             tecla = 27;
                             closegraph();
                             grafico(aux);

                             setfillstyle(SOLID_FILL, BLACK);
                             bar(547,0,800,717.6);
                          }
                      }
                    }
                break;

                case 65:
                case 97:
                case 75:
                       if(aux->sig)
                        aux = aux->sig;
                break;

                case 68:
                case 100:
                case 77:
                     if(aux->ant)
                        aux = aux->ant;
                break;



            }
            pintaTransEne(mur,arrEne);
            pintaTransEne(mur2,arrEne2);

            compInter(&bandTer, aux, esfe, &bE1, esfe2, &bE2, esfe3, &bE3, esfe4, &bE4, esfe5, &bE5, esfe6, &bE6, esfe7, &bE7, casa2, mur, mur2, &vid, &totEsf);

            if(bandTer == 1)
            {
                outtextxy(200,200,"HAS MUERTO");
                delay(1500);
                closegraph();
                grafico(aux);
            }

            pintaTrans(aux, arr);
            pintaPer(aux,cad);




       }



       t2 = clock();
       if(t2 - t1 >= 100)
       {
           if(borra == 0)
           {
             if(aux!=mur || aux !=mur)
             rellenaEne(mur,arrEne);
             rellenaEne(mur2,arrEne2);

            borra = 1;
           }
           else
              if(band == 0)
              {
               moviMur(mur);//Murcielago alas abajo
               moviMur(mur2);
               borra = 0;
               band=1;
              }
              else
               {
                pintaPerEne(mur);//Murcielago alas arriba
                pintaPerEne(mur2);
                pintaPer(aux,cad);
                borra=0;
                band=0;



                if(conMur  < 5 )//Esta hace movimiento horizontal
                        {
                          rellenaEne(mur,arrEne);
                          mur = mur->sig;
                          pintaTransEne(mur,arrEne);


                         }
                         else
                         {
                             if(conMur < 12)
                             {

                                 if(conMur == 11)
                                 {

                                 conMur=-1;
                                 rellena(mur,arrEne);
                                 mur = mur->sig->sig;
                                 pintaTransEne(mur,arrEne);

                                 }
                                 rellenaEne(mur,arrEne);
                                 mur = mur->ant;
                                 pintaTransEne(mur,arrEne);
                             }
                         }
                    conMur++;

                    if(mur2->aba->y1 < lim)
                    {
                        rellenaEne(mur2,arrEne2);
                          mur2 = mur2->aba;
                          pintaTransEne(mur2,arrEne2);


                    }
                    else
                    {
                        while(mur2->arr)
                        {
                          rellenaEne(mur2,arrEne2);
                          mur2 = mur2->arr;
                          pintaTransEne(mur2,arrEne2);
                        }

                    }
               }
           t1 = t2;

       }
   }
}

/*
 Objetivo: Le agrega al archivo con su corresponidente usuario el numero de esferas acumuladas
 Parametro de Entrada:acumulador de esferas, la cadena del nombre del usuario
 Parametro de salida:
*/
void regisEsfe(int acumEsf, char cadNom[], JUG datos)
{
    FILE *fp;

    strcpy(datos.nom,cadNom);

    datos.numEsfe = acumEsf;

 	fp = fopen ( "score.txt", "at" );

 	if(fp == NULL)
        printf("Error al abrir el archivo");


 	fwrite(datos.nom,1,strlen(datos.nom),fp);
    fprintf(fp,"%d",datos.numEsfe);


 	fclose ( fp );
 	printf("\n");



}


