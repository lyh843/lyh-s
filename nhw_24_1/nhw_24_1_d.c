#include<stdio.h>
//求万有引力
int main(void)
{
    const float M = 77.15;
    const float G = 6.674e-11;
    float m, R, N;
    scanf("%f%f", &m, &R);
    
    N = G * M * m / (R * R);
    printf("%e\n", G);
    printf("%.3e\n", N);
}
