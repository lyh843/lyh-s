#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<limits.h>

static char *ones[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
    "0", "1", "twenty", "thirty", "forty", 
    "fifty", "sixty", "seventy", "eighty", "ninety"};
char f_change_string(int number)
{
    int judge = 0;
    if(number != 0)
    {
        judge = 1;
    }
    if(number / 100 == 0)
    {
        if(number / 10 < 2)
        {
            printf("%s ", ones[number]);
        }
        else if(number % 10 == 0)
        {
            printf("%s ", tens[number / 10]);
        }
        else if(number / 10 >= 2)
        {
            printf("%s-%s ", tens[number / 10], ones[number % 10]);
        }
    }
    else
    {
        printf("%s hundred ", ones[number / 100]);
        if(number % 100 != 0)
        {
            printf("and ");
            number = number % 100;
            if(number / 10 < 2)
            {
                printf("%s ", ones[number]);
            }
            else if(number % 10 == 0)
            {
                printf("%s ", tens[number / 10]);
            }
            else if(number / 10 >= 2)
            {
                printf("%s-%s ", tens[number / 10], ones[number % 10]);
            }
        }
    }
    return judge;
}
int f_level_number(int number)
{
    int level_number = 0;
    if(number / (int)pow(10, 3) == 0)
    {
        level_number = 1;
    }
    else if(number / (int)pow(10, 6) == 0)
    {
        level_number = 2;
    }
    else if(number / (int)pow(10, 9) == 0)
    {
        level_number =3;
    }
    else
    {
        level_number = 4;
    }
    return level_number;
}
int f_neg(int number)
{
    bool neg = false;
    if(number < 0)
    {
        return true;
    }
    return false;
}

int main(void)
{
    int number = 0;
    int arr_number_level[5] = {0};
    int judge_number_level[5] = {0};
    scanf("%d", &number);
    if(number == INT_MIN)
    {
        printf("minus two billion one hundred and forty-seven million four hundred and eighty-three thousand six hundred and forty-eight");
        return 0;
    }
    bool neg = f_neg(number);//判断正负
    if(neg)
    {
        number = abs(number);
        printf("minus ");
    }
    int level_number = f_level_number(number);//1：3位数以内；2：6位数以内；3：9位数以内；4：10位数
    for(int i = level_number - 1; i >= 0; i--)//切分数据
    {
        arr_number_level[level_number - 1 - i] = number / (long long)pow(10, 3 * i);
        number = number % (int)pow(10, 3 * i);
    }
    for(int i = 0; i < level_number; i++)
    {
        if(arr_number_level[i] != 0)
        {
            judge_number_level[i] = 1;
        }
    }
    int level_number1 = level_number; 
    for(int i = 0; i < level_number; i++)
    {
        int judge = 0;
        if(judge_number_level[i] == 1)
        {
            judge = f_change_string(arr_number_level[i]);
        }
        if(judge)
        {
            if(level_number1 == 4)
            {
                printf("billion ");
            }
            else if(level_number1 == 3)
            {
                printf("million ");
            }
            else if(level_number1 == 2)
            {
                printf("thousand ");
            }
        }
        level_number1--;
    }
    return 0;
}