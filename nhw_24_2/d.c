#include<stdio.h>
#include<math.h>
#define N 10

int main(void)
{
    long number;
    int arr[N] = {0};
    int num = 0;
    
    scanf("%ld", &number);
    
    //用num来记录number的数字位数
    for(int i = 0, number1 = number; i < 9; i++)
    {
        if(number1 / 10 >= 1)
        {
            number1 = number1 / 10;
            num++;
        }
    }
    num = num + 1;
    //printf("%d\n", num);
    
    //将number的各位数字录入arr
    for(int i = 0, number2 = number; i < num; i++)
    {
        arr[i] = number2 / pow(10, (num - 1 - i));
        //printf("%d", arr[i]);
        number2 = number2 % (int)pow(10, (num - 1 - i));
    }

    //根据情况输出
    int number4 = 0;
    for(int i = 0; i < num; i++)
    {
        number4 += pow(arr[i], num);
    }
    if(number == number4)
    {
        printf("%d", num);
    }
    else
    {
        printf("0");
    }
}