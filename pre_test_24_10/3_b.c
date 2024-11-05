#include<stdio.h>

int main(void)
{
    int len;
    scanf("%d", &len);
    int arr[2001] = {0};
    for(int i = 1; i <= len; i++)
    {
        for(int j = 1; j <= len ; j++)
        {
            if(j % i == 0)
            {
                arr[j] = 1 - arr[j];
            }
        }
    }
    for(int i = 1; i <= len; i++)
    {
        if(arr[i] == 1)
        {
            printf("%d ", i);
        }
    }
    return 0;
}