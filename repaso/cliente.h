typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[14];
    int edad;
    int idCliente;
}Cliente;

int cliente_mostrar(Cliente **pArrayClientes, int QTY);
int cliente_alta(Cliente **pArrayClientes, int *qtyArrayClientes);
int cliente_getEdad(Cliente* this,int* edad);
int cliente_setEdad(Cliente* this,int edad);
int cliente_getNombre(Cliente *this, char *Nombre);
int cliente_setNombre(Cliente *this, char *Nombre);
int cliente_getApellido(Cliente *this, char *Apellido);
int cliente_setApellido(Cliente *this, char *Apellido);
Cliente* cliente_new2(char nombre[50], char apellido[50], int edad);

Cliente* cliente_new();
void cliente_delete(Cliente* this);

int cliente_posicionPorId(Cliente *pArrayClientes[], int QTY, int id);



