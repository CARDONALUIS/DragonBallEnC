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

void fondo(MALLA auxFon,int contFon);
void moviPerPri(MALLA cab, char cad[], char cadNom[], JUG datos);
void menuPri(int *jugar, int *ayu, int *puntu);
void escoPer(char cad[]);
void ayuda(MALLA aux);
void pideNom(char cadNom[]);
void puntuacion(MALLA aux, char arr[100][30]);
void OrdenaNombres();




/*
 Objetivo:Comienza iniciando el modo grafico y me selecciona la funcion a realizar depende de la opcion del menu principal
 Parametro de Entrada:cabezera de malla
 Parametro de salida:
*/
void grafico(MALLA cab)
{
    int i,j, jugar,ayu, puntu;
    JUG datos;
    char cad[20], cadNom[30], arr[100][30];
    MALLA aux, auxCol;
    aux = cab;

    initwindow(800,717.6,"DRAGON BALL");

    menuPri(&jugar,&ayu, &puntu);


  if(ayu)
      ayuda(aux);

  if(puntu)
    puntuacion(aux, arr);



  if(jugar)
  {

   escoPer(cad);
   pideNom(cadNom);

    while(aux->sig)
    {
        aux = aux->sig;
    }

    while(aux->arr)
    {
        aux = aux->arr;
    }

    cab = aux;



   auxCol = aux;



    for(i = 0; i<REN; i++)
    {
        for(j=0; j<COL; j++)
        {
                if(j == COL-1)
                   {
                       setcolor(RGB(252, 252, 252));
                       rectangle(aux->x1, aux->y1, aux->x1+78, aux->y1+119.6);
                       auxCol = auxCol->aba;
                       aux = auxCol;
                   }
                   else
                   {
                       setcolor(RGB(252, 252, 252));
                       rectangle(aux->x1, aux->y1, aux->x1+78, aux->y1+119.6);
                       aux = aux->ant;
                   }
        }
    }

    aux = cab;
    fondo(aux,0);
    moviPerPri(aux, cad, cadNom, datos);

  }




}



/*
 Objetivo:Me crea el menu en la pantalla principal
 Parametro de Entrada:Recibo las diferentes opciones que el usuario pudiera elegir
 Parametro de salida:
*/
void menuPri(int *jugar, int *ayu, int *puntu)
{
  int res = 1,xM, yM;

  readimagefile("goku2.jpeg",0,0,800,717.6);

  settextstyle(10,0,1);
  setcolor(WHITE);
  outtextxy(10,10,"UNIVERSIDAD AUTONOMA DE SAN LUIS POTOSI");
  setcolor(WHITE);
  outtextxy(10,60,"AREA DE CIENCIAS DE LA COMPUTACION");
  setcolor(WHITE);
  outtextxy(10,110,"PROYECTO: JUEGO DRAGON BALL");
  setcolor(WHITE);
  outtextxy(10,160,"ESTRUCTURAS DE DATOS Y ALGORITMOS B");
  setcolor(WHITE);
  outtextxy(10,210,"LUIS EDUARDO CARDONA BECERRA");
  setcolor(WHITE);
  outtextxy(10,260,"PROF. MIGUEL ANGUEL DE LA CRUZ LOPEZ");


  setcolor(WHITE);
  outtextxy(60,310,"JUGAR");
  setcolor(WHITE);
  outtextxy(60,410,"PUNTUACIONES");
  setcolor(WHITE);
  outtextxy(60,510,"AYUDA");
  setcolor(WHITE);
  outtextxy(60,610,"SALIR");
  setcolor(BLACK);
  rectangle(50,300,200,350);
  rectangle(50,400,250,450);
  rectangle(50,500,200,550);
  rectangle(50,600,200,650);

  while(res == 1)
  {
      if(ismouseclick(WM_LBUTTONDOWN))
      {
         xM = mousex();
         yM = mousey();

         if(xM >50 && xM<200 && yM>300 &&yM<350)//JUGAR
         {
            *jugar = 1;
            res = 0;
            *ayu = 0;
            *puntu = 0;


         }

        if(xM >50 && xM<250 && yM>400 &&yM<450)//PUNTUACIONES
         {
            *jugar = 0;
            res = 0;
            *ayu = 0;
            *puntu = 1;


         }

         if(xM >50 && xM<200 && yM>500 &&yM<550)//AYUDA
         {
            *ayu = 1;
            res = 0;
            *jugar = 0;
            *puntu = 0;

         }

         if(xM >50 && xM<200 &&yM>600 &&yM<650)//SALIR
         {
            *jugar  = 0;
            res = 0;
            *ayu = 0;
            *puntu = 0;

         }
         clearmouseclick(WM_LBUTTONDOWN);
      }
  }



}


/*
 Objetivo:Selecciona el personaje al que el usuario eligio
 Parametro de Entrada:Arreglo que contendra el nombre del archivo a abrir
 Parametro de salida:El mismo arreglo de pero ahora con el nombre del archivo a abrir
*/
void escoPer(char cad[])
{
    readimagefile("goku2.jpeg",0,0,800,717.6);

    setcolor(WHITE);
    outtextxy(20,30,"ESCOGE PERSONAJE");
    readimagefile("goku1Ini.jpeg",50,100,150,250);
    readimagefile("frizaIni.jpeg",200,100,300,250);
    readimagefile("gokublueIni.jpeg",50,300,150,450);
    readimagefile("brolyIni.jpeg",200,300,300,450);
    readimagefile("gokuperfectIni.jpeg",50,500,150,650);
    readimagefile("jirenIni.jpeg", 200,500,300,650);

    int res = 1,xM, yM;

    while(res == 1)
  {
      if(ismouseclick(WM_LBUTTONDOWN))
      {
         xM = mousex();
         yM = mousey();

         if(xM >50 && xM<150 && yM>100 &&yM<250)
         {

            res = 0;
            strcpy(cad,"g");//goku


         }

         if(xM>200&&xM<300&&yM>100&&yM<250)
         {
             res = 0;
             strcpy(cad,"friza");


         }

         if(xM>50&&xM<150&&yM>300&&yM<450)
         {
             res = 0;
             strcpy(cad,"gokublue");

         }

         if(xM>200&&xM<300&&yM>300&&yM<450)
         {
             res = 0;
             strcpy(cad,"broly");

         }

         if(xM>50&&xM<150&&yM>500&&yM<650)
         {
             res = 0;
             strcpy(cad,"gokuperfect");
         }

         if(xM>200&&xM<300&&yM>500&&yM<650)
         {
             res = 0;
             strcpy(cad,"jiren");

         }


         clearmouseclick(WM_LBUTTONDOWN);
      }

  }
       strcat(cad,".dat");

}


/*
 Objetivo:Me crea la pantalla grafica del modo de ayuda
 Parametro de Entrada:auxiliar de tipo malla
 Parametro de salida:
*/
void ayuda(MALLA aux)
{
    readimagefile("goku2.jpeg",0,0,800,717.6);
    readimagefile("ayuda.jpeg",20,20,200,230);
    setcolor(WHITE);
    outtextxy(210,70,"Para mover tu personaje principal tendras");
    outtextxy(210,90,"que usar las flechas de direccion");
    outtextxy(210,110,"segun el movimiento que quieras realizar");
    outtextxy(210,130,"o bien con las teclas W(arriba),A(izquierda)");
    outtextxy(210,150,"S(abajo), D(derecha)");


    readimagefile("ayuda2.jpeg",20,240,200,450);
    setcolor(WHITE);
    outtextxy(210,290,"Tendras enemigos que te restaran 2 vidas");
    outtextxy(210,310,"cada que te toquen asi que trata de");
    outtextxy(210,330,"esquivarlos prediciendo sus movimientos");
    outtextxy(210,350,"podras recorrer el mapa hacia abajo cada que");
    outtextxy(210,370,"te valla moviendo hasia abajo");

    readimagefile("ayuda3.jpeg",20,460,200,670);
    setcolor(WHITE);
    outtextxy(210,510,"Tendras que reunir las 7 esferas del dragon");
    outtextxy(210,530,"habra esferas escondidas en las casas segun");
    outtextxy(210,550,"vallan apareciendo, asi que tendras que adivinar");
    outtextxy(210,570,"en cual de ellas estan, pero cuidado hay trampas");
    outtextxy(210,590,"en algunas de ellas que te restaran igual vidas");

    setcolor(BLACK);
    rectangle(650,617.6,790,667.6);
    setcolor(WHITE);
    outtextxy(660,632.6,"REGRESAR");

    int res = 1,xM, yM;

    while(res == 1)
  {
      if(ismouseclick(WM_LBUTTONDOWN))
      {
         xM = mousex();
         yM = mousey();

         if(xM > 650 &&xM <790 && yM>617.6 && yM<667.6)
            {
                res = 0;
                closegraph();
                grafico(aux);
            }



         clearmouseclick(WM_LBUTTONDOWN);
      }

  }

}


/*
 Objetivo:Obtener mediante el teclado el nombre del usuario
 Parametro de Entrada:Cadena con el nombre que sera del usuario
 Parametro de salida:Cadena del nombre ya introducido
*/
void pideNom(char cadNom[])
{
  int xc = 39, yc = 663, c = 1;
  char cad[30], cadFile[30],tecla = 0;

   setcolor(WHITE);
   outtextxy(xc,yc,"Dame el nombre de jugador: ");
   cad[0] = '\n';

   while(tecla != 13)
    {
        if(kbhit())
        {
            tecla = getch();
            cadFile[0]= tecla;

            cad[c] = cadFile[0];

            c++;
            cadFile[c] = '\0';

            outtextxy(xc+300,yc, cadFile);

                    if(tecla == 8)
                    {
                     setfillstyle(SOLID_FILL,BLACK);
                     bar(xc+290,yc,xc+310,yc+19);
                     xc -=13;
                    c = c-2;
                    }
                    else
                        xc += 12;

        }
    }
    cad[c] = '\0';

    int var;
    var= 0;

    strcpy(cadNom,cad);

}

/*
 Objetivo: Abre la pantalla grafica de la parte de las puntuaciones del los usuarios en orden de mayor puntaje
 Parametro de Entrada:auxiliar de tipo malla y un arreglo con las cadenas de los nombres de los usuarios
 Parametro de salida:
*/
void puntuacion(MALLA aux, char arr[100][30])
{

    readimagefile("goku2.jpeg",0,0,800,717.6);



        OrdenaNombres();

        setcolor(BLACK);
        rectangle(650,617.6,790,667.6);
        setcolor(WHITE);
        outtextxy(660,632.6,"REGRESAR");

        int res = 1,xM, yM;

    while(res == 1)
  {
      if(ismouseclick(WM_LBUTTONDOWN))
      {
         xM = mousex();
         yM = mousey();

         if(xM > 650 &&xM <790 && yM>617.6 && yM<667.6)
            {
                res = 0;

                closegraph();

                grafico(aux);
            }

         clearmouseclick(WM_LBUTTONDOWN);
      }

  }

}


/*
 Objetivo:Me ordena los datos del archivo contenedor de los datos de los usuarios
 Parametro de Entrada:
 Parametro de salida:
*/
void OrdenaNombres()
{
    FILE *flujo = fopen("score.txt", "rb");
    int i = 0, a, b, x = 20, y = 70;
    float comp;

    char arr[100][30], aux[30];

    char cadena2[10];
    char cadena[10];
    char cadFin[20];


  if(flujo !=  NULL)
    while(feof(flujo) == 0)
    {
        fscanf(flujo,"%s%s", cadena,cadena2);
        strcat(cadena2,"--------------");
        strcat(cadena2,cadena);
        strcpy(cadFin,cadena2);
        strcpy(arr[i],cadFin);
        i++;
    }


    for(a= 0; a<i; a++)
    {
        for(b=0;b<i-1; b++)
        {
            comp = strcmp(arr[b], arr[b+1]);
            if(comp<0)
            {
                strcpy(aux, arr[b]);
                strcpy(arr[b], arr[b+1]);
                strcpy(arr[b+1], aux);
            }
        }
    }



    setcolor(WHITE);
    outtextxy(20,20, "JUGADORES");
    setcolor(WHITE);
    outtextxy(20,45, "Esferas");
    outtextxy(130,45, "Nombre");
    setcolor(WHITE);


       for(a=0; a<i; a++)
        {
          setcolor(WHITE);
          outtextxy(x,y,arr[a]);
          y +=20;
        }
}

