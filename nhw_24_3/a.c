#include<stdio.h>
#include<math.h>
//欧几里得算法
//两个数的最大公约数等于其中较小的数与两数之差的最大公约数。

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main (void)
{
    long a, b = 0;
    scanf("%ld %ld", &a, &b);
    printf("%d", gcd(a, b));
    return 0;
}