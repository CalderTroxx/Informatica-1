#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main()
{
    float y = 0;
    float x = 0;
    float division = (4 * PI) / 50;

    for (int i = 0; i < 50; i++)
    {

        x = division * i;

        // x = x / 57.2957795;

        y = sin(x) + 0.7 * cos(2 * x) + 0.5 * sin(3 * x);

        printf("%d; %f; %f\n", i + 1, x, y);
    }
}
