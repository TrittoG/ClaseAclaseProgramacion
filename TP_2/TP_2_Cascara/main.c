#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define QTY 20
#include "FUNCIONES.h"
#include <string.h>

int main()
{
    EPersona persona[QTY];
    char seguir='s';
    int opcion=0;

    InicializarArry(persona , QTY);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {
                    per_alta(persona, 38,19,"giuliano");
                    per_alta(persona, 23, 23,"aaaaaaa");
                    per_alta(persona, 24, 11, "rrrrrrrr");
                }
                break;
            case 2:
                {
                    per_baja(persona, QTY);

                }
                break;
            case 3:
                {
                    per_mostrar(persona,QTY);
                    per_ordenar(persona, QTY,0);
                    per_mostrar(persona, QTY);
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
