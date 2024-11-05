#include<stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    char string[2001];
    scanf("%s", string);
    for(int i = 0; i < n; i++)
    {
        if(string[i] == '?')
        {
            printf("%c", string[n - 1 - i]);
        }
        else
        {
            printf("%c", string[i]);
        }
    }
    return 0;
}