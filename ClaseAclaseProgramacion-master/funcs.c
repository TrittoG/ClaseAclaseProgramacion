#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer) == 1)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}


int esEntero(char *str)
{
    int i;
    for(i=0;str[i] != '\0';i++)
    {
        if(str[i] > '9' || str[i] < '0')
            return 0;
    }
    return 1;
}




