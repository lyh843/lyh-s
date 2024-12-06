#include<stdio.h>
#include<math.h>

int judge_prime(int number)
{
    int judge = 1;
    for(int i = 2; i <= sqrt(number + 0.5); i++)
    {
        if(number % i == 0)
        {
            judge = 0;
            break;
        }
    }
    return judge;
}
int turn(int number)
{
    int len = 0;
    int arr_number[5] = {0};
    int turn_number = 0;
    if(number < 10)
    {
        len = 1;
    }
    else if(number < 100)
    {
        len = 2;
    }
    else if(number < 1000)
    {
        len = 3;
    }
    else
    {
        len = 4;
    }
    for(int i = len - 1; i >= 0; i--)
    {
        arr_number[i] = number / (int)pow(10, i);
        number = number % (int)pow(10, i);
    }
    for(int i = 0; i < len; i++)
    {
        turn_number += arr_number[i] * (int)pow(10, len - i - 1);
    }
    return turn_number;
}
int main(void)
{
    int number = 0;
    int turn_number = 0;
    int count = 0;
    scanf("%d", &number);
    for(int i = 2; i <= number; i++)
    {
        if(judge_prime(i))
        {
            if(judge_prime(turn(i)))
            {
                count++;
            }
        }
    }
    printf("%d", count);
}