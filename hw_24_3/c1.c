#include<stdio.h>
#define N 1000

int count(int arr[N], int n, int k, int number)
{
    while(k)
    {
        if(number > n)
        {
            number = number - n;
        }
        k = k - arr[number];
        number++;
    }
    return number;
}

int main (void)
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int arr[N] = {0};
    for(int i = 1; i <= n; i++)
    {
        arr[i] = 1;
    }

    int sum_arr = n;
    int number = 1;
    while(sum_arr - 1)
    {
        number = count(arr, n, k, number);
        arr[number - 1] = 0;
        sum_arr--;
    }
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] == 1)
        {
            printf("%d", i);
        }
    }
}