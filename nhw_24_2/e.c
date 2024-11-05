#include<stdio.h>
#include<math.h>
//为什么y改为long double后程序出错？
int main(void)
{
    int n = 0;
    float x = 0;
    long double y = 0;
    scanf("%f", &x);
    scanf("%d", &n);

    for(int i =0; i <= n; i++)
    {
        if(i % 2 == 0)
        {
            if(x >= 0)
            {
                y += 4 * (pow(x, 2 * i + 1) / (2 * i + 1) );
            }
            else
            {
                y += -4 * (pow(-x, 2 * i + 1) / (2.0 * i + 1.0));
            }
        }
        else
        {
            if(x >= 0)
            {
                y += -4 * (pow(x, 2 * i + 1) / (2.0 * i + 1.0));
            }
            else
            {
                y += 4 * (pow(-x, 2 * i + 1) / (2.0 * i + 1.0));
            }
        }
    }
    printf("%.10Lf", y);
}