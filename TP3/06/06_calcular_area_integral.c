#include <stdio.h>
#include <math.h>

int main()
{
    float x1, x2, base, altura, area;
    int n;

    printf("Ingrese el valor de x1: ");
    scanf("%f", &x1);
    printf("Ingrese el valor de x2: ");
    scanf("%f", &x2);
    printf("Ingrese la cantidad de rectangulos a utilizar: ");
    scanf("%d", &n);

    base = (x2 - x1) / n;

    area = 0.0;
    for (int i = 0; i < n; i++)
    {
        altura = pow(sin(x1 + i * base), 2); // sen^2(x)
        area += base * altura;
    }

    printf("El area bajo la curva es: %f\n", area);
}