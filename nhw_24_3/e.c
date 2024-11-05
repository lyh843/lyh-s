#include<stdio.h>
#include<math.h>
int check(int len, int number, char string[len + 1])
{
    int judge = 0;
    if(number <= 10)
    {
        for(int i = 0; i < len; i++)
        {
            if((int)string[i] >= 48 && (int)string[i] < 48 + number)
            {
                judge += 0;
            }
            else
            {
                judge += 1;
            }
        }
    }
    if(number > 10)
    {
        for(int i = 0; i < len; i++)
        {
            if(((int)string[i] >= 48 && (int)string[i] <= 57) ||( (int)string[i] >= 65 && (int)string[i] < 65 + number - 10 ))
            {
                judge += 0;
            }
            else
            {
                judge += 1;
            }
        }
    }
    if(judge == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(void)
{
    int len, number;
    int arr[31] = {0};
    int result = 0;
    scanf("%d", &len);
    char string1[31] = {0};
    scanf("%d", &number);
    scanf("%s", string1);
    if(check(len, number, string1) == 1)
    {
        for(int i = 0; i < len; i++)
        {
            if((int)string1[i] >= 48 && (int)string1[i] <= 57)
            {
                arr[i] = (int)string1[i] - 48;
            }
            else if((int)string1[i] >= 65 && (int)string1[i] < 65 + number - 10)
            {
                arr[i] = (int)string1[i] - 54;
            }
        }
    }
    else
    {
        printf("Error");
        return 0;
    }
    for(int i = len - 1; i >= 0; i--)
    {
        result += arr[i] * pow(number, i);
    }
    printf("%d", result);
    return 0;
}