#include "fecha.h"

bool esBisiesto(int a);
int cantDiasMes(int m, int a);
int cantDiasAnio(int a);
int diasTotales(const Fecha* fecha);

bool esBisiesto(int a)
{
    return a % 4 == 0 && (a % 100 != 0 || a % 400 == 0);
}

int cantDiasMes(int m, int a)
{
    if(m == 2 && esBisiesto(a))
        return 29;

    int cd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
    return cd[m];
}

int cantDiasAnio(int a)
{
    return 365 + esBisiesto(a);
}

int diasTotales(const Fecha* fecha)
{
    Fecha f = *fecha;
    int d = 0;
    while(f.anio > 1)
    {
        d += cantDiasAnio(f.anio);
        f = fechaRestarDias(&f, cantDiasAnio(f.anio));
    }
    while(f.mes > 1)
    {
        d += cantDiasMes(f.mes, f.anio);
        f = fechaRestarDias(&f, cantDiasMes(f.mes, f.anio));
    }
    while(f.dia > 1)
    {
        d++;
        f = fechaRestarDias(&f, 1);
    }
    return d;
}

// Primitivas

Fecha fechaCrear(int dia, int mes, int anio)
{
    Fecha f;
    f.dia = dia;
    f.mes = mes;
    f.anio = anio;
    return f;
}

Fecha fechaSumarDias(const Fecha* fecha, int dias)
{
    Fecha f = *fecha;
    f.dia += dias;

    while(f.dia > cantDiasMes(f.mes, f.anio))
    {
        f.dia -= cantDiasMes(f.mes, f.anio);
        f.mes++;
        if(f.mes > 12)
        {
            f.mes = 0;
            f.anio++;
        }
    }
    return f;
}

Fecha fechaRestarDias(const Fecha* fecha, int dias)
{
    Fecha f = *fecha;
    f.dia -= dias;

    while(f.dia < 1)
    {
        f.mes--;
        if(f.mes < 1)
        {
            f.mes = 12;
            f.anio--;
        }
        f.dia += cantDiasMes(f.mes, f.anio);
    }
    return f;
}

int fechaDiferencia(const Fecha* fecha1, const Fecha* fecha2)
{
    return diasTotales(fecha1) - diasTotales(fecha2);
}

Fecha fechaDiaDelAnioAFecha(int dia, int anio)
{
    if(dia < 1 || (!esBisiesto(anio) && dia > 365) || (esBisiesto && dia > 366))
        return;
    Fecha f = fechaCrear(1, 1, anio);
    while(dia > 1)
    {
        f = fechaSumarDias(&f, 1);
        dia--;
    }
    return f;
}

int fechaFechaADiaDelAnio(const Fecha* fecha)
{
    Fecha f = fechaCrear(1, 1, fecha->anio);
    int d = 1;
    while(f.mes < fecha->mes || f.dia < fecha->dia)
    {
        f = fechaSumarDias(&f, 1);
        d++;
    }
    return d;
}

int fechaDiaDeLaSemana(const Fecha* fecha)
{
    return fechaFechaADiaDelAnio(fecha) % 7;
}

void fechaMostrar(const Fecha* fecha)
{
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
}
