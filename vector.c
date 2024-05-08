#include "vector.h"

bool redimensionar(Vector* v, int cantPos);
bool insertar(Vector* v, int val, int* pos);
void quitar(Vector* v, int* pos);

bool redimensionar(Vector* v, int cantPos)
{
    int *nv = realloc(v->vec, cantPos * sizeof(int));

    if(!nv)
        return false;

    v->vec = nv;
    v->cap = cantPos;
    return true;
}

bool insertar(Vector* v, int val, int* pos)
{
    if(v->ce == v->cap)
    {
        if(!redimensionar(v, v->cap * 1.5))
            return false;
    }
    for(int* i = v->vec + v->ce; i >= pos; i--)
        *i = *(i-1);
    *pos = val;
    v->ce++;
    return true;
}

void quitar(Vector* v, int* pos)
{
    for(int* i = pos; i < v->vec + v->ce; i++)
        *i = *(i+1);
    v->ce--;
    if(v->cap >= v->ce * 4)
        redimensionar(v, v->cap / 2);
}

// Primitivas

bool vectorCrear(Vector* vector)
{
    vector->vec = malloc(CAP_INICIAL * sizeof(int));

    if(!vector->vec)
        return false;

    vector->ce = 0;
    vector->cap = CAP_INICIAL;
    return true;
}

int vectorInsertarPosicion(Vector* vector, int valor, int posicion)
{
    if(posicion > vector->ce || posicion < 0)
        return FUERA_RANGO;
    for(int* i = vector->vec; i < vector->vec + vector->ce; i++)
        if(*i == valor)
            return DUPLICADO;
    return insertar(vector, valor, vector->vec + posicion) ? TODO_OK : SIN_MEM;
}

int vectorInsertarFin(Vector* vector, int valor)
{
    return vectorInsertarPosicion(vector, valor, vector->ce);
}

int vectorInsertarInicio(Vector* vector, int valor)
{
    return vectorInsertarPosicion(vector, valor, 0);
}

int vectorInsertarOrdenado(Vector* vector, int valor)
{
    int* i = vector->vec;
    while(valor > *i && i < vector->vec + vector->ce)
        i++;
    if(i < vector->vec + vector->ce && *i == valor)
        return DUPLICADO;
    return insertar(vector, valor, i) ? TODO_OK : SIN_MEM;
}

bool vectorQuitarPosicion(Vector* vector, int posicion)
{
    if(posicion >= vector->ce || posicion < 0)
        return false;
    quitar(vector, vector->vec + posicion);
    return true;
}

bool vectorQuitarValor(Vector* vector, int valor)
{
    for(int* i = vector->vec; i < vector->vec + vector->ce; i++)
        if(*i == valor)
        {
            quitar(vector, i);
            return true;
        }
    return false;
}

void vectorVaciar(Vector* vector)
{
    redimensionar(vector, CAP_INICIAL);
    vector->ce = 0;
}

void vectorOrdenar(Vector* vector)
{
    int* ult = vector->vec + vector->ce - 1;
    int aux;
    for(int i = 1; i < vector->ce; i++)
    {
        for(int* j = vector->vec; j < ult; j++)
        {
            if(*j > *(j+1))
            {
                aux = *(j+1);
                *(j+1) = *j;
                *j = aux;
            }
        }
    }
}

void vectorMostrar(const Vector* vector)
{
    printf("[");
    for(int i = 0; i < vector->ce; i++)
    {
        printf("%d", *(vector->vec + i));
        if(i < vector->ce-1)
            printf(", ");
    }
    printf("]");
}

void vectorEliminar(Vector* vector)
{
    free(vector->vec);
}
