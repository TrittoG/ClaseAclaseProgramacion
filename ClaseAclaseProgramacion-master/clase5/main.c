#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "libClase5.h"
#define QTY 5

int main()
{
    int desplazar;
    int arrayEnteros[]={1,2,3,4,5};


    desplazar(arrayEnteros,QTY,1,2,3);
    mostrarArrayInt(arrayEnteros,QTY);


    return 0;
}
