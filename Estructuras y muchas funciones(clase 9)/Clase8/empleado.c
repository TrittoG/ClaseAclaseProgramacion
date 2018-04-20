#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"


int emp_init(Empleado* arrayEmpleados,int sizeArray)
{
        int i;
        int retorno= 0;
        for(i=0;i<sizeArray;i++)
        {
            arrayEmpleados[i].isEmpty = 1;
            retorno = 1;
        }
        return retorno;
}



int emp_mostrar(Empleado* arrayEmpleados,int sizeArray)
{
    int i;


    for(i=0;i<sizeArray;i++)
    {
        if(arrayEmpleados[i].isEmpty == 0)
        {
            printf("apellido %s ",arrayEmpleados[i].apellido);
            printf("nombre %s ",arrayEmpleados[i].nombre);
            printf("ID %d\n", arrayEmpleados[i].idEmpleado);
        }

    }
    return 0;
}


int emp_alta(Empleado* arrayEmpleados,int sizeArray,int id)
{
        int posicion;
        posicion= buscarLibre(arrayEmpleados, sizeArray);

        if(posicion != -1)
        {
            getString("ingrese un apellido ", arrayEmpleados[posicion].apellido);
            getString("ingrese un nombre \n" , arrayEmpleados[posicion].nombre);
            arrayEmpleados[posicion].idEmpleado = id;
            arrayEmpleados[posicion].isEmpty = 0;
        }




    return 0;
}


int emp_baja(Empleado* arrayEmpleados,int sizeArray,int id)
{

    int i;

    for(i=0;i<sizeArray;i++)
    {
        if(arrayEmpleados[i].idEmpleado == id)
        {
            arrayEmpleados[i].isEmpty = 1;
            break;
        }
    }





    return 0;
}



int buscarLibre(Empleado* arrayEmpleados,int sizeArray)
{
    int i;
    int lugarLibre =-1;

    for(i=0;i<sizeArray;i++)
    {
        if(arrayEmpleados[i].isEmpty == 1)
        {
            lugarLibre = i;
            break;

        }
    }

    return lugarLibre;
}

int emp_ordenar(Empleado* arrayEmpleados, int sizeArray)
{
    int i;
    int flag =0;
    Empleado auxiliar[10];

    do
    {
        for(i=0;i<sizeArray;i++)
        {
            if(arrayEmpleados[i].isEmpty == 0)
            {

                if(strcmp(arrayEmpleados[i].apellido, arrayEmpleados[i+1].apellido)==1)
                {
                         auxiliar[i] = arrayEmpleados[i];
                        arrayEmpleados[i] = arrayEmpleados[i+1];
                        arrayEmpleados[i+1] = auxiliar[i];
                        flag = 1;
                }
            }
        }

    }while(flag == 1);

    return 0;
}
