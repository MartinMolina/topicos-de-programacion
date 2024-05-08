#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAP_INICIAL 10

#define TODO_OK 0
#define SIN_MEM 1
#define FUERA_RANGO 2
#define DUPLICADO 3

// TDA

typedef struct
{
    int* vec;
    int ce;
    int cap;
} Vector;

//Primitivas

bool vectorCrear(Vector* vector);

int vectorInsertarPosicion(Vector* vector, int valor, int posicion);
int vectorInsertarFin(Vector* vector, int valor);
int vectorInsertarInicio(Vector* vector, int valor);
int vectorInsertarOrdenado(Vector* vector, int valor);

bool vectorQuitarPosicion(Vector* vector, int posicion);
bool vectorQuitarValor(Vector* vector, int valor);

void vectorVaciar(Vector* vector);
void vectorOrdenar(Vector* vector);
void vectorMostrar(const Vector* vector);

void vectorEliminar(Vector* vector);

#endif // VECTOR_H_INCLUDED
