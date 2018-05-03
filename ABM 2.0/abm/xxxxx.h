#ifndef XXXXX_H_INCLUDED
#define XXXXX_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int isEmpty;
    int dni;

}Xxxx;

void InicializarArry(Xxxx array[], int cantidad_de_elementos);

int obtenerEspacioLibre(Xxxx lista[], int cantidad_de_elementos);

int buscar(Xxxx lista[], int dni, int cantidad_de_elementos);

void xxx_alta(Xxxx lista[], int dni, int edad, char nombre[30]);

void xxx_baja(Xxxx lista[], int cantidad_de_elementos);

void xxx_ordenar(Xxxx lista[], int cantidad_de_elementos, int orden);

void xxx_ordenar(Xxxx lista[], int cantidad_de_elementos, int orden);





#endif // XXXXX_H_INCLUDED
