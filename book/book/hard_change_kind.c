#include<stdio.h>

int main (void)
{
    //强制转换求小数部分
    float f, frac_part;
    scanf("%f", &f);

    frac_part = f - (int) f;

    printf("%f\n", frac_part);
    //强制转换求分数
    int a = 1; 
    int b = 7;
    printf("%f\n", (float)a / b);
    printf("%d", a);
}