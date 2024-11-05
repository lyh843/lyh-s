#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//把end mid start设为局部变量，则有100%概率随机变为零

int mid = (int)pow(2, 5);
int end = (int)pow(2, 10);
long start = 0;
int main(void)
{
    printf("%d\n", (int)pow(2, 5));
    char result_s;
    int result_num = 0;
    //int end = (int)pow(2, 10);
    //int mid = (int)pow(2, 5);
    while(1)
    {
        scanf("%s", &result_s);
        switch(result_s)
        {
            case 'G':
                result_num = 1;
                break;
            case 'L':
                result_num = 2;
                break;
            case 'E':
                return 0;
            default:
                return 0;
        }
        if(result_num == 1)
        {
            end = mid - 1;
            mid = start + (end - start) / 2;
        }
        else if(result_num == 2)
        {
            start = mid + 1;
            mid = start + (end - start) / 2;
        }
        printf("%d\n", mid);
    }
}