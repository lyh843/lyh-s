#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
int main(void)
{
    int times = 0;
    char string10[16] = "\0";
    int arr3[22] = 0;
    for(int i = 0; i < times; i++)
    {
        int flag = true;
        int zhengshu = ture;
        memset(string10, 0, sizeof(string10));
        scanf("%s", string10);
        int len = strlen(string10);
        int number10 = 0;
        for(int i = 0; i < len; i++)
        {
            if(string10[i] == 'Z')
            {
                printf("Radix Error\n");
                flag = false;
                break;
            }
        }
        if(!flag)
        {
            continue;
        }
        number10 = atoi(string10);
        
        int len_a3 = 1;
        for(; number10 > 3; len_a3++)
        {
            arr3[len_a3 - 1] = number10 % 3;
            number10 = (number10 - (number10 % 3)) / 3; 
        }
        arr3[len_a3] = number10;
        len_a3++;
        int string3[22] = "";
        for(int j = len_a3 - 1; j >= 0; j++)
        {
            if(arr3[j] == 1)
            {
                string3[j + 1 - len_a3] = '1';
            }
            else if(arr3[j] == 0)
            {
                string3[j + 1 - len_a3] = '0';
            }
            else if(arr3[j] == 2)
            {
                string3[j + 1 - len_a3] = 'Z';
                arr3[j - 1]++;
            }
            else if(arr3[j] == 3)
            {
                string3[j + 1 - len_a3] = '0';
                arr3[j - 1]++;
            }
        }

    }
}