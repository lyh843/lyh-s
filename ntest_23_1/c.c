#include<stdio.h>
#define N 1500

int count(int arr[N], int number, int num_peo, int num_kill, int num_gun)
{
    while(num_kill)
    {
        if(arr[number] >= 1)
        {
            number++;
            num_kill--;
        }
        else
        {
            number++;
        }
        if(number > num_peo)
        {
            number = 0;
        }
    }
    return number - 1;
}
int main(void)
{
    int num_peo, num_kill, num_gun, num_tail;
    scanf("%d", &num_peo);
    scanf("%d", &num_kill);
    scanf("%d", &num_gun);
    scanf("%d", &num_tail);
    int arr[N] = {0};
    for(int i = 0; i < num_peo; i++)
    {
        for(int j = 0; j < num_tail; j++)
        {
            arr[i]++;
        }
    }
    int num_peo1 = num_peo;
    int number = 0;
    //开始杀
    while(num_peo1 != 1)
    {
        number = count(arr, number, num_peo, num_kill, num_gun);
        arr[number]--;
        if(arr[number] == 0)
        {
            num_peo1--;
        }
    }
    //只剩一只
    for(int i = 0; i < num_peo; i++)
    {
        if(arr[i] != 0)
        {
            printf("%d", i + 1);
        }
    }
}