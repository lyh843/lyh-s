#include<stdio.h>
#include<stdbool.h>
#define N 100
int main(void)
{
    int arr1[N] = {0}, arr2[N] = {0};
    int len_arr1 = 0, len_arr2 = 0, number_t = 0;
    int loc_arr1 = 0, loc_arr2 = 0;
    int min_arr[3] = {0};
    bool findout = false;
    scanf("%d%d%d", &len_arr1, &len_arr2, &number_t);
    min_arr[0] = number_t;
    //input arr1
    for(int i = 0; i < len_arr1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    //in put arr2
    for(int i = 0; i < len_arr2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    //bubblesort-arr2
    for(int i = 0; i < len_arr2; i++)
    {
        int temp = 0;
        for(int j = 0; j < len_arr2 - i - 1; j++)
        {
            if(arr2[j] > arr2[j + 1])
            {
                temp = arr2[j + 1];
                arr2[j + 1] = arr2[j];
                arr2[j] = temp;
            }
        }
    }
    //judge whether can find
    if(number_t < arr1[0] + arr2[0])
    {
        printf("%d", -1);
        return 0;
    }
    //find out the biggest a that smaller than t
    for(int i = len_arr1 - 1; i >= 0; i--)
    {
        if(number_t >= arr1[i] + arr2[0])
        {
            loc_arr1 = i;
            break;
        }
    }
    //find out the biggest b that smaller than t - a
    for(int i = 0; i < len_arr2; i++)
    {
        if(number_t - arr1[loc_arr1] >= arr2[loc_arr2 + 1] && loc_arr2 <= len_arr2 - 2)
        {
            loc_arr2++;
        }
        else
        {
            break;
        }
    }
    for(; loc_arr1 >= 0 && !findout; loc_arr1--)
    {
        for(int j = loc_arr2; j <= len_arr2 - 2 && !findout; j++)
        {
            if(number_t < arr1[loc_arr1] + arr2[loc_arr2 + 1])//如果这个b超了，后面的肯定都超了
            {
                break;
            }
            else if(number_t == arr1[loc_arr1] + arr2[loc_arr2 + 1])//如果刚好为0，那这个肯定是对的
            {
                findout = true;
                min_arr[0] = number_t - arr1[loc_arr1] - arr2[loc_arr2];
                min_arr[1] = loc_arr1;
                loc_arr2++;
                min_arr[2] = loc_arr2;
            }
            else
            {
                if(number_t - arr1[loc_arr1] - arr2[loc_arr2 + 1] < min_arr[0])
                {
                    min_arr[0] = number_t - arr1[loc_arr1] - arr2[loc_arr2 - 1];
                    loc_arr2++;
                    min_arr[1] = loc_arr1;
                    min_arr[2] = loc_arr2;
                }
                else
                {
                    loc_arr2++;
                }
            }
        }
        if(number_t - arr1[loc_arr1] - arr2[loc_arr2] < min_arr[0])
        {
            min_arr[0] = number_t - arr1[loc_arr1] - arr2[loc_arr2];
            min_arr[1] = loc_arr1;
            min_arr[2] = loc_arr2;
        }
    }
    printf("%d", min_arr[0]);
}