#include<stdio.h>

int main (void)
{
    int number;
    int max = 0, step = 0;

    scanf("%d", &number);
    int number1 = number;
    max = number1;
    while(number1 != 1)
    {
        if(number1 % 2 == 0)
        {
            number1 = number1 / 2;
        }
        else
        {
            number1 = 3 * number1 + 1;
        }
        step++;

        if(number1 > max)
        {
            max = number1;
        }
    }
    printf("%d %d", step, max);
}