//pedir 10 numeros y guardar en array en main
//en funcion muestre l oque hay en el array, y cantidad maxima del array

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define QTY 5

int main()
{
    int ARRAYNUMEROS[QTY];
    float resultado;
    int max;

    pedir(QTY, ARRAYNUMEROS);
    mostrar(QTY, ARRAYNUMEROS);
    promedio(QTY, ARRAYNUMEROS, &resultado);
    printf("\n %.2f" ,resultado);
    maximo(QTY,ARRAYNUMEROS,&max);
    printf("\n %d", max);
}
