#ifndef _CLIENTE_H
#define _CLIENTE_H
struct
{
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero;
    char profesion[256];
    char nacionalidad[256];
    char usuario[256];
    int id;
}typedef Cliente;
#endif // _CLIENTE_H


Cliente *cliente_new();
void cliente_delete(Cliente *this);

int cliente_setNombre(Cliente *this, char *nombre);
int cliente_setApellido(Cliente* this, char* apellido);
int cliente_setemail(Cliente* this, char* email);
int cliente_setGenero(Cliente* this, char genero);
int cliente_setProfesion(Cliente* this, char* profesion);
int cliente_setNacionalidad(Cliente* this, char* nacionalidad);
int cliente_setUsuario(Cliente* this, char* usuario);

int cliente_getNombre(Cliente* this, char* nombre);
int cliente_getApellido(Cliente* this, char* apellido);
int cliente_geteMail(Cliente* this, char* email);
int cliente_getGenero(Cliente* this, char* genero);
int cliente_getProfesion(Cliente* this, char* profesion);
int cliente_getNacionalidad(Cliente* this, char* nacionalidad);
int cliente_getUsuario(Cliente* this, char* usuario);
int cliente_getId(Cliente* this,int* id);











Cliente* cliente_newParametrosString(char* strId,char* strName, char* strLastName, char* email, char* genero, char *profesion, char *nacionalidad, char *usuario);


