#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main()
{
    float valor, suma, prom, sum_desviaciones_al_cuadrado, varianza, error_cuadratico_medio;
    float muestras[3];
    float error_estadistico[3];

    for (int i = 0; i < 4; i++)
    {
        printf("Ingrese la muestra de ensayo N° %d: ", i + 1);
        scanf("%f", &muestras[i]);

        suma += muestras[i];
    }

    prom = suma / 4;

    for (int i = 0; i < 4; i++)
    {
        error_estadistico[i] = prom - muestras[i];
        sum_desviaciones_al_cuadrado += pow(error_estadistico[i], 2);
        varianza = sum_desviaciones_al_cuadrado / 4;
        error_cuadratico_medio = sqrt(varianza);
    }

    printf("El valor cuadrático medio del error es: %f ", error_cuadratico_medio);

    sleep(3);
}