#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main()
{
    double y = 0.0;
    double x = 0.0;
    double division = (8 * PI) / 81;

    FILE *archivo;
    archivo = fopen("funcion.txt", "w");

    if (archivo == NULL)
    {
        puts("Error al abrir archivo");
        return -1;
    }

    for (int i = 0; i < 81; i++)
    {

        x = division * i;

        y = pow(sin(x), 2); // y = sen^2(x)

        printf("%d; %f; %f\n", i + 1, x, y);

        fprintf(archivo, "%d; %f; %f\n", i + 1, x, y);
    }

    fclose(archivo);
}