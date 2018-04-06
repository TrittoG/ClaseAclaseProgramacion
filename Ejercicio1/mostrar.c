
int mostrar(int cantidadElementos, int *arrayRecibido)
{
    int retorno = -1;
    int i;

    if(cantidadElementos>0)
    {
        retorno = 0;
        for(i = 0; i < cantidadElementos; i++)
        {
            printf("%d", arrayRecibido[i]);
        }
    }
    return retorno;
}





int pedir(int elementosArray, int *arrayGenerado)
{
    int retorno;
    retorno = -1;
    int i;
    int auxiliarEnteros;

    if(elementosArray > 0)
    {
        retorno = 0;

        for(i = 0; i < elementosArray; i++)
        {
            getInt("Ingrese un nuero", "error", 2, 100, 0, &auxiliarEnteros);
            arrayGenerado[i]= auxiliarEnteros;
        }


    }

    return retorno;
}








int promedio(int elementos, int *aarray, float *resultado)
{
    int retorno;
    retorno = -1;
    int i;
    float suma;
    suma = 0;

    if(elementos > 0)
    {
        retorno = 0;
        for(i=0;i<elementos;i++)
        {
            suma = aarray[i]+suma;
        }
        *resultado = suma / i;
    }

    return retorno;
}



int maximo(int elementos, int *Array, int *maximo)
{
    int retorno = -1;
    int i;
    int maximon;


    if(elementos >0)
    {
        retorno = 0;
        for(i=0;i<elementos;i++)
        {
            if(i==0)
            {
                maximon = Array[i];
            }
            else
            {
                if(Array[i]>maximon)
                {
                    maximon=Array[i];
                }
            }
        }

        *maximo = maximon;
    }
    return retorno;
}




int mayorMenor(int elementos, int *Array)
{
    int retorno = -1;
    int MAYORES[cantidad];
    if(elementos > 0)
    {
        retorno = 0;



    }



    return retorno;

}


