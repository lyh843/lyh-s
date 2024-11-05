#include<stdio.h>

int main(void)
{
    int amount = 0;
    scanf("%d", &amount);
    for(int i = 0; i < amount; i++)
    {
        int len = 0;
        int arr[10] = {0};
        scanf("%d", &len);
        for(int j = 0; j < len; j++)
        {
            scanf("%d", &arr[j]);
        }
        int max = arr[0];
        for(int j = 1; j < len - 1; j++)
        {
            if(arr[j] > max)
            {
                max = arr[j];
            }
        }
        if(max > arr[len - 1])
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
}