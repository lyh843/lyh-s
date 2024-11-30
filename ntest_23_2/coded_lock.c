#include<stdio.h>
#include<stdbool.h>
#define N 1050
int amount = 0, max_range = 0, change_num = 0;
int arr1[N] = {0}, arr2[N] = {0}, arr_temp[N] = {0};
int result = 0;
bool judge = true;
int f_up(int i)
{
    int times = 0;
    do
    {
        if(arr1[i] == arr1[amount - 1 - i])
        {
            return times;
        }
        arr1[i] = arr1[i] + change_num;
        times++;
        while(arr1[i] > max_range)
        {
            arr1[i] = arr1[i] - max_range;
        }
    }
    while(arr1[i] != arr_temp[i]);
    judge = false;
    return 0;
}
int f_down(int i)
{
    int times = 0;
    do
    {
        if(arr2[i] == arr2[amount - 1 - i])
        {
            return times;
        }
        arr2[i] = arr2[i] - change_num;
        times++;
        while(arr2[i] < 1)
        {
            arr2[i] = arr2[i] + max_range;
        }
    }
    while(arr2[i] != arr_temp[i]);
}
void f_opearate()
{
    int temp1 = 0, temp2 = 0, sum = 0;
    for(int i = 0; i < amount / 2 && judge; i++)
    {
        temp1 = f_up(i);
        temp2 = f_down(i);
        if(temp1 < temp2)
        {
            sum += temp1;
        }
        else
        {
            sum += temp2;
        }
    }
    if(judge)
    {
        printf("%d\n",sum);
    }
    else
    {
        printf("Impossible");
    }
}
int main(void)
{
    scanf("%d%d%d", &amount, &max_range, &change_num);
    for(int i = 0; i < amount; i++)
    {
        scanf("%d", &arr1[i]);
        arr_temp[i] = arr1[i];
        arr2[i] = arr1[i];
    }
    f_opearate();
}