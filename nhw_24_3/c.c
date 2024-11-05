#include<stdio.h>

int main(void)
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int number = 1;
    int p_number = 1;
    if(n == 1)
    {
        number = 6;
    }
    else
    {
        number = n - 2;
    }
    for(int i = 0; i < number; i++)
    {
        printf("    ");
    }
    for(int i = 0; i < 7 - number; i++)
    {
        printf("%2d  ",p_number++);
    }
    printf("\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(p_number == m + 1)
            {
                return 0;
            }
            printf("%2d  ", p_number++);
        }
        printf("\n");
    }
    return 0;
}