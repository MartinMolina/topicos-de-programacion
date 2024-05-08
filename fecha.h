#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdbool.h>

// TDA

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

// Primitivas

Fecha fechaCrear(int dia, int mes, int anio);

Fecha fechaSumarDias(const Fecha* fecha, int dias);
Fecha fechaRestarDias(const Fecha* fecha, int dias);

int fechaDiferencia(const Fecha* fecha1, const Fecha* fecha2);

Fecha fechaDiaDelAnioAFecha(int diaDelAnio, int anio);
int fechaFechaADiaDelAnio(const Fecha* fecha);
int fechaDiaDeLaSemana(const Fecha* fecha);

void fechaMostrar(const Fecha* fecha);

#endif // FECHA_H_INCLUDED
