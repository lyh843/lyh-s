#include<stdio.h>

int main(void)
{
    int number = 0, amount = 0;
    scanf("%d", &amount);
    scanf("%d", &number);
    int mid_number = number;
    int result = 0;
    for(int i = 0; i < amount; i++)
    {
        result += mid_number;
        mid_number = mid_number * 10 + number;
    }
    printf("%d", result);
}