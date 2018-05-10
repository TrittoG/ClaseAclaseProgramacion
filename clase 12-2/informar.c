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

    if(cantidad_pantalla > 0 && arrayP != NULL)
    {
        for(i=0;i<cantidad_pantalla;i++)
        {
            if(arrayP[i].isEmpty ==0)
            {
                auxsuma = arrayP[i].precio + auxsuma;
                contador++;
            }
        }
    }
    return auxsuma/contador;

}

int mostrarPantallasNoSuperanPromedio(Pantalla *arrayP, int cantidad_pantalla)
{
    int i;
    float promedio;
    promedio = PromedioPrecios(arrayP,cantidad_pantalla);

    if(cantidad_pantalla > 0 && arrayP != NULL)
    {
        for(i=0;i<cantidad_pantalla;i++)
        {
            if(arrayP[i].precio < promedio && arrayP[i].isEmpty == 0)
            {
                printf("PANTALLA: %s PRECIO %f --------- promedio %.2f\n", arrayP[i].nombre,arrayP[i].precio,promedio);

            }
        }
    }
    return 0;
}


float promedioDias(Contratacion *arrayC, int cantidad_contratacion)
{
    int i;
    float suma =0;
    int contador =0;
    float promedio =0;

    if(cantidad_contratacion > 0 && arrayC != NULL)
    {
        for(i=0;i<cantidad_contratacion;i++)
        {
            if(arrayC[i].isEmpty == 0)
            {
                suma = arrayC[i].dias + suma;
                contador++;
            }
        }
        promedio = suma/contador;
    }

    return promedio;

}

int listarPantallasSuperanDiasContratacion(Pantalla *arrayP, int cantidad_pantalla, Contratacion *arrayC, int cantidad_contratacion)
{
    int i;
    float promDias;


    if(cantidad_contratacion > 0 && arrayC != NULL)
    {
        promDias = promedioDias(arrayC, cantidad_contratacion);

        for(i=0;i<cantidad_contratacion;i++)
        {
            if(arrayC[i].isEmpty == 0 && arrayC[i].dias > promDias)
            {
                printf("NOMBRE: %s -- DIAS: %d ---- PROMEDIO DIAS: %f\n" , arrayP[i].nombre,arrayC[i].dias,promDias);
            }
        }
    }
    return 0;
}


int mostrarPantallasSiSuperanPromedio(Pantalla *arrayP, int cantidad_pantalla)
{
    int i;
    float promedio;
    promedio = PromedioPrecios(arrayP,cantidad_pantalla);

    if(cantidad_pantalla > 0 && arrayP != NULL)
    {
        for(i=0;i<cantidad_pantalla;i++)
        {
            if(arrayP[i].precio > promedio && arrayP[i].isEmpty == 0)
            {
                printf("PANTALLA: %s PRECIO %f --------- promedio %.2f\n", arrayP[i].nombre,arrayP[i].precio,promedio);

            }
        }
    }
    return 0;
}

int contadorPublicaciones(Contratacion *arrayC, int cantidad_contratacion, int idpantalla)
{
    int i;
    int contador=0;
    if(cantidad_contratacion > 0 && arrayC != NULL)
    {
        for(i=0;i<cantidad_contratacion;i++)
        {
            if(arrayC[i].idPantalla == idpantalla && arrayC[i].isEmpty == 0)
            {
                contador++;
            }

        }
    }
    return contador;
}

int mostrarPantallasMasDeUnaPublicacion(Pantalla *arrayP, int cantidad_pantalla, Contratacion *arrayC, int cantidad_contratacion)
{
    int i;
    int contPub;
    if(cantidad_pantalla > 0 && arrayP != NULL)
    {

        for(i=0;i<cantidad_pantalla;i++)
        {
            contPub = contadorPublicaciones(arrayC,cantidad_contratacion,arrayP[i].idPantalla);
            if(arrayP[i].isEmpty == 0 && contPub>1)
            {
                printf("PANTALLA: %s ---- cantidad de publicaciones: %d\n", arrayP[i].nombre,contPub);
            }
        }
    }
    return 0;
}

int listarPantallasIndicandoFacturacion(Pantalla *arrayP, int cant_pantalla, Contratacion *arrayC, int cant_contratacion)
{
    int i;
    int facturacion;
    if(cant_pantalla >0 && arrayP != NULL && cant_contratacion > 0 && arrayC != NULL)
    {
        for(i=0;i<cant_pantalla;i++)
        {
            if(arrayP[i].isEmpty ==0 && arrayC[i].isEmpty == 0)
            {
                facturacion = arrayP[i].precio * arrayC[i].dias;
                printf("pantalla: %s --- facturacion: %d\n", arrayP[i].nombre,facturacion);

            }
        }

    }

    return 0;
}


int informar_pantallaQueMasFactura(Pantalla *ArrayP, int cant_pantalla, Contratacion *ArrayC, int cant_contratacion)
{
    int i;
    int facturacion;
    int masGrande =-1;
    char masPantalla[50];
    if(cant_pantalla >0 && ArrayP != NULL && cant_contratacion > 0 && ArrayC != NULL)
    {
        for(i=0;i<cant_pantalla;i++)
        {
            if(ArrayP[i].isEmpty ==0 && ArrayC[i].isEmpty == 0)
            {
                facturacion = ArrayP[i].precio * ArrayC[i].dias;
                if(facturacion > masGrande)
                {
                    masGrande = facturacion;
                    strcpy(masPantalla, ArrayP[i].nombre);
                }
            }
        }
        printf("LA PANTALLA QUE MAS FACTURA ES: %s ---- FACTURO: %d", masPantalla,masGrande);
    }

    return 0;


}
