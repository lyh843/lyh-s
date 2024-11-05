#include<stdio.h>

int main(void)
{
    int len;
    scanf("%d", &len);
    getchar();
    char string1[len + 2];
    for(int i = 0; i < len; i++)
    {
        scanf("%c", &string1[i]);
    }
    char string2[len + 2];
    for(int i = 0; i < len; i++)
    {
        if(string1[i] >= 65 && string1[i] <= 90)
        {
            string2[len - 1 - i] = string1[i] + 'a' - 'A';
        }
        else if(string1[i] >= 97 && string1[i] <= 122)
        {
            string2[len - 1 - i] = string1[i] + 'A' - 'a';
        }
        else
        {
            string2[len - 1 - i] = string1[i];
        }
    }
    for(int i = 0; i < len; i++)
    {
        printf("%c", string2[i]);
    }
}