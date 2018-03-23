#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int main()
{

    int numero;
    float promedio;
    float suma;
    int i;
    suma = 0;
    int mayor;
    int menor;
    int flag = 0;

    for(i= 1;i < CANTIDAD+1;i++)
    {
    //printf("ingrese un numero mayor que 0 \n");
    //scanf("%d", &numero);
    do//valido numero uno
    {
        printf("ingrese un numero mayor que 0 \n");
        scanf("%d", &numero);
    }while(numero <= 0);

    if(flag == 0)
    {
        mayor= numero;
        menor = numero;
    }
    else
    {
         if(numero < menor)
        {
            menor = numero;
        }
        else
        {
            if(numero > mayor)
            {
                mayor = numero;
            }
        }
    }

    flag++;

    suma = suma + numero;
    }//fin del for

    promedio = suma/3;

    printf("el promedio es: %.2f \n" , promedio);
    printf("el numero maximo es %d y el minimo es %d" ,mayor ,menor);


    return 0;
}
