#include<stdio.h>
#define N 1000

//判断存活人数
int sum_arr(int arr[N], int n)
{
    int sum;
    for(int i = 0; i <= n; i++)
    {
        sum += arr[i];
    }
    if(sum > 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//报数程序
int count(int arr[N], int max, int number, int k)
{
    int num_count = k;
    int i = 0;
    
    while(num_count)
    {
        number = number + i;
        //number大于max时，让number回去第一个存活的人那
        if(number > max)
        {
            int j = 0;
            while(1 - arr[number])
            {
                number = number - max + j;
                if(number < max)
                {
                    j++;
                }
                else 
                {
                    j = 0;
                }
            }
        }
        if(arr[number] == 1)
        {
            num_count = num_count - 1;
        }
        i = 1;
    }
    return number;
}
//判断目前存活的最大数字
int Max(int arr[N], int n)
{
    int max;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] == 1)
        {
            max = i;
        }
    }
    return max;
}

int main (void)
{
    //输入
    int n = 0, k = 0;
    scanf("%d", &n);
    scanf("%d", &k);

    //处理
    //存活
    int arr[N] = {0};
    for(int i = 1; i <= n; i++)
    {
        arr[i] = 1;
    }
    //死亡游戏开始
    int number = 1;
    int max = n;
    while(sum_arr(arr, n))
    {
        max = Max(arr, n);
        number = count(arr, max, number, k);
        arr[number] = 0;
        number = number + 1;
    }
    //输出
    for(int i = 0; i <= n; i++)
    {
        if(arr[i] == 1)
        {
            printf("%d", i);
        }
    }
}