#include<stdio.h>
#define T 21
#define N 2001 
//超时
int main(void)
{
    int num_group = 0, length_group = 0;
    int judge[T] = {0};
    judge[0] = 0;
    scanf("%d", &num_group);
    for(int i = 0; i < num_group; i++)
    {
        int arr[N] = {0};
        scanf("%d", &length_group);
        for(int j = 0; j < length_group; j++)
        {   
            scanf("%d", &arr[j]);
        }
        for(int k = 0; k < length_group - 1; k++)
        {
            if(arr[k] > arr[length_group - 1])
            {
                judge[i] = 1;
                break;
            }
        }
    }
    for(int i = 0; i < num_group; i++)
    {
        if(judge[i] == 0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}