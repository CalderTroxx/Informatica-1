#include <stdio.h>

int calcular_dias(int dia, int mes)
{
    int dias_meses[] = {31, 28, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31};

    int cantidad_dias = 0;

    for (int i = 1; i < mes; i++)
    {
        cantidad_dias += dias_meses[i];
    }
    cantidad_dias += dia;
    return cantidad_dias;
}

int main()
{
    int dia, mes;
    printf("Ingrese el dia: ");
    scanf("%d", &dia);

    printf("Ingrese el mes:");
    scanf("%d", &mes);

    printf("La cantidad de dias es: %d", calcular_dias(dia, mes));
}