#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main()
{
    float division = (4 * PI) / 50;
    const float pre = 0.1;
    float valor, x, h, fun, fun_, der;

    for (int i = 0; i < 50; i++)
    {

        x = division * i;

        fun = sin(x); // f(x) = y = sen(x)

        printf("%d; %f; %f\n", i + 1, x, fun);
    }

    printf("Introducir el punto en el que calcular la derivada: ");
    scanf("%f", &valor);

    h = pre;
    x = valor;

    for (int i = 0; i < 5; i++)
    {
        fun = sin(x);           // f(x) = y = sen(x)
        fun_ = sin(x + h);      // f(x + h) = sen(x + h);
        der = (fun_ - fun) / h; // f`(x) = (f(x + h) - f(x)) / h

        printf(" %12f; %.5f; %12f \n", fun, h, der);
        h = h * pre;
    }
}