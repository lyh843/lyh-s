//给定一个有序数组，将这个数组的各位平方，将平方后的结果按从大到小输出
//双指针法
#include<stdio.h>
#include<stdlib.h>
#define N 100
void f_input_arr(int *pt_arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        scanf("%d", pt_arr + i);
    }
}
void f_square_arr(int *pt_arr, int len)
{
    int i = 0, j = len - 1;
    while(i <= j)
    {
        if(abs(*(pt_arr + i)) > abs(*(pt_arr + j)))
        {
            printf("%d ", pt_arr[i] * pt_arr[i]);
            i++;
        }
        else
        {
            printf("%d ", pt_arr[j] * pt_arr[j]);
            j--;
        }
    }
}
int main(void)
{
    int arr[N] = {0};
    int len = 0;
    scanf("%d", &len);
    f_input_arr(arr, len);
    f_square_arr(arr, len);
}