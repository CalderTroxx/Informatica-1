#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main()
{
    int A[36];
    double S[36];
    double P[36];

    for (int i = 0; i < 36; i++)
    {
        A[i] = (i + 1) * 10;
        S[i] = sin(((A[i] * PI) / 180));
    }
    for (int i = 0; i < 33; i++)
    {
        P[i] = (S[i] + S[i + 1] + S[i + 2]) / 3;
    }

    for (int i = 0; i < 36; i++)
    {
        printf("[%d], [%lf]", A[i], S[i]);
        if (i < 33)
        {
            printf(", [%lf] \n", P[i]);
        }
    }
}