#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                printf("\n\nCuit: %s - Unitario: %.2f - Total: %.2f - Dias: %d\n",
                                    arrayC[i].cuit,
                                    pantallas[indexPantalla].precio,
                                    (arrayC[i].dias * pantallas[indexPantalla].precio),
                                    arrayC[i].dias );
            }
        }

        retorno = 0;
    }
    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias );
                }


        }

        retorno = 0;
    }
    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    //int indexPantalla;
    char ultimoCuit[50];

    cont_ordenarCuit(arrayC,limite,0);
    strcpy(ultimoCuit,"");
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    if(strcmp(ultimoCuit,arrayC[i].cuit) != 0)
                    {
                        printf("\nCuit: %s", arrayC[i].cuit);
                        strcpy(ultimoCuit,arrayC[i].cuit);
                    }


                    //indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    /*printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias );*/

                }


        }

        retorno = 0;
    }
    return retorno;
}


int importeGastado(Contratacion* arrayC,int limite, Pantalla* arrayP, int limitePantallas, int *importe, char *cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(arrayP,limitePantallas,arrayC[i].idPantalla);
                *importe = arrayC[i].dias * arrayP[indexPantalla].precio;
            }
        }

        retorno = 0;
    }
    return retorno;
}



int informar_ClientesGastadoContrataciones(Contratacion* arrayC,int cantidad_cont ,Pantalla* ArrayP, int cantidad_de_elementos)
{
    int i;
    int importe;
    char cuit[50];

    cont_ordenarCuit(arrayC,cantidad_cont, 1);


    for(i=0;i<cantidad_de_elementos;i++)
    {
        if(!arrayC[i].isEmpty)
        {
            if(arrayC[i].cuit != arrayC[i+1].cuit)
            {
                strcpy(cuit,arrayC[i].cuit);
            }

            importeGastado(arrayC,cantidad_cont, ArrayP,cantidad_de_elementos,&importe, cuit);
            printf("CUIT = %s    GASTO= %d\n",cuit, importe);
        }

    }



return 0;
}


int informar_ListadoPantallas(Pantalla* ArrayP, int cantPantalla)
{
    int i;
    int flagSwap;
    Pantalla auxiliarPantalla;



         do
        {
            flagSwap = 0;
            for(i=0;i<cantPantalla-1;i++)
            {
                if(!ArrayP[i].isEmpty && !ArrayP[i+1].isEmpty)
                {
                    if((ArrayP[i].precio > ArrayP[i+1].precio )) //******
                    {
                        auxiliarPantalla = ArrayP[i];
                        ArrayP[i] = ArrayP[i+1];
                        ArrayP[i+1] = auxiliarPantalla;
                        flagSwap = 1;
                    }
                    else if(ArrayP[i].precio == ArrayP[i+1].precio)
                    {
                        if(stricmp(ArrayP[i].nombre,ArrayP[i+1].nombre)==1)
                        {
                            auxiliarPantalla = ArrayP[i];
                            ArrayP[i] = ArrayP[i+1];
                            ArrayP[i+1] = auxiliarPantalla;
                            flagSwap = 1;
                        }
                    }
                }
            }
        }while(flagSwap);

    return 0;
}


int ListarPantallasInferiorAMil(Pantalla *ArrayP, int cantidad_pantalla)
{
    int i;

    if(cantidad_pantalla > 0 && ArrayP != NULL)
    {
        for(i=0;i<cantidad_pantalla;i++)
        {
            if(!ArrayP[i].isEmpty && ArrayP[i].precio <= 1000)
            {
                printf("PANTALLA= %s   PRECIO= %.2f\n", ArrayP[i].nombre,ArrayP[i].precio);
            }
        }
    }
    return 0;
}

float PromedioPrecios(Pantalla *arrayP, int cantidad_pantalla)
{
    int i;
    float auxsuma =0;
    int contador =0;

    for(i=0;i<cantidad_pantalla;i++)
    {
        if(arrayP[i].isEmpty ==0)
        {
            auxsuma = arrayP[i].precio + auxsuma;
            contador++;
        }
    }
    return auxsuma/contador;

}

int mostrarPantallasNoSuperanPromedio(Pantalla *arrayP, int cantidad_pantalla)
{
    int i;

    for(i=0;i<cantidad_pantalla;i++)
    {
        if()
    }
}
