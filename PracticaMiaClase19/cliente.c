#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

Cliente *cliente_new()
{
    Cliente *auxCliente = NULL;
    auxCliente = (Cliente*)malloc(sizeof(Cliente));
    return auxCliente;
}


void cliente_delete(Cliente *this)
{
    if(this != NULL)
        free(this);
}


int cliente_setNombre(Cliente *this, char *nombre)
{
    int retorno=-1;
    if(this != NULL && nombre != NULL) //&& isValidName(nombre))
    {
            retorno = 0;
            strcpy(this->nombre,nombre);
    }
    return retorno;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno=-1;
    if(this != NULL && apellido != NULL) // && isValidApellido(apellido))
    {
            retorno = 0;
            strcpy(this->apellido,apellido);
    }
    return retorno;
}

int cliente_setemail(Cliente* this, char* email)
{
    int retorno=-1;
    if(this != NULL && email != NULL) // && isValidApellido(apellido))
    {
            retorno = 0;
            strcpy(this->email,email);
    }
    return retorno;
}

int cliente_setGenero(Cliente* this, char genero)
{
    int retorno=-1;
    if(this != NULL ) // && isValidApellido(apellido))
    {
            retorno = 0;
            this->genero = genero;
    }
    return retorno;
}

int cliente_setProfesion(Cliente* this, char* profesion)
{
    int retorno=-1;
    if(this != NULL && profesion != NULL) // && isValidApellido(apellido))
    {
            retorno = 0;
            strcpy(this->profesion,profesion);
    }
    return retorno;
}

int cliente_setNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno=-1;
    if(this != NULL && nacionalidad != NULL) // && isValidApellido(apellido))
    {
            retorno = 0;
            strcpy(this->nacionalidad,nacionalidad);
    }
    return retorno;
}

int cliente_setUsuario(Cliente* this, char* usuario)
{
    int retorno=-1;
    if(this != NULL && usuario != NULL) // && isValidApellido(apellido))
    {
            retorno = 0;
            strcpy(this->usuario,usuario);
    }
    return retorno;
}

int cliente_setId(Cliente* this, int id)
{
    static int ultimoId = -1;
    int retorno=-1;
    if(this != NULL)
    {
        retorno = 0;
        if(id > 0)
        {
            this->id = id;
            if(id > ultimoId)
                ultimoId = id;
        }
        else
        {
            ultimoId++;
            this->id =  ultimoId;
        }
    }
    return retorno;
}


int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno=-1;
    if(this != NULL)
    {
            retorno = 0;
            strcpy(nombre,this->nombre);
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno=-1;
    if(this != NULL)
    {
            retorno = 0;
            strcpy(apellido,this->apellido);
    }
    return retorno;
}

int cliente_geteMail(Cliente* this, char* email)
{
    int retorno=-1;
    if(this != NULL)
    {
            retorno = 0;
            strcpy(email,this->email);
    }
    return retorno;
}

int cliente_getGenero(Cliente* this, char* genero)
{
    int retorno=-1;
    if(this != NULL)
    {
            retorno = 0;
           *genero=this->email;
    }
    return retorno;
}

int cliente_getProfesion(Cliente* this, char* profesion)
{
    int retorno=-1;
    if(this != NULL)
    {
            retorno = 0;
            strcpy(profesion,this->profesion);
    }
    return retorno;
}

int cliente_getNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno=-1;
    if(this != NULL)
    {
            retorno = 0;
            strcpy(nacionalidad,this->nacionalidad);
    }
    return retorno;
}

int cliente_getUsuario(Cliente* this, char* usuario)
{
    int retorno=-1;
    if(this != NULL)
    {
            retorno = 0;
            strcpy(usuario,this->usuario);
    }
    return retorno;
}

int cliente_getId(Cliente* this,int* id)
{
    int retorno=-1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}




Cliente* cliente_newParametrosString(char* strId,char* strName, char* strLastName, char* email, char* genero, char *profesion, char *nacionalidad, char *usuario)
{
    Cliente* this;
    int id; // FALTA VALIDAR
    id = atoi(strId); // FALTA VALIDAR

    this = cliente_new();
    cliente_setId(this,id);
    cliente_setNombre(this,strName);
    cliente_setApellido(this,strLastName);
    cliente_setemail(this,email);
    cliente_setGenero(this,genero);
    cliente_setProfesion(this,profesion);
    cliente_setNacionalidad(this,nacionalidad);
    cliente_setUsuario(this,usuario);

    return this;
}




