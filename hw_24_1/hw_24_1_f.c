#include<stdio.h>
//气体的量
#define R 8.314
int main(void)
{
    float P, L, T;
    float n;
    scanf("%f%f%f", &P, &L, &T);

    n = P * L * L * L / (R * T);

    printf("%.4e", n);
}