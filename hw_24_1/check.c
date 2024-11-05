#include <stdio.h>
#include <math.h>

#define WOW(n) ((double)(n))

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }

    return x * f;
}

int main()
{
    int p, q;
    p = read();
    q = read();
    double q2 = WOW(q) / WOW(2);
    double p3 = WOW(p) / WOW(3);
    double mq2 = WOW(-1) * q2;
    double x1 = cbrt(mq2 + sqrt(pow(q2, 2) + pow(p3, 3))) + cbrt(mq2 - sqrt(pow(q2, 2) + pow(p3, 3)));
    printf("%.3lf", x1);
    return 0;
}