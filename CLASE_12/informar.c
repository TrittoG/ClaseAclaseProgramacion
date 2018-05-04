#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;

    if(arrayC != NULL && pantallas != NULL && limite > 0 && lenPantallas > 0)
    {
        retorno = -2;

         for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit, cuit))
            {
                indexPantalla = pantalla_buscarPorId(pantallas, lenPantallas, arrayC[i].idPantalla);
                printf("\nCUIT: %s - ID: %d - VALOR %.2f", arrayC[i].cuit, arrayC[i].id, arrayC[i].dias * pantallas[indexPantalla].precio);
                retorno = 0;
            }
        }


    }


    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int posicion;


    if(arrayC != NULL && pantallas != NULL && limite > 0 && lenPantallas > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayC[i].isEmpty == 0)
            {
                posicion = pantalla_buscarPorId(pantallas,lenPantallas, arrayC[i].idPantalla);
                printf("nombre pantalla: %s \nnombre video: %s\ncantidad de dias: %d\ncuit: %s\n", pantallas[posicion].nombre, arrayC[i].archivo  ,arrayC[i].dias,arrayC[i].cuit);
                retorno = 0;
            }
        }
    }

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    cont_ordenarCuit(arrayC,limite, 0);
    char ultimoCuit[50]="-";

    if(arrayC != NULL && pantallas != NULL && limite > 0 && lenPantallas > 0)
    {
        cont_ordenarCuit(arrayC,limite, 0);
        retorno = -2;

         for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit, ultimoCuit))
            {
                strcpy(ultimoCuit, arrayC[i].cuit);
                printf("INFO DEL CUIT- %sº\n", ultimoCuit);
                informar_ConsultaFacturacion(arrayC,limite,pantallas,lenPantallas,ultimoCuit);
            }
        }


    }


    return retorno;

}
