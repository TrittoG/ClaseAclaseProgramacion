//ejercicio array paralelo
//datos hardcodeados,
//
#include <stdio.h>
#include <stdlib.h>
#include "libr.h"
#define QTY 5

int main()
{
    char apellido[QTY][20]= {"Tritto", "mazzoconi", "cordoba","yema", "gordaiz"};
    int notaUno[QTY] = {10,4,2,9,8};
    int notaDos[QTY] = {1,8,2,8,10};
    float promedio[QTY];

    sacarPromedio(notaUno,notaDos,promedio,QTY);
    mostrar(apellido, promedio,notaUno, notaDos, QTY);

    printf("-------\n");

    ordenarArrayInt(promedio, apellido,notaUno, notaDos, QTY,0);
    mostrar(apellido, promedio,notaUno, notaDos, QTY);

    return 0;
}
