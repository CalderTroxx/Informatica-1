#include <stdio.h>
#include <math.h>

int main()
{
    float arr[20];
    float valor = 0, suma = 0, prom = 0, sum_desviaciones_al_cuadrado = 0, varianza = 0, error_cuadratico_medio = 0;
    float error_estadistico[20];

    FILE *archivo;
    archivo = fopen("archivo.txt", "r");

    if (archivo == NULL)
    {
        puts("Error al abrir archivo");
        return -1;
    }

    for (int i = 0; i < 10; i++)
    {
        fscanf(archivo, "%f", &arr[i]);
        printf("[%f]", arr[i]);
    }
    fclose(archivo);

    for (int i = 0; i < 20; i++)
    {
        suma += arr[i];
    }

    prom = suma / 20;

    for (int i = 0; i < 20; i++)
    {
        error_estadistico[i] = prom - arr[i];
        sum_desviaciones_al_cuadrado += pow(error_estadistico[i], 2);
    }

    varianza = sum_desviaciones_al_cuadrado / (20);
    error_cuadratico_medio = sqrt(varianza);

    printf("\nEl valor cuadrático medio del error es: %f ", error_cuadratico_medio);
    return 0;
}