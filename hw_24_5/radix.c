#include<stdio.h>
#include<stdbool.h>
int f_max(int number[3][3])
{
    int max = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(max < number[i][j])
            {
                max = number[i][j];
            }
        }
    }
    return max;
}
int f_calculate(int number[3][3], int i)
{
    int number1 = number[0][0] * i + number[0][1];
    int number2 = number[1][0] * i + number[1][1];
    int number3 = number[2][0] * i + number[2][1];
    if(number1 * number2 == number3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(void)
{
    int arr_number[3][3] = {0};//每行是一个数，第0列是数的十位部分，第1列是数的个位部分
    int number = 0, max = 0, system = 1;
    bool flag = false;
    for(int i = 0; i < 3; i++)
    {
        scanf("%d", &number);
        arr_number[i][0] = number / 10;
        arr_number[i][1] = number % 10;
    }
    max = f_max(arr_number);
    for(int i = max; i <= 40; i++)
    {
        if(f_calculate(arr_number, i))
        {
            printf("%d", i);
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        printf("0");
    }
    return 0;
}