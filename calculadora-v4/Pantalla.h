#ifndef PANTALLA_H
#define PANTALLA_H


class Pantalla
{

 private:

 int Alineamiento;

 int Izquierda,Arriba,Ancho,Altura;
 char Captura[50];

 public:

 Pantalla(int izquierda, int arriba, int ancho, int altura, char captura[],int Alinear);
 void Dibujar();
 void SetTexto(char texto[]);
 char *GetTexto();
 void Limpiar();
 
};

#endif // PANTALLA_H
