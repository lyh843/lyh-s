#include<stdio.h>
/*
* 传感器
* 单个字符只能用%c
* double要用%lf
* 空格也是字符！！会被scanf的%c识别
*/
int main(void)
{
    //定义界面
    char name[20];
    int pre;
    double frac;
    double factor;
    char unit;
    char new_unit;
    //输入界面
    scanf("%s", name);
    scanf("%d", &pre);
    scanf("%lf", &frac);
    scanf("%lf", &factor);
    scanf(" %c", &unit);
    //处理界面
    double sciEexp = pre + frac;
    double conv = (pre + frac) * factor;
    new_unit = unit - 32;
    //输出界面
    printf("%.2s: ", name);
    printf("%d ", pre);
    printf("(%.5lf) | ", frac);
    printf("%.5E ", sciEexp);
    printf("%.5f ", conv);
    printf("%c", new_unit);
}   