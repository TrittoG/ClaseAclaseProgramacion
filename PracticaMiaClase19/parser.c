#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "cliente.h"
#include "parser.h"
#include "utn.h"
#include <string.h>


int parserCliente(char* path , ArrayList* pArrayListClientes)
{
    int retorno = -1;
    Cliente *auxiliarCliente;
    FILE *pFile;
    int r;

    char nombre[4000];
    char apellido[4000];
    char email[4000];
    char genero[4000];
    char profesion[4000];
    char nacionalidad[4000];
    char usuario[4000];
    char id[4000];


    pFile = fopen(path,"r");

    if(pFile!= NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,email,genero,profesion,usuario,nacionalidad);

        retorno = 0;
        while(!feof(pFile))
        {
            r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,email,genero,profesion,usuario,nacionalidad);
            if(r==8)
            {
                //auxid = atoi(id);
                auxiliarCliente = cliente_newParametrosString(id,nombre,apellido,email,genero,profesion,nacionalidad,usuario);

                al_add(pArrayListClientes,auxiliarCliente);
            }
        }




    }

    fclose(pFile);
    return retorno;
}


int cliente_listarClientes(ArrayList *pArrayClientes)
{
    int retorno = -1;
    int i;
    Cliente* auxCliente;

    char nombre[64];
    char apellido[64];
    char mail[100];

    for(i=0;i<al_len(pArrayClientes);i++)
    {
        retorno = 0;
        auxCliente = al_get(pArrayClientes, i);
        cliente_getNombre(auxCliente, nombre);
        cliente_getApellido(auxCliente,apellido);
        cliente_geteMail(auxCliente,mail);
        printf("NOMBRE : %s  APELLIDO: %s MAIL: %s\n", nombre, apellido,mail);
    }
    return retorno;
}

int  controller_ordenarClientesNombre(ArrayList *pArrayClientes)
{
    int  retorno = -1;
    if (al_sort(pArrayClientes,comparaPersonasPorNombreyApellido,1)== 0)
    {
        printf("lista creada correctamente");
        retorno = 0;
    }

    return retorno;

}

int comparaPersonasPorNombreyApellido(void* clienteA, void* clienteB)
{
    char nombreA[64];
    char nombreB[64];
    int retorno;

    cliente_getNombre(clienteA,nombreA);
    cliente_getNombre(clienteB,nombreB);

    retorno = strcmp(nombreA,nombreB);

    if(!retorno)
    {
        char apellidoA[64];
        char apellidoB[64];

        cliente_getApellido(clienteA,apellidoA);
        cliente_getApellido(clienteB,apellidoB);

        retorno = strcmp(apellidoA,apellidoB);
    }
    return retorno;
}

int comparaPersonasPoreMail(void* clienteA, void* clienteB)
{
    char mailA[64];
    char mailB[64];
    int retorno;

    cliente_geteMail(clienteA,mailA);
    cliente_geteMail(clienteB,mailB);

    retorno = strcmp(mailA,mailB);
}

int  controller_ordenareMail(ArrayList *pArrayClientes)
{
    int  retorno = -1;
    if (al_sort(pArrayClientes,comparaPersonasPoreMail,1)== 0)
    {
        printf("lista creada correctamente");
        retorno = 0;
    }

    return retorno;

}

int controller_agregarCliente(ArrayList *pArrayClientes)
{
    Cliente *auxCliente;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero;
    char profesion[256];
    char nacionalidad[256];
    char usuario[256];
    int id;

    getValidString("ingese un nombre","error","overflow",nombre,100,3);
    getValidString("ingese un apellido","error","overflow",apellido,100,3);
    getValidString("ingese un email","error","overflow",email,100,3);
    getValidString("ingese un genero","error","overflow",&genero,2,3);
    getValidString("ingese un profesion","error","overflow",profesion,100,3);
    getValidString("ingese un nacionalidad","error","overflow",nacionalidad,100,3);
    getValidString("ingese un usuairo","error","overflow",usuario,100,3);
    getValidInt("ingrese id","error",&id,-4,6000,4);


    cliente_setNombre(auxCliente,nombre);
    cliente_setApellido(auxCliente,apellido);
    cliente_setemail(auxCliente,email);
    cliente_setGenero(auxCliente,&genero);
    cliente_setProfesion(auxCliente,profesion);
    cliente_setNacionalidad(auxCliente,nacionalidad);
    cliente_setUsuario(auxCliente,usuario);
    cliente_setId(auxCliente,id);




    if(al_add(pArrayClientes,auxCliente)==0)
    {
        printf("se a creado correctamente");
    }
}


int controller_guardarClientes(char *path, ArrayList *pArrayClientes)
{
    int retorno = -1;
    int i;
    Cliente* auxCliente;

    char nombre[64];
    char apellido[64];
    char email[256];
    char genero;
    char profesion[256];
    char nacionalidad[256];
    char usuario[256];
    int id;
    FILE* pFile;
    pFile = fopen(path, "w");

    if(pFile != NULL)
    {
            for(i=0;i<al_len(pArrayClientes);i++)
            {
            retorno = 0;
            auxCliente = al_get(pArrayClientes, i);
            cliente_getNombre(auxCliente, nombre);
            cliente_getApellido(auxCliente,apellido);
            cliente_geteMail(auxCliente, email);
            cliente_getGenero(auxCliente, &genero);
            cliente_getProfesion(auxCliente, profesion);
            cliente_getNacionalidad(auxCliente, nacionalidad);
            cliente_getUsuario(auxCliente, usuario);
            cliente_getId(auxCliente, &id);




            fprintf(stdout, " %d  %s  %s  %s  %s  %s  %c  %s \n", id, nombre, apellido,email,genero,profesion,nacionalidad,usuario);
            }
    }


    return retorno;
}
