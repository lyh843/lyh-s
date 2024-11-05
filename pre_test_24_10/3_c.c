#include<stdio.h>
#include<string.h>

int main(void)
{
    int num_peo, kill;
    scanf("%d", &num_peo);
    scanf("%d", &kill);
    int arr[51] = {0};
    //memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= num_peo; i++)
    {
        arr[i] = 1;
    }
    arr[0] = 0;
    int sum_peo = num_peo;
    int number = 0;
    while(sum_peo - 1)
    {
        int k = kill;
        while(k - 1)
        {
            number++;
            if(number > num_peo)
            {
                number = 1;
            }
            while(1 - arr[number])//判断这个是不是活人
            {
                number++;
                if(number > num_peo)
                {
                    number = 1;
                }
            }
            k--;
        }
        number++;
        while(1 - arr[number])//判断这个是不是活人
        {
            number++;
            if(number > num_peo)
            {
                number = 1;
            }
        }
        arr[number] = 0;
        sum_peo--;
    }

    for(int i = 1; i <=num_peo; i++)
    {
        if(arr[i] == 1)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}