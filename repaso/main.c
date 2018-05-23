#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "utn.h"
#define QTY 50

int main()
{
    //Cliente arrayClientes[50];

    Cliente* pArrayClientes;

    pArrayClientes = (Cliente*) malloc(sizeof(Cliente));

    int qtyArrayClientes=0;

    //cliente_alta(pArrayClientes, &qtyArrayClientes);
    cliente_alta(pArrayClientes, &qtyArrayClientes);

    cliente_mostrar(pArrayClientes, qtyArrayClientes);

    return 0;
}
