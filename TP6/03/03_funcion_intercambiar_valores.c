#include <stdio.h>

void intercambiar_valores(int X1, int X2)
{
    int mem = 0;

    mem = X1;
    X1 = X2;
    X2 = mem;

    printf("Los valores de X1 y X2 ahora son: %d, %d \n", X1, X2);
}

int main()
{
    int X1 = 10;
    int X2 = 20;

    printf("El valor de X1 y X2 son: %d, %d \n", X1, X2);
    intercambiar_valores(X1, X2);
}