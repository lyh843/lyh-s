#include<stdio.h>
//数字转换Ⅰ
int main(void)
{
    int number, ten, one;
    static char *ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen","fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    static char *tens[] = {"0", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    scanf("%d", &number);

    if(number < 20)//小于20
    {
        printf("%s", ones[number]);
    }
    else if(number < 100 && number % 10 == 0)//大于20，小于100的整十
    {
        printf("%s", tens[number / 10]);
    }
    else if(number < 100)//大于20，小于100，的非整十数
    {
        printf("%s-%s", tens[number / 10], ones[number % 10]);
    }
    else if(number % 100 == 0)//整百
    {
        printf("%s hundred", ones[number / 100]);
    }
    else if(number % 10 == 0)//整百中的整十数
    {
        printf("%s hundred and %s", ones[number / 100], tens[(number - 100) / 10]);
    }
    else if((number % 100) < 10 || ((number % 100) < 20))//整百中十位数为0的数
    {
        printf("%s hundred and %s", ones[number / 100], ones[number % 100]);
    }
    else
    {
        printf("%s hundred and %s-%s", ones[number / 100], tens[(number % 100) / 10], ones[number % 10]);
    }



    return 0;
}