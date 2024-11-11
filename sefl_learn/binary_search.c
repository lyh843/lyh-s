//双闭区间的二分法
#include<stdio.h>
#define N 100
void f_input_arr(int *pt_arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        scanf("%d", pt_arr + i);
    }
}
void f_binary_search(int arr[N], int len, int target)//双闭区间写法
{
    int start = 0, end = len - 1;
    int mid = 0;
    while(start <= end)//正确区间的性质
    {
        mid = start + (end - start) / 2;
        if(target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid  + 1;
        }
    }
    mid = start - 1;
    // 此处展示的“mid = start - 1”可用于查找是否含有对应元素，也可查找arr中，不大于target的最大元素。
    // 而“mid = start”则是arr中不小于taget的最大元素。
    printf("%d", arr[mid]);
}
int main(void)
{
    int arr[N] = {0};
    int len_arr = 0, target = 0;
    scanf("%d%d", &len_arr, &target);
    f_input_arr(arr, len_arr);
    f_binary_search(arr, len_arr, target);
    return 0;
}