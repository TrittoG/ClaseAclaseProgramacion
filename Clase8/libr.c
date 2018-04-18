#include <stdio.h>
#include <stdlib.h>


/** \brief Muestra un mensaje pidiendo un entero, analizando la cantidad de intentos que quieras, y el rango
 *
 * \param char* mensaje mensaje que muestra para pedir el entero
 * \param char* error mensaje que muestra al no respetar lo pedido
 * \param int intentos cantidad de veces que puede intentarlo
 * \param int maximo numero entero maximo a ingresar
 * \param int minimo numero entero minimo a ingresar
 * \param int* resultado devuelve el numero entero ingresado y valido
 * \return int -2 overflow negativo, -1 overflow positivo, 0 todo correcto
 *
 */
int getInt(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado)
{
    int auxiliarEntero;
    int retorno = -1;
    do
    {
        intentos--;
        printf("%s \n", mensaje);
        scanf("%d", &auxiliarEntero);
        if(auxiliarEntero >= minimo && auxiliarEntero <= maximo)
        {
            retorno = 0;
            *resultado = auxiliarEntero;
            break;
        }
        else
        {
            if(auxiliarEntero < minimo)
            {
                retorno = -2;
            }
            else
            {
                retorno = -1;
            }
        }
        printf("%s", error);
    }while(intentos >= 0);

    return retorno;
}

/** \brief Muestra un mensaje pidiendo un flotante, analizando la cantidad de intentos que quieras, y el rango
 *
 * \param char* mensaje mensaje que muestra para pedir el flotante
 * \param char* error mensaje que muestra al no respetar lo pedido
 * \param int intentos cantidad de veces que puede intentarlo
 * \param float maximo numero flotante maximo a ingresar
 * \param float minimo numero flotante minimo a ingresar
 * \param float* resultado devuelve el numero flotante ingresado y valido
 * \return int -2 overflow negativo, -1 overflow positivo, 0 todo correcto
 *
 */
float getFloat(char *mensaje, char *error, int intentos, float maximo, float minimo, float *resultado)
{
    int auxiliarFlotante;
    int retorno = -1;
    do
    {
        intentos--;
        printf("%s \n", mensaje);
        scanf("%d \n", &auxiliarFlotante);
        if(auxiliarFlotante >= minimo && auxiliarFlotante <= maximo)
        {
            retorno = 0;
            *resultado = auxiliarFlotante;
            break;
        }
        else
        {
            if(auxiliarFlotante < minimo)
            {
                retorno = -2;
            }
            else
            {
                retorno = -1;
            }
        }
        printf("%s", error);
    }while(intentos >= 0);
}
/** \brief Pide los valores de un array
 *
 * \param char* mensaje mensaje que muestra para pedir
 * \param char* error mensaje que muestra al no respetar lo pedido
 * \param int intentos cantidad de veces que puede intentarlo
 * \param int maximo numero entero maximo a ingresar
 * \param int minimo numero entero minimo a ingresar
 * \param int* resultado devuelve el valor ingresado y valido
 * \return int -1 la cantidad es menor a 0, 0 todo correcto
 *
 */
int getArray(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado, int cantidad)
{
    int retorno = -1;
    int auxiliar;
    int i;
    if(cantidad > 0)
    {
        for(i = 0; i < cantidad; i++)
        {
            if(getInt(mensaje, error, intentos, maximo, minimo, &auxiliar)==0)
            {
                resultado[i] = auxiliar;
            }
        }
    }

    return retorno;
}

/** \brief  Muestra una array
 *
 * \param int *arrayRecibida array a mostrar
 * \param int cantidad tamaño de la array
 * \return int -1 la cantidad es menor a 0, 0 todo correcto
 *
 */
int mostrarArray(int *arrayRecibida, int cantidad)
{
    int retorno = -1;
    int i;
    if(cantidad > 0)
    {
        for(i=0; i < cantidad; i++)
        {
            printf("%d \n", arrayRecibida[i]);
        }
    }
    return retorno;
}

/** \brief ordena de menor a mayor una array
 *
 * \param int *arrayRecibida array a ordenar
 * \param int cantidad tamaño de la array
 * \return int -1 cantidad no valida <0; 0 todo correcto
 *
 */
int ordenarArray(int *arrayRecibida, int cantidad)
{
    int indice=0;
    int retorno = -1;
    int menor,posmenor;
    int arrayaux[cantidad];
    int contador = cantidad;
    int i;
    if(cantidad > 0)
    {
        retorno = 0;
        do
        {
            for(i=0; i<contador;i++)
            {
                if(i==0)
                {
                    menor = arrayRecibida[i];
                    posmenor=i;
                }
                if(menor>arrayRecibida[i])
                {
                    menor= arrayRecibida[i];
                    posmenor=i;
                }
            }
            arrayaux[indice]=menor;
            indice++;
            for(i=posmenor;i<contador;i++)
            {
                arrayRecibida[i]= arrayRecibida[i+1];
            }
            contador--;
        }while (indice<cantidad);
    }

    for(i = 0; i < cantidad; i++)
    {
        arrayRecibida[i] = arrayaux[i];
    }
    return retorno;
}

int ordenarArrayMejorado(int *arrayRecibida, int cantidad)
{
    int retorno = -1;
    int indice, posmenor, aux, minimo;
    indice = 0;
    int i;
    if(cantidad > 0)
    {
        retorno = 0;
        do
        {
            for(i = indice; i < cantidad; i++)
            {
                if(i==indice)
                {
                    minimo = arrayRecibida[i];
                    posmenor = i;
                }
                else
                {
                    if(minimo > arrayRecibida[i])
                    {
                        posmenor = i;
                        minimo = arrayRecibida[i];
                    }
                }
            }
            arrayRecibida[posmenor] = arrayRecibida[indice];
            arrayRecibida[indice] = minimo;
            indice++;
        }while(indice < 4);
    }

    return retorno;
}












float sacarPromedio(int *notaUno, int *notaDos, float *resultado, int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        resultado[i]= ((float)notaUno[i]+notaDos[i]) /2;
    }
    return 0;
}


int mostrar(char apellido[][20], float *promedio, int *notaUno, int *notaDos, int cantidad)
{
    int i;
    for(i = 0; i< cantidad; i++)
    {
        printf("el alumno %s , con notas %d y %d tuvo un promedio de %.2f \n", apellido[i], notaUno[i], notaDos[i], promedio[i] );
    }

    return 0;
}



int ordenarArrayInt(float * promedio, char apellido[][20], int *notaUno,int *notaDos ,int cantidad,int orden)
{
    int i;
    int flagSwap;
    float auxiliar;
    int auxi;
    char auxilio[cantidad][20];

    do
    {
        flagSwap = 0;
        for(i=0;i< cantidad-1;i++)
        {
            if((promedio[i]>promedio[i+1] && orden == 0) || (promedio[i]<promedio[i+1] && orden == 1))
            {
                auxiliar = promedio[i];
                promedio[i] = promedio[i+1];
                promedio[i+1] = auxiliar;


               strcpy(auxilio[i],apellido[i]);
               strcpy(apellido[i], apellido[i+1]);
               strcpy(apellido[i+1],auxilio[i]);

                auxi = notaUno[i];
                notaUno[i] = notaUno[i+1];
                notaUno[i+1] = auxi;

                auxi = notaDos[i];
                notaDos[i] = notaDos[i+1];
                notaDos[i+1] = auxi;



                flagSwap = 1;
            }

        }
    }while(flagSwap);

    return 0;
}
