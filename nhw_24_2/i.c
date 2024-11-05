#include<stdio.h>

int main (void)
{
    long n = 0;
    int num = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int judge = 1;
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                judge = 0;
            }
        }
        (judge) ? (num++): (num = num);
    }
    printf("%d", num);
}