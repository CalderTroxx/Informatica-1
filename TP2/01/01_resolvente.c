#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, d, x1, x2;

    printf("Ingrese el valor para el coeficiente a: ");
    scanf("%f", &a);

    printf("Ingrese el valor para el coeficiente b: ");
    scanf("%f", &b);

    printf("Ingrese el valor para el coeficiente c: ");
    scanf("%f", &c);

    d = pow(b, 2) - 4 * a * c;

    if (d <= 0)
    {
        printf("El valor del discriminante es inválido para raices reales. ");
    }
    else
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("El valor de la primera raiz es: %.2f\n", x1);
        printf("El valor de la segunda raiz es: %.2f\n", x2);
    }
}