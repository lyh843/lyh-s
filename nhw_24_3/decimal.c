#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#define N 35
bool judge = true;
char ch_number[N] = {0};
char book[17] = "0123456789ABCDEF";
void f_judge(int decimal)
{
    for(int i = 0; ch_number[i] != '\0' && judge; i++)
    {
        if((decimal <= (strchr(book, ch_number[i]) - book)) || strchr(book, ch_number[i]) == NULL)
        {        
            judge = false;
        }
    }
}
void f_change(int len)
{
    for(int i = 0; i < len; i++)
    {
        if(ch_number[i] == 'A')
        {
            ch_number[i] = 10;
        }
        else if(ch_number[i] == 'B')
        {
            ch_number[i] = 11;
        }
        else if(ch_number[i] == 'C')
        {
            ch_number[i] = 12;
        }
        else if(ch_number[i] == 'D')
        {
            ch_number[i] = 13;
        }
        else if(ch_number[i] == 'E')
        {
            ch_number[i] = 14;
        }
        else if(ch_number[i] == 'F')
        {
            ch_number[i] = 15;
        }
        else
        {
            ch_number[i] = ch_number[i] - 48;
        }
    }
}
int f_process(int decimal, int len)
{
    int result = 0;
    for(int i = 0; i < len; i++)
    {
        result += (int)ch_number[i] * pow(decimal, len - i - 1);
    }
    return result;
}
int main(void)
{
    int len = 0, decimal = 0;
    scanf("%d%d", &len, &decimal);
    scanf("%s", ch_number);
    f_judge(decimal);
    if(!judge)
    {
        printf("Error\n");
    }
    else
    {
        f_change(len);
        printf("%d\n", f_process(decimal, len));
    }
}