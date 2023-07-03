#include <stdio.h>
#include <string.h>

int concat(char cadena_1[], char cadena_2[])
{

    printf("Su cadena 1 es: %s \n", cadena_1);
    printf("Su cadena 2 es: %s \n", cadena_2);

    char cadena[30];
    for (int i = 0; i <= strlen(cadena_1); i++)
    {
        cadena[i] = cadena_1[i];
    }
    for (int i = strlen(cadena_1); i <= (strlen(cadena_1) + strlen(cadena_2)); i++)
    {
        cadena[i] = cadena_2[i - strlen(cadena_1)];
    }

    printf("Su cadena es: %s \n", cadena);
}

int main()
{
    char cadena_1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char cadena_2[7] = {'W', 'o', 'r', 'l', 'd', '!', '\0'};

    concat(cadena_1, cadena_2);
}