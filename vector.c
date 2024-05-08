#include "vector.h"

bool reestablecerCapacidad(Vector* v, int cantPos);
bool insertarElem(Vector* v, int val, int* pos);
void quitarElem(Vector* v, int* pos);

bool reestablecerCapacidad(Vector* v, int cantPos)
{
    int *nv = realloc(v->vec, cantPos * sizeof(int));

    if(!nv)
        return false;

    v->vec = nv;
    v->cap = cantPos;
    return true;
}

bool insertarElem(Vector* v, int val, int* pos)
{
    if(v->ce == v->cap)
    {
        if(!reestablecerCapacidad(v, v->cap * 1.5))
            return false;
    }
    for(int* i = v->vec + v->ce; i >= pos; i--)
        *i = *(i-1);
    *pos = val;
    v->ce++;
    return true;
}

void quitarElem(Vector* v, int* pos)
{
    for(int* i = pos; i < v->vec + v->ce; i++)
        *i = *(i+1);
    v->ce--;
    if(v->cap >= v->ce * 4)
        reestablecerCapacidad(v, v->cap / 2);
}

bool vectorCrear(Vector* vector)
{
    vector->vec = malloc(MEM_INICIAL * sizeof(int));

    if(!vector->vec)
        return false;

    vector->ce = 0;
    vector->cap = MEM_INICIAL;
    return true;
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

void vectorVaciar(Vector* vector)
{
    reestablecerCapacidad(vector, MEM_INICIAL);
    vector->ce = 0;
}

int vectorInsertarFin(Vector* vector, int valor)
{
    return vectorInsertarPosicion(vector, valor, vector->ce);
}

int vectorInsertarInicio(Vector* vector, int valor)
{
    return vectorInsertarPosicion(vector, valor, 0);
}

int vectorInsertarPosicion(Vector* vector, int valor, int posicion)
{
    if(posicion > vector->ce || posicion < 0)
        return FUERA_RANGO;
    for(int* i = vector->vec; i < vector->vec + vector->ce; i++)
        if(*i == valor)
            return DUPLICADO;
    return insertarElem(vector, valor, vector->vec + posicion) ? TODO_OK : SIN_MEM;
}

int vectorInsertarOrdenado(Vector* vector, int valor)
{
    int* i = vector->vec;
    while(valor > *i && i < vector->vec + vector->ce)
        i++;
    if(i < vector->vec + vector->ce && *i == valor)
        return DUPLICADO;
    return insertarElem(vector, valor, i) ? TODO_OK : SIN_MEM;
}

bool vectorQuitarPosicion(Vector* vector, int posicion)
{
    if(posicion >= vector->ce || posicion < 0)
        return false;
    quitarElem(vector, vector->vec + posicion);
    return true;
}

bool vectorQuitarValor(Vector* vector, int valor)
{
    for(int* i = vector->vec; i < vector->vec + vector->ce; i++)
        if(*i == valor)
        {
            quitarElem(vector, i);
            return true;
        }
    return false;
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
