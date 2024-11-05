#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

static char *ones[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
    "0", "1", "twenty", "thirty", "forty", 
    "fifty", "sixty", "seventy", "eighty", "ninety"};

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
}

int f_neg(number)
{
    bool neg = false;
    if(number = 0)
    {
        printf("zero");
        return 0;
    }
    else if(number < 0)
    {
        neg = true;
        number = abs(number);
    }
    return neg;
}

int main(void)
{
    int number = 0;
    int arr_number_level[5] = {0};
    scanf("%d", &number);
    bool neg = f_neg(number);//判断正负
    int level_number = f_level_number(number);//1：3位数以内；2：6位数以内；3：9位数以内；4：10位数
    for(int i = 1; i <= level_number; i++)
    {
        arr_number_level[i] = number % (int)pow(10, 3 * i);
        //number = number - 
    }
}