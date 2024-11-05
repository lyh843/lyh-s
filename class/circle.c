#include<stdio.h>
#define Pi 3.14159
//求圆的各种数值
int main(void)
{
    int radius;
    double long1, size, area, volune;
    printf("Please enter the radius:");
    scanf("%d", &radius);

    long1 = 2 * Pi * radius;
    size = radius * radius * Pi;
    area = 4 * Pi * radius * radius;
    volune = 4.0f / 3.0f * Pi * radius * radius * radius;

    printf("%-15.4f : long\n", long1);
    printf("%-15.4f : size\n", size);
    printf("%-15.4f : area\n", area);
    printf("%-15.4f : volune\n", volune);

}