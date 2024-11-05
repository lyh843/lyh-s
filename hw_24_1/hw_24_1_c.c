#include<stdio.h>
#include<math.h>
//圆周率

int main(void)
{
    double pi1, pi2;
    pi1 = log(pow(5280,3) * pow(236674 + 30303 * sqrt(61),3) + 744);
    pi1 = pi1 / (log(exp(1)) * sqrt(427));
    pi2 = 6 * atan(1.0 / 8.0) + 2 * atan(1.0 / 57.0) + atan(1.0 / 239.0);
    pi2 = 4 * pi2;

    printf("%.15f\n", pi1);
    printf("%.15f\n", pi2);
}