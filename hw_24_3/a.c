#include<stdio.h>
//回文字符串
int main (void)
{
    int n;
    scanf("%d", &n);
    char string[n + 10];
    scanf("%s", string);
    
    for(int i = 0; i < n; i++)
    {
        if(string[i] == '?')
        {
            printf("%c", string[n - i -1]);
        }
        else
        {
            printf("%c", string[i]);
        }
    }

}