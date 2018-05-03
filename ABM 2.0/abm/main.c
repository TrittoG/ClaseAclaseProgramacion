#include <stdio.h>
#include <stdlib.h>
#include "xxxxx.h"
#define QTY 20
#include "func.h"
#include <string.h>

int main()
{
    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {
        printf("1- Agregar \n");
        printf("2- Borrar \n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir \n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {

                }
                break;
            case 2:
                {

                }
                break;
            case 3:
                {

                }
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                printf("adios...");
                break;
        }
    }

    return 0;
}
