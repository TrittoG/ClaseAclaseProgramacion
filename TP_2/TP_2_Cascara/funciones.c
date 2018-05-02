#include "funciones.h"
#include <string.h>
#define QTY 20
#include "FUNCIONES.h"
#include <string.h>
#include <stdio.h>

void InicializarArry(EPersona array[], int cantidad_de_elementos)
{
    int i;

    for(i=0;i<cantidad_de_elementos;i++)
    {
        array[i].dni = '\0';
        array[i].edad = '\0';
        strcpy(array[i].nombre, " ");
        array[i].isEmpty = 1;

    }

}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int cantidad_de_elementos)
{

    int i;
    int retorno = -1;

    for(i=0; i< cantidad_de_elementos; i++)//no se puede hacer una cascara de eso y despues modificarla para cada uso?
    {
        if(lista[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }

    }

    return retorno;

}


void per_alta(EPersona lista[], int dni, int edad, char nombre[30])
{
    int espacioLibre;

    espacioLibre = obtenerEspacioLibre(lista, QTY);

    lista[espacioLibre].dni = dni;
    lista[espacioLibre].edad = edad;
    strcpy(lista[espacioLibre].nombre,nombre);
    lista[espacioLibre].isEmpty = 0;


}

void per_baja(EPersona lista[], int cantidad_de_elementos)
{
    int i;
    int dni;

    dni = getIntTrucho("Ingrese el documento de la persona a ser borrada: ");

    for(i=0; i < cantidad_de_elementos;i++)
    {
        if(lista[i].dni == dni)
        {
            lista[i].isEmpty = 1;
            printf("la persona ha sido borrada\n");
            break;
        }
        else
        {
            printf("error no se encuentra ese dni...\n");
            break;
        }
    }

}

void per_ordenar(EPersona lista[], int cantidad_de_elementos, int orden)
{

    char *aux[QTY];
    int dni;
    int edad;
    int i;
    int flagSwap;
    int resultadoComparacion;

    do
    {
        flagSwap = 0;
        for(i=0;i< cantidad_de_elementos-1;i++)
        {
            resultadoComparacion = strcmp(lista[i].nombre, lista[i+1].nombre);
            if((resultadoComparacion > 0 && orden == 0) || (resultadoComparacion < 0 && orden == 1))
            {
                if(lista[i].isEmpty==0)
                {
                    strcpy(aux[i], lista[i].nombre);
                    strcpy(lista[i].nombre, lista[i+1].nombre);
                    strcpy(lista[i+1].nombre, aux[i]);
                    flagSwap = 1;


                    dni = lista[i].dni;
                    lista[i].dni = lista[i+1].dni;
                    lista[i].dni = dni;

                    edad = lista[i].edad;
                    lista[i].edad = lista[i+1].edad;
                    lista[i+1].edad = lista[i].edad;

                }

            }

        }//fin del for
        if(flagSwap == 0)
        {
            break;
        }
    }while(flagSwap==1);


}





void per_mostrar(EPersona lista[], int cantidad_de_elementos)
{
    int i;
    int contador =0;

    for(i=0; i< cantidad_de_elementos;i++)
    {
        if(lista[i].isEmpty == 0)
        {
            printf("NOMBRE: %s\n", lista[i].nombre);
            printf("EDAD: %d\n", lista[i].edad);
            printf("DNI: %d\n", lista[i].dni);
            contador++;

        }

    }


    if(contador == 0)
    {
        printf("error no hay usuarios registrados!\n");
    }

}



