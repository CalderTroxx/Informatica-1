#include <stdio.h>
#include <string.h>

int buscar_vocales(char cadena[], char letra)
{
    int count = 0;

    for (int i = 0; i <= strlen(cadena); i++)
    {
        if (cadena[i] == letra)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char cadena[22] = {'i', 'n', 'g', 'e', 'n', 'i', 'e', 'r', 'i', 'a', ' ', 'e', 'l', 'e', 'c', 't', 'r', 'o', 'n', 'i', 'c', 'a'};

    printf("La cadena: [%s], contiene %d vocales a \n", cadena, buscar_vocales(cadena, 'a'));
    printf("La cadena: [%s], contiene %d vocales e \n", cadena, buscar_vocales(cadena, 'e'));
    printf("La cadena: [%s], contiene %d vocales i \n", cadena, buscar_vocales(cadena, 'i'));
    printf("La cadena: [%s], contiene %d vocales o \n", cadena, buscar_vocales(cadena, 'o'));
    printf("La cadena: [%s], contiene %d vocales u \n", cadena, buscar_vocales(cadena, 'u'));
}