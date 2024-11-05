#include<stdio.h>
//数字黑洞
int max1(int a, int b, int c)
{
    int max;
    if(a == b)
    {
        if(a >=c )
        {
            max = a * 100 + b * 10 + c;
        }
        else
        {
            max = c * 100 + b * 10 + a;
        }   
    }
    else if(a < b)
    {
        if(b < c)
        {
            max = c * 100 + b * 10 + a;
        }
        else if(c < a)
        {
            max = b * 100 + a * 10 + c;
        }
        else
        {
            max = b * 100 + c * 10 + a;
        }
    }
    else if(a > b)
    {
        if(a < c)
        {
            max = c * 100 + a * 10 + b;
        }
        else if(c < b)
        {
            max = a * 100 + b * 10 + c;
        }
        else
        {
            max = a * 100 + c * 10 + b;
        }
    }
    return max;
}
int min1(int a, int b, int c)
{
    int min;
    if(a == b)
    {
        if(a >=c )
        {
            min = c * 100 + b * 10 + a;
        }
        else
        {
            min = a * 100 + b * 10 + c;
        }
    }
    else if(a < b)
    {
        if(b < c)
        {
            min = a * 100 + b * 10 + c;
        }
        else if(c < a)
        {
            min = c * 100 + a * 10 + b;
        }
        else
        {
            min = a * 100 + c * 10 + b;
        }
    }
    else if(b < a)
    {
        if(a < c)
        {
            min =b * 100 + a * 10 + c;
        }
        else if(c < b)
        {
            min = c * 100 + b * 10 + a;
        }
        else
        {
            min = b * 100 + c * 10 + a;
        }
    }
    return min;
}
int main(void)
{
    int a, b, c;
    int max, min;
    int number = 0;
    int number2 =0;
    int addnumber = 0;

    scanf("%1d%1d%1d", &a, &b, &c);
    
    do
    {
        number2 = a * 100 + b * 10 + c;
        max = max1(a, b, c);
        min = min1(a, b, c);
        //printf("%d\t%d\n", max, min);
        number = max - min;
        
        if(number2 > number)
        {
            addnumber = addnumber + number2 - number;
        }
        a = number / 100;
        b = (number % 100) / 10;
        c = number % 10;
        //printf("%d\t<\t%d\t%d\n", number, number2, addnumber);
    } 
    while (number != 495);

    printf("%d", addnumber);
}