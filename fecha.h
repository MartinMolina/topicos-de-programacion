#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdbool.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

Fecha fechaCrear(int dia, int mes, int anio);
void fechaMostrar(const Fecha* fecha);
Fecha fechaSumarDias(const Fecha* fecha, int dias);
Fecha fechaRestarDias(const Fecha* fecha, int dias);
int fechaDiferencia(const Fecha* fecha1, const Fecha* fecha2);
int diaDelAnio(const Fecha* fecha);
Fecha diaDelAnioAFecha(int diaDelAnio, int anio);
int diaDeLaSemana(const Fecha* fecha);

#endif // FECHA_H_INCLUDED
