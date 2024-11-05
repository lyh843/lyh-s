#include<stdio.h>
#include<math.h>

int main(void)
{
    float x = 1.0;
    int i = 1;
    double y = 0;
    for(int i = 0; i <= 1; i++)
    {
        y += 4 * pow(x, 2 * i + 1) / (2 * i + 1);
    }
    printf("%f", y);
}