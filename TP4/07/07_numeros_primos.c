#include <stdio.h>

int main()
{
    int numeros_primos[20];
    int count = 1;
    int primos = 0;
    int flag_no_primo = 0;

    while (primos <= 20)
    {
        for (int i = 2; i < count; i++)
        {
            if (count % i == 0)
            {
                flag_no_primo = 1;
            }
        }
        if (flag_no_primo == 0)
        {
            numeros_primos[primos] = count;
            primos++;
        }
        count++;
        flag_no_primo = 0;
    }

    printf(" Primos: ");

    for (int i = 0; i < 20; i++)
    {
        printf("[%d]", numeros_primos[i]);
    }
}