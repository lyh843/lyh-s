#include<stdio.h>
#define Na 6.02 * 10e+23
//求mol值
int main(void)
{
    double Q;
    Q = 6.0 / 32.0 * Na;
    printf("%.3e\n", Q);
    printf("%.5g\n", Q);
    return 0; 

}