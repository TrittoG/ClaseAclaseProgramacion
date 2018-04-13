#include <stdio.h>
#include <stdlib.h>
#define cantidad 10

int main()
{
    char caracter;
    int i;
    int contA=0;
    int contE=0;
    int contI=0;
    int contO=0;
    int contU=0;

    for(i=0;i<cantidad;i++)
    {

            printf("ingrese un caracter \n");
            fflush(stdin);
            scanf("%c" ,&caracter);


        switch(caracter)
        {
        case 'a' :
        case 'A' :
            contA++;
            break;
        case 'e':
        case 'E':
            contE++;
            break;
        case 'i' :
        case 'I':
            contI++;
            break;
        case 'o' :
        case 'O':
            contO++;
            break;
        case 'u' :
        case 'U':
            contU++;
            break;

            }



    }
    printf("se ingresaron %d a \t %d e \t %d \t i %d \t o %d u", contA, contE,contI, contO, contU);

    return 0;
}
