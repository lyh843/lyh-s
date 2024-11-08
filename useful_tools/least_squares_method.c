//to calculate the least squares
#include<stdio.h>
#include<stdlib.h>
#define N 100
float f_average(float arr[N], int amount)
{
    float average = 0;
    for(int i = 0; i < amount; i++)
    {
        average += arr[i];
    }
    average /= (float)amount;
    return average;
}
float f_sum_xy(float arr_x[N], float arr_y[N], int amount)
{
    float sum_xy = 0;
    for(int i = 0; i < amount; i++)
    {
        sum_xy += arr_x[i] * arr_y[i];
    }
    return sum_xy;
}
float f_sum_xx(float arr_x[N], int amount)
{
    float sum_xx = 0;
    for(int i = 0; i < amount; i++)
    {
        sum_xx += arr_x[i] * arr_x[i];
    }
    return sum_xx;
}
int main(void)
{
    int amount = 0;
    float arr_x[N] = {0};
    float arr_y[N] = {0};
    float average_x = 0;
    float average_y = 0;
    float sum_xy = 0;
    float sum_xx = 0;
    float slope_least_squares = 0;
    float intercept_least_squares = 0;
    printf("Please enter the amount of the \"x\":");
    scanf("%d", &amount);
    printf("Please input the data of x\n");
    for(int i = 0; i < amount; i++)
    {
        scanf("%f", &arr_x[i]);
    }
    printf("Please input the data of y\n");
    for(int i = 0; i < amount; i++)
    {
        scanf("%f", &arr_y[i]);
    }
    average_x = f_average(arr_x, amount);
    average_y = f_average(arr_y, amount);
    sum_xy = f_sum_xy(arr_x, arr_y, amount);
    sum_xx = f_sum_xx(arr_x, amount);
    slope_least_squares = (sum_xy - amount * average_x * average_y) / (sum_xx - amount * average_x * average_x);
    intercept_least_squares = average_y - slope_least_squares * average_x;
    printf("the slope of the least squares is: %.4f\n", slope_least_squares);
    printf("the inercept of the least squares is: %.4f\n", intercept_least_squares);
    system("pause");
    return 0;
}