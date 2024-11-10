#include<stdio.h>

int main(void)
{
    int a = 100, *p = &a;
    *p = 200;
    printf("%d", *p);
}