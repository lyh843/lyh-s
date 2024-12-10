#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
int max_power1 = 0, max_power2 = 0;
char variable[11] = {0};
int num1[10001] = {0}, num2[10001] = {0};
int num_result[16800] = {0}, max_power = 0;
bool print = false;
void f_print()
{
    print = false;
    for(int i = max_power; i >= 2; i--)//从高次项到二次项
    {
        if(num_result[i] == 0)
        {
            continue;
        }
        else if(num_result[i] == 1)
        {
            if(print)
            {
                printf("+%s^%d", variable, i);
            }
            else
            {
                printf("%s^%d", variable, i);
            }
            print = true;
        }
        else if(num_result[i] == -1)
        {
            if(print)
            {
                printf("-%s^%d", variable, i);
            }
            else
            {
                printf("%s^%d", variable, i);
            }
            print = true;
        }
        else if(num_result[i] > 0)
        {
            if(print)
            {
                printf("+%d%s^%d", num_result[i], variable, i);
            }
            else
            {
                printf("%d%s^%d", num_result[i], variable, i);
            }
            print = true;
        }
        else//(num_result[i] < 0)
        {
            if(print)
            {
                printf("%d%s^%d", num_result[i], variable, i);
            }
            else
            {
                printf("%d%s^%d", num_result[i], variable, i);
            }
            print = true;
        }
    }
    if(num_result[1] == 1)//一次项
    {
        if(print)
        {
            printf("+%s", variable);
        }
        else
        {
            printf("%s", variable);
            print = true;
        }
    }
    else if(num_result[1] == -1)
    {
        if(print)
        {
            printf("-%s", variable);
        }
        else
        {
            printf("%s", variable);
            print = true;
        }
    }
    else if(num_result[1] > 0)
    {
        if(print)
        {
            printf("+%d%s", num_result[1], variable);
        }
        else
        {
            printf("%d%s", num_result[1], variable);
            print = true;
        }
    }
    else//小于-1
    {
        printf("%d%s", num_result[1], variable);
        print = true;
    }
    if(num_result[0] > 0)
    {
        if(print)
        {
            printf("+%d", num_result[0]);
        }
        else
        {
            printf("%d", num_result[0]);
        }
    }
    else if(num_result[0] < 0)
    {
        printf("%d", num_result[0]);
    }
    else if(num_result[0] == 0 && !print)
    {
        printf("0");
    }
    printf("\n");
}
void f_add()
{
    for(int i = 0; i <= max_power1 || i <= max_power2; i++)
    {
        num_result[i] = num1[i] + num2[i];
    }
    max_power = max_power1 > max_power2 ? max_power1 : max_power2;
    f_print();
}
void f_minus()
{
    for(int i = 0; i <= max_power1 || i <= max_power; i++)
    {
        num_result[i] = num1[i] - num2[i];
    }
    max_power = max_power1 > max_power2 ? max_power1 : max_power2;
    f_print();
}
void f_multiply()
{
    memset(num_result, 0, sizeof(num_result));
    for(int i = 0; i <= max_power1; i++)
    {
        for(int j = 0; j <= max_power2; j++)
        {
            num_result[i + j] += num1[i] * num2[j];
        }
    }
    max_power = max_power1 + max_power2;
    f_print();
}
int main(void)
{
    scanf("%d%d", &max_power1, &max_power2);
    scanf("%s", variable);
    for(int i = max_power1; i >= 0; i--)
    {
        scanf("%d", &num1[i]);
    }
    for(int i = max_power2; i >= 0; i--)
    {
        scanf("%d", &num2[i]);
    }
    f_add();
    f_minus();
    f_multiply();
}