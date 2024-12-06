#include<stdio.h>
#define N 100
void f_input_arr(int *pt_arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        scanf("%d", pt_arr + i);
    }
}
void f_lower_bound(int *pt_arr, int len, int number, int *pt_min)
{
    int start = 0, end = len -1;
    int mid = start + (end - start) / 2;//二分法的双闭写法
    while(start <= end)
    {
        mid = start + (end - start) / 2;
        if(number < pt_arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    mid = start - 1;
    if(*pt_min > number - pt_arr[mid] && number - pt_arr[mid] >= 0)//如果这个新的最小值小于原来的最小值，并且新的最小值大于0
    {
        *pt_min = number - pt_arr[mid];
    }
}
int main(void)
{
    int arr1[N] = {0}, arr2[N] = {0};
    int len_arr1 = 0, len_arr2 = 0, number_t = 0;
    int min = 0;
    scanf("%d%d%d", &len_arr1, &len_arr2, &number_t);
    min = number_t + 1;
    f_input_arr(arr1, len_arr1);//第一个数组是从小到大的
    f_input_arr(arr2, len_arr2);//第二个数组是乱序的
    for(int i = 0; i < len_arr2; i++)
    {
        if(number_t < arr1[0] + arr2[i])//如果这个都大于，那就arr2就直接下个数吧
        {
            continue;
        }
        f_lower_bound(arr1, len_arr1, number_t - arr2[i], &min);//丢一个确切的arr2的数进去，找最大的arr1
    }
    if(min == number_t + 1)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", min);
    }
}