#include <stdio.h>
#include <math.h>

float calcular_raices(float a, float b, float c, int eleccion_raiz)
{
    float d, x1, x2;
    d = pow(b, 2) - 4 * a * c;

    if (d <= 0)
    {
        printf("El valor del discriminante es inválido para raices reales. ");
    }
    else
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        if (eleccion_raiz == 1)
        {
            return x1;
        }
        else if (eleccion_raiz == 2)
        {
            return x2;
        }
        else
        {
            printf("La opcion ingresada para la raiz es invalida.\n");
        }
    }
}

int main()
{
    float a, b, c;
    int eleccion_raiz;

    printf("Ingrese el valor para el coeficiente a: ");
    scanf("%f", &a);

    printf("Ingrese el valor para el coeficiente b: ");
    scanf("%f", &b);

    printf("Ingrese el valor para el coeficiente c: ");
    scanf("%f", &c);

    printf("Ingrese 1 para ver la primera raiz, 2 para ver la segunda raiz: ");
    scanf("%d", &eleccion_raiz);

    printf("El valor de la raiz seleccionada es: %.2f", calcular_raices(a, b, c, eleccion_raiz));
}