#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include "Mouse.h"
 
 
 int Mouse::InstalarMouse()
 {

  entrada.x.ax = 0;
  int86(51,&entrada,&salida);
  return salida.x.ax;

 }
 int Mouse::MostrarMouse()
 {

  entrada.x.ax = 1;
  int86(51,&entrada,&salida);
  return 1;

 }
 int Mouse::OcultarMouse()
 {

  entrada.x.ax = 2;
  int86(51,&entrada,&salida);
  return 1;

 }
 void Mouse::GetMouseEstatus()
 {

  entrada.x.ax = 3;
  int86(51,&entrada,&salida);
  MouseXpos = salida.x.cx;
  MouseYpos = salida.x.dx;
  MouseBtn = salida.x.bx;

 }
 BOTON Mouse::GetBoton()
 {
  return MouseBtn;
 }

 int Mouse::GetPosX()
 {
  return MouseXpos;
 }

 int Mouse::GetPosY()
 {
  return MouseYpos;
 }

 void Mouse::SetMousePosi(int &xpos, int &ypos)
 {
  entrada.x.ax = 4;
  entrada.x.cx = xpos;
  entrada.x.dx = ypos;
  int86(51,&entrada,&salida);
 }
 int Mouse::MouseDentro(int x1, int y1, int x2, int y2)
 {
  int x_pos, y_pos;
  entrada.x.ax = 3;
  int86(51,&entrada,&salida);
  x_pos = salida.x.cx;
  y_pos = salida.x.dx;

  if(x_pos >= x1 && y_pos >= y1 && x_pos <= x2 && y_pos <= y2)
   return 1;
  else
   return 0;

 }
 void Mouse::RestringirMousePtr(int x1, int y1, int x2, int y2)
 {

  entrada.x.ax = 7;
  entrada.x.cx = x1;
  entrada.x.dx = x2;
  int86(51,&entrada,&salida);

  entrada.x.ax = 8;
  entrada.x.cx = y1;
  entrada.x.dx = y2;
  int86(51,&entrada,&salida);

 }