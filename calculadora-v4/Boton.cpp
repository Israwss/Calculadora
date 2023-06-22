#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include "Mouse.h"
#include "Boton.h"

Boton::Boton(int izquierda, int arriba, int ancho, int altura, char captura[], int Id)
    {
  Izquierda = izquierda;
  Arriba = arriba;
  Ancho = ancho;
  Altura = altura;
  strcpy(Captura,captura);
  ID = Id;
  btnStatus = ESTATUS_BOTON_NORMAL;
  Estado = false;
    }
    
    
   void Boton::Dibujar()
   {
  setfillstyle(SOLID_FILL,LIGHTGRAY);
  bar(Izquierda,Arriba,Izquierda+Ancho,Arriba+Altura);

  setcolor(WHITE);
  line(Izquierda,Arriba,Izquierda+Ancho,Arriba);
  line(Izquierda,Arriba,Izquierda,Arriba+Altura);

  setcolor(BLACK);
  line(Izquierda+Ancho,Arriba,Izquierda+Ancho,Arriba+Altura);
  line(Izquierda,Arriba+Altura,Izquierda+Ancho,Arriba+Altura);

  settextjustify(LEFT_TEXT,TOP_TEXT);
  setcolor(BLACK);
  outtextxy(Izquierda + (Ancho/2) - textwidth(Captura)/2 + 1,
  Arriba + (Altura/2) - textheight(Captura)/2 + 1, Captura);

   }
   
   void Boton::MouseAbajo()
   {


    mouse.OcultarMouse();

    setcolor(BLACK);
    line(Izquierda,Arriba,Izquierda+Ancho,Arriba);
    line(Izquierda,Arriba,Izquierda,Arriba+Altura);

    setcolor(WHITE);
    line(Izquierda+Ancho,Arriba,Izquierda+Ancho,Arriba+Altura);
    line(Izquierda,Arriba+Altura,Izquierda+Ancho,Arriba+Altura);

    mouse.MostrarMouse();

   }
   
   void Boton::MouseArriba()
   {



     mouse.OcultarMouse();

     setcolor(WHITE);
     line(Izquierda,Arriba,Izquierda+Ancho,Arriba);
     line(Izquierda,Arriba,Izquierda,Arriba+Altura);

     setcolor(BLACK);
     line(Izquierda+Ancho,Arriba,Izquierda+Ancho,Arriba+Altura);
     line(Izquierda,Arriba+Altura,Izquierda+Ancho,Arriba+Altura);

     mouse.MostrarMouse();

   }
   
  
   