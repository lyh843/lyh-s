#include <stdio.h>
#define N 1000006
int main(void) 
{
    int len = 0;
    int arr1[N] = {0};
    int arr2[N - 1] = {0};
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < len - 1; i++)
    {
        arr2[i] = arr1[i + 1] - arr1[i];
    }
    int judge1 = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if(arr1[i] <= arr1[i + 1])
        {
        }
        else
        {
            printf("%d", -1);
            return 0;
        }
    }
    for (int i = 0; i < len - 2; i++)
    {
        if(arr2[i] < arr2[i + 1])
        {
        }
        else
        {
            judge1 = 1;
        }
    }
    if(judge1 == 1)
    {
        printf("%d", 0);
    }
    else
    {
        printf("%d", 1);
    }
    return 0;
}