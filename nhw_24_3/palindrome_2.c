#include<stdio.h>
#define N 100005
int len = 0;
char string[N] = {0};
int count1 = 1, count2 = 0;
void f_process()
{
    for(int i = 1; i <= len / 2 + 1; i++)
    {
        if(string[i] == '?' && string[len + 1 - i] == '?')
        {
            string[i] = '*';
            string[len + 1 - i] = '*';
            count2++;
        }
        else if(string[i] == '?' && string[len + 1 - i] != '?')
        {
            string[i] = string[len + 1 - i];
        }
        else if(string[i] != '?' && string[len + 1 - i] == '?')
        {
            string[len + 1 - i] = string[i];
        }
    }
}
void f_special(int a)
{
    if(a == 1)
    {
        printf("%d%d", count1 / 10, count1 % 10);
        count1++;
    }
    else if(a == 2)
    {
        printf("%d%d", count2 % 10, count2 / 10);
        count2--;
    }
}
void f_printf()
{
    for(int i = 1; i <= len; i++)
    {
        if(string[i] == '*' && i <= len / 2)
        {
            f_special(1);
        }
        else if(string[i] == '*' && i > len /2)
        {
            f_special(2);
        }
        else
        {
            printf("%c", string[i]);
        }
    }
}
int main(void)
{
    scanf("%d%s", &len, &string[1]);
    f_process();
    f_printf();
}