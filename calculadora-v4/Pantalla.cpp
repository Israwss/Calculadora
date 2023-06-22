#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include "Pantalla.h"


 Pantalla::Pantalla(int izquierda, int arriba, int ancho, int altura, char captura[],int Alinear)
    {
  Izquierda = izquierda;
  Arriba = arriba;
  Ancho = ancho;
  Altura = altura;
  strcpy(Captura,captura);
  Alineamiento = Alinear;
    }


    void Pantalla::Dibujar()
   {
  setfillstyle(SOLID_FILL,WHITE);
  bar(Izquierda,Arriba,Izquierda+Ancho,Arriba+Altura);

  setcolor(DARKGRAY);
  rectangle(Izquierda,Arriba,Izquierda+Ancho,Arriba+Altura);

  setcolor(BLACK);

  settextjustify(Alineamiento,TOP_TEXT);
  if(Alineamiento==LEFT_TEXT)
   outtextxy(Izquierda+2,Arriba+1+((Altura/2)-(textheight(Captura)/2)),Captura);
  else
   if(Alineamiento==RIGHT_TEXT)
    outtextxy(Izquierda+Ancho-2,Arriba+1+((Altura/2)-(textheight(Captura)/2)),Captura);
  else
   outtextxy(Izquierda+(Ancho/2),Arriba+1+((Altura/2)-(textheight(Captura)/2)),Captura);


   }


 void Pantalla::SetTexto(char texto[])
 {
  if (Izquierda + textwidth(Captura) <= Izquierda + Ancho - textwidth(" "))
  {
   strcat(Captura,texto);
   Dibujar();
  }
 }

 char *Pantalla::GetTexto()
 {
  return Captura;
 }

 void Pantalla::Limpiar()
 {
  strcpy(Captura,"");
  Dibujar();
 }