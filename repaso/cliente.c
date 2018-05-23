#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>


Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

void cliente_delete(Cliente* this)
{
    free(this);
}

int cliente_setApellido(Cliente *this, char *Apellido)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->apellido, Apellido);
        retorno = 0;
    }
    return retorno;
}

int cliente_setNombre(Cliente *this, char *Nombre)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->nombre, Nombre);
        retorno = 0;
    }
    return retorno;
}

int cliente_getApellido(Cliente *this, char *Apellido)
{
    int retorno = -1;

     if(this != NULL)
    {
        strcpy(Apellido, this->apellido);
         retorno = 0;
    }

    return retorno;

}

int cliente_getNombre(Cliente *this, char *Nombre)
{
    int retorno = -1;

     if(this != NULL)
    {
        strcpy(Nombre, this->nombre);
         retorno = 0;
    }

    return retorno;

}







int cliente_setEdad(Cliente* this,int edad)
{
    int retorno = -1;
    if(this != NULL)// && !validarEdad(edad))
    {
        this->edad = edad;
        retorno = 0;

    }
    return retorno;
}

int cliente_getEdad(Cliente* this,int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        retorno = 0;
    }
    return retorno;
}

static int cliente_getID(Cliente* this,int *id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->idCliente;
        retorno = 0;
    }
    return retorno;
}


static int cliente_setId(Cliente* this)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        ultimoId++;
        this->idCliente = ultimoId;
        retorno = 0;
    }
    return retorno;
}

Cliente* cliente_new2(char nombre[50], char apellido[50], int edad)
{
    Cliente *auxClientes = cliente_new();
    cliente_setNombre(auxClientes,nombre);
    cliente_setApellido(auxClientes,apellido);
    cliente_setEdad(auxClientes,edad);
    cliente_setId(auxClientes);
    return auxClientes;
}



int cliente_alta(Cliente *pArrayClientes[], int *qtyArrayClientes)
{
    char nombre[50];
    char apellido[50];
    int edad;
    int retorno = -1;

    if(pArrayClientes != NULL)
    {
        getStringLetras("ingrese un nombre", nombre);
        getStringLetras("ingrese un apellido",apellido);
        edad = getValidInt("ingrese la edad","erorr", 0,150);

        pArrayClientes[*qtyArrayClientes] = cliente_new2(nombre, apellido, edad);
        *qtyArrayClientes= *qtyArrayClientes +1;


        retorno = 0;
    }
    return retorno;
}



int cliente_mostrar(Cliente **pArrayClientes, int QTY)
{
    char auxNombre[20];
    char auxApellido[20];
    int auxEdad;
    int i;
    int id;
    printf("NOMBRE------APELLIDO------EDAD----id\n");

    // for(i=0;i<QTY; i++)
    //  cliente_getEdad((*(arrayC+i)),auxEdad);
    for(;QTY > 0;pArrayClientes++, QTY--)
    {
        cliente_getNombre(*pArrayClientes, &auxNombre);
        printf("%s          " , auxNombre);

        cliente_getApellido(*pArrayClientes, &auxApellido);
        printf("%s          " , auxApellido);

        cliente_getEdad(*pArrayClientes, &auxEdad);
        printf(" %d         " , auxEdad);

        cliente_getID(*pArrayClientes, &id);
        printf("%d\n",  id);

    }
}

int cliente_posicionPorId(Cliente *pArrayClientes[], int QTY, int id)
{
    int i;
    int auxID;
    int retorno = -1;

    if(pArrayClientes != NULL && id != NULL)
    {    for(i=0;i<QTY;i++)
        {
            cliente_getID((*(pArrayClientes+i)), &auxID);
            if(auxID == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int cliente_modificar(Cliente *pArrayClientes[], int *qtyArrayClientes, int id)
{
    char nombre[50];
    char apellido[50];
    int edad;
    int retorno = -1;
    int indice;

    if(pArrayClientes != NULL && id >= 0)
    {
        indice = cliente_posicionPorId(pArrayClientes, qtyArrayClientes,id);
        getStringLetras("ingrese un nombre", nombre);
        getStringLetras("ingrese un apellido",apellido);
        edad = getValidInt("ingrese la edad","erorr", 0,150);

        pArrayClientes[*qtyArrayClientes] = cliente_new2(nombre, apellido, edad);
        *qtyArrayClientes= *qtyArrayClientes +1;


        retorno = 0;
    }
    return retorno;

}
