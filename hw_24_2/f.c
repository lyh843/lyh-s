#include<stdio.h>
//全体起立
int main(void)
{
    int max_scare, num = 0;
    int num2 = 0;
    int arr[100001] = {0};

    scanf("%d", &max_scare);
    for(int i = 0; i < max_scare + 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i < max_scare + 1; i++)
    {
        //printf("%d\t%d\t%d\t%d\n", arr[0], num2, num, i);
        if(arr[i] != 0)
        {
            if(arr[0] >= i)
            {
                arr[0] = arr[0] + arr[i];
            }
            else
            {
                num = i - arr[0] + num;
                num2 = i - arr[0];
                arr[0] = arr[0] + num2 + arr[i];
            }
        }
        
    }
    //printf("%d\t%d\t%d\n", arr[0], num2, num);
    printf("%d", num);
}