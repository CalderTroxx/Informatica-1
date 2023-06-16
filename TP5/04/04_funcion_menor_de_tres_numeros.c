#include <stdio.h>

float menor_numero(float num_1, float num_2, float num_3)
{

    if (num_1 > num_2)
    {
        if (num_1 > num_3)
        {
            return num_1;
        }
        else
        {
            return num_3;
        }
    }
    else if (num_2 > num_3)
    {
        return num_2;
    }
    else
    {
        return num_3;
    }
}

int main()
{
    printf("El numero mayor es: %.2f", menor_numero(34.67, 65.32, 65.33));
}