#include "Empleado.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Empleado* Empleado_new()
{
    Empleado* this;
    this = malloc(sizeof(Empleado));
    return this;
}

Empleado* Empleado_newParametros(char* idStr, char *nombreStr, char *horasStr)
{
    Empleado* this;
    this = Empleado_new();
    int id;
    char nombre[128];
    int horasTrabajadas;

    //una vez validado!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    id = atoi(idStr);
    strcpy(nombre, nombreStr);
    horasTrabajadas = atoi(horasStr);

    Empleado_setId(this, id);
    Empleado_setNombre(this, nombre);
    Empleado_setHorasTrabajadas(this,horasTrabajadas);

    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}


int em_calcularSueldo(void *p)
{
    int retorno= -1;
    int valor;
    int horasTrabajadas;
    int sueldo;

    if(p != NULL)
    {
        Empleado_getHorasTrabajadas(p, &horasTrabajadas);

        if(horasTrabajadas < 120)
        {
            valor = 180;
            sueldo = horasTrabajadas * valor;
            retorno =0;
        }
        else if(horasTrabajadas < 160)
        {

            valor = 240;
            sueldo = horasTrabajadas * valor;

            retorno = 0;


        }
        else if(horasTrabajadas < 240)
        {
            valor = 350;
            sueldo = horasTrabajadas * valor;
            retorno = 0;
        }

        Empleado_setSueldo(p, sueldo);
    }
    return retorno;
}

