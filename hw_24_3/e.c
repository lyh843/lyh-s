#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define N 150

int main (void)
{
    int amount;
    int each_arr[20] = {0};
    int arr[N] = {0};
    char string[20];
    scanf("%d", &amount);
    getchar();
    
    for(int i = 0; i < amount; i++)
    {
        scanf("%s", &string);
        getchar();
        int length_string = strlen(string);
        for(int j = 0; j < length_string; j++)
        {
            switch((int)string[j])
            {
                case 49:
                    each_arr[j] = 1;
                    break;
                case 48:
                    each_arr[j] = 0;
                    break;
                case 90:
                    each_arr[j] = -1;
                    break;
                default:
                    each_arr[j] = 2;
                    break;
            }
        }
        for(int j = length_string -1, k = 0 ; j >= 0; j--, k++)
        {
            if(each_arr[j] == 2)
            {
                arr[i] = 114514;
                break;
            }
            else
            {
                arr[i] += each_arr[j] * pow(3, k);
            }
        }
    }

    for(int i = 0; i < amount; i++)
    {
        if(arr[i] == 114514)
        {
            printf("Radix Error\n");
        }
        else
        {
            printf("%d\n", arr[i]);
        }
    }
}