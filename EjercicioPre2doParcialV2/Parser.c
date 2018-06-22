#include "Empleado.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    Empleado *auxEmpleado;
    int retorno = -1;
    FILE *pFile;

    char nombre[1000];
    char horas[1000];
    char id[1000];

    if(fileName != NULL)
    {

        pFile = fopen(fileName, "r");
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id, nombre, horas);


        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id, nombre, horas);
            //printf("\n%s %s %s", id, nombre, horas);
            auxEmpleado = Empleado_newParametros(id, nombre, horas);
            al_add(listaEmpleados, auxEmpleado);

        }
    }
    printf("\n %d", al_len(listaEmpleados));

    fclose(pFile);

    return 1; // OK
}

