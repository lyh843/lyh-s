#include<stdio.h>
#define num1 int
int main(void)
{
    //typedef类型定义
    typedef int num;
    num a, b, c;
    a = 1.2, b = 2, c = 3;
    printf("%f\n%d\n%d\n", (float)a, b, c);
    //sizeof的使用
    c = sizeof(long long);
    printf("%d", c);
    //typedef类型定义2
    num1 d, e;
    d = 1.5;
    e = 1.5;
    printf("%d, %d", d, e);

}