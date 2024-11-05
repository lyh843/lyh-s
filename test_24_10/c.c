#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//问题出在len的身上
int main(void)
{
    int weigh = 0;
    scanf("%d", &weigh);
    int arr1[20] = {0};//倒序
    int arr2[20] = {0};//正序，留一位进位
    int len = 0;
    //转换进制的代码有待优化
    while(weigh > 0)
    {
        arr1[len] = weigh % 5;
        len++;
        weigh = weigh / 5;
    }
    /*
    if(weigh != 5)
    {
        arr1[len] = weigh;
        len++;
    }
    else
    {
        arr1[len] = 1;
        len++;
        len++;
    }
    */
    //
    for (int i = 0; i < len; i++)
    {
        arr2[i + 1] = arr1[len - i - 1];
    }
    len++;//长度阔一位
    //正序，并且第一位留出来
    for (int i = len; i >= 0; i--)//转换
    {
        switch(arr2[i])
        {
            case 0: case 1: case 2:
                {
                    arr2[i] = arr2[i];
                    break;
                }
            case 3:
            {
                arr2[i] = -2;
                arr2[i - 1]++;
                break;
            }
            case 4:
            {
                arr2[i] = -1;
                arr2[i - 1]++;
                break;
            }
            case 5:
            {
                arr2[i] = 0;
                arr2[i - 1]++;
                break;
            }
            default:
                break;
        }
    }
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        count += abs(arr2[len - i]);
    }
    printf("%d", count);
    return 0;
}