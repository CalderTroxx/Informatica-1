#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main()
{
    double y = 0.0;
    double x = 0.0;
    double division = (8 * PI) / 81;

    double arr[81];
    double der[81];

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

        y = sin(4 * x); // y = sen^2(x)

        // printf("%d; %f; %f\n", i + 1, x, y);

        fprintf(archivo, "%lf\n", y);
    }

    fclose(archivo);

    archivo = fopen("funcion.txt", "r");

    if (archivo == NULL)
    {
        puts("Error al abrir archivo");
        return -1;
    }

    for (int i = 0; i < 81; i++)
    {
        fscanf(archivo, "%lf", &arr[i]);
        printf("[%lf]\n", arr[i]);
    }
    fclose(archivo);

    const float pre = 0.1;
    float h, fun, fun_;

    h = pre;

    for (int i = 0; i < 81; i++)
    {

        x = division * i;

        fun = arr[i];
        fun_ = sin(4 * (x + h));

        der[i] = (fun_ - fun) / h; // f`(x) = (f(x + h) - f(x)) / h

        printf(" [%12f] [%.5f] [%12lf] \n", fun, h, der[i]);
    }

    archivo = fopen("derivadas.txt", "w");

    if (archivo == NULL)
    {
        puts("Error al abrir archivo");
        return -1;
    }

    for (int i = 0; i < 81; i++)
    {
        fprintf(archivo, "%lf\n", der[i]);
    }

    fclose(archivo);
}