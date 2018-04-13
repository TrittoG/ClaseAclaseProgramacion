#include <stdio.h>
#include <stdlib.h>

int mostrarArrayInt(int* array, int cantidad)
{
    int retorno = -1;
    int i;
    if(cantidad > 0)
    {
        retorno = 0;
        for(i=0;i<cantidad;i++)
        {
            printf("\n%d",array[i]);
        }

    }
    return retorno;
}

int ordenarArrayInt(int* array, int cantidad, int orden)
{
    int retorno = -1;
    int i,j;
    int auxiliar;
    if(cantidad > 0)
    {
        retorno = 0;
        for(i=0;i<cantidad-1;i++)
        {
            for(j=i+1;j<cantidad;j++)
            {
                if(array[i] > array[j] && orden == 0)
                {
                    auxiliar = array[j];
                    array[j] = array[i];
                    array[i] = auxiliar;
                }
                else if(array[i] < array[j] && orden == 1)
                {
                    auxiliar = array[j];
                    array[j] = array[i];
                    array[i] = auxiliar;
                }

            }
        }
    }
    return retorno;
}


int burbujeo(int* array, int cantidad, char orden)
{
    int retorno =-1;
    int leeNum;
    int contador;
    int aux;

    if(cantidad >0)
    {
        retorno = 0;

        do
        {
            contador = 0;

                for(leeNum = 0; leeNum < cantidad-1; leeNum++)
                    {
                        if((array[leeNum] > array[leeNum +1] && orden == 'd') || (array[leeNum] < array[leeNum+1] && orden == 'a'))
                        {
                            aux =array[leeNum+1];
                            array[leeNum+1] = array[leeNum];
                            array[leeNum]=aux;
                            contador++;
                        }
                    }

        }while(contador != 0);
    }
    return retorno;
}





int desplazar(int *array, int cantidad, int sentido, int indiceUno, int indiceDos)
{
    int retorno = -1;
    int i;
    int aux;

     if(indiceUno <= 0 || indiceDos > cantidad-1)
            {
                retorno= -2;

            }else
            {



    if(cantidad > 0)
    {
        retorno = 0;


        if(sentido == 0)
        {

            for(i=indiceUno; i < indiceDos+1; i++)
            {
               aux = array[i];
               array[i]= array[i-1];
               array[i-1]=aux;
            }

        }else
        {
            for(i=indiceDos; i > indiceUno-1; i--)
            {
               aux = array[i];
               array[i]= array[i+1];
               array[i+1]=aux;
            }
        }

    }
            }

    return retorno;
}


