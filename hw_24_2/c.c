#include<stdio.h>
//阶乘的和Ⅰ
#define N 10007
int main(void)
{
    int n = 0, result = 0, num = 0;
    int max = 0;
    scanf("%d", &n);

    for(int j = 1; j < (n + 1); j++)
    {
        num = 1;
        for(int i = 1; i < (j + 1); i++)
        {
            num = (num % N) * i;
        }
        result = (result + num) % N;
    }

    printf("%d", result);
}