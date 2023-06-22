#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include "Chasis.h"
#include "Boton.h"


 Chasis::Chasis(int izquierda, int arriba, int ancho, int altura, char captura[])
 {
  Izquierda = izquierda;
  Arriba = arriba;
  Ancho = ancho;
  Altura = altura;
  strcpy(Captura,captura);
 }
 
  void Chasis::Iniciales()
 {
    /*********** Logo ************/

  setcolor(3);
  setfillstyle(SOLID_FILL,3);
  fillellipse(Izquierda+(ANCHOBORDE)+ALTURATITULO/2,Arriba+ALTURATITULO/2,ALTURATITULO/2-1,ALTURATITULO/2-1);
  setcolor(15);
  setfillstyle(SOLID_FILL,15);
  circle(Izquierda+(ANCHOBORDE)+ALTURATITULO/2,Arriba+ALTURATITULO/2,ALTURATITULO/2-3);
  settextstyle(SMALL_FONT,0,0);
  outtextxy(Izquierda+6,Arriba+4,"MM");
  settextstyle(0,0,0);
 }
 
 void Chasis::Dibujar()
 {
  setfillstyle(SOLID_FILL,LIGHTGRAY);
  bar(Izquierda,Arriba,Izquierda+Ancho,Arriba+Altura);

  setcolor(WHITE);
  line(Izquierda,Arriba,Izquierda+Ancho,Arriba);
  line(Izquierda,Arriba,Izquierda,Arriba+Altura);

  setcolor(BLACK);
  line(Izquierda,Arriba+Altura,Izquierda+Ancho,Arriba+Altura);
  line(Izquierda+Ancho,Arriba,Izquierda+Ancho,Arriba+Altura);

  setfillstyle(SOLID_FILL,BLUE);
  bar(Izquierda+ANCHOBORDE,Arriba+ANCHOBORDE,
  Izquierda+Ancho-(ANCHOBORDE*2),Arriba+ALTURATITULO);

  setcolor(WHITE);
  settextjustify(LEFT_TEXT,TOP_TEXT);
  outtextxy(Izquierda+(ANCHOBORDE*2)+ALTURATITULO+2,Arriba+(ANCHOBORDE*2)+(ALTURATITULO/2)-(textheight(Captura)/2),Captura);
  CloseBtn = new Boton(Izquierda+Ancho-ALTURATITULO-1, Arriba+2,ALTURATITULO-2, ALTURATITULO-2, "X", 9809);
  CloseBtn->Dibujar();

  Iniciales();

 }
 

 
