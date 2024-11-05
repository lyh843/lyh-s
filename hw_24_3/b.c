#include<stdio.h>

int main (void)
{
    int n; 
    scanf("%d", &n);
    int arr[2000] = {0};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(((j + 1) % (i + 1)) == 0)
            {
                arr[j] = 1 - arr[j];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 1)
        {
            printf("%d ", i + 1);
        }
    }
}