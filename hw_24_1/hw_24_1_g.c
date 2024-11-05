#include<stdio.h>
#include<math.h>
/*
*   一次三元方程
*   pow不能开负数的立方根   
*   cbrt是开立方根的函数
*   sqrt是开平方根的函数
*/
int main(void)
{
    double q, p;
    double x1, m;

    scanf("%lf%lf", &p ,&q);
    
    if((q * q / 4.0) + (p * p * p / 27.0) > 0)
    {
        m = sqrt((q * q / 4.0) + (p * p * p / 27.0));
    }
    else if((q * q / 4.0) + (p * p * p / 27.0) == 0)
    {
        m = 0;
    }
    else
    {
        m = sqrt(-(q * q / 4.0) - (p * p * p / 27.0));
    }
    
    if((-q / 2.0 + m) > 0)
    {
        x1 = pow(-q / 2.0 + m , (1.0 / 3.0));
        
    }
    else if ((-q / 2.0 + m) == 0)
    {
        x1 = 0;
    }
    else
    {
        x1 = (-1) * pow(q / 2.0 - m , (1.0 / 3.0));
        
    }
    if((-q / 2.0 - m) > 0)
    {
        x1 = x1 + pow(-q / 2.0 - m, (1.0 / 3.0));
    }
    else if ((-q / 2.0 - m) == 0)
    {
        x1 = x1 + 0;
    }
    else
    {
        x1 = x1 + (-1) * pow(q / 2.0 + m, (1.0 / 3.0));
    }

    printf("%.3lf", x1);
}