#include<stdio.h>
#define N 1000000007
//阶乘单循环
int main(void)
{
    long long n = 0, result = 0, num = 0, ans = 1;
    scanf("%lld", &n);
    for(int i = 1; i  < (n + 1); i++)
    {
        ans = ans * i;
        ans = ans % N;
        result = result + ans;
        result = result % N;
    }

    printf("%lld", result);
}