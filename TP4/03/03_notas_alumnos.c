#include <stdio.h>

int main()
{
    float notas_alumnos[9];
    float sum, prom;
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Ingrese la nota del alumno N° %d: ", i + 1);
        scanf("%f", &notas_alumnos[i]);

        sum += notas_alumnos[i];
    }
    prom = sum / 10;

    for (int i = 0; i < 10; i++)
    {
        if (notas_alumnos[i] > prom)
        {
            count++;
        }
    }

    printf("La cantidad de alumnos que obtuvieron notas por encima del promedio es: %d \n", count);
    printf("La cantidad de alumnos que obtuvieron notas por debajo del promedio es: %d", 10 - count);
}