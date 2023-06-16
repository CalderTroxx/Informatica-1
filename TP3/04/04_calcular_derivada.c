#include <stdio.h>
#include <math.h>

int main()
{
    const float pre = 0.1;
    float valor, x, h, fun, fun_, der;

    printf("Introducir en punto en el que calcular la derivada: ");
    scanf("%f", &valor);

    h = pre;
    x = valor;

    for (int i = 0; i < 5; i++)
    {
        fun = pow(sin(x), 2);      // f(x) = y = sen^2(x)
        fun_ = pow(sin(x + h), 2); // f(x + h) = sen^2(x + h);

        der = (fun_ - fun) / h; // f`(x) = (f(x + h) - f(x)) / h

        printf(" [%12f] [%.5f] [%12f] \n", fun, h, der);
        h = h * pre;
    }
}