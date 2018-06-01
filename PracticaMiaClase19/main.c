#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"

/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Listar Clientes
        9. Guardar datos en data.csv (modo texto)
       10. Guardar datos en data.bin (modo binario)
*****************************************************/


int main()
{
    char seguir= 's';
    int opcion;

    FILE* pFile;
    ArrayList* pArrayClientes;
    pArrayClientes = al_newArrayList();

     while(seguir=='s')
    {
        printf("1. Cargar datos desde data.csv\n");
        printf("2. Listar Clientes\n");
        printf("3. Ordenar por nombre y apellido\n");
        printf("4. Ordenar por mail\n");
        printf("5. Agregar un Cliente\n");
        printf("6. Elimina un Cliente\n");
        printf("7. Modificar Cliente (Nombre, Apellido y Mail)\n");
        printf("8. Listar Clientes\n");
        printf("9. Guardar datos en data.csv (modo texto)\n");
        printf("10. Guardar datos en data.bin (modo binario)\n\n");
        printf("11. SALIR\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                parserCliente("data.csv" , pArrayClientes);
                break;
            case 2 :
                cliente_listarClientes(pArrayClientes);

                break;
            case 3 :
                controller_ordenarClientesNombre(pArrayClientes);
                break;
            case 4 :
                controller_ordenareMail(pArrayClientes);

                break;
            case 5:
                controller_agregarCliente(pArrayClientes);

                break;
            case 6 :
                break;
            case 7 :
                break;
            case 8 :
                break;
            case 9 :
                controller_guardarClientes("data2.csv", pArrayClientes);

                break;
            case 10 :
                break;
            case 11 :
                seguir = 'n';
                break;


            }

    }
      return 0;
}

