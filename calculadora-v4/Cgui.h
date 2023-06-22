#ifndef CGUI_H
#define CGUI_H

#define SUMAR 1
#define RESTAR 2
#define MULTIPLICAR 3
#define DIVIDIR 4



class Cgui
{


 public:
 
 int gd;
 int gm;
 int ch;
 int errorcode;
 double opr1;
 double opr2;
 double result;
 int d;
 int Operation;
 double temp;
 char *chr;
 char str[30];
 int len;
 int x;
 int y;
 int w;
 int h;

 
 void Inicializar();
 
 
 
};


#endif // CGUI_H
