#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

int main(void)
{
    int times = 0;
    char string1[16] = "\0";
    scanf("%d", &times);
    int arr[16] = {0};
    bool flag = true;
    int result = 0;
    for(int i = 0; i < times; i++)
    {
        result = 0;
        flag = true;
        memset(arr, 0, sizeof(arr));
        memset(string1, 0, sizeof(string1));
        scanf("%s", string1);
        int len = strlen(string1);
        for(int i = 0; i < len; i++)
        {
            if(string1[i] == '1')
            {
                arr[i] = 1;
            }
            else if(string1[i] == '0')
            {
                arr[i] = 0;
            }
            else if(string1[i] == 'Z')
            {
                arr[i] = -1;
            }
            else
            {
                printf("Radix Error\n");
                flag = false;
                break;
            }
        }
        if(flag)
        {
            for(int i = 0; i < len; i++)
            {
                result += arr[i] * (int)pow(3, len - 1 - i);
            }
            printf("%d\n", result);
        }
    }
}