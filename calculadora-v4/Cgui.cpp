#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include "Mouse.h"
#include "Pantalla.h"
#include "Boton.h"
#include "Chasis.h"
#include "Cgui.h"



void Boton::HabilitarControladorClic()
   {

  if(Estado)
  {
   IdBoton = 0;
   Estado = false;
   return;
  }

  if( mouse.MouseDentro(Izquierda,Arriba,Izquierda+Ancho,Arriba+Altura) == 1)
  {

   if( mouse.GetBoton() == MOUSE_BOTON_I)
   {
    MouseAbajo();
    btnStatus = ESTATUS_BOTON_ABAJO;
   }

   else if(btnStatus == ESTATUS_BOTON_ABAJO &&  mouse.GetBoton() == MOUSE_NORMAL)
   {
    MouseArriba();
    IdBoton = ID;
    btnStatus = ESTATUS_BOTON_NORMAL;
    Estado = true;

   }

  }

 }

   




void Chasis::HabilitarControladorClicCha()
 {
  CloseBtn->HabilitarControladorClic();
  if (IdBoton == 9809)
  exit(0);

 }
 


 
 void Cgui::Inicializar(){
     
     
     
 gd=DETECT;
 opr1 = 0;
 opr2 = 0;
 result = 0;
 d=0;
 Operation=0;

 x = 160;
 y = 130;
 w = 50;
 h = 40;
 
 
 char deci[]={"."};

 char btn[][3]={"AC","/","X","<-","7","8","9","-",
 "4","5","6","+","1","2","3","=","0",".","+/-"};


  // inicializar gráficos y variables locales
  initgraph(&gd,&gm,"//tc//bgi");

  // leer el resultado de la inicialización
  errorcode = graphresult();

  if (errorcode != grOk)// ocurrió un error
  {
   cout<<"Graphics error :: "<<grapherrormsg(errorcode);
   cout <<"\n press any key to halt: ";
   getch();
   exit(1);// terminar con un código de error
  }

 mouse.InstalarMouse();

 /* Dibujando Chasis */

 Chasis *pChasis = new Chasis(150,50,265,340,"Calculadora");
 pChasis->Dibujar();

 /* Dibujando pantalla */

 Pantalla *pPantalla = new Pantalla(160,80,243,30,"",RIGHT_TEXT);
 pPantalla->Dibujar();

 /* Dibujando Botones */

 Boton *pBoton[19];
 for (int i = 0;i<19;i++)
 {
    if(i == 15)
  h = 90;
    else
  h=40;
    pBoton[i] = new Boton(x,y,w,h,btn[i],i+1);
    pBoton[i]->Dibujar();
    x = x+65;
    if(i == 3 || i == 7 || i==11 || i== 15)
    {
      y = y+50;
      x = 160;
    }
 }

 while(1){

   mouse.MostrarMouse(); // Para mostrar el ratón
   mouse.GetMouseEstatus(); // Para obtener la posición del mouse

  // Habilitando click en la clase boton en  Chasis
  pChasis->HabilitarControladorClicCha();
  // Habilitando clics en los Botones
  for(int k = 0;k<19;k++)
  pBoton[k]->HabilitarControladorClic();


  switch(IdBoton)
  {
    case 1: //AC
      pPantalla->Limpiar();
      d = 0;
      opr1=0;
      opr2=0;
      result = 0;
      Operation = 0;

    break;
    case 2: //Dividir
      opr1 = atof(pPantalla->GetTexto());
      pPantalla->Limpiar();
      Operation = DIVIDIR;
      d = 0;

    break;
    case 3: //Multiplicar
      opr1 = atof(pPantalla->GetTexto());
      pPantalla->Limpiar();
      Operation = MULTIPLICAR;
      d=0;

    break;
    case 4: //Backspace
      strcpy(chr,pPantalla->GetTexto());
      len=strlen(chr);
      if(chr[len-2] == deci[0])
      {
         chr[len-1]=0;
         chr[len-2]=0;
      }
      else
         chr[len-1] = 0;
      pPantalla->Limpiar();
      pPantalla->SetTexto(chr);

    break;
    case 5: //7
      pPantalla->SetTexto("7");

    break;
    case 6: //8
      pPantalla->SetTexto("8");

    break;
    case 7: //9
      pPantalla->SetTexto("9");

    break;
    case 8: // Resta
      opr1 = atoi(pPantalla->GetTexto());
      pPantalla->Limpiar();
      Operation = RESTAR;
      d=0;

    break;
    case 9: //4
      pPantalla->SetTexto("4");

    break;
    case 10: //5
      pPantalla->SetTexto("5");

    break;
    case 11: //6
      pPantalla->SetTexto("6");

    break;
    case 12: //Suma
      opr1 = atof(pPantalla->GetTexto());
      pPantalla->Limpiar();
      Operation = SUMAR;
      d=0;

    break;
    case 13: //1
      pPantalla->SetTexto("1");

    break;
    case 14: //2
      pPantalla->SetTexto("2");

    break;
    case 15: //3
      pPantalla->SetTexto("3");

    break;
    case 16: // Igual(=)
      opr2 = atof(pPantalla->GetTexto());

      switch(Operation)
      {
   case SUMAR:
   result = opr1+opr2;
   break;
   case RESTAR:
   result = opr1-opr2;
   break;
   case MULTIPLICAR:
   result = opr1*opr2;
   break;
   case DIVIDIR:
   result = opr1/opr2;
   break;
      }

      pPantalla->Limpiar();
      pPantalla->SetTexto(gcvt(result,10,str));
      opr1=0;
      opr2=0;
      result = 0;
      Operation=0;

    break;
    case 17: //0
      pPantalla->SetTexto("0");

    break;
    case 18: // Decimal(.)
      if(d == 0)
      {
       d = 1;
       pPantalla->SetTexto(".");
      }

    break;
    case 19: //Mas y menos (+/-) (Signo, no operacion)



   temp = atof(pPantalla->GetTexto());
   temp = temp* -1;
   pPantalla->Limpiar();
   pPantalla->SetTexto(gcvt(temp,10,str));


    break;
  }


       while(kbhit()){
  ch = getch();
  if (ch == 27)  //ESC (salida)
  exit(0);
    } }

      

  
 }
