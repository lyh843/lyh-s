#include<stdio.h>
#define N 2002
int main(void)
{
    int len = 0;
    int arr[N] = {0};
    scanf("%d", &len);
    for(int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    int len_short1 = 1;
    for(int i = len - 1; i >= 0; i--)
    {
        if(arr[i] > arr[i - 1])
        {
            break;
        }
        else
        {
            len_short1++;
        }
    }
    int min = arr[len - len_short1];
    int loc_min = len - len_short1;
    for(int i = len - 1;i > len - len_short1; i--)
    {
        if(arr[i] > arr[len - len_short1 - 1] && arr[i] < min)
        {
            min = arr[i];
            loc_min = i;
        }
    }
    int temp = 0;
    temp = arr[loc_min];
    arr[loc_min] = arr[len - len_short1 - 1];
    arr[len - len_short1 - 1] = temp;
    for(int i = 0; i < len_short1 / 2; i++)
    {
        int temp1 = 0;
        temp = arr[i + len - len_short1];
        arr[i + len - len_short1] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}