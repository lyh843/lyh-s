#include<stdio.h>
//三角形
int main (void)
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if((a + b) <= c)//判断能不能构成三角形
    {
        printf("not triangle");
        return 0;
    }
    //可以构成三角形
    if(a == b && b == c)//判断等边
    {
        printf("equilateral triangle");
    }
    else if((a * a + b * b) == (c * c))//判断直角三角形
    {
        printf("right triangle");
    }
    else
    {
        if((a * a + b * b) > (c * c))//钝角
        {
            printf("acute ");
        }
        else if((a * a + b * b) < (c * c))//锐角
        {
            printf("obtuse ");
        }
        if(a == b || b == c)//等腰
        {
            printf("isosceles ");
        }
            printf("triangle");
    }
    
    return 0;
}