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
 Objetivo:Se encarga de inicializar los diferentes objetos que apareceran en el juego para que de tal forma salgan en su lugar correspondiente
 Parametro de Entrada: auxiliares de tipo malla.
 Parametro de salida:
*/
void iniObjeto(MALLA *obj)
{
    *obj = NULL;
}

void colocaObjeCasa(MALLA esfe, MALLA *casa)
{
    *casa = esfe;
}

void colocaObjeCasa2(MALLA esfe, MALLA *casa2)
{
    *casa2 = esfe->arr->ant->ant->ant->ant->aba->aba->aba->ant->ant;
}

void colocaObjeCasa3(MALLA casa2, MALLA *casa3)
{
    *casa3 = casa2 ->aba->aba->aba->aba->aba;
}

void colocaObjeCasa4(MALLA esfe4, MALLA *casa4)
{
    *casa4 = esfe4;
}//aqui esta esfera

void colocaObjeCasa5(MALLA casa3, MALLA *casa5)
{
    *casa5 = casa3->sig->sig->sig->sig->sig->sig->aba->aba;
}


void colocaObjeCasa6(MALLA casa5, MALLA *casa6)
{
  *casa6 = casa5->aba->aba->aba;
}//aqui es trampa

void colocaObjeCasa7(MALLA casa6, MALLA *casa7)
{
    *casa7 = casa6->ant->ant->ant->ant->ant->ant;
}


void colocaObjeCasa8(MALLA esfe6, MALLA *casa8)
{
  *casa8 = esfe6;
}//aqui es esfera

void colocaObjeCasa9(MALLA casa7, MALLA *casa9)
{
    *casa9 = casa7->aba->aba->aba->sig->sig->sig->sig->sig->sig;
}//aqui es trampa

void colocaObjeCasa10(MALLA casa9, MALLA *casa10)
{
    *casa10 = casa9->aba->aba->aba->aba;
}

void colocaObjeMur(MALLA aux, MALLA *mur)
{
    *mur = aux->ant->ant->ant->ant->aba->aba;
}

void colocaObjeMur2(MALLA mur, MALLA *mur2)
{
    *mur2 = mur->ant->aba->sig->sig;
}

void colocaObjeMur3(MALLA mur2, MALLA *mur3)
{
    *mur3 = mur2->aba->aba->aba;
}

void colocaObjeMur4(MALLA mur3, MALLA *mur4)
{
    *mur4 = mur3->ant;
}


void colocaObjeMur5(MALLA mur4, MALLA *mur5)
{
    *mur5 = mur4->sig->sig->sig->aba;
}


void colocaObjeMur6(MALLA mur5, MALLA *mur6)
{
    *mur6 = mur5->sig;
}


void colocaObjeArbol(MALLA aux, MALLA *arbol)
{
    *arbol = aux->aba->aba->aba->aba;
}

void colocaObjeArbol2(MALLA arbol, MALLA *arbol2)
{
    *arbol2 = arbol->ant->ant->ant->ant->ant->ant
    ->aba->aba->aba->aba->aba->aba->aba->aba;
}

void colocaObjeArbol3(MALLA arbol2, MALLA *arbol3)
{
    *arbol3 = arbol2->aba->aba->aba->aba->aba->aba;
}

void colocaObjeArbol4(MALLA arbol3, MALLA *arbol4)
{
    *arbol4 = arbol3->sig->sig->sig->sig->sig->sig
    ->aba->aba->aba->aba->aba->aba->aba->aba;
}

void colocaObjeArbol5(MALLA arbol4, MALLA *arbol5)
{
    *arbol5 = arbol4->aba->aba->aba->aba;
}

void colocaObjeArbol6(MALLA arbol5, MALLA *arbol6)
{
    *arbol6 = arbol5->ant->ant->ant->ant->ant->ant
    ->aba->aba->aba->aba->aba->aba->aba->aba->aba->aba->aba;
}






void colocaObjeEsf1(MALLA aux, MALLA *esfe)
{
        *esfe = aux->aba->aba->aba;

}

void colocaObjeEsf2(MALLA aux, MALLA *esfe2)
{
        *esfe2 = aux->aba->aba->aba->aba->aba
    ->aba->aba->aba->aba->ant->ant->ant
    ->ant->ant->ant;

}

void colocaObjeEsf3(MALLA esfe2, MALLA *esfe3)
{
        *esfe3 = esfe2->aba->aba->aba->aba
    ->sig->sig->sig->sig->sig->sig->aba;

}


void colocaObjeEsf4(MALLA esfe3, MALLA *esfe4)
{
        *esfe4 = esfe3->aba->aba->aba->aba->aba
    ->ant->ant->ant->ant->ant->ant->aba->aba->aba;
}


void colocaObjeEsf5(MALLA esfe4, MALLA *esfe5)
{
        *esfe5 = esfe4->aba->aba->aba->aba->aba->aba
    ->sig->sig->sig->sig->sig->sig;
}


void colocaObjeEsf6(MALLA esfe5, MALLA *esfe6)
{
        *esfe6 = esfe5->aba->aba->aba->aba->aba
    ->ant->ant->ant->ant->ant->ant;
}

void colocaObjeEsf7(MALLA esfe6, MALLA *esfe7)
{
        *esfe7 = esfe6->aba->aba->aba->aba->aba->aba;
}
