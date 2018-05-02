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

int per_baja(EPersona lista[], int cantidad_de_elementos)
{
    int i;
    int dni;
    int retorno;

    dni = getIntTrucho("Ingrese el documento de la persona a ser borrada: ");

    for(i=0; i < cantidad_de_elementos;i++)
    {
        if(lista[i].dni == dni)
        {
            lista[i].isEmpty = 1;
            retorno = 0;
            break;
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}

void per_ordenar(EPersona lista[], int cantidad_de_elementos, int orden)
{

    EPersona aux;

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
                if(lista[i].isEmpty==0 && lista[i+1].isEmpty == 0)
                {

                    aux = lista[i];
                    lista[i]=lista[i+1];
                    lista[i+1] = aux;
                    flagSwap = 1;




                }

            }

        }//fin del for

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



