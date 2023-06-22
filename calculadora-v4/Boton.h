#ifndef BOTON_H
#define BOTON_H
#include "Mouse.h"


enum ESTATUS_BOTON 
{
   ESTATUS_BOTON_NORMAL,
   ESTATUS_BOTON_ABAJO
};

int IdBoton;
enum bool{false,true};

static Mouse mouse;


class Boton
{

 private:

 int Izquierda,Arriba,Ancho,Altura,ID;
 char Captura[50];
 ESTATUS_BOTON btnStatus;
 void MouseAbajo();
 void MouseArriba();
 bool Estado;

 public:

 Boton(int izquierda, int arriba, int ancho, int altura, char captura[], int Id);
 void Dibujar();
 void HabilitarControladorClic(); 

};

#endif // BOTON_H
