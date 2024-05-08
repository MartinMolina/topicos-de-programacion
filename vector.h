#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#define MEM_INICIAL 10
#define TODO_OK 0
#define SIN_MEM 1
#define FUERA_RANGO 2
#define DUPLICADO 3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int* vec;
    int ce;
    int cap;
} Vector;

bool vectorCrear(Vector* vector);
void vectorMostrar(const Vector* vector);
void vectorEliminar(Vector* vector);
void vectorVaciar(Vector* vector);
int vectorInsertarFin(Vector* vector, int valor);
int vectorInsertarInicio(Vector* vector, int valor);
int vectorInsertarPos(Vector* vector, int valor, int posicion);
int vectorInsertarOrdenado(Vector* vector, int valor);
bool vectorQuitarPosicion(Vector* vector, int posicion);
bool vectorQuitarValor(Vector* vector, int valor);
void vectorOrdenar(Vector* vector);

#endif // VECTOR_H_INCLUDED
