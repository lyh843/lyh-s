#include<stdio.h>
#include<math.h>
//求Pi的两种复杂方式
int main(void)
{
    double answer_1, answer_2;
    answer_1 = 4 * 4 * atan(1.0 / 5.0) - 4 *atan(1.0 / 239.0);
    answer_2 = log( pow(640320, 3) + 744) / ( log(exp(1)) * sqrt(163));
    
    printf("%.16g\n", answer_1);
    printf("%.16g\n", answer_2);
}