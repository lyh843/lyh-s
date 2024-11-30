#include<stdio.h>
int main(void)
{
    char string[1030] = {0};
    scanf("%s", string);
    printf("%c", string[0]);
    for(int i = 1; string[i] != '\0'; i++)
    {
        if(string[i] >= 'A' && string[i] <= 'Z')
        {
            printf(" %c", string[i] - 'A' + 'a');
        }
        else
        {
            printf("%c", string[i]);
        }
    }
    return 0;
}