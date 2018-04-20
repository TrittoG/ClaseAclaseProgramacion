#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleado.h"
#define QTY 50


int main()
{
   int proximoID = 0;
   int continuar =0;
   int valor;
   int IDborrar;

   Empleado arrayEmpleados[QTY];

   emp_init(arrayEmpleados, QTY);

   do
   {
       valor =getInt("1- agregar empleados \n2-mostrar empleados  \n3-dar de baja un empleado \n4-ordenar \n5-salir\n");

       switch(valor)
       {
            case 1 :
                {
                    emp_alta(arrayEmpleados,QTY,proximoID);
                    proximoID++;
                    break;
                }
            case 2 :
                {
                    emp_mostrar(arrayEmpleados,QTY);
                    break;
                }
            case 3 :
                {
                    IDborrar = getInt("ingrese el Id del desafortunado\n");
                    emp_baja(arrayEmpleados, QTY, IDborrar);
                    break;
                }
            case 4 :
                {
                    emp_ordenar(arrayEmpleados, QTY);
                    break;
                }
            case 5 :
                {
                    continuar = 1;
                }
       }


   }while(continuar != 1);

    return 0;
}

