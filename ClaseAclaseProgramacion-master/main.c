#include <stdio.h>
#include <string.h>
#include "funcs.h"

int main(void)
{
    int edad;



    if(getInt("Edad?","Fuera de rango",2,0,199,&edad)==0)
    {
        printf("La edad es %d",edad);
    }
    else
    {
        printf("Error");
    }



    return 0;
}
