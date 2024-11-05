#include<stdio.h>
#define N 1000001
//落单的shu
//桶计数法
int main(void)
{
    int number = 0;
    int j = 0;
    int count[N] = {0};
    scanf("%d", &number);
    for(int i = 0; i < 2 * number - 1; i++)
    {
        scanf("%d", &j);
        count[j]++;
    }
    for(int i = 0; i < N; i++)
    {
        if(count[i] == 1)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}