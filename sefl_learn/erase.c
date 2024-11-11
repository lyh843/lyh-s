//给定一个数组，删除掉数组中所有的特定元素
//快慢指针法
#include<stdio.h>
#define N 100
void f_input_arr(int *pt_arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        scanf("%d", pt_arr + i);
    }
}
void f_erase_arr(int *pt_arr, int *pt_len, int target)
{
    int i = 0;
    for(int j = 0; j < *pt_len; j++)
    {
        if(*(pt_arr + j) != target)
        {
            *(pt_arr + i) = *(pt_arr + j);
            i++;
        }
    }
    *pt_len = i;
}
void f_printf_arr(int *pt_arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ", *(pt_arr + i));
    }
}
int main(void)
{
    int arr[N] = {0};
    int len_arr = 0, target = 0;
    scanf("%d%d", &len_arr, &target);
    f_input_arr(arr, len_arr);
    f_erase_arr(arr, &len_arr, target);
    f_printf_arr(arr, len_arr);
}