#include "fecha.h"

int cantDiasMes(int mes, int anio);
int cantDiasAnio(int anio);
int diasTotales(const Fecha* fecha);
bool esBisiesto(int anio);

Fecha fechaCrear(int dia, int mes, int anio)
{
    Fecha f;
    f.dia = dia;
    f.mes = mes;
    f.anio = anio;
    return f;
}

int cantDiasMes(int mes, int anio)
{
    if(mes == 2 && esBisiesto(anio))
        return 29;

    int cd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
    return cd[mes];
}

int cantDiasAnio(int anio)
{
    return 365 + esBisiesto(anio);
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

bool esBisiesto(int anio)
{
    return anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0);
}

void fechaMostrar(const Fecha* fecha)
{
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
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

int diaDelAnio(const Fecha* fecha)
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

Fecha diaDelAnioAFecha(int diaDelAnio, int anio)
{
    if(diaDelAnio < 1 || (!esBisiesto(anio) && diaDelAnio > 365) || (esBisiesto && diaDelAnio > 366))
        return;
    Fecha f = fechaCrear(1, 1, anio);
    while(diaDelAnio > 1)
    {
        f = fechaSumarDias(&f, 1);
        diaDelAnio--;
    }
    return f;
}

int diaDeLaSemana(const Fecha* fecha)
{
    return diaDelAnio(fecha) % 7;
}
