#ifndef MOUSE_H
#define MOUSE_H


enum BOTON{MOUSE_NORMAL = 0,MOUSE_BOTON_I=1,MOUSE_BOTON_D=2,MOUSE_BOTON_M=4};

class Mouse

{
  private:

   int MouseXpos, MouseYpos;
   BOTON MouseBtn;
   union REGS entrada,salida;

  public:

   int InstalarMouse();
   int MostrarMouse();
   int OcultarMouse();
   void GetMouseEstatus();
   BOTON GetBoton();
   int GetPosX();
   int GetPosY();
   void SetMousePosi(int &xpos, int &ypos);
   int MouseDentro(int x1, int y1, int x2, int y2);
   void RestringirMousePtr(int x1, int y1, int x2, int y2);

};

#endif // MOUSE_H



