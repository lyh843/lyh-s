#include<stdio.h>
#define N 5
#define M 6

int main(void)
{
    //初始定义两个子数组
    int arr1[N] = {1, 2, 3, 4, 5};
    int arr2[M] = {2, 3, 7, 8, 10, 12};
    int arr_sum[N + M] = {0};

    //count the number
    int arr1_num = 0; 
    int arr2_num = 0;
    for(int i = 0; i < N+M; i++)
    {
        if(arr1[arr1_num] < arr2[arr2_num])
        {
            arr_sum[i] = arr1[arr1_num];
            arr1_num = arr1_num + 1;
        }
        else
        {
            arr_sum[i] = arr2[arr2_num];
            arr2_num = arr2_num + 1;
        }
        if(arr1_num == N && arr2_num == M)
        {
        break;
        }
    }

    //printf the arr_sum
    for(int i = 0; i < N + M; i++)
    {
        printf("%d", arr_sum[i]);
    }
}