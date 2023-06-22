#ifndef CHASIS_H
#define CHASIS_H

#define ALTURATITULO 21
#define ANCHOBORDE 1
#include "Boton.h"


class Chasis
{

 private:

 int Izquierda,Arriba,Ancho,Altura;
 char Captura[50];
 Boton *CloseBtn;
 public:
 
 Chasis(int izquierda, int arriba, int ancho, int altura, char captura[]);
 void Iniciales();
 void Dibujar();
 void HabilitarControladorClicCha(); 
};

#endif // CHASIS_H


