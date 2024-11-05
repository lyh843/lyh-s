#include<stdio.h>
//输出生日 字符串 数字
int main(void)
{
    int day, year, hour, minute, second;
    char month[10];
    char weekday[10];

    scanf("%s", &month);
    scanf("%d", &day);
    scanf("%d", &year);
    scanf("%s", &weekday);
    scanf("%d%d%d", &hour, &minute, &second);

    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d", weekday, month, day, hour, minute, second, year);
}